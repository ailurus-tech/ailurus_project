//the ailurus_extensional_string.h from Ailurus Project
//a C++ open source libraries project
#include <string>
#include <vector>
namespace ailurus{
	using namespace std;
	vector<string> split(string split_string,char split_char){
		vector<string> splitted_strings;
		for(string::size_type i=0;i<split_string.size();i++){
			if(split_string[i]==split_char){
				string splitted_string="";
				for(string::size_type j=0;j<i;j++){
				//copy the char before variable i
					splitted_string+=split_string[j];
				}
				splitted_strings.insert(splitted_strings.end(),splitted_string);
				string new_split_string=""; 
				for(string::size_type j=i+1;j<split_string.size();j++){
				//copy the char behind variable i
					new_split_string+=split_string[j];
				}
				split_string=new_split_string;//delete string's splitted text
				i=0;//refresh variable i
			}
		}
		splitted_strings.insert(splitted_strings.end(),split_string);
		return splitted_strings;
	}
	string to_upper(string source_string){
		for(
			string::size_type i=0;
			i<source_string.size();
			i++
		){
			if(source_string[i]>='a'&&source_string[i]<='z'){
				source_string[i]=source_string[i]-'a'+'A';
			}
		}
		return source_string;
	}
	string to_lower(string source_string){
		for(
			string::size_type i=0;
			i<source_string.size();
			i++
			){
			if(source_string[i]>='A'&&source_string[i]<='Z'){
				source_string[i]=source_string[i]-'A'+'a';
			}
		}
		return source_string;
	}
}
