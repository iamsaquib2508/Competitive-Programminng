#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int x, ans, pans, i;
        
        set<int> s;
        set<int>::iterator ss;
        ffr(i,0,n)
        {
            cin >> x;
            s.insert(x);
        }
        if(s.size()==1) cout << "0\n";
        else
        {
            ss=s.begin();
            pans=(*ss);
            ss++;
            for(;ss!=s.end();ss++)
            {
                ans=pans;
                pans=(*ss);
            }
            cout << ans << endl;
        }
    }
}
