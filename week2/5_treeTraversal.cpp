#include <iostream>
#include<vector>
using namespace std;

// level에 따라  [i][3]  

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
//             21
// 22 23 24 25 26 0 0


// 전위 순회-> 1 2 4 3 5 6 10 루트 왼쪽 오른쪽
int size = 0;
vector<char> temp[26];

int findVal(char arr[][3], int size, char target){
    for(int i=1; i<=size; i++){
        if(arr[i][1]==target) return i;
        // for(int j=1; j<=3; j++){
        //     cout <<"j" << " ";
        //     if(arr[i][j] == target){
        //         cout << "found!\n";
        //         return i;
        //     } 
        // }
    }
}

void preorder(char arr[][3], int idx, int size){
    int left;

    cout << arr[idx][1];
    
    if(idx<=size){
        // char left_val = ;s

        left = findVal(arr, size, arr[idx][2]); //index
        preorder(arr, left , size);

        int right= findVal(arr, size, arr[idx][3]);
        preorder(arr, right, size);
    }

}

// 왼쪽 루트 오른쪽
void inorder(char arr[][3], int idx, int size){ 
    
    if(idx<=size){
        // char left_val = ;

        int left = findVal(arr, size, arr[idx][2]); //index
        inorder(arr, left , size);
        cout << arr[left][1];

    } else cout << arr[idx][1];


    if(idx<=size){
        int right= findVal(arr, size, arr[idx][3]);
        inorder(arr, right, size);
        cout << arr[right][1];

    }





}


// 왼쪽 루트 오른쪽
void postorder(char arr[][3], int idx, int size){ 
    
    if(idx<=size){
        // char left_val = ;

        int left = findVal(arr, size, arr[idx][2]); //index
        postorder(arr, left , size);

        int right= findVal(arr, size, arr[idx][3]);
        postorder(arr, right, size);
    }
    cout << arr[idx][1];



}



int main(){
    int size = 0;

    // char arr[26] = {'0'};

    cin >> size;
    char arr[size][3] = {'0'};

    for(int i=1; i<=size; i++){
        for(int j=1; j<=3; j++){
            cin >> arr[i][j];
        }
    }

    preorder(arr, 1, size);
    cout << "\n";

    inorder(arr, 1, size);
    cout << "\n";

    postorder(arr, 1, size);




    // for(int i=1; i<=size*3; i++){
    //     cin >> arr[i];
    // }

    // preorder(arr, 1, 7*size);

    // for(int i=0; i<size; i++){
    //     cout << temp->at(i);
    // }

}