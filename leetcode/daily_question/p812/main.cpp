#include <cmath>
#include <vector>

using std::vector;

class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {

    int n;
    int x1, x2, x3;
    int y1, y2, y3;
    double max_area = 0;
    double area;

    n = points.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          x1 = points[i][0];
          x2 = points[j][0];
          x3 = points[k][0];
          y1 = points[i][1];
          y2 = points[j][1];
          y3 = points[k][1];
          area =
              0.5 * std::fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
          if (area > max_area) {
            max_area = area;
          }
        }
      }
    }
    return max_area;
  }
};
