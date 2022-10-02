#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include <queue>
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

		void BFS()   // for BFS
		{
			queue<int> q;
			unordered_map<int, bool> visited;

			for(auto it : adjList)
			{
				if(!visited[it.first])
				{
					q.push(it.first);
					visited[it.first] = true;

					while(!q.empty())
					{
						int front = q.front();
						q.pop();

						cout << front << " ";

						for(int var : adjList[front])
						{
							if(!visited[var])
							{
								q.push(var);
								visited[var] = true;
							}
						}
					}
				}
			}

			cout << endl;
		}
		// for DFS
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

		g.addEdge(1, 2);
		g.addEdge(1, 3);
		g.addEdge(2, 4);
		g.addEdge(2, 5);
		g.addEdge(1, 2);
		g.addEdge(3, 5);
		g.addEdge(1, 2);
		g.addEdge(4, 5);
		g.addEdge(4, 6);
		g.addEdge(5, 6);

		cout << "\nEntered Graph: \n\n";

		g.display();

		cout << "\nTraversal by BFS: \n\n";

		g.BFS();

		cout << "\nTraversal by DFS: \n\n";

		g.DFS();


		return 0;
	}
