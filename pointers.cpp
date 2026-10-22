#include <stdio.h>
#include <iostream>

int main(){
    //         <==========ADDRESS OPERATOR (&) and DEREFERENCE OPERATOR (*)=============>
    //C ONLY
    int apples = 5;

    printf("This is apples: %02d \n", apples);
    printf("And this is apple's address: %x \n", &apples);
    printf("My dereferenced apple is %02d \n", *(&apples));
    
    int* ptrApple = &apples;

    printf("My apple pointer states apples = %02d \n\n", *ptrApple);

    //C++ VERSION
    int bananas = 2;
    std::cout << "This is Bananas: " << bananas << std::endl;
    std::cout << "This is Bananas' Address: " << &bananas << std::endl;
    std::cout << "My dereferenced banana is " << *(&bananas) << std::endl;

    int* ptrBanana = &bananas;

    std::cout << "My banana pointer states bananas = " << *ptrBanana << std::endl;

    *ptrBanana = 39;

    std::cout << "But I can change my pointer with '*ptrBanana = 39;' to state bananas = " << *ptrBanana << std::endl;
    return 0;
    
}