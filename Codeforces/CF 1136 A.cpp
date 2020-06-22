#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, i, x, a;
    vector<int> v;
    while(cin >> n)
    {
        v.clear();
        ffr(i,0,n)
        {
            cin >> a >> a;
            v.pb(a);
        }
        cin >> x;
        ffr(i,0,n)
        {
            if(v[i]<x) continue;

            if(v[i]>=x)
            {
                //i--;
                break;
            }
        }
        cout << n-i << endl;

    }
}
