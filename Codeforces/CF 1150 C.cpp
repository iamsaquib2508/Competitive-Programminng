#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int main()
{
    int n, i, x, t, w;
    while(cin >> n)
    {
        t=0; w=0;
        ffr(i,0,n)
        {
            cin >> x;
            if(x==1) w++; else t++;
        }
        if(t==0)
        {
            cout << "1";
            ffr(i,1,n) cout << " 1";
        }
        else if(w==0)
        {
            cout << "2";
            ffr(i,1,n) cout << " 2";
        }
        else
        {
            cout << "2 1";
            w--; t--;
            ffr(i,0,t) cout << " 2";
            ffr(i,0,w) cout << " 1";
        }
        cout << endl;
    }
}
