#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double geom(int n, ...) {
    double res = 1;
    va_list factor;
    va_start(factor, n);
    for(int i = 0; i < n; i++) {
        res *= va_arg(factor, double);
    }
    va_end(factor);
    return pow(res, 1.0 / n);
}

double power(double a, int n) {
    if (n == 0) return 1;
    else if(n > 0) {
        return power(a, n - 1) * a;
    } 
    else if(n < 0) {
        return power(a, n + 1) * (1.0 / a);
    } 
}

int main() {
    printf(" среднее геометрическое переданных ей чисел (n = 3)\n");
    printf("%lf\n", geom(3, 1.0, 2.0, 3.0));
    printf(" среднее геометрическое переданных ей чисел (n = 1)\n");
    printf("%lf\n", geom(1, 3.0));
    printf("возведения в целую степень(число:2, степень: -1)\n");
    printf("%.8lf\n", power(2, -1));
    printf("возведения в целую степень(число:8, степень: 2)\n");
    printf("%.8lf\n", power(8, 2));
}
