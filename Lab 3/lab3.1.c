#include <stdio.h>
// tests are good
double Abs(double x);
double factorial(double n, double prevfact);
double f(double n, double prevfact);
double solve(double e);
int check(double e);
void input(double *e);

int main(void){
    double e;
    while(1){
        input(&e);
        if(check(e)){
            solve(e);
            break;
        }
        else{
            printf("Error!\n");
        }
    }
    return 0;
}

int check(double e){
    return e <= 0 ? 0 : 1;
}

void input(double *e) {
    printf("Enter precision E\n");
    scanf("%lf", e);
}

double Abs(double x){ // fabs abs
    return x >= 0 ? x : x*(-1);
}

double factorial(double n, double prevfact){
    return n * prevfact;
}

double f(double n, double prevfact){
    return (1 / factorial(n, prevfact));
}

double solve(double e){
    double n = 1;
    double prevSum;
    double sum = 0;
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