#include <stdio.h>
int main()
{
    char ca[1000];
    char res[1000];
    gets(ca);
    int num = 1;
    int index = 0;
    for (int i = 0; (ca[i] <= 90 && ca[i] >= 65) || (ca[i] <= 122 && ca[i] >= 97); i++)
    {
        if (ca[i] == ca[i + 1])
        {
            num++;
        }
        else
        {
            if (num == 1)
                res[index++] = ca[i];
            else
            {
                res[index++] = ca[i];
                char na[100];
                snprintf(na, sizeof(na), "%d", num);
                for (int i = 0; na[i] <= 57 && na[i] >= 48; i++)
                    res[index++] = na[i];
            }
            num = 1;
        }
    }
    printf("%d", index);
    return 0;
}