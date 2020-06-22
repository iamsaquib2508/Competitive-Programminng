#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    ll i, n, sum, cur, x, q, l, r;
    while(cin >> n)
    {
        set<ll> s;
        s.clear();
        vector<ll> v;
        v.clear();

        ffr(i,0,n)
        {
            cin >> x;
            s.insert(x);
        }
        set<ll>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            v.pb(*it);
        }
        int sz=v.size();
        //ffr(i,0,sz) cout << v[i] << " v ";
        ll a[100005]={};
        sum=0; a[0]=0;
        ffr(i,1,sz)
        {
            cur=v[i]-v[i-1];
            a[i]=cur;
        }
        sort(a+1,a+sz);

        ll summ[100005]={};
        sum=0; summ[0]=0;
        ffr(i,1,sz)
        {
            sum+=a[i];
            summ[i]=sum;
        }
        //ffr(i,0,sz) cout << a[i] << " "; cout << "\n";
        cin >> q;
        ll hi, lo, mid, ind;
        ll cov;


        while(q--)
        {
            cin >> l >> r;
            cov=r-l+1;
            //cin >> cov;
            lo=0, hi=sz-1;
            while(hi-lo>1)
            {
                mid=(hi+lo)/2;
                if(a[mid]<=cov)
                {
                    lo=mid;
                }
                else
                {
                    hi=mid;
                }
            }
            //cout << lo << " lo hi " << hi << endl;
            if(a[hi]<=cov)
            {
                ind=hi;
            }
            else ind=lo;
            //cout << ind << " ind for cov\n";

            cout << summ[ind]+(sz-1-ind)*cov+cov << ' ';
        }
        cout << endl;

    }
}
