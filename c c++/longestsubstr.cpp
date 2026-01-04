#include<iostream>
using namespace std;
bool hasDuplicate(string);

class Solution {

    int maxl = 0;

    public:

        int lengthOfLongestSubstring(string s) {

            for(int i = 0; i<s.size(); i++){

                for(int j = 1; j<=s.size()-i; j++){

                    if(hasDuplicate(s.substr(i,j))){

                        break;
                    }

                    maxl = max(j,maxl);

                }
            }

            return maxl;

        }
};

bool hasDuplicate(string s) {
    int freq[256] = {0};

    for (char c : s) {
        if (freq[c] > 0)
            return true;
        freq[c]++;
    }
    return false;
}

int main(){

    string str = "dgrb";

    Solution obj;

    int len = obj.lengthOfLongestSubstring(str);

    cout<<len;
}