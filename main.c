/*
PragramName: Korn Shell 解释器
Author: Sulu. FuHongshuai
Date: 2018/2/26
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<wait.h>
#include<fcntl.h>
#include<errno.h>
#include<signal.h>

#define MAXNAME 100           //文件名最大长度
#define PIPELINE 20           //使用管道连接的最大命令个数
#define MAXARG 20             //命令最大的参数个数
#define OPEN_MAX 20           //打开的文件个数上限
#define MAXLINE 200           //一次执行的命令最大字符数目
#define MAXDIR 50             //当前工作目录名最大字符数
#define MAXSAVE 100           //存储的历史命令最大条数
#define MAXLEN   50           //参数的最大长度


#define FALSE 0
#define TRUE 1

#define ERROR 0
#define OKAY 1
#define QUIT -1

#define MYNAME "PragramName: Korn Shell解释器 Author: Sulu. FuHongshuai Date: 2018/2/26"

struct cmd{
    int infd;                 //输入文件
    int outfd;                //输出文件
    char* av[MAXARG];         //参数
}cmdlin[PIPELINE];            //命令结构


struct cmd historyCmd[MAXSAVE];
/*int x,z;
for(z=0;z<MAXSAVE;z++)
{
    for(x=0;x<MAXARG;x++)
        {
              historyCmd[z].av[x]=malloc(20);
        }
}*/

//////////*********全局变量定义*********//////////////
int hisNum=0;                 //已存储的历史命令条数,初始化为0
int lastpid;
int backgnd;
char *lineptr;
char *avptr;
char infile[MAXNAME+1];
char outfile[MAXNAME+1];
char avline[MAXLINE+1];
char line[MAXLINE+1];
int append;
char curdir[MAXDIR];
//////////********函数声明********////////////////////
void command(int i);              //将line[]中第i个命令以命令名+参数的形式存储到cmdlin[i]中
void execute(int i);              //执行cmdlin[0]到cmdlin[j-1]中的命令（调用forkexec（））
void forkexec(struct cmd* ptr);   //执行ptr指向的命令
int check(char* ptr);             //在lineptr指向的字符串中查找ptr
void getname(char* name);         //将lineptr后面的文件名存入name
int parse();                      //将line[]中的字符串以命令加参数的形式存入cmdlin[]中（调用command（））
int getinline();                  //获取输入命令行，存储到line[]中
void initial();                   //初始化
void addCmd(struct cmd newCmd);   //添加历史命令记录
void printHistory();              //输出历史命令
//////////********使用说明********////////////////////
/*
1)此shell解释器命令格式为
 cmd1[<infileName][|cmd2][|cmd3]...[|cmdn][>or>>outfileName][&]
2)cmd为命令名+参数形式的命令，<为输入重定向，后跟输入重定向文件名infileName；
  >或>>后跟输出重定向文件名，输出内容将写入outfileName，>>表示以追加方式写入文件，>则表示以覆盖方式写入；
3)命令结尾可加后台运行符号& ,表示此命令将以后台运行的方式执行
4)实现了cd命令
5)exit为退出命令。
6)history为历史命令，可以显示最近执行的命令，最多100条。
7)!i为执行历史命令，意为执行第i条历史命令。!!为执行上一条命令。
8)myname为输出此解释器的版本信息。
*/
//////////////////main////////////////////////////////
main()
{
    //分配空间
    int x,z;
    for(z=0;z<MAXSAVE;z++)
    {
        for(x=0;x<MAXARG;x++)
        {
            historyCmd[z].av[x]=malloc(MAXLEN);
        }
    }
    //

    int k;
    for(;;)
    {
//Begin:
        initial();                     //初始化
        int s=getinline();      //获取输入字符串
        if(s==QUIT)
            break;                   //若为exit命令则退出
        if(s==OKAY)
        {
            if(k=parse())
                execute(k);
        }

        if(s==ERROR)
            continue;


    }



    //释放空间

    for(z=0;z<MAXSAVE;z++)
    {
        for(x=0;x<MAXARG;x++)
        {
            free(historyCmd[z].av[x]);
        }
    }

}


//////////********函数实现********////////////////
void initial()
{
    int i;
    backgnd=FALSE;
    lineptr=line;
    avptr=avline;
    infile[0]='\0';
    outfile[0]='\0';
    append=FALSE;

    for(i=0;i<PIPELINE;++i)
    {
        cmdlin[i].infd = 0;
        cmdlin[i].outfd = 1;
    }
    for(i=3;i<OPEN_MAX;++i)
        close(i);
    // curdir=get_current_dir_name();

    getcwd(curdir,MAXDIR);//==NULL) printf("error!");//获取当前工作目录
    //curdir=(char*)get_curent_dir_name();
    //getwd(curdir);
    printf("[xiaow-shell@ %s:]#",curdir);

    fflush(stdout);
}

int getinline()
{

    /* // char* line;
      char prompt[200];
      while(1) {
      set_prompt(prompt);
      if(!(line = readline(prompt)))
          break;
  }

  */

    int i;

    for(i=0;(line[i]=getchar())!='\n'&&i<MAXLINE;++i);
    if(i==MAXLINE)
    {
        fprintf(stderr,"Command line too long\n");
        return(ERROR);
    }

    line[i+1]='\0';
    if(strcmp(line,"exit\n")==0) return QUIT;
    return(OKAY);

}

int parse()
{
    int i;

    command(0);
    if(check("<"))
        getname(infile);
    for(i=1;i<PIPELINE;++i)
        if(check("|"))
            command(i);
        else
            break;

    if(check(">"))
    {
        if(check(">"))
            append=TRUE;
        getname(outfile);
    }


    if(check("&"))
        backgnd=TRUE;

    if(check("\n"))
        return(i);
    else
    {
        fprintf(stderr,"Command line syntax error\n");
        return(ERROR);
    }

}

void command(int i)
{
    int j,flag,inword;

    for(j=0;j<MAXARG-1;++j)
    {
        while(*lineptr==' '||*lineptr=='\t')
            ++lineptr;
        cmdlin[i].av[j]=avptr;
        cmdlin[i].av[j+1]=NULL;
        for(flag=0;flag==0;)
        {
            switch(*lineptr)
            {
                case '>':
                case '<':
                case '|':
                case '&':
                case '\n':
                    if(inword==FALSE)
                        cmdlin[i].av[j]=NULL;
                    *avptr++='\0';
                    return;
                case' ':
                case'\t':
                    inword=FALSE;
                    *avptr++='\0';
                    flag=1;
                    break;
                default:
                    inword=TRUE;
                    *avptr++=*lineptr++;
                    break;
            }

        }

    }


}

void execute(int j)
{
    int i,fd,fds[2];

    if(infile[0]!='\0')
        cmdlin[0].infd=open(infile,O_RDONLY);

    if(outfile[0]!='\0')
        if(append==FALSE)
            cmdlin[j-1].outfd=open(outfile,O_WRONLY|O_CREAT|O_TRUNC,0666);
        else
            cmdlin[j-1].outfd=open(outfile,O_WRONLY|O_CREAT|O_APPEND,0666);


    if(backgnd==TRUE)
        signal(SIGCHLD,SIG_IGN);
    else
        signal(SIGCHLD,SIG_DFL);

    if(strcmp(cmdlin[0].av[0],"history")==0)
    {
        printHistory();
        // addCmd(cmdlin[i]);
        return;
    }

    for(i=0;i<j;++i)
    {

        if(i<j-1)
        {
            pipe(fds);

            cmdlin[i].outfd=fds[1];

            cmdlin[i+1].infd=fds[0];

        }
        if(strcmp(cmdlin[i].av[0],"cd")==0)              //cd 命令
        {
            if((cmdlin[i].av[1])&&chdir(cmdlin[i].av[1])) {printf("cd:error!\n"); return;}
            addCmd(cmdlin[i]);
            return;
        }
        if(cmdlin[i].av[0][0]=='!')

        {
            if(cmdlin[i].av[0][1]=='\0')
            {printf("!:cannot find this command!\n");return; }

            int dex=cmdlin[i].av[0][1]-'0';
            if(cmdlin[i].av[0][2]!='\0')
            {

                int dex1=cmdlin[i].av[0][2]-'0';
                dex=dex*10+dex1;
            }
            if(cmdlin[i].av[0][1]=='!')  dex=1;
            if(dex>hisNum||dex<=0) {printf("!:cannot execute this command!\n");return;}

            if(strcmp(historyCmd[hisNum-dex].av[0],"cd")==0)       //history cd 命令
            {
                if((historyCmd[hisNum-dex].av[1])&&chdir(historyCmd[hisNum-dex].av[1])) {printf("cd:error!\n"); return;}
                return;
            }
            if(strcmp(historyCmd[hisNum-dex].av[0],"myname")==0) {printf("%s\n",MYNAME);return;}
        }


        forkexec(&cmdlin[i]);
        if(cmdlin[i].av[0][0]!='!')
            addCmd(cmdlin[i]);

        if((fd=cmdlin[i].infd)!=0)
            close(fd);
        if((fd=cmdlin[i].outfd)!=1)
            close(fd);
    }

    if(backgnd==FALSE)
        while(wait(NULL)!=lastpid);

}

void forkexec(struct cmd* ptr)
{
    int pid;
    int i;

    if(pid=fork())
    {

        if(backgnd==TRUE)
            printf("%d\n",pid);
        lastpid=pid;

    }
    else
    {

        if(ptr->infd==0&&backgnd==TRUE)
            ptr->infd=open("/dev/null",O_RDONLY);

        if(ptr->infd!=0)
        {
            close(0);
            dup(ptr->infd);
        }
        if(ptr->outfd!=1)
        {
            close(1);
            dup(ptr->outfd);
        }


        if(backgnd==FALSE)
        {
            signal(SIGINT,SIG_DFL);
            signal(SIGQUIT,SIG_DFL);
        }

        for(i=3;i<OPEN_MAX;++i)
        {close(i);}
        if(ptr->av[0][0]=='!')                            //history 命令
        {
            int index=ptr->av[0][1]-'0';
            //int dex=ptr->av[0][1]-'0';
            if(ptr->av[0][2]!='\0')
            {

                int dex1=ptr->av[0][2]-'0';
                index=index*10+dex1;
            }
            if(ptr->av[0][1]=='!')  index=1;


            execvp(historyCmd[hisNum-index].av[0],historyCmd[hisNum-index].av);
            exit(1);
        }
        if(strcmp(ptr->av[0],"myname")==0) {printf("%s\n",MYNAME);exit(1);}

        if(execvp(ptr->av[0],ptr->av)==-1)
        {
            printf("%s:Cannot find this comond!\n",ptr->av[0]);
            exit(1);

        }
        //if(ptr->av[0][0]!='!')
        // addCmd(*ptr);
    }
}

int check(char* ptr)
{
    char* tptr;
    while(*lineptr==' ')
        lineptr++;
    tptr=lineptr;
    while(*ptr!='\0'&&*ptr==*tptr)
    {
        ptr++;
        tptr++;
    }
    if(*ptr!='\0')
        return(FALSE);
    else
    {
        lineptr=tptr;
        return(TRUE);
    }

}

void getname(char* name)

{
    int i;
    for(i=0;i<MAXNAME;++i)
    {
        switch(*lineptr)
        {

            case '>':
            case '<':
            case '|':
            case '&':
            case ' ':
            case '\t':
            case '\n':
                *name='\0';
                return;
            default:
                *name++=*lineptr++;
                break;
        }
    }
    *name='\0';
}

void addCmd(struct cmd newCmd)
{
    // historyCmd[hisNum++]=newCmd;
    int s;
    char* p;
    char* tp;
    /*for(s=MAXSAVE-1;s>0;s--)
    {
      historyCmd[s]=historyCmd[s-1];
    }
 */
    if(hisNum<MAXSAVE)
    {
        for(s=0;newCmd.av[s]!=NULL;s++)
        {
            tp=historyCmd[hisNum].av[s];
            p=newCmd.av[s];
            while(*p!='\0')
            {
                *tp++=*p++;
            }
            *tp='\0';
        }
        for(;s<MAXARG;s++)
            historyCmd[hisNum].av[s]=NULL;
        hisNum++;

    }
    else
        printf("Cannot save so much!\n");
}
void printHistory()
{
    int k;
    int ps;
    for(k=hisNum-1;k>=0;k--)
    {
        printf("%d:",hisNum-k);
        ps=0;
        while(historyCmd[k].av[ps]!=NULL)
            printf("%s ",historyCmd[k].av[ps++]);
        printf("\n");
    }
}