#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    if(!visited[u])
    {
        visited[u] = true;

        for(int i = 0 ; i<adj[u].size();i++) // expolring each neighbour
        {
            int negh_node = adj[u][i];
            if(!recStack[negh_node])
            {
                recStack[negh_node] = true;
                if(isCyclicUtil(adj,negh_node,visited,recStack))
                {
                    cout<<" "<<negh_node;
                    return true;
               }

            }
            else
            {
                // This case is not possible when not visited and found in stack.
            }
        }
    }
    else
    {
        return true;
    }

    return false;
}

// Function to construct an adjacency list from edge list
vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]); // Directed edge from it[0] to it[1]
    }
    return adj;
}

// Function to detect cycle in a directed graph
void isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> G = constructadj(V,edges);
    vector<bool> visited(V, false);;
    vector<bool> recStack(V, false);;

    for(int u = 0;u<V;u++)
    {


        if(isCyclicUtil(G,u,visited,recStack))
        {
            cout<<"Cycle No. "<<u+1<<endl;
            //return true;
        }
    }

    //return false;
}

int main()
{
    int V = 4; // Number of vertices

    // Directed edges of the graph
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    // Output whether the graph contains a cycle
    isCyclic(V, edges);

    return 0;
}
