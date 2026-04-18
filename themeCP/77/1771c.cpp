#include <bits/stdc++.h>
#define int long long
using namespace std;

int p[100001];
vector<int> pms;
int mod = 1e9+7;
int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(a%b,a);
}


void calc(){
	
	memset(p, 1,sizeof(0));
	for(int i =2;i<100001;i++){
		if(!p[i]) continue;
		
		for(int j = i+i;j<100001;j+=i){
			p[j] = 0;
		}
	}

}
void fill(){ 
	for(int i=2;i<100001;i++){
		if(!p[i]) continue;
		pms.push_back(p[i]);
	}
}
void solve(){
	int n;
	cin >> n;
	int pos = 0;	
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];


	}
}
signed main(){
	calc();
	int tc;
	cin >> tc;
	while(tc--) solve();
}
