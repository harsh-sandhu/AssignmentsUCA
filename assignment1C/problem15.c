/*
 * Program to evaluates a reverse Polish expression
 *
 * Compilation: gcc -o eval_expression problem15.c
 * execution: ./eval_expression
 *
 * @Harsh Sandhu, 1911981371, 30/07/21
 */
#include <stdio.h>
#include <limits.h>
#define N 100000

//Declaring a function to evaluates the reverse polish expression
int eval(char* str);

//Declaring a function to return length of string
int length(char* str);

int main(){
    //the string
    char str[N];
    
    //input for the string
    fgets(str,N,stdin);

    //printing the value
    printf("%d\n",eval(str));
}

//function to evaluates the reverse polish expression
int eval(char* str){

    //declaring a character array for arithmetic expressions
    char arth[N];
    //and a index varible for it
    int k=0;

    //length of string
    int len=length(str);

    //initializing an answer variable
    int ans=INT_MIN;

    //iterating through the string
    for(int i=len-1;i>=0;i--){
	
	//if charavter at index is arthmatic operator
	//add the character to arth string
    	if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
	    arth[k++]=str[i];
	}else if(str[i]>='0'&&str[i]<='9'){
            //if character is number 
	    if(ans==INT_MIN){
	    	ans=((int)str[i])-48;
	    }else{
	        k--;
		int n=((int)str[i])-48;
		//evalute expression according to arthmatic operator
		if(arth[k]=='*'){
		    ans=ans*n;
		}else if(arth[k]=='+'){
		    ans=ans+n;
		}else if(arth[k]=='-'){
		    ans=n-ans;
		}else if(arth[k]=='/'){
		    ans=n/ans;
		}
	    }
	}
    }
    //returning the answer
    return ans;
}

//function to find length of the given string
int length(char* str){

    //initializing a size variable
    int size=0;

    //iterating through the string ans counting each character
    for(int i=0;str[i];i++){
        size++;
    }

    //returning the size
    return size;
}
