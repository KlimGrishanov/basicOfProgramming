#include <stdio.h>

void findPosition(double x, double y);
void input(double *x, double *y);
double findLineY(double x);

int main(void) {
    double x, y;
    input(&x, &y);
    findPosition(x, y);
    return 0;
}

void input(double *x, double *y){
    printf("Please insert coordinates of the point: \n");
    scanf("%f %f", x, y);
}

double findLineY(double x){
    return 0.5 * x + 1;
}

void findPosition(double x, double y){
    double lineY = findLineY(x);
    if(y == lineY){
        printf("Point is on the line");
    }
    else if(y < lineY){
        printf("Point is above line");
    }
    else{
        printf("Point is below line");
    }
}