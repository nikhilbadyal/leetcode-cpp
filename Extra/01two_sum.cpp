/*
Given an array of integers nums and and integer target, return the indices of the two numbers such
 that they add up to target.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

std::pair<int,int> two_sum(std::vector<int>nums , int target){
    //Create a map to store the indices of elements in the array.
    std::unordered_map<int,int> hash;
    for(int i = 0 ; i < (int) nums.size(); ++i){
        if(hash.find(target-nums[i]) != hash.end()){
            return std::make_pair(hash[target-nums[i]],i);
        }
        //Store element index in the array.
        hash[nums[i]] = i ;
    }
    return std::make_pair(-1,-1);

}
int main(){
    std::vector<int>  nums = {23,-54,654,-4,3,34,57,-4,-5,-4};
    int target = -1;
    auto ans = two_sum(nums,target);
    if(ans.first != -1 ){
        std::cout<<"Target found at index "<<ans.first+1<<"  "<<ans.second+1<<std::endl;
    }else{
        std::cout<<"No such pair exist.";
    }
    std::cout<<"Working.";
    for (int i = 0 ; i < 20 ; ++i){
        std::cout<<"Fucked you.";
    }
    return 0 ;
}
