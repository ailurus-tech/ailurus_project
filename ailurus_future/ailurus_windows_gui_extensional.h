//the ailurus_string.h from Ailurus Project,
//a C++ open source libraries project
//ailurus future fuctions' demo,they may be instable and have many bugs
//just for developers to test,don't use them except the developing
//and testing environment or at your own risk
//If this library can work well,it will be added into ailurus_windows.h
//in the next version
#include <string>
#include <windows.h>
namespace ailurus{
	class gui_window{
		public:
			gui_window(void){
				window_handle=NULL;
			}
			gui_window(std::string title,gui_window* father_window,
			int width,int height){
				CreateWindowA(NULL,title.c_str(),WS_BORDER,0,0,width,height,
					father_window->get_window_handle(),)
			}
		private:
			HWND window_handle;
	};
}
