#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define null NULL;
#define PI 3.14159265358979323846
#define inp cin>>
#define prt cout<<
#define sho(v) cout<<#v<<" = "<<v;
#define prnt(mys) cout<<mys<<endl
#define prts(mys) cout<<mys<<" "
#define wl while(true)
#define frit(stc) for (auto it=stc.begin();it!=stc.end();++it)
#define frr(ii,n) for (int i=ii;i<=n;i++)
#define fr(n) for (int i=0;i<n;i++)
#define afrr(ii,n) for (int i=ii;i>=n;i--)
#define afr(n) for (int i=n-1;i>=0;i--)
#define jfrr(jj,n) for (int j=jj;j<=n;j++)
#define jfr(n) for (int j=0;j<n;j++)
#define jafrr(jj,n) for (int j=jj;j>=n;j--)
#define jafr(n) for (int j=n-1;j>=0;j--)
#define tolowercase(s) for_each(s.begin(),s.end(),[](char &c){c=tolower(c);});
#define touppercase(s) for_each(s.begin(),s.end(),[](char &c){c=toupper(c);});
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
//freopen("input.in","r",stdin);
//freopen("input.out","r",stdout);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;inp(t);
    while(t--){
        int n;inp(n);
        map<int,int>map1;
        fr(n){
            int input;inp(input);
            map1[input]++;
        }
        n=map1.size();
        int candies[n];
        int j=0;
        for (auto i = map1.begin(); i != map1.end(); ++i,j++) {
            candies[j]=i->second;
        }
        sort(candies,candies+n);
        int sum=0;
        sum+=candies[n-1];
        afr(n-1){
            if(candies[i]>=candies[i+1]){
                candies[i]=candies[i+1]-1;
                if(candies[i]==0)break;
            }
            sum+=candies[i];
        }
        prnt(sum);
    }
    
    }