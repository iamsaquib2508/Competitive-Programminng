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
    lo=0, hi=1e6+3;
    cout << "? 0\n";
    cin >> base;
    if(base==0) cout << "! 0\n";
    else if(base>0)
        while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        cout << mid << endl;
        cin >> got;
        if(got>0)
        {
            lo=mid;
        }
        else if(got<0)
        {
            hi=mid;
        }
        else
        {
            cout << "! " << mid << endl; break;
        }

    }
}
