#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        int a[5003];
        int i, ans, j, lim, L, R;
        bool dirty[5003];

        mm(dirty,0);

        ffr(i,0,n) cin >> a[i];
        sort(a,a+n);

        //ffr(i,0,n) cout << a[i] << endl;
        int finans=0;
        while(k--)
        {
            i=0;
            j=0;
            ans=0;
            while(i<n)
            {
                if(dirty[i])
                {
                    i++; continue;
                }
                j=max(i,j);
                lim=a[i]+5;
                while(j<n && a[j]<=lim)
                {
                    if(dirty[j])
                    {
                        break;
                    }
                    j++;
                }
                int temp=j-i;
                //cout << temp << " hello\n";
                if(ans<temp)
                {
                    L=i; R=j;
                    //cout << L << " L R " << R << endl;
                    ans=temp;
                }
                i++;
            }

            ans=(R-L);
            //cout << ans << " ans\n";
            finans+=ans;
            ffr(i,L,R) dirty[i]=1;
            if(finans==n) break;
        }
        cout << finans << endl;
    }
    return 0;
}
