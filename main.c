#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( int argc, char *argv[] )  //命令行输入
{
    char ch;//用于存放内容
    int key;//定义变量放置密码
    char *command1="-e";//
	char *command2="-d";//
	key= atoi(argv[2]);//将argv[2]存入key
	FILE* fp,*cp;
    if (strcmp(argv[1],command1) == 0)//如果命令为-e，执行加密
    {
        fp=fopen(argv[3],"r+"); //只供读取
        cp=fopen("encrypted.txt","wb"); //只供读取
        if(fp==NULL) //如果失败了
        {
            printf("打开失败错误！");
            exit(1); //中止程序
        }
        while((ch=getc(fp))!=EOF)//加密
        {
            ch=ch^key;//异或加密
            fputc(ch,cp);//写入文件
            
        }
        printf("success!");//表明加密成功
        fclose(fp); //关闭文件
        fclose(cp); //关闭文件
    }
    else if (strcmp(argv[1],command2) == 0)//如果命令为-d.执行解密
    {
        fp=fopen(argv[3],"r+"); //只供读取
        if(fp==NULL) //如果失败了
        {
            printf("打开失败错误！");
            exit(1); //中止程序
        }
        //解密
        while((ch=getc(fp))!=EOF)
        {
            ch=ch^key;//再进行一次异或
            printf("%c",ch);//将结果输出到屏幕
        }
        fclose(fp); //关闭文件
    }
    else printf("Your command is wrong");//命令错误
    return 0;
}

