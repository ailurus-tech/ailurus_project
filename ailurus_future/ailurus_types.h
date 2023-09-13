//the ailurus_types.h from Ailurus Project,a C++ open source libraries project
//ailurus future fuctions' demo,they may be instable and have many bugs
//just for developers to test,don't use them except the developing
//and testing environment or at your own risk
#include <iostream>
#include <string>
#include <cmath>
namespace ailurus{
	class high_accuracy_int{
		public:
			high_accuracy_int(void){//empty initialization
				content="";
			}
			high_accuracy_int(const high_accuracy_int& old){
				content=old.content;
			}
			high_accuracy_int(long long int number){
				int power_of_ten=0;
				for(int i=1;i<=number;i*=10){
					//get the number's nearest 10's power
					power_of_ten=i;
				}
				for(int i=power_of_ten;i>=1;i/=10){
					content+=number/i%10+'0';
					//change the number's digit to a string's char
					//and store it in the variable content
				}
			}
			high_accuracy_int(std::string number){
				content=number;
			}
			high_accuracy_int& operator=(long long int number){
				content="";
				int power_of_ten=0;
				for(int i=1;i<=number;i*=10){
				//get the number's nearest 10's power
					power_of_ten=i;	
				}
				for(int i=power_of_ten;i>=1;i/=10){
					content+=number/i%10+'0';
					//change the number's digit to a string's char
					//and store it in the variable content
				}
				return *this;
			}
			high_accuracy_int& operator=(high_accuracy_int& new_number){
				this->content=new_number.content;
				return *this;
				
			}
			high_accuracy_int& operator=(std::string number){
				this->content=number;
				return *this;
			}
			high_accuracy_int& operator+(high_accuracy_int& number_add){
				string sum="";
				for(int i=0;i<stoi(number_add.content);i++){
					sum+='0';
				}
				sum+=std::max(this->content,number_add.content);
				//length has a digit more than the max number now
				//in order to reserve a digit for carry
				string small_num=std::min(this->content,number_add.content);
				long long int i=(long long int)sum.size()-1;
				//variable i store the index of the string object sum
				for(long long int j=(long long int)(small_num.size()-1);j>=0;j--){
				//from it's smallest digit start adding until finish;
					int digit_add_num=(sum[i]-'0')+(small_num[j]-'0');
					if(digit_add_num>=10){//calculate carry
						sum[i-1]++;
						digit_add_num=digit_add_num-10;
					}
					if((sum[i]-'0')>=10){
						sum[i-1]++;
						sum[i]=sum[i]-10;
					}
					sum[i]=digit_add_num+'0';
					//calculate this digit's new value(include the carry) and change it to a char
					i--;
				}
				this->content="";
				for(std::string::size_type i=0;i<sum.size();i++){
				//copy the number in correct form
				//(without a carry which value is 0)
					if(sum[0]!='0'){//don't have carry
						this->content+=sum[i];
					}
				}
				return *this;
			}
			high_accuracy_int& operator+(long long int number_add){
				high_accuracy_int high_accuracy_number_add=number_add;
				return this->operator+(high_accuracy_number_add);
			}
			high_accuracy_int& operator+(std::string number_add){
				high_accuracy_int high_accuracy_number_add=number_add;
				return this->operator+(high_accuracy_number_add);
			}
			high_accuracy_int& operator*(long long int times){
				high_accuracy_int result=high_accuracy_int(this->content);
				for(long long int i=1;i<times;i++){
					result=result+(*this);
				}
				*this=result;
				return *this;
			}
			friend std::ostream& operator<<(std::ostream& output,high_accuracy_int object){
				output<<object.content;
				return output;
			}
		private:
			std::string content;
	};
}

