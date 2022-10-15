#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printer(int len, int*arr) {
    for(int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* random_array(int n, int m, int len) { //[n,m]
    int*arr =(int*)malloc(len*sizeof(int));
    for(int i = 0; i<len; ++i){
        arr[i] = n + rand()%(m+1-n);
    }
    return arr;
}

void swapR(int *minind, int *maxind) {
    int tmp = *maxind;
    *maxind = *minind;
    *minind = tmp;
    //printf("%d %d", mini, maxi);
}

int* build_arr(int* str, int len, int*size) {
    // 4 2 4 3 4 4 1 5 (int*)malloc(len * sizeof(int))
    int k = 0;
    int* newArr = (int*)malloc(sizeof(int));
    for(int i = 0; i < len; ++i) {
        int fl = 1;
        for(int j =0; j < len; ++j) {
            if (str[i] == newArr[j]) {
                fl = 0;
                break;
            }
        }
        if(fl) {
            newArr[k++] = str[i];
        }
    }
    printf("%d\n", k);
    int* p = (int*)realloc(newArr, sizeof(int) * k);
    newArr = p;
    *size = k; 
    return newArr;
}

int main() {
    int len, n, m;
    
    scanf("%d", &len);
    //scanf("%d", &len);
    scanf("%d %d", &n, &m);
    int *arr = random_array(n,m, len);
    int c;
    printer(len, arr);
    printf("Введите команду:\n 1 для смены максимального и минимального значения \n 2 для создания уникального массива\n");
    scanf("%d", &c);
    if(c == 1) {
        int minind = 0;
        int maxind = 0;
        int maxi = arr[0];
        int mini = arr[0];
        for(int i = 0; i < len; ++i) {
            if (arr[i] > maxi) {
                maxi = arr[i];
                maxind = i;
            }
            if (arr[i] < mini){
                mini = arr[i];
                minind = i;
            }
        }
        swapR(&arr[minind], &arr[maxind]);
        printer(len, arr);
    }
    if(c == 2) {
        int size = 0;
        int* t = build_arr(arr, len, &size);
        printer(size, t);
        free(t);
    }
    free(arr);
    //free(build_arr);
    return 0; 
}
