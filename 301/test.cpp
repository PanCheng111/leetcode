#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    int **opt;
    vector<string> **ans;

public:

    int calc_min_del(int l, int r, const string &s) {
        if (l > r) {
            opt[l][r] = 0;
            return 0;
        }
        if (l == r) {
            if (s[l] == '(' || s[l] == ')') { opt[l][r] = 1; return 1; }
            opt[l][r] = 0;
            return 0;
        } 

        if (opt[l][r] != -1) return opt[l][r];
        int ret = 10000000;
        if (s[l] == '(' && s[r] == ')') {
            int tmp = calc_min_del(l + 1, r - 1, s);
            if (tmp < ret) ret = tmp;
        }
        for (int i = l + 1; i <= r; i++) {
            int tmp = calc_min_del(l, i - 1, s) + calc_min_del(i, r, s);
            if (tmp < ret) ret = tmp;
        }
        int tmp;
        tmp = calc_min_del(l + 1, r, s) + (s[l] == '(' || s[l] == ')') ;
        if (tmp < ret) ret = tmp;
        tmp = calc_min_del(l, r - 1, s) + (s[r] == '(' || s[r] == ')') ;
        if (tmp < ret) ret = tmp;
        opt[l][r] = ret;
        return ret;
    }

    vector<string> calc_ans(int l, int r, const string &s) {
        vector<string> ret;
        if (l > r || opt[l][r] == r - l + 1) {
            ret.push_back("");
            return ret;
        }
        if (l == r) {
            if (s[l] == '(' || s[l] == ')') {
                ret.push_back("");
                return ret;
            }
            string str = s.substr(l, 1);
            ret.push_back(str);
            return ret;
        }
        if (opt[l][r] == 0) {
            string str = s.substr(l, r - l + 1);
            ret.push_back(str);
            return ret;
        }
        if (ans[l][r].size() != 0) return ans[l][r];

        if (s[l] == '(' && s[r] == ')' && opt[l + 1][r - 1] == opt[l][r]) {
            vector<string> tmp = calc_ans(l + 1, r - 1, s);
            for (int i = 0; i < tmp.size(); i++)
                ret.push_back("(" + tmp[i] + ")");
        }
        for (int i = l + 1; i <= r; i++) {
            if (opt[l][i - 1] + opt[i][r] == opt[l][r]) {
                vector<string> t1 = calc_ans(l, i - 1, s);
                vector<string> t2 = calc_ans(i, r, s);
                for (int j = 0; j < t1.size(); j++)
                    for (int k = 0; k < t2.size(); k++)
                        ret.push_back(t1[j] + t2[k]);
            }
           sort(ret.begin(), ret.end());
           int size = unique(ret.begin(), ret.end()) - ret.begin();
           ret.resize(size);
        }
        // if (opt[l + 1][r] + (s[l] == '(' || s[l] == ')') == opt[l][r]) {
        //     vector<string> tmp = calc_ans(l + 1, r, s);
        //     if (s[l] != '(' && s[l] != ')') 
        //         for (int i = 0; i < tmp.size(); i++)
        //             ret.push_back(s[l] + tmp[i]);
        //     else {
        //         for (int i = 0; i < tmp.size(); i++)
        //             ret.push_back(tmp[i]);
        //     }
        // }
        // if (opt[l][r - 1] + (s[r] == '(' || s[r] == ')') == opt[l][r]) {
        //     vector<string> tmp = calc_ans(l, r - 1, s);
        //     if (s[r] != '(' && s[r] != ')') 
        //         for (int i = 0; i < tmp.size(); i++)
        //             ret.push_back(tmp[i] + s[r]);
        //     else {
        //         for (int i = 0; i < tmp.size(); i++)
        //             ret.push_back(tmp[i]);
        //     }
        // }
        sort(ret.begin(), ret.end());
        int size = unique(ret.begin(), ret.end()) - ret.begin();
        ret.resize(size);
        ans[l][r] = ret;
        return ret;
    }

    vector<string> removeInvalidParentheses(string s) {
        int len = s.length();
        opt = new int*[len + 1];
        for (int i = 0; i <= len; i++) {
            opt[i] = new int[len + 1];
            for (int j = 0; j <= len; j++)
                opt[i][j] = -1;
        }
        int min_del = calc_min_del(0, len - 1, s);
        ans = new vector<string>*[len + 1];
        for (int i = 0; i <= len; i++) {
            ans[i] = new vector<string>[len + 1];
            for (int j = 0; j <= len; j++)
                ans[i][j].resize(0);
        }
        vector<string> ret = calc_ans(0, len - 1, s);
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> ret = s.removeInvalidParentheses("h)))uq))v)))))))()");
    for (int i = 0; i < ret.size(); i++)
        printf("%s\n", ret[i].c_str());
    return 0;
}