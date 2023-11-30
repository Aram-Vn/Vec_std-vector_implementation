#include <iostream>
#include "Vec_declaration.h"

int main(){

 Vec<int> v = {1, 2, 3};
 std::cout << v << std::endl;
  
 Vec<bool> b = {false , true, true, false, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 , 0,0 , 0};

	for(int i = 0; i < 125; ++i){
		if(i % 2 == 0) {
			b.push_back(true);
		} else {
			b.push_back(false);
		}	
	}

 std::cout << b << std::endl;
 std::cout << std::endl;
 

	for(int i = 0; i < 120; ++i){
		b.push_back(false);
	}
 
 std::cout << b << std::endl;
 std::cout << std::endl;

 std::cout << std::endl;

 std::cout << b[2] << std::endl;
 std::cout << b[3] << std::endl;
 std::cout << b[4] << std::endl;
 std::cout << b[5] << std::endl;
 std::cout << b[6] << std::endl;
 std::cout << b[7] << std::endl;
 std::cout << b[8] << std::endl;
 std::cout << b[9] << std::endl;
 std::cout << b[999] << std::endl;

}
