/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same
backward as forward.
*/


#include<iostream>

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    bool ans = false;
    int digit , rev =0;
    int orig = x;
    do{
        digit = x % 10;
        rev = (rev*10) + digit;
        x = x /10;
    }while(x!=0);
    if( orig == rev){
        ans = true;
    }
    return ans;
}


int main(){
    std::cout<<isPalindrome(1);
    return 0 ;
}
