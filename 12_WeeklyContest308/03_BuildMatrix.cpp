// https://leetcode.com/contest/weekly-contest-308/problems/build-a-matrix-with-conditions/

#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
using ULL=unsigned long long;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& R, vector<vector<int>>& C) {
    	vector<int>p(k),q(k);
    	vector<vector<int> >ans(k,vector<int>(k));
    	{
			vector<int>deg(k);
			vector<vector<int> >e(k);
			each(x,R){
				e[x[0]-1].pb(x[1]-1);
				++deg[x[1]-1];
			}
			queue<int>que;
			rep(i,0,k-1)if(!deg[i])que.push(i);
			int idx=0;
			while(!que.empty()){
				int u=que.front();
				p[u]=idx++;
				que.pop();
				each(x,e[u])if(!--deg[x])que.push(x);
			}
			if(idx!=k)return vector<vector<int> >();
    	}
    	{
			vector<int>deg(k);
			vector<vector<int> >e(k);
			each(x,C){
				e[x[0]-1].pb(x[1]-1);
				++deg[x[1]-1];
			}
			queue<int>que;
			rep(i,0,k-1)if(!deg[i])que.push(i);
			int idx=0;
			while(!que.empty()){
				int u=que.front();
				q[u]=idx++;
				que.pop();
				each(x,e[u])if(!--deg[x])que.push(x);
			}
			if(idx!=k)return vector<vector<int> >();
    	}
    	rep(i,0,k-1){
    		ans[p[i]][q[i]]=i+1;
    	}
    	return ans;
    }
};