/*
 * program to find if secondary string occurs at end of main string
 *
 * Compilation: gcc -o end_substring problem13.c
 * execution: ./end_substring
 *
 * @Harsh Sandhu, 1911981371, 29/07/21
 *
 */

#include <stdio.h>
#include <stdbool.h>
#define N 100000

//Declaring the function to find if substring is at end of main string
bool substring_at_end(char* str1,char* str2);

//Declaring the string length function
int length(char* str);

int main(){

    //declaring the two strings
    char str1[N];
    char str2[N];

    //Input for the main string
    printf("Enter the main string\n");
    fgets(str1,N,stdin);

    //Input for the secondary string
    printf("Enter the secondary string\n");
    fgets(str2,N,stdin);

    //if secondary string is substring at end of main string
    bool the_index=substring_at_end(str1,str2);

    //print the answer index
    printf("%d\n",the_index);

    return 0;
}

//function to find index of rightmost substring
bool substring_at_end(char *str1, char *str2){

    //finding the length of main string
    int main_len=length(str1);
	
    //finding the length of secondary string
    int secondary_len=length(str2);
	
    int j=main_len-secondary_len;

    //checking if secondary string is at end of main string
    for(int i=0;str1[j+i]&&str2[i];i++){
	
	//if any character is not matching return false
	if(str1[i+j]!=str2[i]){
	    return false;
	}
    }
    return true;
}

//function to find length of the string
int length(char* str){
    //intializing a size variable
    int size=0;

    //iterating through the string
    for(int i=0;str[i]!='\0';i++){
        size++;
    }

    return size;
}

