class Solution {
public:
vector<pair<int,int>>directions={
    {1,0},{-1,0},{0,1},{0,-1}
};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS=heights.size();
        int COLS=heights[0].size();
        set<pair<int,int>>pacific;
        set<pair<int,int>>atlantic;
        for(int c = 0; c < COLS; c++)
            dfs(0,c,pacific, heights[0][c], heights);

        // Pacific: left column
        for(int r = 0; r < ROWS; r++)
            dfs(r,0,pacific, heights[r][0], heights);

        // Atlantic: bottom row
        for(int c = 0; c < COLS; c++)
            dfs(ROWS-1,c,atlantic, heights[ROWS-1][c], heights);

        // Atlantic: right column
        for(int r = 0; r < ROWS; r++)
            dfs(r,COLS-1,atlantic, heights[r][COLS-1], heights);

        vector<vector<int>> result;
        for(int r = 0; r < ROWS; r++)
        { 
            for(int c = 0; c < COLS; c++)
            {
                if(pacific.count({r,c}) && 
                   atlantic.count({r,c}))
                {
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
    void dfs(int r,int c,set<pair<int,int>>& ocean, int prevHeight, vector<vector<int>>& heights){
        int ROWS=heights.size();
        int COLS=heights[0].size();
        if(r<0||r>=ROWS||c<0||c>=COLS || ocean.count({r,c}) || heights[r][c] < prevHeight) return;
        
        ocean.insert({r,c});
        for(auto [dr,dc]:directions){
            dfs(r+dr,c+dc,ocean, heights[r][c], heights);
        }
    }
};