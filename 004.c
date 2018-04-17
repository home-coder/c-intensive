/*************************************************************************
 > Filename   : 004.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-26 18:42:48
 ************************************************************************/

#include <stdio.h>

#define TEST_3 1

int main()
{
#if TEST_0
	//没有const, 虽然操作了只读常量区但是编译过程通过，所以为了让其编译也不通过，最好的编码方式是当时就加上一个const
	char *str = "helloworld";
	str[3] = 'm';
#endif

#if TEST_1
	//编译就会报错，const 在C语言中并不是强制的保护作用，仅仅起到给编译器看的作用
	const char *str = "helloworld";
	str[3] = 'm';
#endif

#if TEST_2
	const char *const str = "helloworld";
	str = "mall";
#endif

#if TEST_3
	const char *str = "helloworld";
	str = "mall";
#endif
	return 0;
}

/*
   嵌入式C语言const关键字是否为常量的讨论

   chengx2年前

   Rocky老师在我们的嵌入式底层驱动开发企业直通班的直播课程中，在跟同学交流的时候，发现很多的同学对于const这个关键字的理解存在很大的误解。现在总结下对这个关键字理解上的误区，希望在以后的编程中，能够灵活使用const这个关键字。 在C语言的学习中，希望大家能够通过一些精简的代码小实例，对自己的想法进行实际的验证，不断通过自己的思考，自己的验证，来提升C语言的功底，为我们后面linux系统开发打下坚实的基础。 （1）const == 常量？ 对于这个问题，很多学员由于在C++和JAVA编程中的思维定势，普遍认为const修饰的变量是不能改变，结果就误认为该变量变成了常量。但是在我们的C语言中，对于const修饰的变量是否和C++/JAVA一样的理解那？ 下面我们来看一个例子： int main              {                char array[4];                const int test_a = 0;                     test_a = 10; return 0;              } 这个结果很明显，编译器直接报错，根本就不能生成最终的目标文件，其原因在于“test_a = 10；”这句话，对const修饰的变量，后面进行赋值操作。这好像已经证明了const修饰的变量是不能被修改的，那究竟是不是那，那么下面我们把这个例子修改下： int main              {                char array[4];                const int test_a = 0;                     array[4] = 0x88;                printf(“the test_a is %x\n”,test_a);              }   其中最后一句printf的目的是看下变量test_a的值是否改变，根据const的理解，如果const修饰的是变量是不能被修改的话，那么a的值一定不会改变，肯定还是0。但是在实际运行的结果中，我们发现a的值已经变为十六进制的0x88了。这说明const修饰的变量test_a，已经被我们程序修改了。 【结论及疑问：】 通过这2个简单的小例子，已经可以证明了const != 常量。但是为什么那？？？ 那我们来分析下，对于第二例子，修改的原因是array[4]的赋值操作，我们知道array[4]这个变量已经造成了array这个数组变量的越界访问。array数组的成员本身只有0,1,2,3，那么array[4]访问的是谁那，根据局部变量的地址分配，可以知道array[4]的地址和int test_a的地址是一样，那么array[4]实际上就是访问了test_a的内存空间，当然，我们可以尝试使用对test_a进行取地址来用%p的方式查看下他的地址和array[4]是否一样。 那么对array[4]的修改，自然也修改了const int test_a的空间，这也是为什么我们在最后打印test_a的值的时候看到了0x88这个结果。 这个问题，我们清楚了，但是如果在深入的想一想，我我们还会有新的发现。 当然这个结论，对于C++和JAVA开发的程序员，就觉得很迷糊了，而且我们也可以在c++
/*中进行验证，你会发现第二个程序在C++的编译情况下，结论和C是不一致的，那么为什么那，大家可以参考我们的[《嵌入式C语言高级课程》和《ARM汇编优化》](http://www.maiziedu.com/course/qrs/ "《嵌入式C语言高级课程》和《ARM汇编优化》")系列课程，相信通过学习一定的底层及汇编语言，我们将更深入的理解这个问题。 文章由Rocky老师，王海宁，麦子学院嵌入式专业负责人编辑发布，版权所有未经同意请勿转载。 欢迎加入2015嵌入式应用开发 QQ群：321914005（互相学习、交流）*/
