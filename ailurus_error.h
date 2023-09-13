//the ailurus_error.h from Ailurus Project,a C++ open source libraries project
#include <string>
#ifndef ailurus_windows
	#include "ailurus_windows.h"
	#define ailurus_windows
#endif
namespace ailurus{
	void show_error(ailurus::command_window& window,std::string error_text){
		window.set_colour(0x4);
		window.out<<error_text<<end_line;
		window.set_colour(0xf);
	}
}
