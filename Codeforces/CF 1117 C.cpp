#include<bits/stdc++.h>
#define ffr(i,a,b) for(i-a;i<b;i++)
#define pb push_back
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

ll vecx, vecy;
ll turx, tury;

void valx(char a)
{
    if(a=='U')
    {
        tury++;
    }
    else if(a=='D')
    {
        tury--;
    }
    else if(a=='R')
    {
        turx++;
    }
    else if(a=='L')
    {
        turx--;
    }
    return ;
}


int main()
{
    ll x1, x2, y1, y2, n, i, sz;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
    vecx=x2-x1; vecy=y2-y1;
    sz=s.size();
    ll cumsum[100005]; mm(cumsum,0);
    turx=0, tury=0;
    ffr(i,0,sz)
    {
        val(s[i]);
    }

    if(vecy>0) doney=tury;
    
    if(tur==-n)
    {
        cout << "-1\n"; return 0;
    }
    ll fullcost=(vecx+vecy);
    ll fullround=fullcost/(tur+n);
    ll rem=fullcost%(tur+n);
    ll ans=fullround*(n);
    while(rem>0)
    {
        rem-=val(s[i]);
        rem--;
        ans++;
    }
    cout << ans << endl;

}
