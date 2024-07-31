/*  Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 
  1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat 
  can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked 
  and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
  Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.
*/

#include<iostream>
#include<vector>
using namespace std;

 vector<string> ans;
    void solve(int i,int j,int n,int m,string s,vector<vector<int>> &vis,vector<vector<int>> &mat){
        if(i<0 || j<0 || i>n-1||j>m-1|| vis[i][j]|| mat[i][j]==0) return;
        if(i==n-1 && j==m-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        solve(i+1,j,n,m,s+'D',vis,mat);
        solve(i,j+1,n,m,s+'R',vis,mat);
        solve(i-1,j,n,m,s+'U',vis,mat);
        solve(i,j-1,n,m,s+'L',vis,mat);
        vis[i][j]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n =mat.size(),m=mat[0].size();
        if(mat[0][0]==0) return {"-1"};
        vector<vector<int>> vis(n,vector<int>(m,0));
        solve(0,0,n,m,"",vis,mat);
        return ans;
};

int main(){
  vector<vector<int>>matrix = {
       {1, 0, 0, 0},
       {1, 1, 0, 1}, 
       {1, 1, 0, 0},
       {0, 1, 1, 1}
       };

       cout<<"Shortest path from source to destination: "<<endl;
       vector<string> paths = findPath(matrix);
    
      if (paths[0] == "-1") {
        cout << "No valid paths found." << endl;
      } else {
          for (string path : paths) {
            cout << path << endl;
        }
    }
    
    return 0;
}

