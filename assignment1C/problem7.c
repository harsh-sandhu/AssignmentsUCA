/*
 * Program to print lines which have character length more than 80
 *
 * Compilation: gcc -o print_long_lines problem7.c
 * execution: ./print_long_lines
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 */

#include <stdio.h>
#define N 100000

//Declaring the function to print long lines
void print_long_lines(char* str);

//Declaring function to print values in string starting from given index about line break
void printLine(char* str,int start_point);

int main(){
    //the string(character array) str
    char str[N];

    //---Input for string str---
    
    //creating a temporaray string
    char tempstr[N];

    //initializing a varible index
    int index=0;

    //taking multiline input line by line
    while(1==scanf("%[^\n]%*c",tempstr)){

	//Appending the tempstr values to main string str
	for(int i=0;tempstr[i]!='\0';i++){
	    str[index++]=tempstr[i];
	}
	str[index++]='\n';
    }

    //calling function with the string str to print line with character length more than 80
    print_long_lines(str);

    return 0;
}

//function to print line which have more than 80 characters
void print_long_lines(char* str){

	//initialing a variable to point at starting of line(each line)
	int start_point=0;

	//iterating through string and checking for line breaks
	for(int i=0;str[i]!='\0';i++){

	    if(str[i]=='\n'){
		
		//if line break occurs and length of line is greater then 80, print the line
	        if(i-start_point>80){
		    printLine(str,start_point);
		}
		
		//point to start of next line
		start_point=i+1; 
	    }
	}
}

//function to print line in a given string starting from given index (upto the line break)
void printLine(char* str,int start_point){
    
    //iterating through string starting from given index and upto the line break
    for(int i=start_point;str[i]!='\0'&&str[i]!='\n';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
