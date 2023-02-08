#include <iostream>
#include <string>
#include <vector>
#include <cstring> 

using namespace std;

void show(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

pair<int, int> add (const pair<int, int> & p1, const pair<int, int> & p2) {
    pair<int, int> sum;
    sum.first = p1.first + p2.first;
    sum.second = p1.second + p2.second;
    return sum;
}

void assign(vector<vector<int>>& grid, pair<int, int>& pos, int value) {
    grid[pos.first][pos.second] = value;
}

int get_color(vector<vector<int>>& grid, pair<int, int>& pos) {
    return grid[pos.first][pos.second];
}

bool in_bound(int m, int n, pair<int, int>& pos) {
    return pos.first >= 0 && pos.first <= m-1 && pos.second >= 0 && pos.second <= n-1;
}

bool is_border(vector<vector<int>>& grid, int m, int n, 
                pair<int, int>& pos, vector<pair<int, int>> directions, int origin_color) {
    int new_pos_color;
    pair<int, int> new_pos;

    for(auto & direction : directions) {
        new_pos = add(pos, direction);
        if(!in_bound(m, n, new_pos)) {return true;}
        else {
            new_pos_color = get_color(grid, new_pos);
            if(new_pos_color != origin_color && new_pos_color != -1 && new_pos_color != 0) { return true;}
        }
    }
    return false;
}

void dfs(vector<vector<int>>& grid, int m, int n, 
            pair<int, int> pos, vector<pair<int, int>> directions, 
            int origin_color) {

    if(!in_bound(m, n, pos)) {return;}

    int current_color = get_color(grid, pos);
    if(current_color != origin_color) {return;} 

    if(is_border(grid, m, n, pos, directions, origin_color)) {
        assign(grid, pos, 0); // if this block is border with label it to 0 and search for other directions
    } else {
        assign(grid, pos, -1); // label this place has been visited with -1
    }

    for(auto & direction : directions) {
        dfs(grid, m, n, add(pos, direction), directions, origin_color);
    }
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int m = grid.size(), n = grid[0].size(), origin_color = grid[row][col];
    pair<int, int> pos = pair<int, int>(row, col);
    vector<pair<int, int>> directions = {pair<int, int>(-1, 0),
                                        pair<int, int>(0, 1),
                                        pair<int, int>(1, 0),
                                        pair<int, int>(0, -1)};

    dfs(grid, m, n, 
        pos, directions, 
        origin_color);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            switch(grid[i][j]) {
                case 0:
                    grid[i][j] = color;
                    break;
                case -1:
                    grid[i][j] = origin_color;
                    break;
            }
        }
    }
    
    return grid;
}

int border[50][50], visited[50][50];
void dfs2(vector<vector<int>>& grid,int m, int n, int r, int c) {
    if(visited[r][c])
        return;
    visited[r][c] = 1;
    if(r==0 || c==0 || r==m-1 || c==n-1)
        border[r][c] = 1;
    if(r>0) {
        if(grid[r-1][c]==grid[r][c])
            dfs2(grid,m,n,r-1,c);
        else
            border[r][c] = 1;
    }
    if(c>0) {
        if(grid[r][c-1]==grid[r][c])
            dfs2(grid,m,n,r,c-1);
        else
            border[r][c] = 1;
    }
    if(r<m-1) {
        if(grid[r+1][c]==grid[r][c])
            dfs2(grid,m,n,r+1,c);
        else
            border[r][c] = 1;
    }
    if(c<n-1) {
        if(grid[r][c+1]==grid[r][c])
            dfs2(grid,m,n,r,c+1);
        else
            border[r][c] = 1;
    }
}

vector<vector<int>> colorBorder2(vector<vector<int>>& grid, int row, int col, int color) {
    int m = grid.size(), n = grid[0].size(), compNum = 0;
    memset(border,0,sizeof(border));
    memset(visited,0,sizeof(visited));
    
    dfs2(grid,m,n,row,col);
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(border[i][j]==1)
                grid[i][j] = color;
        }
    }
    
    return grid;
}


int main() {
    // vector<vector<int>> grid {{1,1,1}, {1,1,1}, {1,1,1}};
    vector<vector<int>> grid {{1,1,1,1}, {1,1,1,1}, {2,1,3,4}, {2,1,4,3}, {1,1,1,1}};
    show(grid);
    grid = colorBorder2(grid, 0, 0, 5);
    cout << endl;
    show(grid);
}


