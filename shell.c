/***************************************************************************
  > Filename   : shell.c
  > Author     : oneface - one_face@sina.com
  > Company    : 一尊还酹江月
  > Time       : 2018-04-21 10:48:07
  > Description: 

  - This program is free software; you can redistribute it and/or modify it
  - under the terms of the GNU General Public License as published by the
  - Free Software Foundation;  either version 2 of the  License, or (at your
  - option) any later version.
 **************************************************************************/
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAXCMDS 20
#define MAXCMDL 100
#define MAXARGS 100
#define MAXCHARS 1024


char *cmdv[MAXCMDS+1];
char *argv[MAXARGS+1]; //参数指针
char cmdline[MAXCHARS];
char precmd[MAXCMDL];
char *cmd;
int cmds;
int pfd[2] = {-1, -1};
int wpipe[2] = {-1, -1};
pid_t pid;

char  *re_stdout = NULL, *re_stdin = NULL;

void flush_argv(char *cmd) {
	int i;
	char *arg=NULL;
	re_stdout = NULL; re_stdin = NULL;
	argv[0] = strtok_r(cmd, " \t\n", &arg);
	if(!argv[0]) return;
	for(i=1; i<MAXARGS && (argv[i]=strtok_r(NULL, " \t\n", &arg)); i++) {
		if(argv[i][0] == '>') {
			if(argv[i][1]) re_stdout = argv[i]+1;
			else re_stdout = strtok_r(NULL, " \t\n", &arg);
			argv[i++] = NULL;
		}else if(argv[i][0] == '<') {
			if(argv[i][1]) re_stdin = argv[i]+1;
			else re_stdin = strtok_r(NULL, " \t\n", &arg);
			argv[i++] = NULL;
		}
	}
}

void myexec(char *cmd) {
	flush_argv(cmd);
	if(!argv[0]) exit(EXIT_FAILURE);
	int re_fd;
	if(re_stdout) {
		re_fd = open(re_stdout, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP);
		if(re_fd < 0) {
			perror("re_stdout error");
			exit(EXIT_FAILURE);
		}
		dup2(re_fd, STDOUT_FILENO);
	}
	if(re_stdin) {
		re_fd = open(re_stdin, O_RDONLY);
		if(re_fd < 0) {
			perror("re_stdin error");
			exit(EXIT_FAILURE);
		}
		dup2(re_fd, STDIN_FILENO); 
	}
	int i;
	if(strchr(argv[0], '/'))
		i = execv(argv[0], (char * const *)argv);
	else
		i = execvp(argv[0], (char * const *)argv);
	if(i<0) { 
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
}

void flush_cmdv(void) {
re_flush:
	printf("MyShell: ");
	fflush(stdout);
	if(fgets(cmdline, MAXCHARS, stdin) == NULL) {
		printf("exit\n");
		exit(EXIT_SUCCESS); 
	}
	cmdv[0] = strtok_r(cmdline, "|", &cmd);
	strncpy(precmd, cmdv[0], MAXCMDL);
	flush_argv(precmd);
	if(!argv[0]) goto re_flush;
	if(strncmp(argv[0], "q", 2) == 0 || strncmp(argv[0], "quit", 5) == 0 ||
			strncmp(argv[0], "exit", 5) == 0)
		exit(EXIT_SUCCESS);
	if(strncmp(argv[0], "cd", 3) == 0) {
		if(chdir(argv[1]) < 0)
			perror("change dir failed");
		goto re_flush;
	}
	for(cmds=1; cmds<MAXCMDS && (cmdv[cmds]=strtok_r(NULL, "|", &cmd)); cmds++) 
		;
}

void re_fork(int index) {
	if(index < cmds-1) {
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
	}
	if(index) {
		pipe(pfd);
		pid = fork();
		if(pid > 0) {
			close(pfd[1]);
			dup2(pfd[0], STDIN_FILENO);
		}     
		if(pid == 0)
			re_fork(index - 1);
	}
	myexec(cmdv[index]); 
}

int main(void)
{
re_label:
	flush_cmdv();
	pipe(wpipe);
	pid = fork();
	if(pid == 0) {
		close(wpipe[0]); //为子进程节省文件描述符
		re_fork(cmds - 1);
	}
	if(pid > 0) {
		close(wpipe[1]); //重复申请最后关闭
		read(wpipe[0], NULL, 1); //利用管道等待所有进程退出
		close(wpipe[0]); //重复申请最好关闭
		goto re_label;
	}
}

