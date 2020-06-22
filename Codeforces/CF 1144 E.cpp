#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

void pn(int* arr, int ko)
{
    int i;
    ffr(i,0,ko)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

}

int main()
{
    int n; string s, t;
    int ans[200005], res[200005];
    while(cin >> n)
    {
        cin >> s >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());

        int carry=0, tmp, i;
        ffr(i,0,n)
        {
            tmp=s[i]-'a'+t[i]-'a'+carry;

            if(tmp>25) {tmp-=26; carry=1;}
            else carry=0;

            res[i]=tmp;
        }
        int rem=0, k=0, cur;
        if(carry>0)
        {res[i]=1; rem=carry;}

        //pn(res,n+rem);

        for(i=n-1;i>=0;i--)
        {
            cur=rem*26+res[i];
            {
                ans[k]=cur/2;
                rem=cur&1;
                k++;
            }
        }
        //pn(ans,k);

        ffr(i,0,k)
        {
            cout << (char)('a'+ans[i]) ;
        }
        cout << endl;

    }
}
