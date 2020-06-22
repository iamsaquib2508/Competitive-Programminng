




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

//AC

#define MX 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t, k, tttt, req, s, xx, i, j, prvm, prvl, curm, curl, ext, ac, a[MX], mm, fcd;
    vector<int> ou; ou.clear();

    cin >> n >> t >> k;
    a[0]=1;
    s=0;
    ffrr(i,1,t)
    {
        cin >> xx;
        a[i]=xx;
        s+=max(0,a[i-1]-xx);
    }
    s+=a[i-1];
    if(s>k)
    {
        cout << "-1\n";
    }
    else
    {
        req=k-s;
        prvm=1; prvl=1;
        //cout << n << endl;
        ffrr(xx,1,t)
        {
            curl=a[xx];
            curm=prvm+curl;
            
            ac=prvl-1; 
            fcd=(prvl>curl)*(prvl-curl);
            ac-=fcd;
            
            //pf("req %d ac %d prvm %d curm %d", req, ac, prvm, curm);
            if(req>=ac)
            {
                req-=ac;
                tttt=ac;
            }
            else
            {
                tttt=req; req=0;
            }
            mm=tttt+fcd;
            ext=curl-prvl+mm;
            //cout << " mm " << mm << " ext " << ext << endl;
            
            for(i=mm, j=prvm+1; i<prvl; i++, j++)
            {
                //cout << j-prvl << " " << j << endl;
                ou.pb(j-prvl); ou.pb(j);
            }
            s=j-prvl-1;
            for(i=0; i<ext; i++, j++)
            {
                //cout << s << " " << j << endl;
                ou.pb(s); ou.pb(j);
            }
            
            prvm=curm; prvl=curl;
            //cin >> curm;
           
        }
        if(req>0) cout << "-1\n";
        else
        {
            cout << n << endl;
            s=ou.size();
            ffr(i,0,s)
            {
                cout << ou[i] << " " << ou[i+1] << endl; i++;
            }
            ou.clear();
        }
    }


	return 0;

}
