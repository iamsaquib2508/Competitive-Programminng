




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

    int i, j, k, n, cnt=0;
    bool allowed[400005];
    string s; char cur;
    cin >> n >> k;
    cin >> s;
    ffr(i,0,n)
    {
        allowed[i]=1;
    }
    ffr(i,0,26)
    {
        cur='a'+i;
        ffr(j,0,n)
        {
            if(cnt==k) break;
            if(!allowed[j]) continue;
            //cout << s[j] << " ";
            if(s[j]==cur)
            {
                cnt++; allowed[j]=0;
            }
        }
        //cout << endl;
    }
    ffr(i,0,n)
    {
        if(allowed[i]) cout << s[i];
    }



    return 0;
}
