// Find the ordering of tasks from given dependencies
// Input: 2, [[1, 0]]
// Output: [0, 1]
// Explanation: There are a total of 2 tasks to pick. 
//To pick task 1 you should have finished task 0.
// So the correct task order is [0, 1] .
// https://www.geeksforgeeks.org/find-the-ordering-of-tasks-from-given-dependencies/
#include<bits/stdc++.h>
using namespace std;

//return adjacency list representation of graph from given
//set of pairs
vector<unordered_set<int>> make_graph(int numTasks, vector<pair<int,int>>& prerequisites)
{
    vector<unordered_set<int>>graph(numTasks);
    for(auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

//computes indegree of every set
vector<int> compute_indegree(vector<unordered_set<int>>&graph)
{
    vector<int> degrees(graph.size(), 0);
    for(auto neighbours :  graph)
        for(int neigh : neighbours)
            degrees[neigh]++;
    return degrees;
}

//main function for topological sorting
vector<int> findOrder(int numTasks, vector<pair<int,int>>& prerequisites)
{
    //create an adjacency list
    vector<unordered_set<int>> graph = make_graph(numTasks,
                                                        prerequisites);
    //Find vertices of zero degree
    vector<int> degrees = compute_indegree(graph);
    queue<int> zeroes;
    for (int i = 0; i < numTasks; i++)
        if(!degrees[i])
            zeroes.push(i);

        //Find vertices in topological order
        //starting with vertices of 0 degreee
        //and reducing degrees of adjacent
        vector<int> toposort;
        for (int i = 0; i < numTasks; i++)
        {
            if(zeroes.empty())
                return {};

            int zero = zeroes.front();
            zeroes.pop();
            toposort.push_back(zero);
            for(int neigh : graph[zero]) {
                if(!--degrees[neigh])
                    zeroes.push(neigh);
            }
        }
    return toposort;
}
int main()
{
    int numTasks = 4;

    vector<pair<int, int >> prerequisites;

    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));

    vector<int> v = findOrder(numTasks, prerequisites);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}