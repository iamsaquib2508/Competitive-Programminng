#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

int main(){
    ll k;
    while(cin >> k){
        string ans, mul="codeforces";
        //if(k==1){ans="codeforces";}
        ll temp, cur=1, pten=1, solo, myc, i, j, ten3, rem, p, tt;
        ten3=81*81*9;
        //cout << ten3;
        if(k>ten3)
        {
            pten=ten3; cur=3;
            while(k>pten){
                cur++;
                temp=(cur*cur*cur);
                pten=temp*temp*temp*cur;

                //cout << pten << endl;
            }
            myc=pten;
            solo=0;
            while(myc>k){
                solo++;
                myc-=(myc/cur);
                //cout << myc << endl;
            }
            if(myc<k) solo--;
            //cout << solo << " solo\n";
            ffr(i,0,solo){
                ffr(j,1,cur) ans+=mul[i];
            }
            ffr(i,solo,10){
                ffr(j,0,cur) ans+=mul[i];
            }
            cout << ans << endl;
        }
        else{

            //k/=9;
            tt=0;
            ll larg=1;
            ll a, b;
            while(1){
                if(k/larg<9) break;
                tt+=2; larg*=9;
            }
            //cout << tt << endl;
            rem=k%larg;
            k/=larg;
            if(rem>0) k++;
            a=0; b=0; j=0;
            if(tt<10)
            {
                if(k<4) {a=1; b=k;}
                else if(k==4) {a=2; b=2;}
                else if(k<7) {a=3; b=2;}
                else {
                    a=2; b=2; cout << "cc"; j=1; tt--;
                }
                ffr(i,0,a) cout << mul[j]; if(a>0) j++;
                ffr(i,0,b) cout << mul[j]; if(b>0) j++;
            }


            ffr(i,0,tt){
                ffr(p,0,3) cout << mul[j]; j++;
            }
            ffr(j,j,10) cout << mul[j];
            cout << endl;
        }

    }
}
