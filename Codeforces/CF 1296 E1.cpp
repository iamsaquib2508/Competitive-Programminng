#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

class node
{
public:
    char c; int id, col;
    node(){}
    node(char cc, int idd, int coll){c=cc; id=idd; col=coll;}

};

#define NMAX 200002

std::vector<int> ans(NMAX);
queue<int> v[26];

void ff(int start, int end, set<int> st)
{
    if(start==end) return;
    ffr(i,0,26)
    {
        int use=0, sz=v[i].size();
        if(sz>0)
        {
            int base=v[i].front();
            ans[base]=use;
            v[i].pop();

            while(!v[i].empty())
            {
                //cout << v[i][j] << ' ';
                if(v[i].front()-base==j) {ans[v[i].front()]=use; v[i].pop();}
                else break;
            }
            use=st.size();
            while(!v[i].empty()) {ans[v[i].front()]=use; st.insert(use); ff()}
        }
    }
}

int main()
{
    int tt=100; //cin >> tt;
    while(tt--)
    {
        int n, i, j, curcol, itemp;
        string s;
        char c;

        cin >> n >> s;

        ffr(i,0,26) v[i].clear();
        i=0;
        for(char a: s)
        {
            //v.pb(node(a,i,0));
            v[a-'a'].p(i);
            i++;
        }
        set<int> st; st.clear(); st.insert(0);
        ans.clear();
        ff(0,n,st);


        //if(st.size()<3)
        {
            cout << "YES\n";
            for(int a: ans) cout << a; cout << endl;
        }
        //else cout << "NO\n";

        //cout << gotmax << endl;
        //for(int a: ans) cout << a << ' '; cout << endl;

    }
}
