/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/

#include<iostream>

bool isMatch(std::string s, std::string p){
    bool ans = true;
    if(s.size() > p.size()){
       return false;
    }
    for(int i = 0 ; i < (int) s.size() ; ++i ){
        if(s[i] == p[i]){
            continue;
        }else{
            if(p[i]=='.'){
                if(p[i+1] == '#'){
                    i = i +1;
                    continue;
                }
                p[i] = s[i];
            }else if(p[i]=='*'){
                if(p[i-1]==s[i]){
                    int c= 1 ;
                    for(int j = i+1 ; j <(int)s.size();++j){
                        if(s[j] == s[i-1]){
                            c++;
                        }
                        break;
                    }
                    s = s.substr(0,i)+ std::string(c,s[i]) +
                }
            }
        }
    }
    for(int i =0 ; i < (int)s.size();++i){
        if(s[i]!= p[i]){
            ans = false;
        }
    }
    return ans;
}

int main(){
    std::string s = "ab";
    std::string p =  ".*";
    std::cout<<isMatch(s,p);
    return 0 ;
}
