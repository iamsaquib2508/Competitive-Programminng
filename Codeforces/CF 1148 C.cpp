
/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int main()
{
    int n, i, x, c, d, n2;
    int arr[300005], pos[300005];
    vector< pii > v;
    while(cin >> n)
    {
        v.clear();
        ffrr(i,1,n)
        {
            cin >> x;
            arr[i]=x;
            pos[x]=i;
        }
        n2=n/2;
        ffrr(i,1,n2)
        {
            if(arr[i]!=i)
            {
                if(pos[i]>=i+n2)
                {
                    c=i;
                    d=pos[i];
                    v.pb(mp(c,d));

                    int t;
                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;

                }
                else
                {
                    c=pos[i]+n2;
                    d=pos[i];
                    v.pb(mp(c,d));

                    int t;
                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;

                    d=i;
                    v.pb(mp(c,d));

                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;
                }
            }
            cout << pos[2] << endl;
        }
        ffrr(i,i,n)
        {
            if(arr[i]!=i)
            {

                {
                    x=pos[i];

                    c=1;
                    d=pos[i];
                    v.pb(mp(c,d));

                    int t;
                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;

                    d=i;
                    v.pb(mp(c,d));

                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;

                    c=x;
                    v.pb(mp(c,d));

                    t=arr[c]; arr[c]=arr[d]; arr[d]=t; pos[arr[c]]=c; pos[arr[d]]=d;
                }
            }
        }
        int sz=v.size();
        cout << sz << endl;
        ffr(i,0,sz)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }
}
