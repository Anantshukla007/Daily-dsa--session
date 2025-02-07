/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. */


#include <vector>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int s = 0, e = m - 1, idx = -1;

    // Step 1: Find the correct row using binary search
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (matrix[mid][0] == target) return true;
        if (matrix[mid][0] < target) {
            idx = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    // If no valid row is found, return false
    if (idx == -1) return false;

    // Step 2: Find the target within the selected row using binary search
    return binary_search(matrix[idx].begin(), matrix[idx].end(), target);
}
