#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
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
void luckNumbers(ll num);
vector<long>vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n;inp(n);
    luckNumbers(0);
    sort( vec.begin(), vec.end() );
    int index=-1;
    fr(vec.size()){
        if(vec[i]==n){
            index=i;
            break;
        }
    }
    prnt(index);
    }
void luckNumbers(ll num){
    if(num>1000000000)return;
    vec.push_back(num);
    luckNumbers(num*10l+4l);
    luckNumbers(num*10l+7l);
}