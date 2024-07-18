package Graphsss;
import java.util.*;

class Graph 
{
    private int V;   
    private LinkedList<Integer> adj[]; 

    Graph(int v)
     {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

  
    void addEdge(int v, int w) 
    {
        adj[v].add(w);
        adj[w].add(v);
    }

   
    void BFS(int src, int target) 
    {
      
        boolean visited[] = new boolean[V];

       
        LinkedList<Integer> queue = new LinkedList<Integer>();
        visited[src] = true;
        queue.add(src);
       
        int parent[] = new int[V];
        Arrays.fill(parent, -1);

        while (queue.size() != 0) 
        {
            
            int s = queue.poll();

           
            if (s == target) 
            {
                printPath(parent, target);
                return;
            }

            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext())
             {
                int n = i.next();
                if (!visited[n]) 
                {
                    visited[n] = true;
                    parent[n] = s;
                    queue.add(n);
                }
            }
        }
        System.out.println("No path found betwen source and target");
    }

   
    void printPath(int parent[], int target) 
    {
        if (parent[target] == -1) {
            System.out.print(target + " ");
            return;
        }
        printPath(parent, parent[target]);
        System.out.print(target + " ");
    }

    public static void main(String args[]) 
    {
        Graph g = new Graph(6);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 5);
        g.addEdge(4, 5);

        int source = 0;
        int target = 5;
        System.out.println("Shortest path from " + source + " to " + target + " is:");
        g.BFS(source, target);
    }
}
