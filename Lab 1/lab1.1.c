#include <stdio.h>

void findPosition(double x, double y);
double input(double *x, double *y);

int main(void) {
    double x, y;
    input(&x, &y);
    findPosition(x, y);
    return 0;
}

double input(double *x, double *y){
    printf("Please insert coordinates of the point: \n");
    scanf("%f %f", x, y);
}

void findPosition(double x, double y){
    double lineY = 0.5 * x + 1;
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