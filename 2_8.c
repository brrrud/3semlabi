#include<stdio.h>
#include<math.h>

double func(double x) {
    double eq; 
    eq = cos(x);
    return eq;
}
double dich_find(double a, double b, double(*form)(double x), double eps){
    double x = 0.0;
    while(fabs(a-b) > eps) {
        x = (a + b) / 2;
        if(func(a) * func(b) > eps){
            a = x;
        } 
        else {
            b = x;
        }
    }
    return x;

}
int main() {
    double a, b, eps;
    scanf("%lf%lf", &a, &b);
    scanf("%lf", &eps);
    int p = 1;
    printf("%lf", dich_find(a, b, func, eps));

}
