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
// freopen("input.in","r",stdin);
// freopen("input.out","r",stdout);
vector<pair<ll, ll>> edges[1000005];
ll carCost[100005];
bool visited[100005];
ll result = 0;
ll n, m, k;


struct Choice
{
    ll cost, node;
    bool train;
    Choice(ll f, ll s, bool t)
    {
        cost = f;
        node = s;
        train = t;
    }
    bool operator <(const Choice &a) const
    {
        if (cost == a.cost)
            return train > a.train;
        return cost > a.cost;
    }
};
priority_queue<Choice> q;
void dijkstra(ll root)
{
    carCost[root] = 0;
    q.push(Choice(0, root, 0));
    frr(1, n)
        carCost[i] = 1e18;
    while (q.size())
    {
        ll current = q.top().node;
        ll cost = q.top().cost;
        bool isTrainLine = q.top().train;
        q.pop();
        if (visited[current])
        {
            result += isTrainLine;
            continue;
        }
        visited[current] = true;
        fr(edges[current].size())
        {
            ll newNode = edges[current][i].first;
            ll newCost = edges[current][i].second + cost;
            if (newCost < carCost[newNode])
            {
                carCost[newNode] = newCost;
                q.push(Choice(newCost, newNode, 0));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll from, to, cost;
    cin >> n >> m >> k;
    fr(m)
    {
        cin >> from >> to >> cost;
        edges[from].push_back(make_pair(to, cost));
        edges[to].push_back(make_pair(from, cost));
    }
    fr(k)
    {
        cin >> to >> cost;
        q.push(Choice(cost,to,1));
    }
    dijkstra(1);
    prnt(result);
}