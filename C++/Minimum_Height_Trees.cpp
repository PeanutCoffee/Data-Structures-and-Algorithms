class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    //if there's only 1 node ->return {0}
            return {0};
        
        vector <vector<int>> adj(n);        //to store neighbors of each node
        vector <int> in(n, 0);              //to store degrees of each node
        for(auto edge : edges){             //updating values in adj and in as we iterate through each edges
            int u = edge[0], v = edge[1];  
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        
        queue <int> q;                      //to store the nodes which needs to be excluded in order to reach the middle nodes
        for(int i=0; i<n; i++)
            if(in[i]==1)
                q.push(i);
        
        vector <int> res;                   //to store the final result
        while(!q.empty())
        {
            res.clear();            //clearing before we start traversing level by level.
            int size=q.size();
            while(size--)           //doing for each inserted nodes
            {
                int cur=q.front();
                q.pop();
                res.push_back(cur); //adding nodes to vector (it may or may not be the final solution)
                for(auto &neigh :adj[cur])
                {
                    in[neigh]--;            //removing current leave nodes
                    if(in[neigh]==1)        //adding current leave nodes
                        q.push(neigh);
                }
            }
        }
        return res;
    }
};

// Best
// Tc: O(N)
// Sc: O(N)
