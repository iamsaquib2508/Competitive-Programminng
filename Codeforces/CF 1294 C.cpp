




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

vector<ll> v;
ll temp2;

void ff(int num, int cnt)
{
    if(cnt==2) {temp2=num; v.pb(num);}
    else if(cnt>=6) {v.pb(num); v.pb(num*num); v.pb(num*num*num);}
    else if(cnt>=3) {v.pb(num); v.pb(num*num);}
    else if(cnt==1) {v.pb(num);}

}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        v.clear();
        temp2=-1;
        ll inp, n, i, cnt;

        cin >> n;
        inp=n;

        cnt=0;
        while(!(n&1)) {n>>=1; cnt++;}
        ff(2, cnt);


        ll div=3;
        while(1)
        {
            //cout << n << " n\n";
            if(n==1)
            {
                if(v.size()>2)
                {
                    cout << "YES\n"; cout << v[0] << ' ' << v[1] << ' ' << inp/v[0]/v[1] << endl;
                    break;
                }
                else {cout << "NO\n"; break;}
            }
            else if(v.size()>1)
            {
                cout << "YES\n"; cout << v[0] << ' ' << v[1] << ' ' << inp/v[0]/v[1] << endl;
                break;
            }
            else
            {
                cnt=0;
                while(!(n%div)) {n/=div; cnt++;}
                if(temp2>0)
                {
                    //ff(div,cnt);
                    if(cnt>1) {v.pb(div*temp2); cnt--; temp2=-1;}
                    ff(div,cnt);
                }
                else
                {
                    ff(div,cnt);
                }
                div+=2;
            }
            if(div>38000)
            {
                cout << "NO\n"; break;
            }
        }
    }




    return 0;
}
