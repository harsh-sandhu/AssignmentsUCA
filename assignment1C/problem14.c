/*
 * program to make custom functions: strncpy,strncat,strncmp
 *
 * Compilation: gcc -o custom_string_functions problem14.c
 * execution: ./custom_string_functions
 *
 * @Harsh Sandhu, 1911981371, 29/07/21
 *
 */

#include <stdio.h>
#define N 100000

//Declaring the strncpy function
char* strnCpy(char* dest,char* source, int size);

//Declaring the strncat function
char* strnCat(char* dest,char* source, int size);

//Declaring the strncmp function
int strnCmp(char* str1,char* str2,int size);

int main(){

    //declaring the two strings and the num
    char str1[N];
    char str2[N];
    int size;

    //Input for the main string
    printf("Enter the first/destination string(press enter in case you want to use strncpy)\n");
    fgets(str1,N,stdin);
    

    //Input for the secondary string
    printf("Enter the second/source string\n");
    fgets(str2,N,stdin);

    //Input for size
    printf("Enter the size\n");
    scanf("%d",&size);

    //choice Input
    int n;
    printf("Enter your choice\n");
    printf("Enter 1 for strncpy\n");
    printf("Enter 2 for strncat\n");
    printf("Enter 3 for strncmp\n");
    scanf("%d",&n);


    //operations according the options selected
    if(n==1){
        printf("%s\n",strnCpy(str1,str2,size));
    }
    if(n==2){
        printf("%s\n",strnCat(str1,str2,size));
    }
    if(n==3){
        printf("%d\n",strnCmp(str1,str2,size));
    }

    return 0;
}

//strncpy--> copy the source string to destination string
char* strnCpy(char* dest, char* source, int size){
   
    //intializing a head pointer
    char* head=dest;

    //adding the data from source to dest
    while(*source&&size--){
	*dest=*source;
	dest++;
	source++;
    }
    //end string
    *dest='\0';

    //returning the dest
    return head;
}

//strncat--concat the source string to destination string
char* strnCat(char* dest, char* source, int size){
    
    //initailizing the index
    int i=0;

    //going the end of dest string
    while(dest[i]!='\0'){
        i++;
    }

    //incase endline is present
    if(dest[i-1]=='\n'){
        i--;
    }
    
    //copying source data to dest character by character
    int j=0;
    while(source[j]!='\0'&&size--){
    	dest[i]=source[j];
	i++;
	j++;
    }

    //returning the concatinated string
    return dest;
}

//strncmp--compare both the strings
int strnCmp(char* str1, char* str2, int size){
    
    //initailizing an intial index	
    int i=0;

    //iterating through the strings
    while(str1[i]&&str2[i]&&size--){

	//if at any index two strings dont match
	if(str1[i]!=str2[i]){

	    //return the difference between them	
	    return (int)(str1[i]-str2[i]);
	}
	i++;	
    }

    //general return statement
    return str1[i]-str2[i];
}

