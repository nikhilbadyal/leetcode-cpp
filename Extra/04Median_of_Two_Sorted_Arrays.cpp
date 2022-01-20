/*
Given two sorted arrays nums1 and nums2 of size m and n respectively.
Return the median of the two sorted arrays.
*/
#include<iostream>
#include<vector>

std::vector<int> merge_array(std::vector<int> & nums1 , std::vector<int>&nums2){
    int s1 = nums1.size();
    int s2 = nums2.size();
    std::vector<int> ans(s1+s2);
    int i = 0 ;
    int j =0 ;
    int k = 0;
    while(i < s1 && j < s2){
        if(nums2[j] > nums1[i]){
            ans[k] = nums1[i];
            i++;
            k++;
        }else{
            ans[k] = nums2[j];
            j++;
            k++;
        }
    }
    while(i != s1){
        ans[k] = nums1[i];
        i++;
        k++;
    }
    while(j != s2){
        ans[k] = nums2[j];
        j++;
        k++;
    }
    return ans;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double med ;
    std::vector<int> merged = merge_array(nums1,nums2);
    int size = merged.size();
    int mid = size/2;
    if(size%2 ==0 ){
        med = (double)(merged[mid]+ merged[mid-1])/2;
    }else{
        med = merged[mid];
    }

    return med ;
}
int main(){
    std::vector<int> nums1{1,3};
    std::vector<int> nums2{2};
    double med = findMedianSortedArrays(nums1 , nums2);
    std::cout<<"Median of sorted arrays is "<<med<<std::endl;
    std::cout<<"Working.";
    return 0 ;
}
