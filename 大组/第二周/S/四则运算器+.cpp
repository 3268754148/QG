#include <stdio.h>
#include <string.h>
#include<windows.h>
void remove_spaces(char* s) {
    char* s1 = s;
    for (; *s != '\0'; s++) {
        if (*s != ' ') {
            *s1 = *s;
            s1++;
        }
    }
    *(--s1) = '\0';
}
char* pushstack(char input[], char s1[], char s2[], int top1, int top2)
{
    for (int i = 0; ; i++)
    {
        if (input[i] - '0' <= 9 && input[i] - '0' >= 0)
        {
            s2[top2++] = input[i];
        }
        else if (input[i] == '(')
        {
            s1[top1++] = input[i];
        }
        else if (input[i] == ')')
        {
            top1--;
            while (1)
            {
                s2[top2++] = s1[top1--];
                if (s1[top1] == '(')
                {
                    break;
                }
            }
        }
        else if (input[i] == '+' || input[i] == '-')
        {
            while (1)
            {
                if (s1[top1 - 1] == '+' || s1[top1 - 1] == '-' || s1[top1 - 1] == '*' || s1[top1 - 1] == '/')
                {
                    top1--;
                    s2[top2++] = s1[top1];
                }
                else
                {
                    break;
                }
            }
            s1[top1++] = input[i];
        }
        else if (input[i] == '*' || input[i] == '/')
        {
            while (1)
            {
                if (s1[top1 - 1] == '*' || s1[top1 - 1] == '/')
                {
                    top1--;
                    s2[top2++] = s1[top1];
                }
                else
                {
                    break;
                }
            }
            s1[top1++] = input[i];
        }
        else if (input[i] == '\0')
        {
            top1--;
            while (1)
            {
                s2[top2++] = s1[top1--];
                if (top1 == 0)
                {
                    return s2;
                }
            }
        }
        else
        {
            printf("输入错误\n");
            
            return NULL;
        }
    }
}
void outstack(char* arr, double* a, int top3)
{
    for (int i = 1;; i++)
    {
        if (arr[i] - '0' <= 9 && arr[i] - '0' >= 0)
        {
            a[top3++] = arr[i] - '0';
        }
        if (arr[i] == '*')
        {
            a[top3 - 2] = a[top3 - 2] * a[top3 - 1];
            top3--;
        }
        if (arr[i] == '/')
        {
            a[top3 - 2] = a[top3 - 2] / a[top3 - 1];
            top3--;
        }
        if (arr[i] == '+')
        {
            a[top3 - 2] = a[top3 - 2] + a[top3 - 1];
            top3--;
        }
        if (arr[i] == '-')
        {
            a[top3 - 2] = a[top3 - 2] - a[top3 - 1];
            top3--;
        }
        if (arr[i] == '\0')
        {
            printf("%lf\n", a[1]);
            return;
        }
    }
}
int main() {
    char input[100];
    while (1)
    {
        printf("请输入(若0则退出）\n");
        fgets(input, sizeof(input), stdin);
        remove_spaces(input);
        if (strcmp(input,"0") == 0)
        {
            printf("退出成功\n");
            break;
        }
        char stack1[100];
        stack1[0] = 0;
        char stack2[100];
        stack1[0] = 0;
        int top1 = 1;
        int top2 = 1;
        char* arr = pushstack(input, stack1, stack2, 1, 1);
        if (arr == NULL)
        {
            printf("请重新输入\n");
            continue;
        }
        double a[100];
        outstack(arr, a, 1);
    }
    system("pause");
}