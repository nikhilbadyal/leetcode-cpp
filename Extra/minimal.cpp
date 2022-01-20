#include<iostream>
#include<unordered_map>
#include<vector>

int minA(int s , std::vector<int> & nums){
    int minlen = INT_MIN;
    int sum = 0 ;
    int i = 0 ;
    for(int j =0 ; j < (int) nums.size() ; ++j){
        sum += nums[i];
        while(sum >= s ){
            minlen= std::min(minlen , j -i +1 );
            sum -= nums[i++];
        }

    }
    return minlen == INT_MIN ? 0 : minlen ;
}
int main(){
    std::vector<int> nums {4,4,55,52,23,67,76,5,26,456,37};
    std::cout<<minA(134,nums);
    return 0 ;
}
