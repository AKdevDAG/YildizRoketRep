#include <stdio.h>
#include <stdlib.h>


void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
   
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
   
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        printf("%d", binaryNum[j]); 
} 

enum G_range
{
    x_2G = 0b00,
    x_4G,   // 01
    x_8G,   // 10
    x_16G,  // 11
};

enum Bandwidth
{
    x_7_81Hz = 0b000,
    x_15_63Hz, // 001
    x_31_25Hz, // 010
    x_625Hz,   // 011
    x_125Hz,   // 100
    x_250Hz,   // 101
    x_500Hz,   // 110
    x_1000Hz,  // 111
};

enum Operation_Mode
{
    Normal = 0b000,
    Suspend, //001
    LowPower1, //010
    Standby, //011
    LowPower2, //100
    DeepSuspend //101
};

struct Config
{
   enum G_range gr;
   enum Bandwidth bd;
   enum Operation_Mode om ;
   unsigned int AccConfigValue ;

};



int main()
{  
    struct Config x ;
    x.gr = x_8G;    // 10
    x.bd = x_1000Hz; // 111
    x.om = LowPower1;  // 010
    x.AccConfigValue = (x.om << 5) | (x.bd << 2) | x.gr ; //01011110
    printf("AccConfigValue(Decimal): %d\n",x.AccConfigValue);
    printf("AccConfigValue(Hexadecimal):0x%x\n",x.AccConfigValue);
    printf("AccConfigValue(Binary): 0b");
    decToBinary(x.AccConfigValue);


}