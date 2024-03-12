#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l = {1,2};
    list<int>::iterator t = l.begin();
    l.push_front(10); //10 1 2
    cout << *t << endl;
    l.push_back(5); // 10 1 6 2 5
    l.insert(t,6);
    t++; // t는 6을 가리킴
    t = l.erase(t); // t는 삭제된 5를 가리킴
    cout << *l.end() << "\n";

    for(auto i : l) cout << i << ' ';
    cout << "\n";

    for(list<int>::iterator it = l.begin(); it!=l.end(); it++){
        cout << *it << ' ';
    }

}