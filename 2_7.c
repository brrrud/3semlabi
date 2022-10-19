#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    double x;
    double y;
}point;


point make_vec(point vec1, point vec2){
    point vec;
    vec.x = vec2.x - vec1.x;
    vec.y = vec2.y - vec1.y;
    return vec;
}
point make_point(double a , double b){
    point z;
    z.x = a;
    z.y = b;
    return z;
}

bool is_angle(point ab, point bc) {
    double  res = ab.x * bc.y - ab.y * bc.x;
    if (res>0){
        return true;
    }
    return false; 
}
bool is_convex(int n, ...){
    va_list num;
    point* cort = (point*)malloc(n*sizeof(point));
    //point cort[n];

    va_start(num, n);
    for(int i = 0; i < n; ++i){
        cort[i] = va_arg(num, point);
    }
    va_end(num);

    point curr_zero = cort[0];
    for(int i = 0; i < n-1; ++i){
        cort[i].x = cort[i+1].x-cort[i].x;
        cort[i].y = cort[i+1].y-cort[i].y;
    }
    cort[n-1].x = curr_zero.x - cort[n-1].x;
    cort[n-1].y = curr_zero.y - cort[n-1].y;

    for(int i = 0; i < n-1; ++i) {
        bool result = is_angle(cort[i], cort[i+1]);
        if (result == false){
            return false;
        }

    }
    return true;
}
int main(){
    int n = 3;
    point* cort[3];
    point temp1= {-2.3, 5.1}; //A
    point temp2 = {5.0, 3.5}; //B
    point temp3 = {2.6, 9.9}; //E
    //point temp4 = {2.0, 4.0}; //D
    point temp5 = {-2 , 10}; //C
    if (n < 3){
        printf("Not correct data");
        return 0;
    }
    else{
        if(is_convex(4, temp1, temp2, temp3, temp5)){
            printf("HELL YEAH");
        }
        else{
            printf("NO");
        }
    }
    return 0;
}
