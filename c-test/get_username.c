#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

char dir_upload[256];

char * get_userdir(void)
{
    uid_t userid;
    struct passwd *pwd;

    userid = getuid();
    pwd = getpwuid(userid);
    
    return pwd->pw_dir;
}
#define USER_DIR get_userdir()

char * get_upload_folder(void)
{
    sprintf(dir_upload,"%s/upload-folder",USER_DIR);
    return dir_upload;
}
#define DIR_UPLOAD get_upload_folder()

int main(int argc, const char *argv[])
{
    uid_t userid;
    struct passwd *pwd;

    userid = getuid();
    printf("userid is %d\n",userid);
    pwd = getpwuid(userid);
    printf("username: %s\n",pwd->pw_name);
    printf("userdir: %s\n",pwd->pw_dir);

    printf("%s\n",USER_DIR);
    printf("upload: %s\n",DIR_UPLOAD);
    
    return 0;
}

