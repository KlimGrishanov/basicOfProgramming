#include <stdio.h>
// 0 - on line
// 1 - above
// -1 - below

double findForLine(double y, double lineY);

double firstLineY(double x);
double secondLineY(double x);
double thirdLineY(double x);

void printArea(int numArea);

void findPosition(double x, double y);
void findArea(int ansFirstLine, int ansSecondLine, int ansThirdLine);
void findIntersection(int ansFirstLine, int ansSecondLine, int ansThirdLine);

void input(double *x, double *y);

int main(){
    double x, y;
    input(&x, &y);
    findPosition(x, y);
}

void printArea(int numArea){
    printf("The point in %d area", numArea);
}

void input(double *x, double *y){
    printf("Please insert coordinates of the point: \n");
    scanf("%lf %lf", x, y);
}

double firstLineY(double x){
    return 2 * x + 2;
}

double secondLineY(double x){
    return 0.5 * x - 1;
}

double thirdLineY(double x){
    return (-x) + 2;
}

double findForLine(double y, double lineY){
    int ans;
    if(y == lineY){
        ans = 0;
    }
    else if(y > lineY){
        ans = 1;
    }
    else{
        ans = -1;
    }
    return ans;
}

void findPosition(double x, double y){
    int ansFirstLine, ansSecondLine, ansThirdLine;
    ansFirstLine = findForLine(y, firstLineY(x));
    ansSecondLine = findForLine(y, secondLineY(x));
    ansThirdLine = findForLine(y, thirdLineY(x));
    if(ansFirstLine == 0 || ansSecondLine == 0 || ansThirdLine == 0){
        findIntersection(ansFirstLine, ansSecondLine, ansThirdLine);
    }
    else{
        findArea(ansFirstLine, ansSecondLine, ansThirdLine);
    }
}

void findIntersection(int ansFirstLine, int ansSecondLine, int ansThirdLine){
    if(ansFirstLine == 0 && ansSecondLine != 0 && ansThirdLine != 0){
        printf("y = 2x + 2");
    }
    else if(ansSecondLine == 0 && ansFirstLine != 0 && ansThirdLine != 0){
        printf("y = 0.5x - 1");
    }
    else if(ansThirdLine == 0 && ansFirstLine != 0 && ansSecondLine != 0){
        printf("y = -x + 2");
    }
    else if(ansFirstLine == 0 && ansSecondLine == 0){
        printf("y = 2x + 2\n");
        printf("y = 0.5x - 1");
    }
    else if(ansFirstLine == 0 && ansThirdLine == 0){
        printf("y = 2x + 2\n");
        printf("y = -x + 2");
    }
    else{
        printf("y = 0.5x - 1\n");
        printf("y = -x + 2");
    }
}

void findArea(int ansFirstLine, int ansSecondLine, int ansThirdLine){
    if(ansFirstLine == -1 && ansSecondLine == 1 && ansThirdLine == 1){
        printArea(1);
    }
    else if(ansFirstLine == -1 && ansSecondLine == -1 && ansThirdLine == 1){
        printArea(2);
    }
    else if(ansFirstLine == -1 && ansSecondLine == -1 && ansThirdLine == -1){
        printArea(3);
    }
    else if(ansFirstLine == 1 && ansSecondLine == -1 && ansThirdLine == -1){
        printArea(4);
    }
    else if(ansFirstLine == 1 && ansSecondLine == 1 && ansThirdLine == -1){
        printArea(5);
    }
    else if(ansFirstLine == 1 && ansSecondLine == 1 && ansThirdLine == 1){
        printArea(6);
    }
    else{
        printArea(7);
    }
}