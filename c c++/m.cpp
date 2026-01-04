#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        int ls = 0;
        int in = 0;

        if(strs.size()==1){

            return strs[0];
        }

        for(int i = 1; i<strs.size(); i++){

            if(strs[ls].size()>strs[i].size()){

                ls = i;
            }

        }

        for(int i = 0; i<strs[ls].size(); i++){

            for(int j = 0; j<strs.size()-1; j++){

                if(strs[j][i]==strs[j+1][i]){

                }
                else{

                    in = i;
                    return strs[0].substr(0, in);
                }
            }

            in = i+1;
        }

        return strs[0].substr(0, in);
    }
};

int main(){

    Solution obj;

    vector<string> v1 = {"Ankur","Ankush","Ansh"};

    string str = obj.longestCommonPrefix(v1);

    cout<<str;

}