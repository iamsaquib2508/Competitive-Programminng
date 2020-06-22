#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}

vector<int> v[100005];

int min_dfs(int s, int par=-1, int prev=0)
{
    int tmp, temp;
    if(v[s].size()==1 && v[s][0]==par)
    {
        //leaf
        //cout << prev << endl;
        return prev; //??
    }
    if(par!=-1 && v[s].size()==2)
    {
        if(v[s][0]==par) tmp=v[s][1];
        else tmp=v[s][0];
        return min_dfs(tmp, s, prev+1);
    }
    set<bool> st; st.clear();
    for(int vv:v[s])
    {
        if(vv==par) continue;
        temp=min_dfs(vv, s, +1);
        //cout << temp << endl;
        if(temp==-1) return -1;
        st.insert(temp&1);
    }
    if(st.size()==2)
    {
        return -1;
    }
    else
    {
        tmp = *(st.begin());
        tmp ^= (prev&1);
        return tmp;
    }
}

int max_dfs(int s, int par=-1, int prev=0)
{
    int tmp, temp, ans=0;
    if(v[s].size()==1 && v[s][0]==par)
    {
        //leaf
        return prev; //??
    }
    if(par!=-1 && v[s].size()==2)
    {
        if(v[s][0]==par) tmp=v[s][1];
        else tmp=v[s][0];
        return max_dfs(tmp, s, prev+1);
    }
    set<bool> st; st.clear();
    bool ongot=0;
    for(int vv:v[s])
    {
        if(vv==par) continue;
        temp=max_dfs(vv, s, +1);
        if(temp==1) ongot=1;
        //
        else ans+=temp;

        //cout << temp << endl;
    }
    if(ongot) ans++;
    return ans+prev;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int i, vv, uu;
        ffr(i,0,100005) v[i].clear();
        ffr(i,1,n)
        {
            cin >> uu >> vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        ffr(i,1,n)
        {
            if(v[i].size()>1) break;
        }

        int min_ans=min_dfs(i)==-1? 3:1 ;

        int max_ans=max_dfs(i);

        cout << min_ans <<  ' ' << max_ans << endl;
    }
}
