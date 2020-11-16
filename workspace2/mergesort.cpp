#include<cstdio>

int arr[10] = {9,8,7,6,5,4,3,2,1,0};
void merge(int a[], int left, int right, int mid){
    int i = left;
    int j = mid+1;
    int k = left;
    int temp[10];
    while(i<=mid && j <=right){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    if(i > mid){
        for(int t=j; t<=right; t++) temp[k++] = a[t];
    }
    else{
        for(int t=i; t<=mid; t++) temp[k++] = a[t];
    }   
    for(int t=left; t<=right; t++) a[t] = temp[t];
}

void mergesort(int a[], int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(a,left,right,mid);
}

int main(){
    mergesort(arr,0,9);
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}