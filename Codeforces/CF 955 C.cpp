




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

#define eps 1e-8



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, q, x, j, cc, binred, cnt, temp; ll L, R; ll lll, rrr;
    ll ans;
    int a[100], b[100]; mm(a,0); mm(b,0);
    a[1]=1;
    ffr(k,2,61)
    {
        for(j=k;j<61;j+=k)
        {
            a[j]++;
            b[j]+=(a[k]==1);
        }
    }
    //ffr(k,2,61) cout << a[k] << endl;
    cin >> q;
    while(q--)
    {
        ans=0;
        cin >> L >> R;
        if(R==1)
        {
            cout << 1 << endl; continue;
        }
        if(L==1) 
        {
            L++; ans=1;
        }
        ffr(k,2,61)
        {
            //if(a[k]>1) continue;
            lll=ceil(pow(L,1.0/k));
            

            rrr=floor(pow(R,1.0/k));
            
            x=(rrr-lll+1);
            ans+= x;
            if(a[k]==1) continue;
            ans-=x;
            cc=0; binred=0;
            for(j=k-1; j>=2; j--)
            {
                if(k%j!=0) continue;
                cnt=a[j];
                cc+=(cnt==1);

                
                
                binred+=(b[j]-1);
                //if(cnt==1) continue;
                
            }
                ans-=(a[k]-1)*x;
                ans+=binred*x;
            //ans-= (a[k]-1)*x;
            
            //cout << lll << " " << rrr << endl;
            //cin >> x;
        }
        
        cout << ans << endl;
    }
    
    //fix size
    return 0;
}
