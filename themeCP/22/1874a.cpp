#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
int a[100], b[100];
int tc;
int sum(){
	int res = 0;
	for(int i= 0;i<n;i++){
		res+=a[i];
	}
	return res;
}
void solve(){
	cin >> n >> m >> k;
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<m;i++) cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);	
	
	if(!(k%2)){
		if(b[m-1] < a[0]){
			cout << sum()-a[n-1]+b[0];
		}else if(b[m-1] < a[n-1]){
			cout << sum()-a[0]+b[m-1]+min(b[0],a[0])-a[n-1];
		}else{
			cout << sum()-a[0]+min(b[0],a[0]);
		}
	}else if(k%2){
		cout << max(sum()-a[0]+b[m-1], sum());
	}
	cout << '\n';

}
signed main(){
	cin >> tc;
	while(tc--){
		solve();
	}
}
