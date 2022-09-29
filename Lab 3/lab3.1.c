#include <stdio.h>

double Abs(double x);
double factorial(double n, double prevfact);
double f(double n, double prevfact);
double solve(double e);
void input(double *e);

int main(void){
    double e;
    input(&e);
    if(e<=0){
        printf("Error");
    }else{
        solve(e);
    }
    return 0;
}

void input(double *e) {
    printf("Enter precision E\n");
    scanf("%lf", e);
}

double Abs(double x){
    return x >= 0 ? x : x*(-1);
}

double factorial(double n, double prevfact){
    return n * prevfact;
}

double f(double n, double prevfact){
    return (1 / factorial(n, prevfact));
}

double solve(double e){
    double n = 2;
    double prevSum;
    double sum = 1;
    double prevfact = 1;
    double step;
    do{
        prevSum = sum;
        step = f(n, prevfact);
        prevfact = factorial(n, prevfact);
        sum += step;
        n++;
    }while(Abs(sum - prevSum) > e);
    printf("%.15lf", sum);
}
