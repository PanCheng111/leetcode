#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int maxPoints(vector<Point>& points) {
        unordered_map<string, int> slopes;
        int len = points.size();
        int ret = 0;
        for (int i = 0; i < len; i++) {
            slopes.clear();
            int overlaps = 1;
            for (int j = i + 1; j < len; j++) {
                int deltax = points[j].x - points[i].x;
                int deltay = points[j].y - points[i].y;
                if (deltax == 0 && deltay == 0) { overlaps ++; continue; } 
                int g = gcd(deltax, deltay);
                char tmp[20];
                sprintf(tmp, "%d,%d", (deltax / g), (deltay / g));
                string slope = tmp;
                slopes[slope] ++;
            }
            int max = overlaps;
            unordered_map<string, int>::iterator iter;
            for (iter = slopes.begin(); iter != slopes.end(); iter ++) {
                if (iter->second + overlaps > max) max = iter->second + overlaps;
            }
            if (max > ret) ret = max;
        }
        return ret;
    }
};

int main() {
//    [[0,0],[94911151,94911150],[94911152,94911151]]

    Point a(0, 0);
    Point b(94911151, 94911150);
    Point c(94911152, 94911151);
    vector<Point> lists;
    lists.push_back(a);
    lists.push_back(b);
    lists.push_back(c);

    Solution s;
    printf("%d\n", s.maxPoints(lists));
    
    return 0;

}