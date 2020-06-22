#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

// int ff(int ir)
// {
//     int lo=-1, hi=v.size(), mid;
//     while(hi-lo>1)
//     {
//         mid=(lo+hi)/2;
//         if(v[mid]<=ir) lo=mid;
//         else hi=mid;
//     }
//     return v.size()-hi;
// }


ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (x2-x1)*(y2-y1)+1 << endl;

    }
}

/*
100
1 1 2 2
1 2 2 4
120 1 120 10000
1 1 1 1
1 1 3 3
1 1 3 4
1 1 4 5

2
3
1
1
4
6
12
*/
