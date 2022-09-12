#include <stdio.h>
#include <math.h>

void funcFor(double fromNum, double toNum, double stepI);
void funcWhile(double fromNum, double toNum, double stepI);
void funcDoWhile(double fromNum, double toNum, double stepI);

void input(double *fromNum, double *toNum, double *iter);
int check(double fromNum, double toNum, double iter);

double stepIter(double fromNum, double toNum, double iter);

void input(double *fromNum, double *toNum, double *iter){
    printf("Please insert fromNum, toNum and number of iterations");
    scanf("%lf %lf %lf", fromNum, toNum, iter);
}

double stepIter(double fromNum, double toNum, double iter){
    return (toNum-fromNum)/(iter);
}

int check(double fromNum, double toNum, double iter){
    if(fromNum < 0 || toNum < fromNum || toNum <= 0 || iter <= 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main(void){
    double fromNum, toNum, iter;
    while(1){
        input(&fromNum, &toNum, &iter);
        if(check(fromNum, toNum, iter)){
            double stepI = stepIter(fromNum, toNum, iter);
            funcFor(fromNum, toNum, stepI);
            funcWhile(fromNum, toNum, stepI);
            funcDoWhile(fromNum, toNum, stepI);
            break;
        }
        else{
            printf("Error!\n");
        }
    }
}

void funcFor(double fromNum, double toNum, double stepI){
    printf("for:");
    printf("\nx    |");
    for(double i = fromNum; i < toNum - 0.000001; i += stepI){
        printf(" %6.5lf |", i);
    }
    printf("\nf(x) |");
    for(double i = fromNum; i < toNum - 0.000001; i += stepI){
        printf(" %6.5lf |", (sin(i)*sin(i)) / i);
    }
}

void funcWhile(double fromNum, double toNum, double stepI){
    printf("\nWhile:\nx    |");
    double temp = fromNum;
    while(fromNum < toNum - 0.000001){
        printf(" %6.5lf |", fromNum);
        fromNum += stepI;
    }
    fromNum = temp;
    printf("\nf(x) |");
    while(fromNum < toNum - 0.000001){
        printf(" %6.5lf |", (sin(fromNum) * sin(fromNum)) / fromNum);
        fromNum += stepI;
    }
}

void funcDoWhile(double fromNum, double toNum, double stepI){
    printf("\nDo While:\nx    |");
    double temp = fromNum;
    do{
        printf(" %6.5lf |", fromNum);
        fromNum += stepI;
    }while(fromNum < toNum-0.000001);
    fromNum = temp;
    printf("\nf(x) |");
    do{
        printf(" %6.5lf |", (sin(fromNum) * sin(fromNum)) / fromNum);
        fromNum += stepI;
    }while(fromNum < toNum-0.000001);
}