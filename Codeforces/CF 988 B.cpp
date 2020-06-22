



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


bool cmp(string a, string b)
{

    int i, j, sza, szb, tempj;
    if(a==b) return 1;
    sza=a.size();
    szb=b.size();
    if(szb<sza)
    {
    return 0;
    }
    bool sol=0;
    ffr(j,0,szb)
    {
        i=0;
        tempj=j;
        while(i<sza && j<szb && a[i]==b[j])
        {
            i++; j++;
        }
        if(i==sza)
        {
            sol=1; break;
        }
        else
        {
            j=tempj;
        }

    }
    //cout << "in " << a << " " << b << " " << sol << endl;;
    return sol;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int i, j, n;
    string a[200], t;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> a[i];
    }
    //sort(a,a+n,cmp);
    ffr(i,0,n)
    {
        ffr(j,i+1,n)
        {
            if(!cmp(a[i],a[j]))
            {
                t=a[i]; a[i]=a[j]; a[j]=t;
            }
        }
    }
    ffr(i,1,n)
    {
        if(!cmp(a[i-1],a[i])) break;
    }
    if(i==n)
    {
        cout << "YES\n";
        ffr(i,0,n)
        {
            cout << a[i] << "\n";
        }
    }
    else cout << "NO\n";



    return 0;
}
