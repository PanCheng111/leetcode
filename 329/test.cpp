#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    int N, M;
    int **opt;
    int dx[4];
    int dy[4];

public:
    Solution() {
        dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
        dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;
    }

    int work(int x, int y, const vector<vector<int>>& matrix) {
        //if (x < 0 || y < 0 || x >= N || y >= M) return 0;
        if (opt[x][y] != -1) return opt[x][y];
        int ret = 1;
        for (int i = 0; i < 4; i++) 
            if (x + dx[i] >=0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M) {
                int tmp = 0;
                if (matrix[x + dx[i]][y + dy[i]] > matrix[x][y]) {
                    tmp = work(x + dx[i], y + dy[i], matrix) + 1;
                    if (tmp > ret) ret = tmp;
                }
            }
        opt[x][y] = ret;
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        N = matrix.size();
        if (N == 0) return 0;
        M = matrix[0].size();
        opt = new int*[N + 1];
        for (int i = 0; i <= N; i++) {
            opt[i] = new int[M + 1];
            for (int j = 0; j <= M; j++)
                opt[i][j] = -1;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (opt[i][j] == -1) work(i, j, matrix);
        int ans = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (opt[i][j] > ans) ans = opt[i][j];
        return ans;        
    }
};

int main() {
    Solution s;
    int row1[] = {1, 2};
    //int row2[] = {6, 6, 8};
    //int row3[] = {2, 1, 1};
    vector<int> r1(row1, row1+2);
   /// vector<int> r2(row2, row2+3);
   // vector<int> r3(row3, row3+3);
    vector<vector<int> > matrix;
    matrix.push_back(r1);
  //  matrix.push_back(r2);
   // matrix.push_back(r3);
    printf("%d\n", s.longestIncreasingPath(matrix));
    return 0;
}