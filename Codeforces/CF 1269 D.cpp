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

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}



int main()
{
    ll n;
    while(cin >> n)
    {
        ll i, mx=0, x, a[n+5], lv;
        ffr(i,0,n)
        {
            cin >> x;
            a[i+1]=x;
            mx=maxx(mx,x);
        }
        //a[n]=a[n-1];
        //sort(a,a+n);
        ll prev=0, cur=n, ans=0, evcnt=0;
        for(lv=1;lv<=mx;lv++)
        {
            if(cur<=0) break;
            //work with cur
            //cout << cur << " cur\n";
            if(cur&1)
            {
                if(prev && ((evcnt&1)==0) ) {ans++; prev=0; }
                //else if(prev){}
                else {prev=1;}
                evcnt=0;
                ans+=(cur/2);

            }
            else
            {
                evcnt++;
                ans+=(cur/2);
                //prev=0;
            }
            while(cur>0 && a[cur]<=lv) cur--;

        }
        cout << ans << endl;
    }
}
