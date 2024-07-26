public class Day_24{
    private static final int size=9;

    public static void main(String[] args) {
        int board[][]={
            {3,0,6,5,0,8,4,0,0},
            {5,2,0,0,0,0,0,0,0},
            {0,8,7,0,0,0,0,3,1},
            {0,0,3,0,1,0,0,8,0},
            {9,0,0,8,6,3,0,0,5},
            {0,5,0,9,0,0,6,0,0},
            {1,3,0,0,0,0,2,5,0},
            {0,0,0,0,0,0,0,7,4},
            {0,0,5,2,0,6,3,0,0}
        };
        if(solvesudoku(board))
            printboard(board);
        else 
            System.out.println("No solution");
    }

    private static boolean solvesudoku(int board[][]){
        for(int row=0;row<size;row++){
            for(int col=0;col<size;col++){
                if(board[row][col]==0){
                    for(int num=1;num<=size;num++){
                        if(isSafe(board,row,col,num)){
                            board[row][col]=num;
                            if(solvesudoku(board))
                                return true;
                            board[row][col]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isSafe(int[][] board,int row,int col,int num) {
        for(int x=0;x<size;x++){
            if(board[row][x]==num)
                return false;
        }
        for(int x=0;x<size;x++) {
            if(board[x][col]==num) 
                return false;
        }
        int startRow=row-row%3,startCol=col-col%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+startRow][j+startCol]==num) 
                    return false;
            }
        }
        return true;
    }

    private static void printboard(int board[][]) {
        for(int r=0;r<size;r++){
            for(int d=0;d<size;d++){
                System.out.print(board[r][d]);
                System.out.print(" ");
            }
            System.out.print("\n");
            if((r+1)%3==0)
                System.out.print("");
        }
    }
}
