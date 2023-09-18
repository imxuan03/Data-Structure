#include <stdio.h>
#include <strings.h>

int main()
{
    char S[10];
    fgets(S, 10, stdin);
    int hours = 10*(S[0]-48) + S[1]-48;
    if(S[8]=='A' && hours == 12) hours = 0;
    if(S[8]=='P' && hours != 12) hours += 12;
    S[0] = (hours/10+48);
    S[1] = (hours%10+48);
    S[8] = '\0';
    printf("%s", S);
}