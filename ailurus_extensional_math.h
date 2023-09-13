template<typename integer> integer factorial(integer number){
	if(number==1){
		return 1;
	}
	return number*factorial(number-1);
}
