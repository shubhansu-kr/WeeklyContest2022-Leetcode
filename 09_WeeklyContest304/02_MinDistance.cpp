// https://leetcode.com/contest/weekly-contest-304/problems/find-closest-node-to-given-two-nodes/

// You are given a directed graph of n nodes numbered from 0 to n - 1,
// where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n,
// indicating that there is a directed edge from node i to node edges[i].
// If there is no outgoing edge from i, then edges[i] == -1.
// You are also given two integers node1 and node2.
// Return the index of the node that can be reached from both node1 and
// node2, such that the maximum between the distance from node1 to that node,
// and from node2 to that node is minimized. If there are multiple answers,
// return the node with the smallest index, and if no possible answer exists,
// return -1.
// Note that edges may contain cycles.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++)
        {
            int child=edges[i];
            if(child!=-1)
                g[i].push_back(child);
        }
        
        auto bfs_trav=[&](int sr)
        {
            vector<int> dist(n,1e9);
            queue<int> bfs;
            
            bfs.push(sr);
            dist[sr]=0;
            
            while(!bfs.empty())
            {
                int node=bfs.front();
                bfs.pop();
                
                for(auto child : g[node])
                {
                    if(dist[child]>dist[node]+1)
                    {
                        dist[child]=dist[node]+1;
                        bfs.push(child);
                    }
                }
            }
            
            return dist;
        };
        
        auto dist1=bfs_trav(node1);
        auto dist2=bfs_trav(node2);
        
        int val=1e8;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(val>std::max(dist1[i],dist2[i]))
            {
                ans=i;
                val=std::max(dist1[i],dist2[i]);
            }
        }
        
        return ans;
    }
};

int main()
{

    return 0;
}