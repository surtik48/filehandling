#include <stdio.h>
#include <stdlib.h>
long count_characters(FILE *f)
{
    fseek(f,-1,SEEK_END);
    long pos = ftell(f);
    pos++;
    return pos;
}
void main()
{
    int i;
    long cnt;
    char ch, ch1;
    FILE *fp1, *fp2;
    fp1=fopen("File1.txt","w");
    char c[100];
    if(fp1!=NULL)
    {printf("enter the content\n");
        gets(c);
        fputs(c,fp1);
        printf("the contents of file 1: %s",c);
            }

    fclose(fp1);

    if (fp1 = fopen("File1.txt", "r"))
    {
        fp2 = fopen("File2.txt", "w");
        cnt = count_characters(fp1);
        while (cnt)
        {
            ch = fgetc(fp1);
            fputc(ch, fp2);
            fseek(fp1, -2,SEEK_CUR);
            cnt--;
        }
    }
    fclose(fp1);
    fclose(fp2);
    fp2=fopen("File2.txt","r");
    char rev[100];
    if(fp2!=NULL)
    {

        printf("\ncontent in file 2: %s",fgets(rev,100,fp2));
    }
    fclose(fp2);

}



