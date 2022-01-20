// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>
using namespace std;




	// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// CPoint CLASS IS DEFINED BY DEFAULT
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
string longestPalindromicSubstring(string inputStream)
{
    if(inputStream.size() <= 0 ){
        return "";
    }
    if(inputStream.size() ==1 ){
        return inputStream;
    }
    int maxl = 0 ;
    int sind = 0;
    int i =0 ;
    while(i < inputStream.size()){
        int lpos = i;
        int rpos = i;
        while(rpos < inputStream.size()-1 && inputStream[rpos +1 ] == inputStream[rpos]){
            rpos++;
        }
        i = rpos +1;
        while(rpos < inputStream.size() -1 && lpos > 0 && inputStream[rpos+1] == inputStream[lpos-1]){
            rpos++;
            lpos--;
        }
        int new_len = rpos- lpos +1 ;
        if(new_len > maxl){
            sind = lpos;
            maxl = new_len;
        }

    }
    return inputStream.substr(sind,maxl);
}
// FUNCTION SIGNATURE ENDS




















































/*
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for(int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
*/

/*#include <iostream>
#include<vector>
using namespace std;

int main()
{
    //std::vector< std::vector<int>> num(3);
    // for(int i =0 ; i < 3 ; ++i){
    //     num[i].push_back(4);
    // }
    // for(auto x : num ){
    //     for(auto y : x ){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    // int r = 344;
    // r = -r;
    // std::cout<<r;
    // string str = "   nikg";
    // char c = str[0];
    // if( c == 32){
    //     cout<<"Hell ";
    // }
    // char c = '3';
    // int d = c - '0';
    // cout<<d;
    // string str = "asdf";
    // str[2] = 'x';
    //
    // cout<<str;
    //int c = 2**2;
    cout<<c;
    return 0;
}*/
