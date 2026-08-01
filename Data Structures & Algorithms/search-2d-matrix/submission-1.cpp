class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), l = 0, h = n * m-1, b;
        while(l <= h) {
            b = l + (h-l)/2;
            int r = b / m, c = b%m;
            if(matrix[r][c] < target) l = b + 1;
            else if(matrix[r][c] > target) h = b-1;
            else return true;
        }
        return false;
    }
};
