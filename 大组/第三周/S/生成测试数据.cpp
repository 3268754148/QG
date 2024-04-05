#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>

int main()
{
    FILE* fp;
    int n;
    printf("请输入生成测试数据的量\n");
    scanf("%d", &n);
   
    fp = fopen("data.txt", "w");
    if (fp == NULL) 
    {
        printf("File cannot open! ");
        exit(0);
    }
    fprintf(fp, "%d\n", n);
    int random = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        random = rand();
      
        fprintf(fp, "%d ", random % 1000);
    }
   
       
    


    fclose(fp);
    return 0;
}

	
	