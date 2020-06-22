#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define ld long double
#define pf printf

using namespace std;

vector<int> v[35];

int bfs(int s, int r)
{
	//r++;
	int dis[35], ans=1;
	mm(dis,-1);
	dis[s]=0;
	queue<int> q;
	//q.clear();
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(), sz, i;
		if(dis[u]==r) break;
		q.pop();
		sz=v[u].size();
		ffr(i,0,sz)
		{
			if(dis[v[u][i]]>=0) continue;
			else 
			{
				dis[v[u][i]]=dis[u]+1;
				ans++;
				//pf("u=%d v=%d ans=%d\n", u, v[u][i], ans);
				q.push(v[u][i]);
			}
		}
	}
	return ans;
}

int main()
{
	int cc=1, id, r, a, b, n, x, ans;
	map<int,int> m;
	map<int,int>::iterator i;
	while(cin >> n)
	{
		if(n==0) break;
		id=0;
		m.clear();
		ffr(x,0,100) v[x].clear();
		ffr(x,0,n)
		{
			cin >> a >> b;
			i=m.find(a);
			if(i!=m.end()) a=i->second;
			else
			{
				m[a]=id;
				a=id;
				id++;
			}
			i=m.find(b);
			if(i!=m.end()) b=i->second;
			else
			{
				m[b]=id;
				b=id;
				id++;
			}
			#define pb push_back
			v[a].pb(b);
			v[b].pb(a);
		}
		//total == id
		while(cin >> a >> r)
		{
			if(a==0 && r==0) break;
			i=m.find(a);
			if(i!=m.end()) 
			{
				a=i->second;
				ans=id-bfs(a,r);
				a=i->first;
			}
			else
			{
				ans=id;
			}
			pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cc++, ans, a, r);
		}
	}
	return 0;
}
