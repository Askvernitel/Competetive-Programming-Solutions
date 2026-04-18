#include <bits/stdc++.h>

using namespace std;
void solve(){
	int m, s;
	cin >> m >> s;
	int a[101];
	memset(a, 0, sizeof(a));
	int last = 0;
	for(int i =0;i<m;i++){
		int num;
		cin >> num;
		last = max(num,last);
		a[num]=1;
	}
	int sum = 0;
	for(int i =1;i<=last;i++){
		if(a[i] == 0) sum+=i;
	}
	for(int i =last+1;i<=101;i++){
		if(sum == s){
			cout << "YES\n";
			return;
		}
		if(sum > s){
			cout << "NO\n";
			return;
		}
		sum+=i;
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
