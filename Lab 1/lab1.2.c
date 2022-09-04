#include <stdio.h>
// 0 - on line
// 1 - above
// -1 - below
double findForFirstLine(double x, double y);
double findForSecondLine(double x, double y);
double findForThirdLine(double x, double y);

int main(){
    int ansFirstLine, ansSecondLine, ansThirdLine;
    printf("Please insert coordinates of the point:\n");
    double x, y;
    scanf("%lf %lf", &x, &y);
    ansFirstLine = findForFirstLine(x, y);
    ansSecondLine = findForSecondLine(x, y);
    ansThirdLine = findForThirdLine(x, y);
    if(ansFirstLine == 0 || ansSecondLine == 0 || ansThirdLine == 0){
        printf("Point on the line.");
    }
    else if(ansFirstLine == -1 && ansSecondLine == 1 && ansThirdLine == 1){
        printf("Area #1");
    }
    else if(ansFirstLine == -1 && ansSecondLine == -1 && ansThirdLine == 1){
        printf("Area #2");
    }
    else if(ansFirstLine == -1 && ansSecondLine == -1 && ansThirdLine == -1){
        printf("Area #3");
    }
    else if(ansFirstLine == 1 && ansSecondLine == -1 && ansThirdLine == -1){
        printf("Area #4");
    }
    else if(ansFirstLine == 1 && ansSecondLine == 1 && ansThirdLine == -1){
        printf("Area #5");
    }
    else if(ansFirstLine == 1 && ansSecondLine == 1 && ansThirdLine == 1){
        printf("Area #6");
    }
    else{
        printf("Area #7");
    }
}

double findForFirstLine(double x, double y){
    int ans;
    if(y == (2 * x + 2)){
        ans = 0;
    }
    else if(y > (2 * x + 2)){
        ans = 1;
    }
    else{
        ans = -1;
    }
    return ans;
}

double findForSecondLine(double x, double y){
    int ans;
    if(y == (0.5 * x - 1)){
        ans = 0;
    }
    else if(y > (0.5 * x - 1)){
        ans = 1;
    }
    else{
        ans = -1;
    }
    return ans;
}

double findForThirdLine(double x, double y){
    int ans;
    if(y == (-x + 2)){
        ans = 0;
    }
    else if(y > (-x + 2)){
        ans = 1;
    }
    else{
        ans = -1;
    }
    return ans;
}
