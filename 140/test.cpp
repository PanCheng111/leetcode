#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    int *opt;
    vector<string> ret;
    
public:
    void search_ans(int i, string ans, const string &s, vector<string>& wordDict) {
        if (i == 0) {
            ret.push_back(ans);
            return;
        }
        string ori_ans = ans;
        for (int j = i - 1; j >= 0; j --) 
            if (opt[j] == true && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                if (ori_ans != "") ans = s.substr(j, i - j) + " " + ori_ans;
                    else ans = s.substr(j, i - j);
                search_ans(j, ans, s, wordDict);
            }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int len = s.length();
        opt = new int[len + 1];
        memset(opt, 0, sizeof(int) * (len + 1));
        opt[0] = 1;
        for (int i = 1; i <= len; i++) 
            for (int j = 0; j < i; j++)
                if (opt[j] == true && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    opt[i] = true;
                    break;
                }
        search_ans(len, "", s, wordDict);
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> dict;
    dict.push_back("cat");
    dict.push_back("cats");
    dict.push_back("and");
    dict.push_back("sand");
    dict.push_back("dog");
    
    vector<string> ret = s.wordBreak("catsanddog", dict);
    for (int i = 0; i < ret.size(); i++)
        printf("%s\n", ret[i].c_str());
    return 0;
}