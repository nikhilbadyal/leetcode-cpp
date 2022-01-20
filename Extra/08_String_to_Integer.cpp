#include<iostream>
#include<algorithm>
#include<cmath>

std::pair<std::string,bool> remove_ws(std::string str){
    int index = 0;
    for(int i = 0 ; i < (int)str.size();++i){
        if(str[i] != 32){
            index = i;
            break;
        }
    }
    char c = 43;
    if(str[index] == 45 || str[index] == 43){
        c= str[index];
        index++;
    }
    return make_pair(str.substr(index),c==45?true:false);
}
std::string process(std::string str){
   auto c  = remove_ws(str);
    for(int i =0 ; i <(int) str.size();++i){
        if(str[i] < 48 || str[i] > 57 ){
            str = str.substr(0,i);
            break;
        }
    }
    return str;
}
int myAtoi(std::string str) {
    int int_min = -pow(2,31);
    int int_max = pow(2,31)-1;
    str = process(str);

    reverse(str.begin(),str.end());
    long int fact = 1;
    long int digit =0 ;
    long int ans =0 ;
    bool over = false;
    for(int i =0 ; i < (int) str.size(); ++i){
        digit = str[i] - '0';
        digit =  digit* fact;
        ans += digit;
        fact = fact*10;
        if(ans < 0 || digit < 0 ){
            over = true;
            break;
        }
    }
    if(is_neg){
        if(over){
            return int_min;
        }
        return -ans;
    }
    if(over){
        return int_max;
    }
    return ans ;

}
int main(){

    std::cout<<"Number after conversion is "<<myAtoi("-91283472332")<<std::endl;
    std::cout<<"Working.";
    return 0 ;
}
