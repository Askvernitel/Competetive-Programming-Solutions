#include <bits/stdc++.h>

using namespace std;

int main(){
	int r,c;
	cin >> r >> c;
	
	int teams[10];
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			char cur; 
			cin >> cur;
			if(cur != 'F' && cur != 'S' && cur !='.'){
				teams[cur-'0']=j;
			}
		}
	}
	for(int i = 1;i<10;i++){
		int place=0;
		int arr[100];
		memset(arr, 0, sizeof(arr));
		for(int j =1;j<10;j++){
			if(j == i) continue;
			if(teams[i] < teams[j]){
				if(!arr[teams[j]]){
					place++;
					arr[teams[j]]=1;
				}
			}
		}
		cout << place+1 << '\n';
	}

}
