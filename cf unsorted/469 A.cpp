




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
    
    int a, l, r, inc;
    //while(1)
    {

    
    cin >> l >> r >> a;
    if(l<r)
    {
        inc=r-l;
        if(inc<=a)
        {
            
            a-=inc;
            cout << 2*(r+a/2) << endl;
        }
        else
        {
            l=l+a;
            cout << (l+l) << endl;
        }
    }
    else
    {
        inc=l-r;
        if(inc<=a)
        {
            
            a-=inc;
            cout << 2*(l+a/2) << endl;
        }
        else
        {
            r=r+a;
            cout << (r+r) << endl;
        }
    }
    
}
	return 0;

}
