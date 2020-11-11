//Given a directed graph ,design an algorithm to find out whether there is a route between two nodes
//https://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
#include<list>
#include<iostream>
using namespace std;

//this class represents a directed graph using adjacency list
class Graph
{
    int v;          //number of vertices
    list<int> *adj; //pointer to array contaning adjacency list 
public:
    Graph(int v);               //constructor
    void addEdge(int v, int w); //function to add an edge to graph
    bool isReachable(int s, int d);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);//add w to v's list
}

//a BFS based fn to check whether d is reachable from s
bool Graph::isReachable(int s, int d)
{
    //Base Case
    if(s == d)
        return true;

    //mark all the vertices as not visited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    //create a queue for bfs
    list<int> queue;

    //mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    //it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        //deque a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        //get all adjacent vertices of the dequeues vertex s
        //if a adjacent has not been visited,then mark it visited
        //and enqueue it
        for(i = adj[s].begin();i != adj[s].end(); ++i) {
            //if this adjacent node is the destination node,then
            //return true
            if(*i == d)
                return true;
            
            //else continue to do BFS
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    //If BFS is complete without visiting d
    return false;
}

int main()
{
    Graph g(4);//four vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int u = 1,v = 3;
    if(g.isReachable(u, v))
        cout<<"\n There is a path from "<<u<<" to "<<v;
    else
        cout<<"\n There is no path from "<<u<<" to "<<v;

    u = 3,v =1;
    if(g.isReachable(u, v))
        cout<<"\n There is a path from "<<u<<" to "<<v;
    else
        cout<<"\n There is no path from "<<u<<" to "<<v;

    return 0;
}