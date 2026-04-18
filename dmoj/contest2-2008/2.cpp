#include <bits/stdc++.h>


using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int a[n+1]; 

	for(int i =0;i<n+1;i++) a[i] = i;
	int cnt = 0;
	for(int i =2;i<=n;i++){
		if(a[i] == 0) continue;
		bool found = 0;
		int num = -1;
		for(int j = i;j<=n;j+=i){
			if(a[j] == 0) continue;
			cnt++;
			a[j] = 0;
			if(cnt == k){num=j;found=1; break;}
			
		}

		if(found){
			cout << num;
			break;
		}
		
	}
}
