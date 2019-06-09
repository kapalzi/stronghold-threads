//
//  main.cpp
//  stronghold-threads
//
//  Created by Krzysztof Kapała on 25/05/2019.
//  Copyright © 2019 Krzysztof Kapała. All rights reserved.
//

#include <iostream>
#include "Life.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Life *life = new Life();
    life->initLife();
    
    
    while(1) {
        if (std::cin.get() == 's') {
            life->clean();
        }
    }
    return 0;
}
