// https://leetcode.com/contest/weekly-contest-304/problems/longest-cycle-in-a-graph/

// You are given a directed graph of n nodes numbered from 0 to n - 1,
// where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n,
// indicating that there is a directed edge from node i to node edges[i].
// If there is no outgoing edge from node i, then edges[i] == -1.
// Return the length of the longest cycle in the graph. If no cycle exists,
// return -1.
// A cycle is a path that starts and ends at the same node.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs1(int node,vector<vector<int>>&g,vector<int>&vis,stack<int>&topo)
    {
        vis[node]=1;
        for(auto child : g[node])
        {
            if(vis[child]==0)
            {
                vis[node]=1;
                dfs1(child,g,vis,topo);
            }
        }
        topo.push(node);
    }
    void Revdfs(int node,vector<vector<int>>&g,vector<int>&vis,vector<int>&component)
    {
        vis[node]=1;
        component.push_back(node);
        for(auto child : g[node])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                Revdfs(child,g,vis,component);
            }
        }
    }
    
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        
        vector<vector<int>> g(n);
        vector<vector<int>> rev(n);
        for(int i=0;i<n;i++)
        {
            int child=edges[i];
            if(child!=-1)
            {
                g[i].push_back(child);
                rev[child].push_back(i);
            }
        }
        
        vector<int> vis1(n,0);
        stack<int> topo;
        for(int i=0;i<n;i++)
        {
            if(!vis1[i])
                dfs1(i,g,vis1,topo);
        }
        
        vector<int> vis2(n,0);
        int ans=-1;
        while(!topo.empty())
        {
            int node=topo.top();
            topo.pop();
 
            if(vis2[node]==0)
            {
                vector<int> component;
                component.clear();
                Revdfs(node,rev,vis2,component);
                int k=component.size();
                if(k!=1)
                    ans=std::max(ans,k);
            }
        }
        
        return ans;
    }
};

int main()
{

    return 0;
}