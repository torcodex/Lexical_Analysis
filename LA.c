#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int iskey(char b){
    int flag;
    char keys[21][10] = {
        "char", "int", "void", "if", "for", "else", "while", "do", "break", "return", "switch", "case", "default", "continue", "const", "goto", "typeof", "sizeof", "struct", "enum", "auto"
    };
    for(int i=0;i<21;i++){
        if(strcmp(keys[i],b)==0){
            flag = 1;
        }
    }
    return flag;
}

void main(){
    char ch,buffer[15],buf[15], op=[]="+-*/%=",num="0123456789", sc="{[;,]}";
    FILE *fp;
    int i,j=0,k=0,flag=0;
    fp=fopen("pr.txt","r");
    if(fp==NULL){
        printf("Error!!!");
    }
    while(ch=fgetc(fp)!=EOF){
        for(i=0;i<6;i++){
            if(ch==op[i]){
                printf("%c is an operator\n",ch);
            }
            if(ch==sc[i]){
                printf("%c is an special character\n",ch);
            }
        }
        if(isalpha(ch)){
            buffer[j++]=ch;
        }
        if(isdigit(ch)){
            buf[k++]=ch;
            flag=1
        }
    }
}