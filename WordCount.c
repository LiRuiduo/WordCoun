#include <stdio.h>
#include <string.h>
int main (int paraNum, char *arrPoint[]) // paraNum 表示参数个数, *arrPoint[]指针数组, 每一个指针指向一个字符串
{
    //声明fp是指针，用来指向FILE的对象 
    FILE *fp;
    int count = 0; // 统计数
    int i; //用于循环使用的参数 
    if ((fp=fopen(arrPoint[2], "r")) == NULL)//打开文件并作异常判断 
    {
        puts("error!\n");
        return 0;
    }
    if (arrPoint[1][1] == 'w') // 统计单词数 
    {
        char word[1024];
        while (fscanf(fp, "%s", word) != EOF)//从文件读入数据 
        {
            count ++;
            for ( i = 1; i < strlen(word) - 1; i ++){
            	if (word[i] == ',' && word[i - 1] != ',' && word[i + 1] != ',') 
                    count ++;
			}
                 
        }
        printf("单词数=%d\n", count);
    }
    else if (arrPoint[1][1] == 'c') // 统计字符数 
    {
        char c;
        while ((c = fgetc(fp)) != EOF){
        	count ++;
		}  
        printf("字符数=%d", count);
    }
    fclose(fp);
    return 0;
}


