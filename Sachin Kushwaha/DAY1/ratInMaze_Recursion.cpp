// RAT IN MAZE PROBLEM SOLVED USING C++ 
// Author - Sachin

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isSafe(vector<vector<int>> &visited,int x,int y,vector<vector<int>> &m, int n){
        // checking all three conditions for insuring that rat can move to next block or not
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0 ){
            return true;
        } 
        else return false;
    }

    private: 
    void solve(vector<vector<int>> &m,int n,vector<vector<int>> &visited,
                            vector<string>& ans,string path,int x,int y){

        // base case 
        if( x==n-1 && y== n-1){
            ans.push_back(path);
            return;
        }
        
        // initialising current position/coordinate(x,y) visited(i.e, 1)
        visited[x][y]=1;
        
        // D down
        // for down movement coordinates should be (x+1,y)
        int newx=x+1;
        int newy=y;
        if(isSafe(visited,newx,newy,m,n)){
            path.push_back('D');
            solve(m,n,visited,ans,path,newx,newy);
            path.pop_back();
        }
        
        // L left
        // for left movement coordinates should be (x,y-1)
        newx=x;
        newy=y-1;
        if(isSafe(visited,newx,newy,m,n)){
            path.push_back('L');
            solve(m,n,visited,ans,path,newx,newy);
            path.pop_back();
        }
        
        // R right
        // for right movement coordinates should be (x,y+1)
        newx=x;
        newy=y+1;
        if(isSafe(visited,newx,newy,m,n)){
            path.push_back('R');
            solve(m,n,visited,ans,path,newx,newy);
            path.pop_back();
        }

        // U up
        // for up movement coordinates should be (x-1,y)
        newx=x-1;
        newy=y;
        if(isSafe(visited,newx,newy,m,n)){
            path.push_back('U');
            solve(m,n,visited,ans,path,newx,newy);
            path.pop_back();
        }
        
        // backtracking 
        // initialising to zero again helps to make visited matrix same as initial 
        // i.e, removing all traces of visit so that new visit pattern generate
        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        int x=0;
        int y=0;

        // checking if start position exist or not 
        if(m[0][0] == 0 ){
            return ans;
        }
        
        // initialising each value of matrix(visited) to zero
        vector<vector<int>> visited(n, vector<int> (n,0));
        
        string path="";
        
        solve(m,n,visited,ans,path,x,y);
        sort(ans.begin(),ans.end());
        return ans;
    }
};



// creating main()

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (unsigned int i = 0; i < result.size(); i++){ cout << result[i] << " ";}
        cout << endl;
    }
    return 0;
}