#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int abc[3][n];
	for(int i =0;i<3;i++){
		for(int j =0;j<n;j++){
			cin >> abc[i][j];
		}
	}
	int sum = 0 ;
	for(int i =0;i<n;i++){
		sum+=abc[0][i];
	}
	int req = (sum%3)? sum/3+1:sum/3;
	map<int,pair<int,int>> ans;
	for(int i =0;i<3;i++){
		for(int j =0;j<3;j++){
			if(i == j) continue;
			for(int k = 0;k<3;k++){
				if(k == i || k == j) continue;
				
				int sum1 = 0;
				int l1 = 0;
				int r1 = 0;
				for(int v = l1;v<=n;v++){
					if(sum1 >= req){
						r1=v-1;
						break;
					}
					if(v < n)
					sum1+=abc[i][v];
				}
				if(sum1 < req ) continue;

				int sum2 = 0;
				int l2 = r1+1;
				int r2 = r1+1;
				for(int  v= l2;v<=n;v++){ 
					if(sum2 >= req){ 
						r2=v-1;
						break;
					}
					if(v<n)
					sum2+=abc[j][v];
				}
				if(sum2 < req) continue;

				int sum3 = 0;
				int l3 = r2+1;
				int r3 = r2+1;
				for(int v =l3;v<n;v++){
					if(sum3 >= req){
						r3=v;
						break;
					}
					sum3+=abc[k][v];
				}
				if(sum3 < req) continue;
				r3 = n-1;
				ans[i] = {l1, r1};
				ans[j] = {l2, r2};
				ans[k] = {l3, r3};
			}
		}
	}
	if(ans.size() == 0){ 
		cout << -1 << '\n';
		return;
	}

	for(auto &[x,y]:ans){ 
		cout << y.first+1 << " " << y.second+1 << ' ';
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	
	while(tc--) solve();
}
