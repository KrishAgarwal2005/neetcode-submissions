class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        int time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
while(fresh>0 && !q.empty()){
    int size = q.size();
    for(int i=0;i<size;i++){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
for(int k=0;k<4;k++){
    int row=r+dirs[k].first;
    int col=c+dirs[k].second;
    if(row>=0 && row<m && col<n && col>=0 && grid[row][col]==1 ) {
        grid[row][col]=2;
        q.push({row,col});
        fresh--;
        }
}
    }
    time++;
}
return fresh==0?time:-1;
    }
};