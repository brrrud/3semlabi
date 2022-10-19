#include<stdio.h>
#include<stdarg.h>
#include<math.h>
// x+5x^2+3x^3
double calcul(double x, int n, double k){
    return(k*powf(x, n));
}
double polinomial_cnt(double x, int n, ...){
    va_list num;
    va_start(num, n);
    double result = 0.0;    
    for(int i = 0; i < n+1; ++i) {
        result+=calcul(x, i, va_arg(num, double));
    }
    va_end(num);
    return result;
}
int main() {
    // 2.
    printf("%lf", polinomial_cnt(2.34, 3, 2.1, -2.6, -7.1, 3.4));
}
