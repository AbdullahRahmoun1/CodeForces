#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back 
const int M=100001;
int n,m,x,y,z,a,b;
vector<vector<pair<int,int> > >g;
bool vis[M];
ll cost[M];
ll dijkstra(int a,int b){
    priority_queue<pair<ll,int> >q;
    q.push(make_pair(0,a));
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++)cost[i]=-1e18;
    cost[a]=0;
    while(!q.empty()){
        int currentnode=q.top().second;
        ll currentcost=q.top().first;
        q.pop();
        if(vis[currentnode])continue;
        cost[currentnode]=currentcost;
        vis[currentnode]=true;
        if(currentnode==b){
            return -currentcost;
        }
        for(int i=0;i<(int)g[currentnode].size();i++){
 
            int newnode=g[currentnode][i].first;
            int edgeweight=-g[currentnode][i].second;
            if(edgeweight+currentcost>cost[newnode]){
 
                cost[newnode]=edgeweight+currentcost;
                q.push(make_pair(cost[newnode],newnode));
 
            }
        }
    }
    return -1;
 
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		g.clear();
		g.resize(n+1);
		for(int i=0;i<m;i++){
			cin>>x>>y>>z;
			g[x].push_back(make_pair(y,z));
		}
		cin>>a>>b;
		ll ans=dijkstra(a,b);
        if(ans==-1)cout<<"NO\n";
        else cout<<ans<<endl;
	}
	return 0;
} 