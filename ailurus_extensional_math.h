//the ailurus_extensional_math.h from Ailurus Project
//a C++ open source libraries project
template<typename integer> integer factorial(integer number){
	if(number==1){
		return 1;
	}
	return number*factorial(number-1);
}
template<typename integer> integer abs(integer number){
	return (number>=0)?number:-number;
	//if number>=0 return itself,else return it's opposite number.
}
