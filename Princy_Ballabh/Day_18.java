public class Day_18{
    final static int INF = 99999, V = 5;
    public static void main(String[] args) {
        int graph[][]={{ 0, 4, INF, 5, INF},
                        { INF, 0, 1, INF, 6},
                        { 2, INF, 0, 3, INF},
                        { INF, INF, 1, 0, 2},
                        { 1, INF, INF, 4, 0}};
        Day_18 a=new Day_18();
        a.floydwarshall(graph);
    }

    void floydwarshall(int graph[][]){
        int dist[][]=new int[V][V];
        int i,j,k;
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
                dist[i][j]=graph[i][j];
        for(k=0;k<V;k++){
            for(i=0;i<V;i++){
                for(j=0;j<V;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        printSolution(dist);
    }

    void printSolution(int dist[][]){
        System.out.println("Output: ");
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]==INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j]+"   ");
            }
            System.out.println();
        }
    }   
}
