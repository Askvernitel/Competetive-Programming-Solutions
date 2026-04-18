#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int cur = 1;
	int arr[n][m];
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			arr[i][j]=cur;
			cur++;
		}
	}
	{	
		int i = 0;
		int u = 0;
		for(int j = 1;j<n;j+=2){
			for(int k =0;k<m;k++){
				swap(arr[i][k], arr[j][k]);
			}
			i++;
			u=j;
		}
		if(m%2){
		for(int j=0;j<i;j++){
			int p = arr[j][0];
			for(int k =0;k<m;k++){
				arr[j][k]=arr[j][k+1];
			}
			arr[j][m-1]=p;
		}
		}
		int c = u-1;
		for(int j = 0;j<m;j++){
			swap(arr[c][j], arr[i][j]);
		}
	}
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
