#include<iostream>
using namespace std;
int n, k=0;
int x, y;
int cnt = 0;
int temp[5000];
// min-heap을 만족하도록 
void heapify(int a[], int n, int idx){
    int least = idx;
    int l = idx*2;
    int r = idx*2+1;
    if(r<=n && a[least]>a[r]) least = r;

    if(l<=n && a[least]>a[l]) least = l;

    if(least!=idx){
        swap(a[idx], a[least]);
        
        cnt++;
        if(cnt==k){
            x= idx;
            y = least;
            // cout << k << "  hereL" << y << endl;
            for(int j=1; j<=n; j++){
                temp[j] = a[j];
            }
        } 
        heapify(a,n,least);
    }
}


void build_min_heap(int a[], int n){
    for(int i=n/2; i>=1; i--){
        heapify(a,n,i);
    }
}

void heap_sort(int a[], int n){
    build_min_heap(a, n);
    
    for(int i=n; i>1; i--){
        swap(a[1], a[i]);  
        cnt++;
        if(cnt==k){
            x= 1;
            y= i;
            cout << "hereL: " <<  y << endl;
            // cout << 1 << " " << i << "\n";
            for(int j=1; j<=n; j++){
                temp[j] = a[j];
            }
        } 
        heapify(a, i-1, 1);
    }
}


int main(){
    // int n, k;
    int arr[5000];
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    
    heap_sort(arr, n);

    if(cnt>k){
        cout << temp[x] << " " << temp[y] << "\n";
        for(int j=1; j<=n; j++){
            cout << temp[j] << " ";
        }
    }  else {
        cout << -1;
    }
    


    return 0;

}