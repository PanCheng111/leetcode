#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int **opt = new int*[len1 + 1];
        for (int i = 0; i <= len1; i++) {
            opt[i] = new int[len2 + 1];
            for (int j = 0; j <= len2; j++)
                opt[i][j] = 10000000;
        }
        //printf("here\n");
        opt[0][0] = 0;
        for (int i = 0; i <= len1; i++)
            opt[i][0] = i;
        for (int j = 0; j <= len2; j++)
            opt[0][j] = j;
        //printf("here1\n");
        for (int i = 1; i <= len1; i++) 
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) opt[i][j] = opt[i - 1][j - 1];
                if (opt[i][j] > opt[i - 1][j] + 1) opt[i][j] = opt[i - 1][j] + 1;
                if (opt[i][j] > opt[i][j - 1] + 1) opt[i][j] = opt[i][j - 1] + 1;
                if (opt[i][j] > opt[i - 1][j - 1] + 1) opt[i][j] = opt[i - 1][j - 1] + 1;
            }
        return opt[len1][len2];
    }
};

int main() {
    Solution s;
    printf("%d\n", s.minDistance("intention", "execution"));
    return 0;
}