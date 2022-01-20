/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/

#include<iostream>
#include<vector>

std::string convert(std::string s, int numRows) {
    std::vector<std::vector<char>>zig(numRows,std::vector<char>(1,'#'));
    bool going_down = true;
    int cr = 0 ;
    int cc =0 ;
    if(numRows == 1){
        return s;
    }
    for(int i = 0 ; i < (int) s.size() ; ++i){
        if(going_down){
            zig[cr][cc] = s[i];
            cr++;
            if(cr>=numRows){
                going_down = false;
                cr--;
            }
        }else{
            cr = cr-1;
            if(cr<0){
                cr =0 ;
            }
            cc = cc +1;
            for(int i =0 ; i < numRows ; ++i){
                zig[i].push_back('#');
            }
            zig[cr][cc] = s[i];
            if(cr ==  0 ){
                going_down = true;
                cr++;
            }
        }
    }
    std::string str = "";
    for(auto x : zig ){
        for(auto y :  x){
            if(y != '#'){
                str += y;
            }
        }
    }
    return str;
}
int main(){
    std::cout<<"Output String is : "<<convert("",1)<<std::endl;
    std::cout<<"Working.";
    return 0 ;
}
