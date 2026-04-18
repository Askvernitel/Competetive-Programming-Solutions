#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	string a[3][n];
	multiset<string> ms;
	for(int i =0;i<3;i++){
		for(int j =0;j<n;j++){
			cin >> a[i][j];
			ms.insert(a[i][j]);
		}
	}
	int cnt[3]={0,0,0};
	for(int j =0;j<3;j++){
		for(int i= 0;i<n;i++){
			if(ms.count(a[j][i])==1){ 
				cnt[j]+=3;
			}else if(ms.count(a[j][i])==2){
			
				cnt[j]++;
			}
		}
	}
	cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();


}
