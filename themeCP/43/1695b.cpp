#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	a[n] = INT_MAX;	
	int minv1 = INT_MAX, minv2=INT_MAX;
	int idx1=-1, idx2 = -1;
	for(int i = 0;i<n;i+=2){
		if(minv1 > a[i]){
			idx1 = i;
			minv1 = a[i];
		}
		if(minv2 > a[i+1]){
			idx2 = i+1;
			minv2 = a[i+1];
		}
	}

	if((n%2 == 0 && minv1 < minv2) ||(n%2 == 0 && minv1 == minv2 && idx1 < idx2)){
		cout << "Joe\n";
		return;
	}
	cout << "Mike\n";

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
