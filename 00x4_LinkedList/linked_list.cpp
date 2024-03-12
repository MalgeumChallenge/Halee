#include<iostream>
using namespace std;

class Node{
public:
    double data; 
    Node* next; //다음 노드를 가리키는 포인터
};

class List{
public:
    List(void){
        head = NULL;
    }
    // ~List(void);
    
    bool IsEmpty(){
        return head==NULL;
    }

    Node *InsertNode(int index, double x);
    int FindNode(double x);
    int DeleteNode(double x);
    void DisplayList(void);

private:
    // 가장 맨 앞의 노드(데이터 없이 포인터만 있는 시작점)
    Node *head;
};


// 1. currNode: insert할 newNode 이전의 노드를 while문을 통해 index를 통해 찾는다.


Node *List::InsertNode(int index, double x) //index가 삽압하려는 위치, x가 데이터
{

// 1. index번째 노드를 찾는다. -> 만약 존재하지 않으면 null 반환
    
    if(index<0) return NULL;

    int nextIndex = 1;
    Node *currNode = head;

    // 현재 노드가 존재하고, 입력값 index가 1이 아닐 때(head가 아닐때)
    // head에서 부터 index에 맞는 node를 찾을 때까지(index<=nextIndex) 현재 노드를 한 칸씩 이동한다.
    while(currNode && index>nextIndex){
        currNode = currNode->next;
        nextIndex++;
    }
    
    if(index>0 && currNode==NULL){
        return NULL;
    }


// 2. 새로운 노드를 생성
    Node *newNode = new Node;
    newNode->data = x;

// 3. 노드를 맨 처음에 삽입
    if(index==0){
        newNode->next = head;
        head = newNode;
    } 
// 4. 노드를 중간이나 마지막에 삽입    
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }

    return newNode;
}



int List::FindNode(double x)
{
    Node *currNode = head;
    int currIndex = 0;

    while(currNode && currNode->data!=x){
        currNode = currNode->next;
        currIndex++;
    }

    // currNode->data == x일 때 while 탈출하므로
    if(currNode) return currIndex;

    return -1;
}


// 1. 삭제할 노드를 담을 currNode와 currNode를 가리키는 prevNode 선언
// 2. 삭제할 노드를 리스트에서 한 칸씩 이동하며 찾기
// 3. currNode(삭제할 노드)가 중간에 있을 때 또는 currNode==head일 때의 case 나누기
//    -> currNode는 존재해야하고, if prevNode else !prevNode로 케이스 분리


int List::DeleteNode(double x)
{
    Node *prevNode = NULL;
    Node *currNode = head;
    int currIndex = 0;

    while(currNode && currNode->data!=x){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    if(currNode){
        if(prevNode){
            prevNode->next = currNode->next;
            delete currNode;
        }
        // currNode 가 head일 때
        else{
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }    
    

    return -1;
}

void List::DisplayList(void)
{
}


int main(){
    // Node *A;
    // Node *B;
    // Node *C;
    // A->data = 0;
    // A->next = B;

    // B->data = 1;
    // B->next = C;

    // C->data = 2;
    // C->next = A;

    double A, B, C;

    List list;
    list.InsertNode(0, A);
    list.InsertNode(1, B);
    list.InsertNode(2, C);
    cout << list.FindNode(C);


    

}
