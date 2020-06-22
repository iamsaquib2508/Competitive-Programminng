




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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    fs=-1; fp=-1;
    ffr(i,0,n)
    {
        cin >> X[i] >> c[i];
        if(c[i]=='R') {
        rase=1; if(fs==-1) fs=i;}
        else if(c[i]=='B') base=1;
        else if(c[i]=='P') {
        if(fs==-1) fs=i;}
    }
    
    if(rase)
    {
        ffr(i,fs+1,n)
        {
            if(c[i]=='P' || c[i]=='R')
            {
                ans+=(X[i]-X[fs]);
                fs=i;
            }
        }
        fs=-1; mn=inf;
        ffr(i,0,n)
        {
            if(c[i]=='P') 
            {
                fp=i;
                if(fs==-1) continue;
                else 
                {
                    if((X[i]-X[fs])<mn)
                    {
                        ans-=mn; ans+=X[i]-X[fs];
                    }
                }
            }
            else if(c[i]=='B')
            {
                if(fp==-1) fs=i;
                else
                {
                    fs=i; mn=X[i]-X[fp];
                    ans+=mn;
                }
            }
        }
        
    }
    

    return 0;
}
