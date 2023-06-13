class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> rows, cols;
        int n = grid.size();
        
        for (int i=0 ; i<n ; i++){
            vector<int> temp;
            for (int j=0 ; j<n ; j++){
                temp.push_back(grid[i][j]);
            }
            rows.push_back(temp);
        }
        
        for (int i=0 ; i<n ; i++){
            vector<int> temp;
            for (int j=0 ; j<n ; j++){
                temp.push_back(grid[j][i]);
            }
            cols.push_back(temp);
        }
        
        int ctr = 0;
        map<vector<int>, int> rows_mp;
        map<vector<int>, int> cols_mp;
        for (auto x : rows){
            rows_mp[x]++;
        }
        for (auto y : cols){
            cols_mp[y]++;
        }
        
        for (auto it : rows_mp){
            if (cols_mp.find(it.first) != cols_mp.end()){
                ctr += rows_mp[it.first] * cols_mp[it.first];
            }
        }
        
        return ctr;
      
    }
};
