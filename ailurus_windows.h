//the ailurus_windows.h from Ailurus Project,a C++ open source libraries project
#include <iostream>
#include <windows.h>
#include <cstdlib>
#ifndef end_line_is_macro
	#define end_line_is_macro 0//it isn't a macro
#endif
#if end_line_is_macro
	#define end_line end_line
#endif
#ifndef screen_colour_is_macro
	#define screen_colour_is_macro 0//it isn't a macro
#endif
#if screen_colour_is_macro
	#define screen_colour screen_colour
#endif
namespace ailurus{
	using namespace std;
	constexpr char end_line='\n';
	class window{
		public:
			virtual HANDLE get_window_handle(void)=0;
	};
	class command_window:public window{//It includes cli_window and tui_window 
		public:
			command_window(){
				this->window_handle=GetStdHandle(STD_OUTPUT_HANDLE);
			}
			command_window(const command_window& other_screen)=delete;
			//disallow to create a new command_window object from an old one
			//because a command window can only had one command_window object
			//to control itself
			void set_colour(int colour){
				SetConsoleTextAttribute(this->window_handle,(WORD)colour);
			}
			void clear(){
				system("cls");
			}
			class output{//the output stream in the command_window object
				public:
					output(ailurus::command_window* father_screen){
						this->father_screen=father_screen;
					}
					output(const output& old){
						this->father_screen=old.father_screen;
					}
					template<typename type> output& operator<<(const type& output_object){
						cout<<output_object;
						return *this;
					}
					template<typename type> output& operator()(const type& output_object){
						return this->operator<<(output_object);
					}
					ailurus::command_window* get_father_screen(){
						return this->father_screen;
					}
				private:
					ailurus::command_window* father_screen;
			};
			output out=output(this);//create an object for outputting
			class input{//the input stream in the command_window object
				public:
					input(ailurus::command_window* father_screen){
						this->father_screen=father_screen;
					}
					input(const input& old){
						this->father_screen=old.father_screen;
					}
					template<typename type> input& operator>>(type& input_object){
						cin>>input_object;
						return *this;
					}
					template<typename type> input& operator()(const type& input_object){
						return this->operator>>(input_object);
					}
					ailurus::command_window* get_father_screen(){
						return this->father_screen;
					}
				private:
					ailurus::command_window* father_screen;
			};
			input in=input(this);//create an object for inputting
			HANDLE get_window_handle(void) override{
				return this->window_handle;
			}
		private:
			HANDLE window_handle;
	};
	class screen_colour{
		public:
			screen_colour(int colour_get){
				this->colour=colour_get;
			}
			screen_colour(const screen_colour& old){
				this->colour=old.colour;
			}
			friend command_window::output& operator<<(command_window::output& out,const screen_colour& new_colour){
				out.get_father_screen()->set_colour(new_colour.colour);
				return out;
			}
		private:
			int colour;
	};
	const screen_colour colour_reset=screen_colour(0xf);
	void message_box(
		string window_name,
		string message,
		unsigned int buttons=MB_OK
	){
		MessageBox(NULL,message.c_str(),window_name.c_str(),(UINT)buttons);
	}
}
