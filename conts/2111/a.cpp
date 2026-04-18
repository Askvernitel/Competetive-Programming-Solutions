#include <bits/stdc++.h>

using namespace std;
void solve(){
	int x;
	cin >> x;
	
	int arr[3] = {0,0,0};
	int res=0;
	while(min({arr[0],arr[1], arr[2]}) < x){ 
		int mni = 0;
		int minv=INT_MAX;
		for(int i = 0;i<3;i++){
			if(minv > arr[i]){ 
				mni=i;
				minv=arr[i];
			}
		}
		int mni1= 0;
		int minv1=INT_MAX;
		for(int i =0;i<3;i++){
			if(i==mni) continue;	
			if(minv1 > arr[i]){
				mni1=i;
				minv1=arr[i];
			}
		}

		arr[mni]=2*minv1+1;
		res++;
	}
	cout << res << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
