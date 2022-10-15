#include<stdio.h>
#include<stdlib.h>
void printer(unsigned len, int*arr) {
    for(int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int* random_array (unsigned size_a) {
    int *a = (int*)malloc(sizeof(int)*size_a);
    for(int i = 0; i<size_a; i++) {
        a[i] = rand() % 99;
    }
    return a;
}
int* solution_sum(int* a, int* b, unsigned size_a, unsigned size_b) { 
    int *c = (int*)malloc(size_a * sizeof(int));
    for(int i = 0; i<size_a; ++i) {
        if(i>=size_b){
            c[i] = a[i] +b[size_b-1];
        }
        else{
            c[i] = a[i] + b[i];
        }
    }
    return c;
}
int main(){
    unsigned size_a;
    unsigned size_b;
    printf("Размер массива А: ");
    scanf("%u", &size_a);
    printf("Размер массива B: ");
    scanf("%u", &size_b);

    int*a = random_array(size_a);
    int*b = random_array(size_b);
    int*c = solution_sum(a, b, size_a, size_b);

    printer(size_a, a);
    printer(size_b, b);
    printer(size_a, c);

    free(a);
    free(b);
    free(c);
}
