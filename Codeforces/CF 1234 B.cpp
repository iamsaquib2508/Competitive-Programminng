#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main() {
    int n, m, x, i, start;
    set<int> st;
    vector<int> v;
    while(cin >> n >> m)
    {
        st.clear(); v.clear();
        start=0;
        ffr(i,0,n)
        {
            cin >> x;
            if(st.find(x)!=st.end()) continue;


            if(v.size()>=m) { st.erase(st.find(v[start])); start++; }

            v.push_back(x);
            st.insert(x);

        }
        cout << v.size()-start << endl;
        for(i=v.size()-1;i>=start;i--)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
