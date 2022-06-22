#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

void Read();
void Write();
void append();
void clear();
void help();
void dt();
void exits();
void startscreen();
void removes();
void renames();
void edit();
void cdir();
void copy();
void cknow();
void lknow();
void ccount();
void gcd();
void lcm();
void ls(const char *dir);
void cat(const char *pathname);
void mv(const char *source,const char *destination);
int func(int argc, char *argv[]);
int main(int argc, char *argv[]){

    char a[100];
    system("clear");
    dt();
    printf("\033[1;36m\033[1;40m");
    printf("                        |--------------------------------------\n");
    printf("                        |            20's Terminal            |\n");
    printf("                        |                                     |\n");
    printf("                        |   Welcome To Group 20's Terminal    |\n");
    printf("                        |   Type \"menu\" for more things!      |\n");
    printf("                        ---------------------------------------\n");

    while(1){

    printf("\n          >>> ");
    fflush(stdin);
    scanf("%s", a);

    if(strcmp(a, "read") == 0){
        Read();
    }
    else if(strcmp(a, "write") == 0){
        Write();
    }
    else if(strcmp(a, "bash") == 0){
          func(argc,&argv);

    }else if(strcmp(a, "append") == 0){

        append();

    }else if(strcmp(a, "clr") == 0){

        system("clear");
        

    }else if(strcmp(a, "menu") == 0){

        menu();

    }else if(strcmp(a, "dt") == 0){

        dt();

    }else if(strcmp(a, "stscr") == 0){

        startscreen();

    }else if(strcmp(a, "remove") == 0){

        removes();

    }else if(strcmp(a, "rename") == 0){

        renames();

    }else if(strcmp(a, "edit") == 0){

        edit();

    }else if(strcmp(a, "cdir") == 0){

        cdir();

    }else if(strcmp(a, "copy") == 0){

        copy();

    }else if(strcmp(a, "cknow") == 0){

        cknow();

    }else if(strcmp(a, "lknow") == 0){

        lknow();

    }else if(strcmp(a, "ccount") == 0){

        ccount();

    }else if(strcmp(a, "gcd") == 0){

        gcd();

    }else if(strcmp(a, "lcm") == 0){

        lcm();

    }else if(strcmp(a, "exit") == 0){

        exits();

    }else{
        printf("            Enter only stated things in menu\n");
    }


    }

    return 0;

}

void Read(){
    printf("            \033[1;36m\033[1;40m");
    char a[100];

    printf("            Use .txt or any other extension to read\nEx: hello.txt\n\n");

    FILE *p;

    printf("            Enter File Name To Read: ");
    printf("\n          >>> ");
    scanf("%s", a);

    printf("            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    char c;

    p = fopen(a, "r");

    if(p == NULL){
        printf("\n            Error\n");
    }

    printf("\n");

    c = fgetc(p);

    while(c != EOF){
        printf("%c", c);
        c = fgetc(p);
    }

    printf("            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    fclose(p);

    printf("\n\n             Successfully Read\n");

}

void Write(){
     
    char a[100];

    printf("            Use .txt or any other extension to write\nEx: hello.txt\n\n");


        FILE *p;

        printf("            Enter File Name To Write: ");
        printf("\n          >>> ");
        scanf("%s", a);

        p = fopen(a, "w");

        fflush(stdin);

        printf("            Enter ~ to exit from writing\n");
        printf("            Start writing: \n");

        int ch=NULL;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }



        fclose(p);

        printf("\n\n            Successfully Written\n");
}

void append(){

    char a[100];

    printf("            Use .txt or any other extension to append\nEx: hello.txt\n\n");



        FILE *p;

        printf("            Enter File Name To Append: ");
        printf("\n          >>> ");
        scanf("%s", a);

        if(p == NULL){
        printf("Error");
        }

        p = fopen(a, "a");

        printf("            Enter ~ to exit from writing\n");
        printf("            Start writing: \n");

        int ch=NULL;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }


        fclose(p);

        printf("\n\n            Successfully Appended\n");

}

void clear(){
    printf("            \033[1;36m\033[1;40m");
    system("clear");
    
}

void dt(){
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void startscreen(){
    system("clear");
    printf("            \033[1;36m\033[1;40m");
    dt();
    printf("                        |--------------------------------------\n");
    printf("                        |            20's Terminal            |\n");
    printf("                        |                                     |\n");
    printf("                        |   Welcome To Group 20's Terminal    |\n");
    printf("                        |   Type \"menu\" for more things!      |\n");
    printf("                        ---------------------------------------\n");
}

void removes(){
    char a[100];
    int m;

    printf("            Enter a file name to remove: ");
    printf("\n          >>> ");
    scanf("%s", a);

    m = remove(a);

    if(m == 0){
        printf("            Successfully removed a file\n");
    }else{
        printf("            Error in removing please check if the file exists in directory\n");
    }

}

void renames(){

    char a[100], b[100];
    int m;

    printf("            Enter a file name to rename: ");
    printf("\n          >>> ");
    scanf("%s", a);

    printf("\n            Enter new name: ");
    printf("\n          >>> ");
    scanf("%s", b);

    m = rename(a, b);

    if(m == 0){
        printf("            Successfully renamed a file\n");
    }else{
        printf("            Error in removing please check if the file exists in directory\n");
    }

}

void edit(){
    
    system("gedit");

    printf("            Successfully opened the editing software\n");
}

void cdir(){
    char a[100];

    printf("            Your Directory:\n");
    system("dir");
}

void copy(){

    char a[100], b[100];
    int c;
    FILE *p, *q;

    printf("            Use .txt or any other extension to copy\nEx: hello.txt\n\n");
    printf("            Enter existing file name: ");
    printf("\n          >>> ");
    scanf("%s", a);
    printf("\n            Enter copy destination file name: ");
    printf("\n          >>> ");
    scanf("%s", b);

    if(p == NULL){
        printf("            The file is not found\n");
    }else{

    p = fopen(a, "r");
    q = fopen(b, "a");

    c = fgetc(p);
    while(c != EOF){
        fputc(c, q);
        c = fgetc(p);
    }

    fclose(p);
    fclose(q);

    printf("\n            Successfully copied\n");
    }

}

void cknow(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("            Use .txt or any other extension to cknow\nEx: hello.txt\n\n");
    printf("            Enter existing file name: ");
    printf("\n          >>> ");
    scanf("%s", a);

    fflush(stdin);
    printf("\n            Enter the character to search: ");
    printf("\n          >>> ");
    scanf("%c", &cha);

    p = fopen(a, "r");

    if(p == NULL){
        printf("            The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == cha){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("            No. of times %c repeated is = %d\n",  cha, count);
    }
}

void lknow(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("            Use .txt or any other extension to cknow\nEx: hello.txt\n\n");
    printf("            Enter existing file name: ");
    printf("\n          >>> ");
    scanf("%s", a);

    p = fopen(a, "r");

    if(p == NULL){
        printf("            The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("            No. of lines = %d\n", count);
    }

}

void ccount(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("            Use .txt or any other extension to ccount\nEx: hello.txt\n\n");
    printf("            Enter existing file name: ");
    printf("\n          >>> ");
    scanf("%s", a);

    p = fopen(a, "r");

    if(p == NULL){
        printf("            The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c != ' ' && c != '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("            No. of characters in file is = %d\n", count);
    }
}

void gcd(){
    int i, gcd, a, b;

    printf("            Enter two numbers (by pressing enter):\n");
    printf("\n          >>> ");
    scanf("%d %d", &a, &b);

    for(i=1; i<=a && i<=b; i++){
        if(a%i==0 && b%i == 0){
            gcd = i;
        }
    }

    printf("            GCD = %d\n", gcd);
}

void lcm(){
    int i, gcd, lcm, a, b;

    printf("            Enter two numbers (by pressing enter):\n");
    printf("\n          >>> ");
    scanf("%d %d", &a, &b);

    for(i=1; i<=a && i<=b; i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }

    lcm = (a*b)/gcd;

    printf("            LCM = %d\n", lcm);
}




void menu(){
    printf("\n");
    printf("            ------------------------------------------------------------------------\n");
    printf("            |You can enter the following commands:                                 |\n");
    printf("            |write  >>> To write to a file                                         |\n");
    printf("            |read   >>> To read from a file                                        |\n");
    printf("            |append >>> To append a file                                           |\n");
    printf("            |remove >>> To remove a file                                           |\n");
    printf("            |rename >>> To rename a file                                           |\n");
    printf("            |clr    >>> To clear the screen                                        |\n");
    printf("            |dt     >>> To show date and time                                      |\n");
    printf("            |stscr  >>> To show start screen                                       |\n");
    printf("            |edit   >>> To open a new file in gedit                                |\n");
    printf("            |cdir   >>> To see the directory(location) and files                   |\n");
    printf("            |copy   >>> To copy one file to new file or append to a existing file  |\n");
    printf("            |cknow  >>> To know how many time(s) a character repeated in file      |\n");
    printf("            |lknow  >>> To know how line(s) are there in a file                    |\n");
    printf("            |gcd    >>> To perform GCD of numbers                                  |\n");
    printf("            |lcm    >>> To perform LCM of numbers                                  |\n");
    printf("            |bash  >>> To run some basic bash shell commands                       |\n");
    printf("            |exit   >>> To exit                                                    |\n");
    printf("            -----------------------------------------------------------------------\n");
}
void my_cat(char *pathname)
{
    int fd, count;
    char buffer[2048];
    fd = open(pathname, O_RDONLY);
    if (fd == -1)
    {
        printf("            Error : cannot open file\n");
    }
    while ((count = read(fd, buffer, sizeof(buffer))) > 0)
    {
        printf("            %s", buffer);
    }
}

void my_ls(const char *dir)
{
    struct dirent *d;
    DIR *dh = opendir(dir);
    if (!dh)
    {
        if (errno = ENOENT)
        {
            perror("            Directory doesn't exist");
        }
        else
        {
            perror("            Unable to read directory");
        }
        exit(EXIT_FAILURE);
    }
    while ((d = readdir(dh)) != NULL)
    {
        printf("%s              \n", d->d_name);
    }
    printf("\n");
}

void my_mv(char *source, char *destination)
{
    printf("            source=%s \n             destination=%s \n ", source, destination);
    if(rename(source,destination) == -1){
        printf("            Cannot move!\n");
    }
}

int func(int argc, char *argv[])
{
    char path[2048];
    char destination[2048];
    int ch;
    while(1){
    printf("            Following are your options :");
    printf("            \n1.cat\n2.ls\n3.mv\n4.Go back to menu\n5.Exit from terminal\n");
    printf("            Choose an option : ");
    printf("\n          >>> ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("            Enter file path : ");
        printf("\n          >>> ");
        scanf("%s", path);
        my_cat(path);
    }
    else if (ch == 2)
    {
        printf("            Enter folder path : ");
        printf("\n          >>> ");
        scanf("%s", path);
        my_ls(path);
    }
    else if (ch == 3)
    {
        printf("            Enter source path : ");
        printf("\n          >>> ");
        scanf("%s", path);
        printf("            Enter destination path : ");
        printf("\n          >>> ");
        scanf("%s", destination);
        my_mv(path, destination);
    }
    else if(ch == 4)
    {
        menu();
        return;
    }
    else if(ch == 5)
    {
        exit(0);
    }
    }
}
void exits(){
    exit(1);
}
