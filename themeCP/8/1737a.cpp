#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int arr[26];
	memset(arr, 0, sizeof(arr));
	int u = n/k;
	for(int i =0;i<n;i++){
		char ch;
		cin >> ch;
		arr[ch-'a']++;
	}
	
	for(int i = 0;i<k;i++){
		int p = u;
		int j = 0;
		char mex = 'z';
		int found = 0;
		while(p >0 && j < 26){
			if(arr[j] == 0){ 
				found = 1;
				mex = min((int)mex, (int)'a'+j);
			}else{ 
				if(!found) mex = (int)'a'+j +1;
				arr[j]--;
				p--;
			}
			j++;
		}
		cout << mex << "";
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
		
	
}
