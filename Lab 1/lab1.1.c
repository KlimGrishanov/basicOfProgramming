#include <stdio.h>

int main(void) {
    printf("Line equation: y = 0.5x + 1\n");
    printf("Please insert coordinates of the point:\n");
    double x, y;
    scanf("%a %a", &x, &y);
    if(y == (0.5 * x + 1)){
        printf("Point is on the line");
    }
    else if(y < (0.5 * x + 1)){
        printf("Point is above line");
    }
    else{
        printf("Point is below line");
    }
}
