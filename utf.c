/***************************************************************************
  > Filename   : utf.c
  > Author     : oneface - one_face@sina.com
  > Company    : 一尊还酹江月
  > Time       : 2018-04-24 16:34:40
  > Description: 

  - This program is free software; you can redistribute it and/or modify it
  - under the terms of the GNU General Public License as published by the
  - Free Software Foundation;  either version 2 of the  License, or (at your
  - option) any later version.
 **************************************************************************/
#include <stdio.h>

#include <string.h>
#include <glib.h>

gchar *demo_text =
"我的 C81 每天都在口袋里\n"
"      @";

static gchar * get_utf8_char(const gchar *base) {
	gchar *new_base = g_utf8_next_char(base);
	gsize n = new_base - base;
	gchar *utf8_char = g_memdup(base, (n + 1));
	utf8_char[n] = '\0';
	return utf8_char;
}

static gboolean is_space(const gchar *c) {
	gboolean ret = FALSE;
	gchar *utf8_char = get_utf8_char(c);
	char *space_chars_set[] = {" ", "\t", "　"};
	size_t n = sizeof(space_chars_set) / sizeof(space_chars_set[0]);
	for (size_t i = 0; i < n; i++) {
		if (!strcmp(utf8_char, space_chars_set[i])) {
			ret = TRUE;
			break;
		}
	}
	g_free(utf8_char);
	return ret;
}

static gboolean is_line_break(const gchar *c) {
	gboolean ret = FALSE;
	gchar *utf8_char = get_utf8_char(c);
	if (!strcmp(utf8_char, "\n")) ret = TRUE;
	g_free(utf8_char);
	return ret;
}

int main(void) {
	gboolean is_right_at_sign = TRUE;
	glong offset = g_utf8_strlen(demo_text, -1);
	gchar *viewer = g_utf8_offset_to_pointer(demo_text, offset - 1);
	while (viewer != demo_text) {
		viewer = g_utf8_prev_char(viewer);
		if (!is_space(viewer)) {
			if (!is_line_break(viewer)) is_right_at_sign = FALSE;
			break;
		}
	}
	if (is_right_at_sign) g_print("Right @ !\n");

	return 0;
}
