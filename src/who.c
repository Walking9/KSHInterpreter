#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void show_info(struct utmp*);
void show_time(long);

int main(int argc, char** argv) {
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);
    printf("ksh-shell:\n");
    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);
        return 0;
    }

    while(read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);
    close(utmpfd);

    return 0;
}

void show_info(struct utmp *utbufp) {
    if(utbufp->ut_type != USER_PROCESS)
        return;

    printf("%-8.8s", utbufp->ut_user);//左对齐，最多显示8个字符，不足右边补空格
    printf(" ");
    printf("%-8.8s", utbufp->ut_line);
    printf(" ");
    show_time(utbufp->ut_time); //显示时间
    printf("(%s)", utbufp->ut_host);
    printf("\n");
}

void show_time(long ltime) {
    char * cp;
    cp = ctime(&ltime);
    printf("%12.12s", cp+4);
}
