/*
 * Program to perform different Binary Operations using Bitwise Operators
 *
 * Compilations: gcc -o bits_and_bytes bitsAndBytes.c
 * execution: ./bits_and_bytes
 *
 * @Harsh Sandhu, 1911981371, 01/08/21
 */

#include <stdio.h>

//Declaring function for Bitwise-And(&) using ~(NOT) and |(OR)
int bitAnd(int x, int y);

//Declaring function for Bitwise-Xor(^) using ~(NOT) and |(OR)
int bitXor(int x, int y);

//Declaring function which return 1 if positive, 0 if zero and -1 if Negetive
int sign(int x);

//Declaring function extract byte n from word x
int getByte(int x, int n);

//Declaring function logicalShift to shift x to right by n
int logicalShift(int x, int n);

//Declaring function to make a ternary operation
int conditional(int x, int y, int z);

//Declaring function to return 0 if x = number except 0, 1 if x=0
int bang(int x);

//Declaring the function that return x with the n bits that begin at position p inverted
int invert (int x, int p, int n);

int main(){
    int type=0;
    printf("Choose the function you want to use\n");
    printf("1. BitAnd\n");
    printf("2. BitXor\n");
    printf("3. Sign\n");
    printf("4. GetByte\n");
    printf("5. LogicalShift\n");
    printf("6. Conditional\n");
    printf("7. Bang\n");
    printf("8. Invert\n");
    scanf("%d",&type);

    int x=0,y=0,n=0;
    if(type==1){
	printf("Enter the first number\n");
	scanf("%d",&x);
        printf("Enter the second number\n");
        scanf("%d",&y);
	printf("BitAnd => %d\n",bitAnd(x,y));
    }
    if(type==2){
        printf("Enter the first number\n");
        scanf("%d",&x);
        printf("Enter the second number\n");
        scanf("%d",&y);
        printf("BitXor => %d\n",bitXor(x,y));
    }
    if(type==3){
        printf("Enter the number\n");
        scanf("%d",&x);
        printf("sign => %d\n",sign(x));
    }

    if(type==4){
        printf("Enter the number\n");
        scanf("%d",&x);
        printf("Enter the byte number\n");
        scanf("%d",&n);
        printf("getByte => %d\n",getByte(x,n));
    }
    if(type==5){
        printf("Enter the number\n");
        scanf("%d",&x);
        printf("Enter the number by which you want to shift\n");
        scanf("%d",&n);
        printf("logicalShift => %d\n",logicalShift(x,n));
    }
    if(type==6){
        printf("Enter the first number\n");
        scanf("%d",&x);
        printf("Enter the second number\n");
        scanf("%d",&y);
	printf("Enter the third number\n");
	scanf("%d",&n);
        printf("conditional => %d\n",conditional(x,y,n));
    }
    if(type==7){
        printf("Enter the number\n");
        scanf("%d",&x);
        printf("bang => %d\n",bang(x));
    }
    if(type==8){
        printf("Enter the number\n");
        scanf("%d",&x);
        printf("Enter the position\n");
        scanf("%d",&y);
	printf("Enter the number of bits\n");
	scanf("%d",&n);
        printf("invert => %d\n",invert(x,y,n));
    }

}

int bitAnd(int x,int y){
    return ~((~(x|x))|(~(y|y)));
}

int bitXor(int x,int y){
    return ~((~(x&(~(x&y))))&(~(y&(~(x&y)))));
}

int sign(int x){
    return (x>>31)-(-x>>31);
}

int getByte(int x, int n){
    return (x>>(8*n))&255;
}

int logicalShift(int x, int n){
    return (int)((unsigned int)x>>n);
}

int conditional(int x, int y,int z){
    return (x&y)|((~x)&z);
}

int invert(int x, int p, int n){
    return x ^ (~(~0 << n) << p); 
}

int bang(int x){
    return (( ~((~x)+1) & ~x) >> 31) & 1;
}

