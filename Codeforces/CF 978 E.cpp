#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int

using namespace std;

int main()
{
    ll n, w, i, mxp=0, mxn=0, cur=0, x;
    cin >> n >> w;
    ffr(i,0,n)
    {
        cin >> x;
        cur+=x;
        if(cur>0) mxp=max(mxp,cur);
        else if(cur<0) mxn=min(mxn,cur);

    }
    cout << max(w+1-(mxp-mxn),0ll) << endl;
    return 0;
}
