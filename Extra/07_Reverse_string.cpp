/*
Given a 32-bit signed integer, reverse digits of an integer.
*/

#include<iostream>

int reverse(int x){
    long int rev = 0 ;
    int digit ;
    do{
        digit = x % 10;
        rev = (rev*10) + digit;
        x = x /10;
    }while(x != 0 );

    return rev;
}
int main(){
    std::cout<<"Reverse no is "<<reverse(-326344);
    return 0 ;
}
