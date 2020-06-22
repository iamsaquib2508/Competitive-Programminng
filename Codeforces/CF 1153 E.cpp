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

int n;

int quercol(int r)
{
    int hi, lo, mid, got;
    lo=0, hi=n;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;

        pf("? %d %d %d %d\n", r, 1, r, mid);
        cin >> got;
        if(got&1) hi=mid;
        else lo=mid;
    }
    return hi;
}

int querrow(int r)
{
    int hi, lo, mid, got;
    lo=0, hi=n;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;

        pf("? %d %d %d %d\n", 1, r, mid, r);
        cin >> got;
        if(got&1) hi=mid;
        else lo=mid;
    }
    return hi;
}

int main()
{
    while(cin >> n)
    {
        vector<int> ans;
        ans.clear();
        int col, row, got;
        col=n;
        while(col>0)
        {
            pf("? %d %d %d %d\n", col, 1, col, n);
            cin >> got;
            if(got&1) break;
            col--;
        }
        if(got&1)
        {
            ans.pb(col);
            ans.pb(quercol(col));

            col--;
            while(col>0)
            {
                pf("? %d %d %d %d\n", col, 1, col, n);
                cin >> got;
                if(got&1) break;
                col--;
            }
            ans.pb(col);
            ans.pb(quercol(col));
        }
        else
        {
            row=n;
            while(row>0)
            {
                pf("? %d %d %d %d\n", 1, row, n, row);
                cin >> got;
                if(got&1) break;
                row--;
            }
            int temp=querrow(row);
            ans.pb(temp);
            ans.pb(row);
            row--;
            while(row>0)
            {
                pf("? %d %d %d %d\n", 1, row, n, row);
                cin >> got;
                if(got&1) break;
                row--;
            }
            ans.pb(temp);
            ans.pb(row);
        }
        pf("! %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    }
    return 0;
}
