




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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //while(1)
    {
    string s;
    int i, j, sz, pr, nn, done=0, n;
    cin >> n;
    cin >> s;
    sz=s.size();
    ffr(i,1,sz)
    {
        if(s[i]!='?' && s[i]==s[i-1]) 
        {
            pf("No\n");
            return 0;
        }
    }
    //cout << sz << endl;
    if(s[0]=='?' || s[sz-1]=='?')
    {
        pf("Yes\n");
    }
    else if(sz<3)
    {
        pf("No\n");
    }
    else
    {
        sz--;
        ffr(i,1,sz)
        {
            if (done) break;
            pr=s[i-1]; nn=s[i+1];
            if(s[i]=='?')
            {
                if(nn=='?' || pr==nn)
                {
                    pf("Yes\n"); done=1;
                }
                else
                {
                    i++;
                }
                
            }
            else
            {
                if(pr==s[i] || nn==s[i])
                {
                    pf("No\n"); done=1;
                }
            }
        }
        if(!done) pf("No\n");
    }
    
}
    //fix size
    return 0;
}
