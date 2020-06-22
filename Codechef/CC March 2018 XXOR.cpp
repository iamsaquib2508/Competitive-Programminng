




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




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll j, i, n, q, t=1, l, r, mul;
    ll ans, temp;
    int arr[100002][31];
    
    //cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> q;
        mm(arr,0);
        ffrr(i,1,n)
        {
            cin >> temp;
            
            ffr(j,0,31)
            {
                arr[i][j]=arr[i-1][j];
                if(temp&1)
                {
                    arr[i][j]++;
                }
                temp=temp>>1;
            }
        }
        
        ffr(i,0,q)
        {
            cin >> l >> r;
            mul=1; ans=0;
            ffr(j,0,31)
            {
                temp=arr[r][j]-arr[l-1][j];
                if(temp+temp<(r-l+1)) ans+=mul;
                
                
                mul=(mul<<1);
            }
            cout << ans << endl;
        }

        
    }
	return 0;

}
