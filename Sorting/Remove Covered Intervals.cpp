#include <algorithm>
#include <vector>

class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
                return (lhs[0] != rhs[0]) ? (lhs[0] < rhs[0])
                                          : (lhs[1] > rhs[1]);
              });
    int count = 0, mx = 0;

    for (const auto &interval : intervals) {
      if (interval[1] > mx) {
        count++;
        mx = interval[1];
      }
    }
    return count;
  }
};
