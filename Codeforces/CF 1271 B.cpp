#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

string s;
int n;
vector<int> v;

bool f(char c)
{
    int i;
    v.clear();
    string ss=s;
    ffr(i,1,n)
    {
        if(ss[i-1]==c)
        continue;
        else
        {
            v.pb(i-1);
            ss[i]='W'-ss[i]+'B';
        }
    }
    if(ss[i-1]==c) return true;
    else return false;
}

int main()
{
    while(cin >> n)
    {
        cin >> s;

        if(f('B') || f('W'))
        {
            cout << v.size() << endl;
            for(int a: v)
            {
                cout << a+1 << " ";
            }
            if(v.size()>0)cout << endl;
        }
        else cout << "-1\n";
    }
}
