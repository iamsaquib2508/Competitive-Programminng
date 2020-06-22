#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, t, a;
    s="GCIAIYRAOEINRAGRTEECRWIEMNDSVDSBEKVNNR";
    t="RESATVNEIIEINAHUIINLKVHHDTOLLLLNETTLAHA";
    a=" GCIAIYRAOEINRAGRTEECRWIEMNDSVDSBEKVNNRRESATVNEIIEINAHUIINLKVHHDTOLLLLNETTLAHA";
    cout << a.size()<< ' ' <<s.size()<<' ' <<t.size() << endl;
    string res="";
    res+=a[1];
    res+=a[8];
    res+=a[15];
    res+=a[22];
    res+=a[29];
    res+=a[36];
    res+=a[43];
    res+=a[50];
    res+=a[57];
    res+=a[64];
    res+=a[71];
    cout << res << endl;
    return 0;
}
