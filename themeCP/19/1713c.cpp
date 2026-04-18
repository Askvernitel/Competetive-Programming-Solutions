#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int nexts(int x){
	double s = sqrt(x);

	return (s == int(s))? s+1:s+2;
}
void solve(){
	int n;
	cin >> n;
	

	int s = nexts(n);
	int ans[n];	
	memset(ans, 0,sizeof(ans));
	int cur = n-1;
	while(cur >= 0){

		while((s*s)-cur > n-1 || ans[(s*s)-cur]){
			s--;
		}
		ans[(s*s)-cur] = cur;
		cur--;
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
