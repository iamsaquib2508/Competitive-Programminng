#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mp make_pair
#define pii pair<int,int>

using namespace std;

string g[15];
map<pii, int> dis;
map<pii, bool> vis;

void bfs(pii s){
    dis[s] = 0;
    vis[s] = true;
    queue<pii> q;
    q.push(s);
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for 
    }
}

int main(){
	int cc=1, tt;
    cin >> tt;
    while(tt--){
        int n, i, j;
    	cin >> n;
        pii apos, bpos, cpos;
        ffr(i,0,n){
        	cin >> g[i];
            ffr(j,0,n){
                if(g[i][j] == 'A')
                    apos = mp(i, j);
            }
        }
        
    	cout << "Case " << cc++ << ": " << ans << '\n';
    }
}