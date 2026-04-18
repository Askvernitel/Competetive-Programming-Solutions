#include <bits/stdc++.h>

using namespace std;
int const N = 10000;
int arr[N];

int main(){
	memset(arr, 0, sizeof(arr));
	int n, k;
	cin >> n >> k;
	int a[n], b[k];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<k;i++){
		cin >> b[i];
	}
	arr[0]=1;
	for(int i =0;i<N;i++){
		if(!arr[i]) continue;
		for(int j=0;j<n;j++){
			if(i + a[j] < N)
			arr[i+a[j]]=1;	
		}
	}

	for(int i =0;i<k;i++){
		int pos = 0;
		for(int j =0;j<=10;j++){
			if(arr[(j*360) + b[i]]){
				pos = 1;
				break;
			}
		}
		
		if(b[i] ==0) pos =1;
		if(pos){
			cout << "YES\n"; 
		}else{
			cout << "NO\n";
		}
	}
}
