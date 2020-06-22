




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
    
    cin >> n;
    ffr(i,0,n)
    {
        cin >> a[i];
    }
    ffr(i,0,n)
    {
        cin >> x;
        v.pb(i);
    }
    sort(v.begin(), v.end());
    ffr(i,0,n)
    {
        x=a[i];
        mm(temp,0);
        mul=1;
        while(x>0)
        {
            
            temp[j]=x%2;
            x/=2;
            j++;
            mul+=mul;
        }
        mul/=2;
        for(k=j-1;k>=0;k--)
        {
            if(temp[k]==0)
            {
                while(hi>lo)
                {
                    mid=(lo+hi)/2;
                    if(mid==lo)
                    {
                        
                    }
                    if(v[mid]>=mul)
                    {
                        mid=hi;
                    }
                    else
                    {
                        mid=lo;
                    }

                }
            }
        }
    }
    
    

	return 0;

}
