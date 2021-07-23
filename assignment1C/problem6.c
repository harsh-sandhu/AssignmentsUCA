/*
 * program to check if the given string is palindrome or not
 *
 * Compilation: gcc -o check_palindrome problem6.c
 * execution: ./check_palindrome
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 */

#include <stdio.h>
#include <stdbool.h>
#define N 100000

//Declaring a function to change string to lowercase
void to_lower_case(char* str);

//Declaring a function to check if string is palindrome or not
bool check_palindrome(char* str,int len);

//Decalring a function to find the length of string
int length(char* str);

int main(){
    //the (character array)string str
    char str[N];

    //Input the string str
    printf("Enter the string\n");
    fgets(str,N,stdin);

    //Converting the string to lower case
    to_lower_case(str);

    //finding the length of string
    int len=length(str);
    
    //checking for palindrome
    if(check_palindrome(str,len)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    
    return 0;
}

//Function to check wheather the given string is palindrome
//return type: boolean
bool check_palindrome(char* str,int len){
    
    //intializing two varibles pointing to first and last index
    int i=0,j=len-2;

    //iterate through the string
    while(i<j){

	//if there is a white space ignore and point to next index( previous index in casse of j)
    	if(str[i]==' '){
	    i++;
	    continue;
	}
	if(str[j]==' '){
	    j--;
	    continue;
	}

        //if at some point value at i and j are not same
	//that means its not a palindrome string
        if(str[i]!=str[j]){
	    return false;
	}

	//changing i to next index and j to previous index
	i++;
	j--;
    }

    //if the string passes the whole loop with every value of i equal to value at j
    //that means string is palindrome
    return true;
}
//Function to change the string to lowerCase 
void to_lower_case(char *str){
    
    for(int i=0;str[i]!='\0';i++){

	//if character is in uppercase then add 32 into its ASCII value
        if(str[i]>'A'&&str[i]<'Z'){
	    str[i]+=32;
	}
    }
}
//Function for finding the length of the given string
int length(char* str){

	//initializing a len variable for length
	int len=0;

	for(int i=0;str[i]!='\0';i++){
	    len++;
	}
	return len;
}
