#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

using namespace std;

int main()
{
    int n, i, x;
    cin >> n;
    int cnt=0, ans=0, fst=0;
    cin >> x;
    if(x==1) {fst=-1; cnt++;}
    ffr(i,1,n)
    {
        cin >> x;
        if(x==1)
        {
            cnt++;
        }
        else
        {
            ans=max(ans,cnt);
            if(fst==-1) fst=cnt;
            cnt=0;
        }
    }
    if(cnt>0) ans=max(ans,cnt+fst);
    cout << ans << endl;

}
