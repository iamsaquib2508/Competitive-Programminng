




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int i, sz;
    string s;
    while(cin >> s)
    {
    sz=s.size();
    char c=s[0];
    ffr(i,0,sz)
    {
      if(c!=s[i])
      {
        c=34;
      }
        if(s[i]!=s[sz-1-i])
        {
            break;
        }

    }
    if(i<sz)
    {
      cout << sz << endl;
    }
    else if(c==34)
    {
      cout << sz-1 << endl;
    }
    else cout << "0\n" ;
}


    return 0;
}
