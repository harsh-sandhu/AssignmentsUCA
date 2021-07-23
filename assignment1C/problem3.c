/*
 * Program to find number of vowels and consonants in a String
 *
 * Compilation: gcc -o count_vowels_consonants problem3.c
 * execution: ./count_vowels_consonants
 *
 * @Harsh Sandhu, 1911981371, 23/07/2021
 * */

#include <stdio.h>
#include <string.h>
#define N 100000

//Declaring the function to print number of vowels and consonants in a String
void count_vowels_consonants(char str[]);

int main(){
    //the String str;
    char str[N];

    //Input for String str
    printf("Enter the String\n");
    fgets(str,N,stdin);

    //passing str into the counting function
    count_vowels_consonants(str);

}

//the vowels and consonants counting function and then printing it
void count_vowels_consonants(char str[]){
    
    //creating the general vowel array
    char vowel_list[]={'a','A','e','E','i','I','o','O','u','U'};

    int vowels=0,consonants=0;

    //iterating through the String
    for(int i=0;str[i]!='\0';i++){
       
	//checking if the ith character of String is a vowel or not
	for(int j=0;j<sizeof(vowel_list)/sizeof(char);j++){
	    if(str[i]==vowel_list[j]){
	    	vowels++;
	    }
	}
	
	//adding all the alphabets which are not whitespaces
	if(str[i]!=' '){
	    consonants++;
	}

    }
    //to find consonants subtract number of vowels from alphabets(currently stroed in consonants)
    consonants-=vowels;

    //printing the number of vowels and consonants
    printf("Vowels=%d ,Consonants=%d\n",vowels,consonants);
}	
