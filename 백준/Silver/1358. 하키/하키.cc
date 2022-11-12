#include <stdio.h>
 
 
int main(void)
{
    int W, H, X, Y, P;
    int count = 0;
    scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);
    while (P--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        if ((a - X)*(a - X) + (b - (Y + H / 2))*(b - (Y + H / 2)) <= (H / 2)*(H / 2) && a < X)
            count++;
        else if (X <= a&&a <= X + W&&Y <= b&&b <= Y + H)
            count++;
 
 
 
        else if ((a - (X + W))*(a - (W + X)) + (b - (Y + H / 2))*(b - (Y + H / 2)) <= (H / 2)*(H / 2) && X + W < a)
            count++;
    }
    printf("%d", count);
    return 0;
 
    
}