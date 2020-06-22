#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

vector<int> v[1003], q;
int firstVertex, d1, minimumD, closestVertexOutside, d2, extra, node1, d3, node2, d4;
int farthestDfromV1;
bool vis[1003];

void dfs0(int s, int p, int dis){
    vis[s]=1;
    if(v[s].size()==1 && v[s][0]==p){
        farthestDfromV1=maxx(farthestDfromV1,dis);
        return;
    }
    for(int vv:v[s]){
        if(vv!=p){
            dfs0(vv, s, dis+1);
            //?
        }
    }
    return ;
}

void dfs1(int s, int p, int dis){
    vis[s]=1;
    if(dis==d1){
        q.pb(s);
        return;
    }
    else if(v[s].size()==1 && v[s][0]==p){
        return;
    }
    for(int vv:v[s]){
        if(vv!=p){
            dfs1(vv, s, dis+1);
            //?
        }
    }
    return;
}

bool dfs2(int s, int p, int dis){
    vis[s]=1;
    if(dis==d1){
        if(s==closestVertexOutside){
            q.pb(s);
            return 1;
        }
        else return 0;
    }
    else if(v[s].size()==1 && v[s][0]==p){
        return 0;
    }
    bool got;
    for(int vv:v[s]){
        if(vv!=p){
            got=dfs2(vv, s, dis+1);
            if(got){
                q.pb(s);
                return 1;
            }
            //?
        }
    }
    return 0;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, u, uu;
        cin >> n;
        ffr(i,0,1003) v[i].clear();
        ffr(i,1,n){
            cin >> u >> uu;
            v[u].pb(uu);
            v[uu].pb(u);
        }
        farthestDfromV1=0;
        cout << "? " << n;
        ffr(i,1,n) cout << " " << i; cout << " " << n << endl;
        cin >> firstVertex >> minimumD;

        mm(vis,0);
        dfs0(firstVertex,-1,0);

        d1=minn(farthestDfromV1,minimumD);
        //cout << d1 << endl;
        q.clear();
        mm(vis,0);
        dfs1(firstVertex,-1,0);
        cout << "? " << q.size();
        for(int aa:q) cout << ' ' << aa; cout << endl;
        cin >> closestVertexOutside >> d2;

        extra = (d2-minimumD)/2;
        q.clear();
        mm(vis,0);
        dfs2(firstVertex, -1, 0); //look closestVertexOutside at extra slack
        node1 = q[extra];
        //cout << "? 1 " << node1 << endl;
        q.clear();
        mm(vis,0);
        d1=minimumD;
        dfs1(node1,-1,0);
        cout << "? " << q.size();
        for(int aa:q) cout << ' ' << aa; cout << endl;
        cin >> node2 >> d4;
        //assert(d4==minimumD);
        cout << "! " << node1 << ' ' << node2 << endl;
        string s;
        cin >> s;
        //assert(s=="Correct");
    }
    return 0;
}

/*


I need a help with a solution that I have of problem 1370F2 - The Hidden Pair (Hard Version). I understand the editorial and I know how it works. But I have a solution of my own, which I don't know why should fail. The idea is simple, and quite similar to the one in the editorial.

Let, the hidden nodes are $$$s$$$ and $$$t$$$. Their distance is $$$L$$$. So, let the path between $$$s$$$ and $$$t$$$ be $$$P(s,t)$$$, and $$$|P(s,t)|=L$$$.

    QUERY First, query for all nodes, which will give one of the nodes on $$$P(s,t)$$$ and $$$L$$$. Let's call the node $$$x_1$$$.
    Root the tree at $$$x_1$$$. Find all the nodes that are $$$min(L,maxDepth)$$$ distance away from $$$x_1$$$.
    QUERY query over all these nodes. Here, I hope that a node $$$x_2$$$ is returned where $$$P(x_1,x_2)$$$ contains one of $$$s$$$ or $$$t$$$. Why do I hope that? Without loss of generality, let's say $$$P(x_1,x_2)$$$ contains $$$s$$$. Then $$$dis(s,x_2)+dis(t,x_2)$$$ will be equal to $$$2*dis(s,x_2)+L$$$. As we know $$$L$$$, we can know $$$dis(s,x_2)$$$ and get $$$s$$$ by following the path $$$P(x_2,x_1)$$$.
    QUERY As we have found one of the nodes, clearly we can query over all the nodes that are $$$L$$$ distance away from it and find the other node. This will solve the problem in $$$3$$$ queries.

Now, the only thing I need to prove is that in step 3 or query 2, I really get a node $$$x_2$$$ such that $$$P(x_1,x_2)$$$ contains one of $$$s$$$ or $$$t$$$. Let's take the proof out of the context. All I need to know is that in an infinitely large tree, if a path $$$P$$$ consists of nodes $$$p_1, p_2, ...p_L$$$, is it possible to have a node $$$x$$$ which is $$$L$$$ distance away from $$$p_k ($$$ for every $$$1\leq k\leq L)$$$, have minimum $$$dis(p_1,x)+dis(p_L,x)$$$, but not have any of $$$p_1$$$ or $$$p_L$$$ on the path from $$$p_k$$$ to $$$x$$$? I find the idea really simple, and believe that it is correct. Can anyone show me the mistake (or the lack of it)?
*/
