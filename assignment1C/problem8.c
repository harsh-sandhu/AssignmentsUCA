/*
 * program to reverse a character string
 *
 * Compilation: gcc -o reverse_string problem8.c
 * execution: ./reverse_string
 *
 * @Harsh Sandhu, 1911981371, 24/07/21
 */

#include <stdio.h>
#define N 100000

//Declaring a function to reverse a string
void reverse(char* str);

//Declaring function to get the length of string
int length(char* str);

//Declaring a function to swap values at two given index in an string
void swap(char* str,int i,int j);

int main(){
    //the string(Character array) str
    char str[N];

    //Taking input for string str
    fgets(str,N,stdin);

    //reversing the string str
    reverse(str);

    //printing the reversed string
    printf("%s\n",str);

    return 0;
}

//function to reverse the given string
void reverse(char* str){
    
    //geting the length of string
    int len=length(str);
    
    //---using a two-pointer method to reverse string in-place---

    //initailizing the two pointers
    int i=0,j=len-1;
   
    //iterating through the string
    while(i<j){
	
	//swaping the values at two pointers	   
        swap(str,i,j);

        i++;
        j--;
    } 
}

//function to swap values at two given indexs in a string
void swap(char* str, int i,int j){
    
    //swapping without using the third variable
    str[i]=str[i]+str[j];
    str[j]=str[i]-str[j];
    str[i]=str[i]-str[j];

}

//function to find length of given string
int length(char* str){
    //initializing an variable for length
    int len=0;

    //iterating through each character of string while increasing the len varible
    for(int i=0;str[i]!='\0';i++){
        len++;
    }

    //returing the length ignoring the '\0' 
    return len-1;
}
