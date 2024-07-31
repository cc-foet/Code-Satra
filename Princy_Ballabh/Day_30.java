import java.util.*;

public class Day_30{ //this ques is solved using Kruskal's algorithm
    public static void main(String args[]){
        int[][] graph={{0,1,2},{1,2,3},{0,3,6},{1,3,8},{1,4,5},{2,4,7}};
        int n=5;
        List<int[]> mst=kruskal(graph,n);
        for(int i=0;i<mst.size();i++)
            System.out.print(Arrays.toString(mst.get(i))+", ");
    }

    static class UnionFind{
        private int parent[],rank[];
        public UnionFind(int size){
            parent=new int[size];
            rank=new int[size];
            for(int i=0;i<size;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }

        public int find(int p){
            if(parent[p]!=p)
                parent[p]=find(parent[p]);
            return parent[p];
        }

        public boolean union(int p, int q){
            int rootP=find(p);
            int rootQ=find(q);
            if(rootP==rootQ) 
            return false;
            if(rank[rootP]>rank[rootQ]) 
                parent[rootQ]=rootP;
            else if(rank[rootP]<rank[rootQ]) 
                parent[rootP]=rootQ;
            else {
                parent[rootQ]=rootP;
                rank[rootP]++;
            }
            return true;
        }
    }

    public static List<int[]> kruskal(int[][] edges, int numnodes){
        List<int[]> mst=new ArrayList<>();
        UnionFind uf=new UnionFind(numnodes);
        Arrays.sort(edges, Comparator.comparingInt(edge->edge[2]));
        for(int i=0;i<edges.length;i++){
            if(uf.union(edges[i][0], edges[i][1])){
                mst.add(edges[i]);
                if(mst.size() == numnodes-1) break;
            }
        }
        return mst;
    }    
}
