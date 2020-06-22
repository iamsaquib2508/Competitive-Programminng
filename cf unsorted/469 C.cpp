




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
    //while(1)
    {

    string s;
    int i, j, sz, sz2, cur, temp;
    cin >> s;
    sz=s.size();
    if(s[0]!='0' || s[sz-1]!='0')
    {
        cout << "-1\n"; return 0;
    }
    vector<int> v;
    v.clear();
    cur=0;
    ffr(i,0,sz)
    {
        if(s[i]=='1')
        {
            if(s[i+1]=='1')
            {
                cout << "-1\n"; return 0;
            }
            if(i+2<sz && s[i+2]=='1')
            {
                i++;
                
            }
            else
            {
                v.pb(i+1-cur+1);
                i++;
            }

        }
        else if(s[i]=='0')
        {
            if(i+1<sz) 
            {
                if(s[i+1]=='1')
                {
                    cur=i;
                    
                }
                else v.pb(1);
            }
            else v.pb(1);
            
        }
    }
    sz2=v.size();
    cout << sz2 << endl;
    cur=1;
    ffr(i,0,sz2)
    {
        temp=v[i];
        cout << temp;
        ffr(j,0,temp)
        {
            cout << " " << cur+j;
        }
        cout << endl;
        cur+=temp;
    }
    
}
	return 0;

}
