




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

int n;
vector<int> v;

string trans(string ss, int wh)
{
    //cout << n-wh << " " ;
    v.pb(n-wh);
    string ret="";
    int i;
    for(i=n-1; i>=wh; i--)
    {
        ret+=ss[i];
    }
    ffr(i,0,wh)
    {
        ret+=ss[i];
    }
    //cout << ret << endl;
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    
    cin >> n;
    string s, t;
    char c; int i, j, cur, dum;
    v.clear();
    
    cin >> s;
    cin >> t;

    c=t[0];
    ffr(i,0,n)
    {
        if(c==s[i])
        {
            s=trans(s,i+1);
            break;
        }
    }
    if(i==n)
    {
        cout << "-1\n"; return 0;
    }
    cur=n-1;
    ffr(i,1,n)
    {

        c=t[i];
        ffr(j,0,cur)
        {
            if(c==s[j])
            {
                s=trans(s,j+1);
                s=trans(s,n-1);
                s=trans(s,0);
                
                break;
            }
        }
        if(j==cur)
        {
            cout << "-1\n"; return 0;
        }
        cur--;
    }
    //cout << endl;
    int sz=v.size();
    cout << sz << endl;
    sz--;
    ffr(i,0,sz)
    {
        cout << v[i] << " ";
    }
    cout << v[i];

    //fix size
    return 0;
}
