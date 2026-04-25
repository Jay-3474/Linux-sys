#include "main.h"

//extern void ghost_function();

int sum_fun(int x, int y)
{
//	ghost_function(); // the poison call
	return x+y;
}
