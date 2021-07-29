/*
 * program to return index of first location of any character matching in secondary string in main string
 *
 * Compilation: gcc -o return_first_index problem11.c
 * execution: ./return_first_index
 *
 * @Harsh Sandhu , 1911981371, 29/07/21
 */

#include <stdio.h>
#define N 100000

//Declaring function for the first index from main string where characater of secondary string matches
int firstIndex(char *str1,char *str2);

int main(){
    //declaring the two strings
    char str1[N];
    char str2[N];

    //Input for main string
    printf("Enter the main string\n");
    fgets(str1,N,stdin);

    //Input for secondary string
    printf("Enter the secondary string\n");
    fgets(str2,N,stdin);

    //getting the index using the function
    int the_index=firstIndex(str1,str2);

    //printing the answer
    printf("%d\n",the_index);

    return 0;
}

//function for the first index from main string where charcater if secondary string matches
int firstIndex(char *str1,char *str2){

    //intializing a min index
    int min=100000;

    //iterating through the secondary string
    for(int i=0;str2[i]!='\0';i++){

	//iterating through the main string
        for(int j=0;str1[j]!='\0';j++){

	    //checking if character matches from main and secondary string
	    if(str1[j]!='\0'&&str1[j]!='\n'&&str1[j]==str2[i]){
		//minimum index
	        min=min<j?min:j;
		break;
	    }
	}
    }
    if(min==100000){
    	min=-1;
    }
    return min;
}
