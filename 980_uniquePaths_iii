class Solution {
public:
  // num_0 initialized to 1 as we already start from '1' and do a num_0-- in dfs which is 1 extra than required. Try out with [[0,1],[0,2]] example
  int result=0, num_0=1;
  int uniquePathsIII(vector<vector<int>>& grid) {
    int index_1i, index_1j;
    // we need to get indices of grid[i][j]='1' which is our starting point
    // Also we update number of '0's present in grid
    for(int i=0; i<grid.size();i++){
      for(int j=0; j<grid[0].size();j++){
        if(grid[i][j] == 1){
          index_1i = i;
          index_1j = j;
        }
        if(grid[i][j] == 0) num_0++;
      }
    }
    // dfs from '1'
    dfs(grid, index_1i, index_1j);
    return result;
  }
  
  void dfs(vector<vector<int>>& grid, int i, int j){
    // handling extreme cases and when grid[i][j] < 0
    // we assign every encountered grid[i][j] to -2 as it is already visited
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<0) return;
    if(grid[i][j] == 2){
      // we only need to record unique path else we just do a pre-mature return
      if(!num_0) result++;
      return;
    }
    // assign visited nodes to -2
    grid[i][j] = -2;
    // decrement num_0 by one as we have visited '0' here to proceed ahead
    num_0--;
    
    // grid search in 4 directions
    dfs(grid, i+1, j);
    dfs(grid, i, j+1);
    dfs(grid, i-1, j);
    dfs(grid, i, j-1);
    
    // update grid[i][j] from -2 to 0 and increment num_0 as dfs is completed
    grid[i][j] = 0;
    num_0++;
    return;
  }
};
