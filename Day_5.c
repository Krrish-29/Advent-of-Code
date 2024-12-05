#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE*ptr;
    ptr=fopen("Day_5.txt","r");
    fprintf(ptr,"%d");
}