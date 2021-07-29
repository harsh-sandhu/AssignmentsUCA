/*
 * program to find rightmost index where secondary string is located in main string
 *
 * Compilation: gcc -o rightmost_index problem12.c
 * execution: ./rightmost_index
 *
 * @Harsh Sandhu, 1911981371, 29/07/21
 *
 */

#include <stdio.h>
#include <string.h>
#define N 100000

//Declaring the function to find rightmost substring index
int rightmost_substring(char* str1,char* str2);

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

    //getting the rightmost string from the function
    int the_index=rightmost_substring(str1,str2);

    //print the answer index
    printf("%d\n",the_index);

    return 0;
}

//function to find index of rightmost substring
int rightmost_substring(char *str1, char *str2){

    //finding the length of main string
    int len=strlen(str1);

    //intializing the rightmost index
    int max=-1;

    //iterating through the main string in reverse order
    for(int i=len-2;i>=0;i--){

	//if at any point first index of two strings match
	//check if its a substring of main string
    	if(str2[0]==str1[i]){

	    int j,count=0;

	    //getting the length of secondary string
	    int n=strlen(str2);

	    //iterating through the secondary string
	    for(j=0;str2[j]&&str1[i+j];j++){
		//--comparing each character of both--
		if(str1[i+j]!=str2[j]){
		    break;
		}else{
		    if(str2[j]!='\n'){
		        count++;
		    }
		}
	    }
	    //if all characters match then its a substring return answer
	    if(count==n-1){
		max=i;
		return max;
	    }
	}
    }
    return max;
}

