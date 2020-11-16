#include<iostream>

using namespace std;

int arr[10] = {3,8,7,1,9,5,2,0,4,6};


void merge(int arr[],int left, int right, int mid){
    int temp[12] = {0, };
    int i = left;
    int j = left;
    int k = mid+1;
    while(i<=mid && k<=right){
        if(arr[i]<arr[k]) temp[j++] = arr[i++];
        
        else temp[j++] = arr[k++];
    }

    if(i > mid) for(int l = k; l<=right; l++) temp[j++] = arr[l];
    else if(k > right)for(int l = i; l<=mid; l++) temp[j++] = arr[l];
    for(int i =left; i<=right; i++) arr[i] = temp[i];
}

void mergesort(int arr[], int start, int end){
    if(start>=end) return;
    int mid= (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, end, mid);
    
}

void quicksort(int arr[], int start, int end){
    if(start >= end) return;
    int i = start+1;
    int j = end;
    int key = start;
    while(i<=j){
        while(arr[key] > arr[i]) i++;
        while(arr[key] < arr[j] && j>start) j--;
        if(i > j){
            int temp = arr[j];
            arr[j] =arr[key];
            arr[key] = temp;
        }
        else{
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    quicksort(arr, start, j-1);
    quicksort(arr, j+1, end);
}


int main(){
    mergesort(arr, 0, 9);
    //quicksort(arr,0,9);
    for(int i = 0; i<10; i++)printf("%d ", arr[i]);
}