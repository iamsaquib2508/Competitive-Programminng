




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
    vector<int> v; v.clear();
    int n, k, i, j, sz;
    string s; char temp;
    cin >> n;
    cin >> s;
    ffrr(i,1,n)
    {
        if(n%i==0) v.pb(i);
    }
    sz=v.size();
    ffr(j,0,sz)
    {
        i=v[j]-1;
        {
            for(k=0;k<i;k++,i--)
            {
                temp=s[k];
                s[k]=s[i];
                s[i]=temp;
            }
        }
    }
    cout << s << endl;



    return 0;
}
