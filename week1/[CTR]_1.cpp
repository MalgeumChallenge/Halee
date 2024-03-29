// 문제) 연속해서 0이 나오지 않는 n자리 이진수를 차례대로 출력하는 프로그램을 작성

#include<iostream>
#include<string>
using namespace std;

int n; // size

void generate(string num){
    if(num.length()==n){
        cout << num << "\n";
        return;  // 얘 안 해주면 무한루프... 잊지 말기!
    }

    int lastNum = num.back()-'0';
    if(lastNum==0) generate(num+'1');
    else if(lastNum==1){
        generate(num+'0');
        generate(num+'1');
    }
}

int main(){
    cin >> n;
    for(int i=0; i<2; i++){
        string num = to_string(i);
        generate(num);
    }


}