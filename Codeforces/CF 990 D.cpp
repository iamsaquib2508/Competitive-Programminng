




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
    //cin.tie(NULL);
    int n, a, b, i, j;
    bool ar[1002][1002];
    mm(ar,0);
    cin >> n >> a >> b;
    if(a==1 && b==1)
    {
        if(n==1)
        {
            cout << "YES\n0\n";
        }
        else if(n>3)
        {
            ffr(i,1,n)
            {
                ar[i][i-1]=1;
                ar[i-1][i]=1;
            }
            cout << "YES\n";
            ffr(i,0,n)
            {
                ffr(j,0,n)
                {
                    //a[i][j]=!a[i][j];
                    if(i==j) cout << '0';
                    else cout << ar[i][j] ;
                }
                cout << '\n';
            }
        }
        else cout << "NO\n";
    }
    else if(a>1 && b>1)
    {
        cout << "NO\n";
    }
    else if(a>1)
    {
        ffr(i,a,n)
        {
            ar[i][i-1]=1;
            ar[i-1][i]=1;
        }
        cout << "YES\n";
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                //a[i][j]=!a[i][j];
                cout << ar[i][j] ;
            }
            cout << '\n';
        }
    }
    else if(b>1)
    {
        ffr(i,b,n)
        {
            ar[i][i-1]=1;
            ar[i-1][i]=1;
        }
        cout << "YES\n";
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                //a[i][j]=!a[i][j];
                if(i==j) cout << '0';
                else cout << !ar[i][j] ;
            }
            cout << '\n';
        }
    }



    return 0;
}
