/*
 * Program to Convert Hexadecimal numbers to Decimal Integer numbers
 *
 * Compilation: gcc -o htoi problem9.c
 * execution: ./htoi
 *
 * @Harsh Sandhu, 1911981371, 24/07/21
 */

#include <stdio.h>
#define N 100000

//Declaring a function to convert hexadecimal to decimal
int htoi(char* s);

//Decalring a function to find length of given string
int length(char* s);

int main(){
    //the hexadecimal string(character array)
    char s[N];

    //Input for the string s
    printf("Enter the Hexadecimal number\n");
    fgets(s,N,stdin);

    //converting the hexadecimal number to decimal number
    int decimal_number=htoi(s);

    //printing the decimal number
    printf("The Decimal value of %s",s);
    printf("%d\n",decimal_number);

    return 0;
}

//Function to convert hexadecimal number to decimal Integer values
int htoi(char* s){

    //initializing a variable for starting index 
    int start_index=0;

    //checking for '0x' or '0X' possiblity
    if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){
        start_index=2;
    }

    //Initalizing a varible to decimal value
    int decimal=0;

    //getting the length of string
    int size=length(s);

    //power varible
    int power=1; //power = 16^0;

    for(int i=size-1;i>=start_index;i--){

	//initializing the current character and declaring a number value for that character
        int curr_char=s[i];
	int num_val=0;

	//for hexadecimals from A-F(10-15)
	if(curr_char=='a'||curr_char=='A'){
	    num_val=10;
	}else if(curr_char=='b'||curr_char=='B'){
	    num_val=11;
	}else if(curr_char=='c'||curr_char=='C'){
	    num_val=12;
	}else if(curr_char=='d'||curr_char=='D'){
	    num_val=13;
	}else if(curr_char=='e'||curr_char=='E'){
	    num_val=14;
	}else if(curr_char=='f'||curr_char=='F'){
	    num_val=15;
	}else{
	    num_val=curr_char-48;
	}

	//adding the product of number value and the power of 16 to decimal
	decimal+=num_val*(power);

	//increasing the power
	power*=16;// such as 16^1, 16^2,...

    }

    //returning the decimal integer value
    return decimal;

}

//Function to find length of given string
int length(char* s){
    //Initializing a varaible for length
    int len=0;
    
    //counting the each character of string
    for(int i=0;s[i]!='\0';i++){
        len++;
    }

    //Returing length ignoring the end character
    return len-1;
}
