#include <bits/stdc++.h>
using namespace std;

int arr[101][3];
int display[3];
int ind_conv(string cow){
    if(cow == "Bessie"){
        return 0;
    }else if(cow == "Elsie"){
        return 1;
    }
    return 2;
    
}
bool compare(int prev_display[], int now_display[]){
    int ind_prev[3]={0,0,0};
    int maxv = max({prev_display[0], prev_display[1], prev_display[2]});
    
    for(int i = 0;i<3;i++){
        if(prev_display[i] == maxv){ 
            ind_prev[i] = 1;
        }
    }
    maxv = max({now_display[0], now_display[1], now_display[2]});
    int ind_now[3]={0,0,0};
    for(int i =0;i<3;i++){
        if(now_display[i] == maxv){ 
            ind_now[i] = 1;
        }
    }
    for(int i =0;i<3;i++){
        if(ind_now[i] != ind_prev[i]){
            return true;
        }
    }
    return false;
}
int main(){ 
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;

    cin >> n;
    for(int i = 0;i<n;i++){
        int day;
        string cow;
        string output;
        
        cin >> day >> cow >> output;
        
        if(output[0] == '+'){ 
            arr[day][ind_conv(cow)]+=stoi(output.substr(1,output.size()-1));
        }else{ 
            arr[day][ind_conv(cow)]-=stoi(output.substr(1,output.size()-1));
        } 
    }
    int ans = 0;
    for(int i = 0;i<=100;i++){
        int new_display[3] = {display[0]+arr[i][0], display[1]+arr[i][1], display[2]+arr[i][2]};
        if(compare(display, new_display)){ 
            ans++;
        }
        for(int i =0;i<3;i++) display[i] = new_display[i];
        
    }
    cout << ans;
}
