// 순환 연결 리스트 조건을 추가해주는 것이 중요

#include <iostream>
#include <list>
using namespace std;



int main(){
    int N, K;
    cin >> N >> K;

    list<int> L;
    list<int> ans;

    for(int i=0; i<N; i++){
        L.push_back(i+1);
    }

    list<int>::iterator iter = L.begin();

    // 1 2 3 4 5 6 7

    while(L.size()>0){

        // k번째 원소에 접근, iter가 end에 도달하면 다시 처음로 설정
        for(int i=0; i<K-1; i++){
            iter++;
            if(iter==L.end()){
                iter = L.begin();
            }
        }

        ans.push_back(*iter);
        iter = L.erase(iter); // 삭제한 L(iter) 값의 다음 값

        // 제거한 후 iter가 맨 끝을 가리킬 때도 맨 처음으로 이동 
        if(iter == L.end() && !L.empty()){
            iter = L.begin();
        }
    }


    cout << "<";
    for(auto it = ans.begin(); it != ans.end(); ++it){
        cout << *it;
        if(next(it)!=ans.end()){
            cout << ", ";
        }
    }
    cout << ">";
    
    

    return 0;



}