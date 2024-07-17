import java.util.*;

public class adjacencylist {
    static class Edge{
        int src;
        int dest;
        int wt;
        public Edge(int src, int dest, int wt){
            this.src = src;
            this.dest = dest;
            this.wt = wt;
        }
    }

    public static void main(String args[]){
        int v = 5;
        // an arraylist of array of type edge
        // we have to convert null -> to empty arraylist
        ArrayList<Edge>[] graph = new ArrayList[v];
        for(int i=0; i<v; i++){
            graph[i] = new ArrayList<>(); // at each index of arrray a new array list created 
            // to store  data 
        }
        graph[0].add(new Edge(0,1,5));
        // here at index of 0 a new edge stored which contain
        // (source as 0 , destination as 1 and weight as 5)
        graph[1].add(new Edge(1, 0, 5));
        graph[1].add(new Edge(1, 2, 1));
        graph[1].add(new Edge(1, 3, 3));



        graph[2].add(new Edge(2, 1, 1));
        graph[2].add(new Edge(2, 3, 1));
        graph[2].add(new Edge(2, 4, 4));


        graph[3].add(new Edge(3, 1, 3));
        graph[3].add(new Edge(3, 2, 1));


        graph[4].add(new Edge(4, 2, 2));
        
        // to print the edges of graph using for loops 
        // in each loop for each index of array traverse to each index of arraylist and print all the nodes destination and weight

        for(int i = 0; i<graph[0].size(); i++) {
            Edge e = graph[0].get(i);
            System.out.println("0 -> "+e.dest);
        }
        for(int i = 0; i<graph[1].size(); i++) {
            Edge e = graph[1].get(i);
            System.out.println("1 -> "+e.dest);
        }
        for(int i = 0; i<graph[2].size(); i++) {
            Edge e = graph[2].get(i);
            System.out.println("2 -> "+e.dest);
        }
        for(int i = 0; i<graph[3].size(); i++) {
            Edge e = graph[3].get(i);
            System.out.println("3 -> "+e.dest);
        }
        for(int i = 0; i<graph[4].size(); i++) {
            Edge e = graph[4].get(i);
            System.out.println("4 -> "+e.dest);
        }
    }
}
 