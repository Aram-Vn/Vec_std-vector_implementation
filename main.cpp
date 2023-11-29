#include <iostream>
#include "Vec_declaration.h"

int main(){

 Vec<int> v = {1, 2, 3};
 std::cout << v << std::endl;
  
 Vec<bool> b;

	for(int i = 0; i < 125; ++i){
		b.push_back(true);
	}

 std::cout << std::endl;
 
 std::cout << b << std::endl;

	for(int i = 0; i < 125; ++i){
		b.push_back(false);
	}

 std::cout << std::endl;

 std::cout << b << std::endl;

 /* std::cout << std::endl; */

 /* std::cout << b[2] << std::endl; */

}
