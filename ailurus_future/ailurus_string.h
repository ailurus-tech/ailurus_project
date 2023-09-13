//the ailurus_string.h from Ailurus Project,
//a C++ open source libraries project
//ailurus future fuctions' demo,they may be instable and have many bugs
//just for developers to test,don't use them except the developing
//and testing environment or at your own risk
#include <vector>
#ifndef ailurus_string_type_name
	#define ailurus_string_type_name 0
#endif
namespace ailurus{
	class string{
		public:
			string(){
				content="";
			}
			string(char* text){
				content=text;
			}
			string(std::string text){
				content=text;
			}
			string(const ailurus::string& old){
				content=old.content;
			}
			operator+(ailurus::string append){
				this->content+=append.content;
			}
			friend ailurus::command_window::input& operator>>//input
			(ailurus::command_window::input& in,ailurus::string& object){
				in>>object.content;
				return in;
			}
			friend ailurus::command_window::output& operator>>//output
			(ailurus::command_window::output& out,ailurus::string& object){
				out<<object.content;
				return out;
			}
			std::vector<std::string> split(ailurus::string splitted_str,char split_char){
			//call the split function in namespace ailurus to do split
				return ailurus::split(splitted_str.content,split_char);
			}
		private:
			std::string content;
	};
}
#if ailurus_string_type_name
//set the name of the string in namespace ailurus "ailurus::ailurus_string"
	typedef ailurus::string ailurus_string;
#endif
