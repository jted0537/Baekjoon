#include<iostream>

using namespace std;

int arr[7] = {3,7,2,8,5,9,1};
int buffer[7] = {};

int max_idx(int arr[], int a, int b) {
    if(arr[a] > arr[b]) return a;
    else return b;
}

int min_idx(int arr[], int a, int b) {
    if(arr[a] > arr[b]) return b;
    else return a;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
버블정렬(Bubble sort)
주의사항 : 반복문을 돌 때 len-1까지만 돌아도 모두 정렬이 된다.
역순으로 정렬이 되어있는 경우 len-2만큼 반복을 하게 돠면 한 element가 정렬리 되지 않는다.
오름차순, 내림차순은 조건문안에서 등호를 바꿔줌으로써 변경가능하다.
시간복잡도 O(n^2)
*/
void bubble_sort(int arr[], int len, bool ascending) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1; j++) {
            if(ascending) {
                // 오름차순
                // 보고있는 값보다 다음값이 작다면 교환
                if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
            }
            else {
                // 내림차순
                // 보고있는 값보다 다음값이 크다면 교환
                if(arr[j] < arr[j+1]) swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/*
선택정렬(Selection sort)
주의사항 : 인덱스를 통해 접근을 해야 나중에 swap할때 편리하다. 그저 작은값, 큰값만 저장하면 인덱스 접근이 불편하다.
오름차순, 내림차순은 최솟값을 구하냐 최댓값을 구하냐에 따라 달라진다.
시간복잡도 O(n^2)
*/
void selection_sort(int arr[], int len, bool ascending) {
    for(int i = 0; i < len; i++) {
        int idx = i;
        for(int j = i; j < len; j++) {
            // 오름차순
            // 최솟값을 찾아서 현재 보고 있는 값과 교환
            if(ascending) idx = min_idx(arr, idx, j);
            // 내림차순
            // 최댓값을 찾아서 현재 보고 있는 값과 교환
            else idx = max_idx(arr, idx, j);
        }
        swap(&arr[i], &arr[idx]);
    }
}

/*
삽입정렬(Insertion sort)
주의사항 : 삽입정렬은 정렬기준에 따라 자기보다 큰 걸 만나면 이동을 종료하거나 자기보다 작은 걸 만나면 이동을 종료한다.
즉, 본인이 갈 수 있는 최선의 자리까지 선형 이동을 한다고 볼 수 있다.
오름차순, 내림차순은 값 비교를 할 때 등호를 바꿔줌으로써 결정가능하다.
시간복잡도 O(n^2)
*/
void insertion_sort(int arr[], int len, bool ascending) {
    for(int i = 1; i < len; i++) {
        int j = i - 1;
        int val = arr[i];
        if(ascending) {
            // 오름차순
            // 자기보다 작은 걸 찾거나, 인덱스의 마지막까지 갈 경우 이동을 종료한다.
            while(j >= 0 && arr[j] > val) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else {
            // 내림차순
            // 자기보다 큰 걸 찾거나, 인덱스의 마지막까지 갈 경우 이동을 종료한다.
            while(j >= 0 && arr[j] < val) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = val;
    }
}

/*
퀵 정렬(Quick sort)
분할정복 방식
주의사항 : 함수가 한 번 호출될 때마다 피봇의 위치가 정해짐.
그 때마다 st가 ed까지 다가가기전에는 큰값과 작은값의 위치를 swap, 모든 애들이 정상적으로 정렬이 되었을 때는 피봇과 ed를 swap.
시간복잡도 O(nlogn) 그러나, 최악의 경우 O(n^2)의 시간복잡도를 가짐.
최악의 경우는 재귀에서 1과 n-1로 나뉘는 경우를 의미함.
즉, 이미 오름차순이거나 내림차순일 경우 최악의 파티션구조를 가짐.
빠른 이유는 불필요한 데이터의 이동을 줄이고, 먼 거리의 데이터를 교환하며, 한 번 결정된 기준은 추후 연산에서 제외되기 때문이다.
*/
void quick_sort(int arr[], int start, int end, bool ascending) {
    if(start >= end) return;
    int pivot = start;
    int st = start + 1;
    int ed = end;
    while(st <= ed) {
        if(ascending) {
            // 오름차순
            // st는 피봇보다 큰값의 위치를, ed는 피봇보다 작은값의 위치를 찾아냄.
            while(arr[pivot] > arr[st]) st++;
            while(arr[pivot] < arr[ed]) ed--;
        }
        else {
            // 내림차순
            // st는 피봇보다 작은값의 위치를, ed는 피봇보다 큰 값의 위치를 찾아냄.
            while(arr[pivot] < arr[st]) st++;
            while(arr[pivot] > arr[ed]) ed--;
        }

        if(st <= ed) {
            // 평소에는 피봇을 기준으로 큰값과 작은값의 교환만 진행
            swap(&arr[st], &arr[ed]);
        }
        else {
            // 끝날때는 마지막으로 제일 작은값(혹은 큰 값)과 pivot의 위치를 교환
            swap(&arr[pivot], &arr[ed]);
        }
    }
    quick_sort(arr, start, ed - 1, ascending);
    quick_sort(arr, ed + 1, end, ascending);
}

/*
병합 정렬(Merge sort)

*/
void merge_sort(int arr[], int start, int end) {
    if(start >= end) return;
    int center = (start + end) / 2;
    merge_sort(arr, start, center);
    merge_sort(arr, center + 1, end);

    int buffer_idx = 0;
    int i, j = 0;
    int k = start;
    for(i = start; i < center; i++) {
        buffer[buffer_idx++] = arr[i];
    }

    while(i < end && j < buffer_idx) {
        if(buffer[j] < arr[i]) {
            
        }
    }

}


int main() {

    //bubble_sort(arr, 7, true);
    //selection_sort(arr, 7, true);
    //insertion_sort(arr, 7, true);
    quick_sort(arr, 0, 6, true);
    for(int i = 0; i < 7; i++) cout << arr[i] << " ";
    cout << endl;
}