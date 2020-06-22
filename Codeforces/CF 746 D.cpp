




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

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */


//AC

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, a, b, i, j, mode=0;
    char as, bs;
    cin >> n >> k >> a >> b;
    if(b<a)
    {
        a=a^b;
        b=a^b;
        a=a^b;
        mode=1;
    }
    int up=n-a, dn=a+1;
    int x=ceil(up*1.0/dn);
    int rem=0;
    if(x>k) cout << "NO\n";
    else
    {
        if(mode)
        {
            as='B', bs='G';
        }
        else
        {
            as='G', bs='B';
        }
        ffr(i,0,a)
        {
            ffr(j,0,x)
            {
                cout << bs ;
                
            }
            cout << as;
            
            up-=x; dn--;
            x=ceil(up*1.0/dn);
        }
        int t=up; rem+=t;
        ffr(i,0,t) cout << bs;
    }
    //cout << rem << endl;
    
	return 0;

}
