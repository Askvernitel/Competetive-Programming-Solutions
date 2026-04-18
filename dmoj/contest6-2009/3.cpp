#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main(){
	int n ;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> hex >> a[i];
	}
	
	for(int i =0;i<n;i++){
		if(a[i] < 0x20){ 
			cout << ".";
		}else{
			cout << "-";
		}
	}
	cout << endl;
}
