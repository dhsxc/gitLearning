#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc,char **argv){
    if(argc==3){
        FILE *fp = fopen(argv[2],"r");
        if(!fp){
            printf("Could not open file!");
            return -1;
        }
        if(!strcmp(argv[1],"-c")){
            char temp;
            int num = 0;
            temp = fgetc(fp);
            while( temp != EOF ){
                temp = fgetc(fp);
                num++;
            }
            printf("%d\n",num);
        }
        else if(!strcmp(argv[1],"-w")){
            int w = 0;
            char a = fgetc(fp);
            while( a != EOF){
                if(a!=' '&&a!=','){
                    while(a!=' '&&a!=','&&a!=EOF)
                        a =fgetc(fp);
                    w++;
                    a =fgetc(fp);
                }
                else
                    a =fgetc(fp);
            }
            printf("%d\n",w);
        }
    }
}

