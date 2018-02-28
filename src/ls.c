//
// Created by brunon on 18-2-27.
//

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>

void ksh_ls();
void showFile(char* filename);
void show_file_info(char* filename, struct stat* info_p);
void mode_to_letters(int mode, char * str);
char* uid_to_name(uid_t uid);
char* gid_to_name(gid_t gid);

void ksh_ls() {
    DIR* dir_ptr = opendir(".");    //当前目录下
    struct dirent* direntp;
    while((direntp = readdir(dir_ptr)) != NULL) {  //逐个显示目录里的文件信息
        showFile(direntp->d_name);   //ls -l
        //printf("%s  ", direntp->d_name);
    }
    printf("\n");
    closedir(dir_ptr);
}

void showFile(char* filename) {
    struct stat info;
    if (stat(filename, &info) == -1)     //读取文件信息失败
        perror(filename);
    else {                               //显示文件基本信息
        show_file_info( filename, &info );
    }
}

void show_file_info(char *filename, struct stat *info_p)
{
    char modestr[11];
    mode_to_letters(info_p->st_mode, modestr);
    printf("%s"  , modestr);
    //st_nlink连接该文件的硬链接数，刚建立的文件值为1
    printf("%4d "  , (int) info_p->st_nlink);
    printf("%-8s " , uid_to_name(info_p->st_uid));
    printf("%-8s " , gid_to_name(info_p->st_gid));
    printf("%8ld " , (long)info_p->st_size);
    printf("%.12s ", 4+ctime(&info_p->st_mtime));
    printf("%s\n" , filename);
}

void mode_to_letters(int mode, char * str)
{
    strcpy(str, "----------");           /* default=无参数 */
    if (S_ISDIR(mode))
        str[0] = 'd';    /* 目录      */
    if (S_ISCHR(mode))
        str[0] = 'c';    /* 字符设备   */
    if (S_ISBLK(mode))
        str[0] = 'b';    /* 块设备     */
    if (mode & S_IRUSR)
        str[1] = 'r';    /* 用户权限  */
    if (mode & S_IWUSR)
        str[2] = 'w';
    if (mode & S_IXUSR)
        str[3] = 'x';
    if (mode & S_IRGRP)
        str[4] = 'r';    /* 组权限 */
    if (mode & S_IWGRP)
        str[5] = 'w';
    if (mode & S_IXGRP)
        str[6] = 'x';
    if (mode & S_IROTH)
        str[7] = 'r';    /* 其人的权限 */
    if (mode & S_IWOTH)
        str[8] = 'w';
    if (mode & S_IXOTH)
        str[9] = 'x';
}

char* uid_to_name(uid_t uid)     //获取用户ID
{
    struct  passwd *pw_ptr;
    static  char numstr[10];
    if ((pw_ptr = getpwuid(uid)) == NULL) {
        sprintf(numstr,"%d", uid);
        return numstr;
    }
    else {
        return pw_ptr->pw_name ;
    }
}



char* gid_to_name(gid_t gid)    //获取组ID
{
    struct group *grp_ptr;
    static  char numstr[10];
    if ((grp_ptr = getgrgid(gid)) == NULL) {
        sprintf(numstr,"%d", gid);
        return numstr;
    }
    else {
        return grp_ptr->gr_name;
    }
}

int main(int argc, char**argv){
    printf("ksh-shell:\n");
	ksh_ls();
    return 0;
}
