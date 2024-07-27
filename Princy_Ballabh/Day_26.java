public class Day_26{
    int parent[],rank[];

    public Day_26(int size){
        parent=new int[size];
        rank=new int[size];
        for(int i=0;i<size;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    public static void main(String args[]){
        int N=5;
        int connections[][]={{0,2},{4,2},{3,1}};
        int query[]={4,0};
        Day_26 obj=new Day_26(N);

        for(int[] connection: connections){
            obj.union(connection[0],connection[1]);
        }
        boolean result=obj.find(query[0])==obj.find(query[1]);
        System.out.println(result);
    }

    public int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);        
        return parent[x];
    }

    public void union(int x, int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]) 
                parent[rootY]=rootX;
             else if(rank[rootX]<rank[rootY]) 
                parent[rootX]=rootY;
             else{
                parent[rootY]=rootX;
                rank[rootX]++;
            }
        }
    }
}
