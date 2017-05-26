#include <iostream>
#include <cassert>

void swap(int& a, int& b){
	a = a + b;	// a = a + b
	b = a - b;	// b = (a + b) - b
	a = a - b;	// a = (a + b) - ((a + b) - b)
	
	// a = (a + b) - ((a + b) - b)
	// a = (a + b) - a
	// a = b
	
	// b = (a + b) - b
	// b = a
	
}

void swap_test(int a, int b){
	
	int back_a = a;
	int back_b = b;
	
	swap(a, b);
	
	std::cout << "initial a: " 	<< back_a << "\t swapped a: " << a << std::endl;
	std::cout << "initial b: " 	<< back_b << "\t swapped b: " << b << std::endl;
	std::cout << std::endl;
	
	assert(a == back_b);
	assert(b == back_a);
	
}

int main(int argc, char** argv){

	swap_test( 10, 10);
	swap_test( 10, 20);
	swap_test( 10,-10);
	swap_test(-10, 10);
	swap_test(-10,-20);
	
	return 0;
}
