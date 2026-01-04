#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>&nums, int target) {
        
        for(int i = 0; i<nums.size(); i++){

            for(int j = 0; j<nums.size(); j++){

                if(nums[i]+nums[j]==target){

                    return {i,j}; 
                }
            }
        }

        return {-1,-1};
    }
};

int main(){

    vector<int> v1 = {23,242,434,2};

    Solution obj;

    vector<int> v2 = obj.twoSum(v1,25);

    for(auto x : v2){

        cout<<x<<" ";
    }
}