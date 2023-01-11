void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int column)
{
  int dirx[] = {0, 0, -1, 1};
  int diry[] = {1, -1, 0, 0};
  visited[i][j] = true;
  bool found = false;
  for (int k = 0; k < 4; k++)
  {
    int x = i + dirx[k];
    int y = j + diry[k];
    if(x>=0 && x<row && y>=0 && y<column && !visited[x][y] && !grid[x][y])
    {
      dfs(x, y, grid, visited, row, column);
    }
  }
}

void dealWithEdgesOfGrid(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int column)
{
  for (int i = 0; i < row; i++)
  {
    if (!visited[i][0] && !grid[i][0])
    {
      dfs(i, 0, grid, visited, row, column);
    }
    if (!visited[i][column - 1] && !grid[i][column - 1])
    {
      dfs(i, column - 1, grid, visited, row, column);
    }
  }
  for (int j = 0; j < column; j++)
  {
    if (!visited[0][j] && grid[0][j] == 0)
    {
      dfs(0, j, grid, visited, row, column);
    }
    if (!visited[row - 1][j] && grid[row - 1][j] == 0)
    {
      dfs(row - 1, j, grid, visited, row, column);
    }
  }
}

int findNumberOfConnectedComponents(vector<vector<int>> &grid, int row, int column)
{
  int count = 0;
  vector<vector<bool>> visited(row, vector<bool>(column, false));
  dealWithEdgesOfGrid(grid, visited, row, column);
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      if (!grid[i][j] && !visited[i][j])
      {
        dfs(i, j, grid, visited, row, column);
        count++;
      }
    }
  }
  return count;
}

int closedIsland(vector<vector<int>> &grid)
{
  int row = grid.size();
  int col = grid.front().size();
  return findNumberOfConnectedComponents(grid, row, col);
}