#include <stdio.h>
#include <math.h>

double calcElem(double h, double x);
double rightRectangle(double n, double x, double h);
double calcH(double a, double b, double n);
double Abs(double x);
double checkSum(double e, double a, double b);
void input(double *a, double *b, double *e);
int check(double a, double b, double e);

int main(){
    double a, b, e;
    while(1){
        input(&a, &b, &e);
        if(check(a, b, e)){
            double ans = checkSum(e, a, b);
            printf("%.15lf", ans);
            break;
        }
        else{
            printf("Numbers must be greater than zero\n");
        }
    }
    return 0;
}

int check(double a, double b, double e){
    return (a <= 0 || b <= 0 || e <= 0) ? 0 : 1;
}

void input(double *a, double *b, double *e){
    printf("Enter value of a and b\n");
    scanf("%lf %lf", a, b);
    printf("Enter precision E\n");
    scanf("%lf", e);
}

double calcElem(double h, double x){
    return h * log(x);
}

double Abs(double x){
    return x >= 0 ? x : x*(-1);
}

double rightRectangle(double n, double x, double h){
    double s = 0;
    for(int i = 0; i <= n; i++){
        s += calcElem(h, x);
        x += h;
    }
    return s;
}

double calcH(double a, double b, double n){
    return (b-a)/n;
}

double checkSum(double e, double a, double b){
    double n = 2;
    double firstCalc = rightRectangle(n, a, calcH(a, b, n));
    n *= 2;
    double nextCalc = rightRectangle(n, a, calcH(a, b, n));
    while(Abs(firstCalc-nextCalc) >= e){
        firstCalc = nextCalc;
        n = n * 2;
        nextCalc = rightRectangle(n, a, calcH(a, b, n));
    }
    return nextCalc;
}