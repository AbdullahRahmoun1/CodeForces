#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define null NULL;
#define PI 3.14159265358979323846
#define inp cin >>
#define prt cout <<
#define sho(v) cout << #v << " = " << v;
#define prnt(mys) cout << mys << endl
#define prts(mys) cout << mys << " "
#define wl while (true)
#define frit(stc) for (auto it = stc.begin(); it != stc.end(); ++it)
#define frr(ii, n) for (int i = ii; i <= n; i++)
#define fr(n) for (int i = 0; i < n; i++)
#define afrr(ii, n) for (int i = ii; i >= n; i--)
#define afr(n) for (int i = n - 1; i >= 0; i--)
#define jfrr(jj, n) for (int j = jj; j <= n; j++)
#define jfr(n) for (int j = 0; j < n; j++)
#define jafrr(jj, n) for (int j = jj; j >= n; j--)
#define jafr(n) for (int j = n - 1; j >= 0; j--)
#define tolowercase(s) for_each(s.begin(), s.end(), [](char &c) { c = tolower(c); });
#define touppercase(s) for_each(s.begin(), s.end(), [](char &c) { c = toupper(c); });
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
/*
    dist=32
    A=65
    Z=90
    [\]^_`
    a=97
    z=122
    tonumber-48
*/
int main()
{
    int n;
    inp n;
    pair<string, ll> inpt[n];
    fr(n)
    {
        inp inpt[i].first;
        inp inpt[i].second;
    }
    map<string, ll> m;
    fr(n)
    {
        string s = inpt[i].first;
        ll sc = inpt[i].second;
        m[s] += sc;
    }
    ll mx = LLONG_MIN;
    vector<string> v;
    for (auto p : m)
    {
        if (p.second == mx)
        {
            v.push_back(p.first);
            continue;
        }
        if (p.second > mx)
        {
            v = vector<string>();
            v.push_back(p.first);
            mx = p.second;
            continue;
        }
    }

    if (v.size() == 1)
    {
        prnt(v[0]);
    }
    else
    {
        m = map<string, ll>();
        fr(n)
        {
            string s = inpt[i].first;
            ll sc = inpt[i].second;
            m[s] += sc;
            if (m[s] >= mx)
            {
                fr(v.size())
                {
                    if (v[i] == s)
                    {
                        prnt(s);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
