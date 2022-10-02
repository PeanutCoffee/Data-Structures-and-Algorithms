class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l= new list<int>[V];
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    
    void dfsHelper(int node,bool*visited,list<int>&arr){
        visited[node]= true;
        
        for(auto n: l[node]){
            if(!visited[n]){
                dfsHelper(n,visited,arr);
            }
        }
        arr.push_front(node);
    }
    
    list<int> dfs(){
        bool *visited= new bool[V]{0};
        list<int>arr;
        dfsHelper(0,visited,arr);
        return arr;
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        Graph g(n);
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                g.addEdge(i,rooms[i][j]);
            }
        }
        list<int>a = g.dfs();
        vector<int>res;
        for(auto it= a.begin();it!=a.end();it++){
            res.push_back(*it);
        }
        if(res.size()==n){
            return true;
        }
        return false;
    }
};
