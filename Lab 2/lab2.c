#include <stdio.h>
#include <math.h>

void funcFor(double fromNum, double stepI, int iter);
void funcWhile(double fromNum, double toNum, double stepI);
void funcDoWhile(double fromNum, double toNum, double stepI);

void start(double fromNum, double toNum, int iter);
void input(double *fromNum, double *toNum, int *iter);
void checkIsNan(double value);
void printCell(double value);

int check(double fromNum, double toNum, int iter);
double f(double i);
double stepIter(double fromNum, double toNum, int iter);

int main(void){
    double fromNum, toNum;
    int iter;
    while(1){
        input(&fromNum, &toNum, &iter);
        if(check(fromNum, toNum, iter)){
            start(fromNum, toNum, iter);
            break;
        }
        else{
            printf("Try again\n");
        }
    }
    return 0;
}

void printCell(double value){
    printf(" %10.3lf\t|", value);
}

void checkIsNan(double value){
    if(isnan(value)){
        printf("      Error!\t|");
    }else{
        printCell(value);
    }
}

double f(double i){
    return ((sin(i)*sin(i)) / i);
}

void input(double *fromNum, double *toNum, int *iter){
    printf("Please insert fromNum, toNum and number of iterations\n");
    scanf("%lf %lf %d", fromNum, toNum, iter);
}

double stepIter(double fromNum, double toNum, int iter){
    return (toNum-fromNum)/(iter-1);
}

int check(double fromNum, double toNum, int iter){
    int ans;
    if(iter <= 0){
        printf("Iter below 0\n");
        ans = 0;
    }else if(fromNum == toNum && iter != 1){
        printf("Right border equal left border and iter more than 1\n");
        ans = 0;
    }else if(fromNum != toNum && iter == 1){
        printf("Iter equal 1, but must be at least 2 if right border dont equal left border\n");
        ans = 0;
    }else{
        ans = 1;
    }
    return ans;
}

void start(double fromNum, double toNum, int iter){
    double stepI;
    if(fromNum > toNum){
        printf("Error, leftBorder larger rightBorder");
    }
    else{
        stepI = stepIter(fromNum, toNum, iter);
        funcFor(fromNum, stepI, iter);
        funcWhile(fromNum, toNum, stepI);
        funcDoWhile(fromNum, toNum, stepI);
    }
}

void funcFor(double fromNum, double stepI, int iter){
    double x = fromNum;
    printf("for:\nx    |");
    for(int i = 0; i < iter; i++){
        printCell(fromNum);
        fromNum += stepI;
    }
    fromNum = x;
    printf("\nf(x) |");
    for(int i = 0; i < iter; i++){
        checkIsNan(f(fromNum));
        fromNum += stepI;
    }
}

void leftEqualRightBorder(double value){
    printCell(value);
    printf("\nf(x) |");
    checkIsNan(f(value));
}

void funcWhile(double fromNum, double toNum, double stepI){
    printf("\nWhile:\nx    |");
    double temp = fromNum;
    if(fromNum == toNum){
        leftEqualRightBorder(fromNum);
    }else{
        while(fromNum < toNum + stepI){
            printCell(fromNum);
            fromNum += stepI;
        }
        fromNum = temp;
        printf("\nf(x) |");
        while(fromNum < toNum + stepI){
            checkIsNan(f(fromNum));
            fromNum += stepI;
        }
    }
}

void funcDoWhile(double fromNum, double toNum, double stepI){
    printf("\nDo While:\nx    |");
    double temp = fromNum;
    do{
        printCell(fromNum);
        fromNum += stepI;
    }while(fromNum < toNum + stepI);
    fromNum = temp;
    printf("\nf(x) |");
    do{
        checkIsNan(f(fromNum));
        fromNum += stepI;
    }while(fromNum < toNum + stepI);
}