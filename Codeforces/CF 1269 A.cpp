#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 100003
#define pil pair<int,ll>
#define mp make_pair

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

ll in[MMAX]={}, out[MMAX]={};


int main()
{
    int n; cin >> n;
    if(n&1)
    {
        cout << n+9 << " 9\n";
    }
    else cout << n+4 << " 4\n";
}
