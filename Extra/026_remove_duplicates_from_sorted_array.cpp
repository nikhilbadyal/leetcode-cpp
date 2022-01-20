/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
*/

#include<iostream>
#include<vector>

int removeDuplicates(std::vector<int>& nums) {
    int slow = 0 ;
    for(int fast =1 ; fast < (int) nums.size() ;++fast){

        if(nums[slow] != nums[fast]){
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow+1;

}

int main(){
    std::vector<int> nums{1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9 };
    int index = removeDuplicates(nums);
    for(int i = 0 ; i < index ;++i){
        std::cout<<nums[i]<<"  ";
    }
    return 0 ;
}
