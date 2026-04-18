#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	vector<int> vec;
	int been=0;
	for(int i =0;i<n;i++){
		if(vec.size() == 0 || (!been && vec.back() <= a[i]) || (been && vec[0] >= a[i] && a[i] >= vec.back())){
			vec.push_back(a[i]);
			cout << 1;
		}else{
			if(vec[0] >= a[i] && !been){
				been = 1;

				vec.push_back(a[i]);
				cout << 1;
			}else{
				cout << 0 ;
			}
		}

	}
	
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
