#include <iostream>
#include "Vec_declaration.h"

int main(){

 	Vec<int> v = {1, 2, 3, 4, 5, 6};
 	std::cout << v << std::endl;

	Vec<int>::r_itr fit;
	
	fit = v.end() - 2;

    for(Vec<int>::r_itr fit1 = v.begin() + 2; fit1 != fit; ++fit1) {
        std::cout << *fit1 << " ";
    }
    std::cout << std::endl;
}

