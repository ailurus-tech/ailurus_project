#include "ailurus_windows.h"
#include "ailurus_extensional_string.h"
#include "ailurus_extensional_math.h"
using namespace ailurus;
int main(){
	int a=5;
	int b=factorial(a);
	command_window main_window;
	main_window.out<<a<<b<<end_line;
	return 0;
}
