class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        int ans = numeric_limits<int>::max();
        //cout << ans << endl;
        int last_row = triangle.size()-1;
        int last_row_size = triangle[last_row].size();
        vector<vector<int>>dp(last_row_size,(vector<int>(last_row_size,0)));
        
        dp[0][0] = triangle[0][0]; //頂點
        
        for(int i=1;i<triangle.size();i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            
            for(int j=1;j<triangle[i].size()-1;j++){
                dp[i][j] = min ( (dp[i-1][j-1] + triangle[i][j]) , (dp[i-1][j] + triangle[i][j]));
                if(i == triangle.size()-1){
                    //cout << ans << " " << dp[i][j] << endl;
                    ans = min(ans,dp[i][j]);
                }
            }
            if(i==triangle.size()-1){
                ans = min(ans,dp[last_row][last_row]);
                ans = min(ans,dp[last_row][0]);
            }
        }
        
        // for(auto i:dp){
        //     for(auto j:i)
        //         cout << j << " ";
        //     cout << endl;
        // }
       
        
        return ans;
    }
};
