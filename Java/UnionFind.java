import java.util.Arrays;
public class UnionFind{
    int num;
    int numComponents;
    int[] rank;
    int[] parent;

    UnionFind(int n){
        num = n; numComponents = n;
        rank = new int[n];
        Arrays.fill(rank, 0);
        parent = new int[n];
        for(int i = 0; i<n; i++)
            parent[i] = i;
    }
    
    int size(){return num;}
    
    int components(){return numComponents;}
    
    int find(int p){
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    public boolean isCycle(int[][] edgeList){
        for(int[] edge : edgeList){
            int v1 = edge[0];
            int v2 = edge[1];
            int root1 = find(v1);
            int root2 = find(v2);
            if(root1 == root2)
                return true;
            union(root1, root2);
        }
        return false;
    }
    
    public void union(int p, int q){
        int rootp = find(p); int rootq = find(q);
        if(rootp == rootq) return;
        if(rank[rootp] < rank[rootq]) parent[rootp] = rootq;
        else{
            parent[rootq] = rootp;
            if(rank[rootp] == rank[rootq]){rank[rootp]++;}
        }
        numComponents--;
    }
    
    public boolean connected(int p, int q){
        return find(p) == find(q);
    }
    
}