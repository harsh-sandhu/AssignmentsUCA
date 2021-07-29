/*
 * program to delete each character of one string from other string
 *
 * Compilation: gcc -o delete_string problem10.c
 * execution: ./delete_string
 *
 * @Harsh Sandhu, 1911981371, 29/07/2021
 */
#include <stdio.h>
#define N 100000

//Declaring the function to delete character of one string from other string
void deleteCharacters(char *str1,char *str2);

int main(){
    //declaring the two strings
    char str1[N];
    char str2[N];

    //Input for the main string from which characters are supposed to deleted
    printf("Enter the main string\n");
    fgets(str1,N,stdin);

    //Input for the secondary string whose characters are used to be deleted from main string
    printf("Enter the secondary string\n");
    fgets(str2,N,stdin);

    //deleting characters using the function
    deleteCharacters(str1,str2);

    //printing the output
    printf("%s\n",str1);

    return 0;
}

//function to delete character of secondary string from main string
void deleteCharacters(char *str1,char *str2){

    //iterating through each character of secondary string
    for(int i=0;str2[i]!='\0';i++){

	//iterating through each character of main string     
    	for(int j=0;str1[j]!='\0';j++){

	    //comparing character of main and secondary string
	    if(str2[i]==str1[j]){

		//if match founds, all the charcters after the matched character
		//are replaced to previous index
	        for(int k=j;str1[k]!='\0';k++){
		    str1[k]=str1[k+1];
		}

		//to repeat current index
		j--;
	    }
	}
    }
}
