#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> res;
        int size = grid.size();

        for (int i = 0; i < size - 2; i++)
        {
            vector<int> v;
            for (int j = 0; j < size - 2; j++)
            {
                v.push_back(findLargest(grid,i,j));
            }
            res.push_back(v);
        }
        
        return res;
    }

    int findLargest(vector<vector<int>> &grid, int posX,int posY)
    {
        int max = grid[posX][posY];
        for (int i = posX; i < posX + 3; i++)
        {
            for (int j = posY; j < posY + 3; j++)
            {
                if (max < grid[i][j])
                {
                    max = grid[i][j];
                }
            }
        }
        return max;
    }
};