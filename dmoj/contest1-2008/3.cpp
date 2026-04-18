#include <bits/stdc++.h>

using namespace std;
int arr[101][101];
int main(){
	int r, c;

	cin >> r >> c;

	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			char ch; cin >> ch;
			if(ch == 'x'){
				arr[i][j] = 1;
			}else{
				arr[i][j] = 0;
			}
		}
	}
	vector<array<int,3>> ans;
	for(int i =0;i<r;i++){

		for(int j=0;j<c;j++){
			if(arr[i][j]){
				int cnt1=0, cnt2 =0;
				for(int k = j;k<c;k++){
					if(arr[i][k]) cnt1++;
					else break;
				}
				for(int k = i;k<r;k++){
					if(arr[k][j]) cnt2++;
					else break;
				}
				ans.push_back({i,j,min(cnt1,cnt2)});

			}
		}
	}
	int n = ans.size();
	int idx1=0, idx2 = 0;
	for(int i=0;i<n;i++){
		int tmp[101][101];
		for(int t = 0;t<r;t++){
			for(int u =0;u<c;u++){
				tmp[t][u] = arr[t][u];
			}
		}

		int pos = 1;
		for(int j =i+1;j<n;j++){
			pos =1;
			int p1=ans[i][0],p2=ans[i][1],p3=ans[i][2];
			for(int k = p1; k<p1+p3;k++){
				for(int v = p2;v<p2+p3;v++){
					tmp[k][v] = 0;
				}
			}

			int k1=ans[j][0],k2=ans[j][1],k3=ans[j][2];

			for(int k = k1; k<k1+k3;k++){
				for(int v = k2;v<k2+k3;v++){
					tmp[k][v] = 0;
				}
			}
			for(int k=0;k<r;k++){

				for(int v=0;v<c;v++){
				
					if(tmp[k][v] == 1){pos = 0; break;}
				}
			}
			for(int t = 0;t<r;t++){
				for(int u =0;u<c;u++){
					tmp[t][u] = arr[t][u];
				}
			}
	
			if(pos){idx1=i; idx2=j; break;}


		}
		if(pos) break;
		}

	cout<< ans[idx1][0]+1 << " " << ans[idx1][1]+1 << " " << ans[idx1][2] << '\n';
	cout << ans[idx2][0]+1 << " " << ans[idx2][1]+1 << " " << ans[idx2][2] << '\n';




}
