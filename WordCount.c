#include <stdio.h>
#include <string.h>
int main (int paraNum, char *arrPoint[]) // paraNum ��ʾ��������, *arrPoint[]ָ������, ÿһ��ָ��ָ��һ���ַ���
{
    //����fp��ָ�룬����ָ��FILE�Ķ��� 
    FILE *fp;
    int count = 0; // ͳ����
    int i; //����ѭ��ʹ�õĲ��� 
    if ((fp=fopen(arrPoint[2], "r")) == NULL)//���ļ������쳣�ж� 
    {
        puts("error!\n");
        return 0;
    }
    if (arrPoint[1][1] == 'w') // ͳ�Ƶ����� 
    {
        char word[1024];
        while (fscanf(fp, "%s", word) != EOF)//���ļ��������� 
        {
            count ++;
            for ( i = 1; i < strlen(word) - 1; i ++){
            	if (word[i] == ',' && word[i - 1] != ',' && word[i + 1] != ',') 
                    count ++;
			}
                 
        }
        printf("������=%d\n", count);
    }
    else if (arrPoint[1][1] == 'c') // ͳ���ַ��� 
    {
        char c;
        while ((c = fgetc(fp)) != EOF){
        	count ++;
		}  
        printf("�ַ���=%d", count);
    }
    fclose(fp);
    return 0;
}


