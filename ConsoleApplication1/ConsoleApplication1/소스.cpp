#include <Windows.h>
#include <stdio.h>


class Test
{
public:
	void(Test::*fp)();
	int(Test::*fp2)(int, int);

	Test()
	{
		fp = &Test::ClassFunc1;
	}
	void ClassFunc1()
	{
		printf("is ClassFunc1!\n");
	}
	int ClassFunc2(int a, int b)
	{
		printf("is ClassFunc2! %d , %d\n", a, b);

		(this->*fp)();

		return a + b;
	}
};

class Child : public Test
{
public:
	void(Child::*func)();
	void ClassFunc1()
	{
		printf("is ChildFunc1!\n");
	}
	int ChildFunc2(int a, int b)
	{
		printf("is ChildFunc2! %d , %d\n", a, b);

		return a + b;
	}
};

void aa()
{
	int a = 10;
	printf("%d\n", a);
}

#include "StopWatch.h"

void main()
{
	Child tem;

	tem.func = &Test::ClassFunc1;

	void(*fp)();

	fp = aa;


	(tem.*tem.func)();
}