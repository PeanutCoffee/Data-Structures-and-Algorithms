#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class graph
	{
	public:

		unordered_map<int, list<int>> adjList;

		void addEdge(int key, int neighbor, bool biDir = true)
		{
			adjList[key].push_back(neighbor);

			if(biDir)
			{
				adjList[neighbor].push_back(key);
			}
		}

		void display()
		{
			for(auto it : adjList)
			{
				cout << it.first << ": ";

				for(int var : it.second)
				{
					cout << var << ", ";
				}

				cout << endl;
			}

			cout << endl;
		}

		unordered_map<int, bool> visited;

		void dfsHelper(int key)
		{
			if(visited[key])
			{
				return;
			}

			visited[key] = true;

			cout << key << " ";

			for(int var : adjList[key])
			{
				dfsHelper(var);
			}
		}

		void DFS()
		{
			for(auto it : adjList)
			{
				dfsHelper(it.first);
			}

			cout << endl;
		}
	};

int main()
	{
		graph g;

		g.addEdge(1,2);
        g.addEdge(1,4);
        g.addEdge(3,2);
        g.addEdge(3,4);
        g.addEdge(3,5);
        g.addEdge(5,6);

        cout << "Graph inserted: \n\n";

        g.display();

        cout << "\nDepth First Search Traversal: \n\n";

        g.DFS();

        cout << "\n";

        return 0;
	}