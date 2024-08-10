class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        set<int> nums;
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check rows
        for (int i = 0; i < 3; ++i) {
            int rowSum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (rowSum != sum) return false;
            nums.insert(grid[row + i][col]);
            nums.insert(grid[row + i][col + 1]);
            nums.insert(grid[row + i][col + 2]);
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            int colSum = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];
            if (colSum != sum) return false;
        }

        // Check diagonals
        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (diag1 != sum || diag2 != sum) return false;

        // Check if all numbers are distinct and within [1,9]
        return nums == set<int>({1, 2, 3, 4, 5, 6, 7, 8, 9});
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Slide a 3x3 window over the grid
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    ++count;
                }
            }
        }

        return count;
    }
};
