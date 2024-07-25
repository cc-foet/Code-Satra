public class Day_23{
    public static void main(String args[]){
        int n=4;
        int[][] board=solvenqueens(n);
        printoutput(board);
    }

    public static int[][] solvenqueens(int n){
        int[][] board=new int[n][n];
        solve(board,0);
        return board;
    }

    private static boolean solve(int board[][],int row){
        int n=board.length;
        if(row>=n)
            return true;
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col)){
                board[row][col]=1;
                if(solve(board,row+1)) 
                    return true;
                board[row][col]=0;
            }
        }
        return false;
    }

    private static boolean isSafe(int[][] board,int row,int col){
        int n=board.length;
        for(int i=0;i<row;i++){
            if(board[i][col]==1)
                return false;
        }
        for(int i=row,j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j]==1)
                return false;
        }
        for(int i=row,j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
    }

    private static void printoutput(int[][] board){
        int n=board.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
