class Solution {
public:
    
    void solve(vector<vector<int>>& image , int sr , int sc , int color , vector<vector<bool>>& ans , int changethis){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != changethis || ans[sr][sc] == true){
            return;
        }
        
        image[sr][sc] = color; 
        ans[sr][sc] = true;
        solve(image , sr , sc + 1 , color , ans , changethis);
        solve(image , sr + 1 , sc , color , ans , changethis);
        solve(image , sr - 1 , sc , color , ans , changethis);
        solve(image , sr , sc - 1 , color , ans , changethis);
        ans[sr][sc] = false;
        return;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> ans(n , vector<bool>(m , false));;
        int changethis = image[sr][sc];
        solve(image , sr , sc , newColor , ans , changethis);
        return image;
    }
};