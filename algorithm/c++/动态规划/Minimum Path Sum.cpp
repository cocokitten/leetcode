
/********************************************************************************************

Given a m x n grid filled with non-negative numbers, find a path from top left 
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

********************************************************************************************/
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size() - 1;    //行m
		int n = grid[0].size() - 1;  //列n

		int minArray[100][100];
		minArray[m][n] = grid[m][n];

		for(int i=m;i>=0;i--)
			for (int j = n; j >=n; j--) {
				minArray[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
			}
		return minArray[0][0];
	}
};