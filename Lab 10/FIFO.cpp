#include <stdio.h> 
using namespace std;

int main()
{
    int i, j, l, rs[50], frame[10], nf, k, avail, count = 0;
    printf("Enter length of ref. string : ");
    scanf("%d", &l);
    printf("Enter reference string :\n");
    for (i = 1; i <= l; i++)
        scanf("%d", &rs[i]);
    printf("Enter number frames: "); 
    scanf(" % d ", & nf);
    for (i = 0; i < nf;
         i++)
        frame[i] = -1;
    j = 0;
printf("\nRef. str Page frames"); for(i=1; i<=l; i++)
{
        printf("\n%4d\t", rs[i]);
        avail = 0;
        for (k = 0; k < nf; k++)
            if (frame[k] == rs[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = rs[i];
            j =
                (j + 1) % nf;
            count++;
            for (k = 0; k < nf; k++)
                printf("%4d", frame[k]);
        }
}
printf("\n\nTotal no. of page faults : %d\n",count);
}
