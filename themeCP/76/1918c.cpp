#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int a, b, r;
	cin >> a >> b >> r;

	vector<int> a1, b1;

	while(a > 0){
		int t = a % 2;
		a1.push_back(t);
		a/=2;
	}
	while(b > 0){
		int t = b % 2;
		b1.push_back(t);
		b/=2;
	}

	int n = a1.size(), m = b1.size();
	if(n < m){
		for(int i =0;i<m-n;i++){
			a1.push_back(0);
		}
	}else{
		for(int i =0;i<n-m;i++){
			b1.push_back(0);
		}
	}


	
	int p = max(n,m);
	int ans =0 ;
	int cur=0;
	bool first = 1;
	char cc;
	int t = r;
	for(int j = p-1;j>=0;j--){
		int c = pow(2, j);

		if(a1[j] != b1[j] && first){
			ans+=c;
			first = 0;
			if(a1[j] == 1){
				cc = 'a';
			}else{
				cc = 'b';
			}
		}
		else if(!first && a1[j] != b1[j]){
			if(n > m){
				if(b1[j]== 0 && t >= c){
					t-=c;
					ans-=c;
				}else if (b1[j] == 0){
					ans+=c;
				}else{
					ans-=c;
				}
			}else if(n < m){
				if(a1[j]== 0 && t >= c){
					t-=c;
					ans-=c;
				}else if (a1[j] == 0){
					ans+=c;
				}else{
					ans-=c;
				}
			}else if(n ==m){
				if(cc == 'a'){

				if(b1[j]== 0 && t >= c){
					t-=c;
					ans-=c;
				}else if (b1[j] == 0){
					ans+=c;
				}else{
					ans-=c;
				}
				}else{

				if(a1[j]== 0 && t >= c){
					t-=c;
					ans-=c;
				}else if (a1[j] == 0){
					ans+=c;
				}else{
					ans-=c;
				}
				}
			}
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
