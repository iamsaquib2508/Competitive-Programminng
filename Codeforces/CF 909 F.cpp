




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

int pp[100005];

void ff(int n)
{
    if(n==0) return;
    int x, cur, nn, i;
    x=1;
    ffr(i,1,n)
    {
        x+=x;
        if(x>n)
        {
            x/=2; break;
        }
        else if(x==n) break;
    }
    cur=x;
    nn=cur+cur-1;
    ffrr(i,cur,n)
    {
        pp[i]=nn-i;
        pp[nn-i]=i;
    }
    ff(nn-i);
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int n, i, x, cur, end, cc;
    
    cin >> n;
    if(n%2==1) cout << "NO\n";
    else
    {
        cout << "YES\n";
        ff(n);
        ffr(i,1,n) cout << pp[i] << " "; cout << pp[n] << endl;
    }
    
    if(n<6)
    {
        cout << "NO\n"; return 0;
    }
    if(n==6)
    {
        cout << "YES\n3 6 2 5 1 4\n"; return 0;
    }
    //cout << "YES\n5 3 2 6 7 4 1";
    if(n==7)
    {
        
        cout << "YES\n5 3 2 6 7 4 1\n"; return 0;
    }
    
    x=1;
    ffr(i,1,n)
    {
        x+=x;
        if(x>n)
        {
            x/=2; break;
        }
        else if(x==n) 
        {
            cout << "NO\n"; return 0;
        }
    }
    cout << "YES\n5 3 2 6 7 4 1 ";
    cc=8;
    while(cc<x)
    {
        end=cc+cc-1;
        cout << end << " ";
        ffrr(i,cc+1,end)
        {
            cout << i-1 << " ";
        }
        cc=i;
    }
    end=n;
    cout << end << " ";
    ffr(i,cc+1,end)
    {
        cout << i-1 << " ";
    }
    cout << end-1 << endl;
    

    //fix size
    return 0;
}
