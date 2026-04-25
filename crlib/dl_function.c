/* To implement dynamic loading in c using dlfcn.h you will need to compile the functions into a shared objec(.so) file
RTLD_LAZY -> resolve symbols as they are needed, symbols are resolved only when the code is executed, faster startup but potential surprise crashes later if a symbol is missing, large libraries where you might only use 10% of the functions.
RTLD_NOW -> resolve all symbols immediately, all symbols are resolved before dlopen returns, slower startup but ensures all symbols exist immediately, production systems where you want to catch linking errors early.
RTLD_LAZY -> transfers from HDD to RAM while RTLD_NOW -> transfers from HDD to VRAM and then to RAM
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void run_dynamic_test(const char* lib_path, int mode)
{
	void *handle;
	int (*math_func) (int , int);
	char *error;
	
	// open the shared library
	// mode will be RTLD_LAZY or RTLD_NOW
	handle = dlopen(lib_path, mode);
	if(!handle)
	{
		fprintf(stderr, "Error: %s\n", dlerror());
		return;
	}
	
	// clear existing errors
	dlerror();
	
	// look up the sum function
	math_func = (int (*)(int, int)) dlsym(handle, "sum_fun");
	
	error = dlerror();
	if(error != NULL)
	{
		fprintf(stderr, "symbol lookup error: %s\n", error);
	}
	else
	{
		printf("Result of sum: %d\n", (*math_func)(10,5));
	}
	
	//close the handle
	dlclose(handle);
}

int main(void)
{
	printf("--- Testing RTLD_LAZY ---\n");
	run_dynamic_test("./libcalc.so", RTLD_LAZY);
	printf("--- Testing RTLD_NOW ---\n");
	run_dynamic_test("./libcalc.so", RTLD_NOW);
	return 0;
}
