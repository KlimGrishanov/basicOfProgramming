#include <stdio.h>
#include <math.h>

void funcFor(double fromNum, double stepI, int iter);
void funcWhile(double fromNum, double toNum, double stepI);
void funcDoWhile(double fromNum, double toNum, double stepI);

double f(double i);
void start(double fromNum, double toNum, int iter);
void input(double *fromNum, double *toNum, int *iter);
int check(double fromNum, double toNum, int iter);

double stepIter(double fromNum, double toNum, int iter);

int main(void){
    double fromNum, toNum, iter;
    while(1){
        input(&fromNum, &toNum, &iter);
        if(check(fromNum, toNum, iter)){
            start(fromNum, toNum, iter);
            break;
        }
        else{
            printf("Error! Iterration <= 0 or right border equals left border without 1 iter or iter 1 but 2 border!\n");
        }
    }
    return 0;
}

double f(double i){
    return ((sin(i)*sin(i)) / i);
}

void input(double *fromNum, double *toNum, int *iter){
    printf("Please insert fromNum, toNum and number of iterations\n");
    scanf("%lf %lf %lf", fromNum, toNum, iter);
}

double stepIter(double fromNum, double toNum, int iter){
    return (toNum-fromNum)/(iter-1);
}

int check(double fromNum, double toNum, int iter){
    if(iter <= 0 || (fromNum == toNum && iter != 1) || (fromNum != toNum && iter == 1)){
        return 0;
    }
    else{
        return 1;
    }
}

void start(double fromNum, double toNum, int iter){
    double stepI;
    if(fromNum > toNum){
        stepI = stepIter(toNum, fromNum, iter);
        funcFor(toNum, stepI, iter);
        funcWhile(toNum, fromNum, stepI);
        funcDoWhile(toNum, fromNum, stepI);
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
        printf(" %6.5lf |", fromNum);
        fromNum += stepI;
    }
    fromNum = x;
    printf("\nf(x) |");
    for(int i = 0; i < iter; i++){
        double temp = f(fromNum);
        if(isnan(temp)){
            printf(" Cant calc |");
        }else{
            printf(" %6.5lf |", f(fromNum));
        }
        fromNum += stepI;
    }
}

void funcWhile(double fromNum, double toNum, double stepI){
    printf("\nWhile:\nx    |");
    double temp = fromNum;
    double check = f(fromNum);
    if(fromNum == toNum){
        printf(" %6.5lf |", fromNum);
        printf("\nf(x) |");
        if(isnan(check)){
            printf(" Cant calc |");
        }else {
            printf(" %6.5lf |", f(fromNum));
        }
    }else{
        while(fromNum < toNum + stepI){
            printf(" %6.5lf |", fromNum);
            fromNum += stepI;
        }
        fromNum = temp;
        printf("\nf(x) |");
        while(fromNum < toNum + stepI){
            check = f(fromNum);
            if(isnan((check))){
                printf(" Cant calc |");
            }else{
                printf(" %6.5lf |", f(fromNum));
            }
            fromNum += stepI;
        }
    }
}

void funcDoWhile(double fromNum, double toNum, double stepI){
    printf("\nDo While:\nx    |");
    double temp = fromNum;
    do{
        printf(" %6.5lf |", fromNum);
        fromNum += stepI;
    }while(fromNum < toNum + stepI);
    fromNum = temp;
    printf("\nf(x) |");
    do{
        double check = f(fromNum);
        if(isnan((check))){
            printf(" Cant calc |");
        }else{
            printf(" %6.5lf |", f(fromNum));
        }
        fromNum += stepI;
    }while(fromNum < toNum + stepI);
}