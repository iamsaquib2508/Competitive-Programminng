




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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; int cur, sz, i, two, arr[200], cnt=0;
    
    mm(arr,0);

    cin >> s;
    sz=s.size();
    
    
    ffr(i,0,sz)
    {

        if(arr[s[i]]==0)
        {
            cnt++;
        }
        arr[s[i]]++;
    }
    
    if(cnt==1 || cnt>4)
    {
        cout << "No\n";
    }
    else
    {
        if(cnt==2)
        {

            two=0;
            ffr(i,0,26)
            {
                cur=i+'a';
                
                if(arr[cur]>1) two++;
            }
            if(two==2) cout << "Yes\n";
            else cout << "No\n";
        }
        else if(cnt==3)
        {
            two=0;
            ffr(i,0,26)
            {
                cur=i+'a';

                if(arr[cur]>1) two++;
            }
            if(two>0) cout << "Yes\n";
            else cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    
    
    //fix size
    return 0;
}
