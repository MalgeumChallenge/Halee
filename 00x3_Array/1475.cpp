#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string n="";
    cin >> n; // 방번호

    //방번호를 출력하기 위해 필요한 세트의 개수
    //0-9 하나씩
    // 2, 3, 4, 5, 7 -> k개이면 k개의 set 필요
    // 0, 1, 8 -> 똑같이 k개이면 k개의 set 필요
    // 6, 9 -> 2k+1개 이상이면 k+1개의 set 필요.
    // 3개 2개 세트
    // 2개 1개
    // int cntsix = 0;
    int val = 0;
    int arr[10]={0};

    for(int i=0; i<n.size(); i++){
        val = int(n[i])-48;
        arr[val]++;
    }

    if((arr[6]+arr[9])%2==1){
        arr[6]=(arr[6]+arr[9])/2+1;
    } else {
        arr[6]=(arr[6]+arr[9])/2;
    }

    arr[9] = arr[6];

    int max=0;
    for(int i=0; i<10; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }

    cout << max;

}