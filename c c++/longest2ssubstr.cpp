#include<iostream>
#include<vector>
using namespace std;

bool hasDuplicate(string);
string reverseString(string);

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> v1;

        for(int k = 0; k<s.size(); k++){

            for(int i = 0; i<s.size(); i++){

                for(int j = 0; j<s.size()-1; j++){

                    if(s.substr(k,i)==s.substr(j,i)&&j!=k){

                        string t = s.substr(k,i);

                        if (hasDuplicate(t)){

                            break;
                        }
                        v1.emplace_back(i);

                        break;
                    }

                    if(s.substr(k,i)==reverseString(s.substr(j,i))&&j!=k){

                        string t = s.substr(k,i);

                        if (hasDuplicate(t)){

                            break;
                        }
                        v1.emplace_back(i);
                    }
                }
            }
        }

        int max = v1.front();

        for(auto x : v1){

            if(max<x){

                max = x;
            }
        }

        return max;
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

string reverseString(string s) {
    int i = 0, j = s.length() - 1;

    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}


int main(){

    string str1 = "ankurpfgrprukna";

    Solution obj;

    int a = obj.lengthOfLongestSubstring(str1);

    cout<<a;

}