




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
    string in[6]={"red","green","blue","purple","yellow","orange"};
    string out[6]={"Reality","Time","Space","Power","Mind","Soul"}, a;
    int i, n, arr[6]={0,0,0,0,0,0};

    cin >> n;
    ffr(i,0,n)
    {
        cin >> a;
        if(a=="red") arr[0]=1;
        if(a=="green") arr[1]=1;
        if(a=="blue") arr[2]=1;
        if(a=="purple") arr[3]=1;
        if(a=="yellow") arr[4]=1;
        if(a=="orange") arr[5]=1;

    }
    cout << 6-n << endl;
    ffr(i,0,6)
    {
        //cout << arr[i] << " ";
        if(arr[i]==0) cout << out[i] << endl;
    }





    return 0;
}
