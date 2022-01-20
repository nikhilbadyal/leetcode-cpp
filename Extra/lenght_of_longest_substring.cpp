#include<iostream>
#include<unordered_map>

int lenstr(std::string s , int k){
    int maxLen = 0 ;
    std::unordered_map<char,int> hash;
    int max_len = 0;
    for(int i = 0 , j = 0 ; j < (int)s.size() ; ++j ){
        hash.insert({s[j],j});
        if((int)hash.size() > k ){
            while(i < j && hash.at(s[i]) != i){i++;}
            hash.erase(s[i++]);
        }
        max_len = std::max(max_len , j - i +1 );
    }
    return maxLen ;
}
int main(){
    std::string s = "eceba";
    int k = 2;
    std::cout<<lenstr(s , k );
    std::cout<<"Working.";
    return 0 ;
}
