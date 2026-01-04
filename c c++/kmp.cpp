#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> prefix_function(string s) {

    int n = s.length();
    vector<int> pi(n);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        
        if (s[i] == s[j])
            j++;
        
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(string text, string pattern) {

    string s = pattern + "#" + text;     // join with a separator
    vector<int> pi = prefix_function(s);

    vector<int> result;
    int pLen = pattern.length();

    for (int i = 0; i < s.length(); i++)
        if (pi[i] == pLen)
            result.push_back(i - 2*pLen); // starting index in text

    return result;
}

int main() {

    string text = "ababcababcac";
    string pattern = "ababc";

    vector<int> matches = kmp(text, pattern);

    for (int idx : matches)
        cout << "Pattern found at index " << idx << endl;
    
}
