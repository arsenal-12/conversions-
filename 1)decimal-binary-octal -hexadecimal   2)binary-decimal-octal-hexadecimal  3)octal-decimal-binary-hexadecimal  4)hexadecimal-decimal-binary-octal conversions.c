/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define max 100
int a[max],d[max],c[max],i=0,j=0,k=0;
long double fraDecimal=0.0,dFractional=0.0;
long int dIntegral = 0,bIntegral=0,bFractional[max];
long int intFactor=1,rem,flag=0;
char fraBinary[max],fraoctal[max],frahexa[max];
int decimalnumber=0;
void divi(int num,int base)
{
    int q;
    i=0;
    while(num!=0)
    {
        q=(int)num/base;
        a[i]=num%base ;
        i++;
        num=q;
    }
    
}

void replace(int d[])
{
      if(d[k]==10)
      d[k]='A';
      else if(d[k]==11)
      d[k]='B';
      else if(d[k]==12)
      d[k]='C';
      else if(d[k]==13)
      d[k]='D';
      else if(d[k]==14)
      d[k]='E';
      else
      d[k]='F';
    
      
}

int rep(int d)
{
      if(d==10)
      d='A';
      else if(d==11)
      d='B';
      else if(d==12)
      d='C';
      else if(d==13)
      d='D';
      else if(d==14)
      d='E';
      else
      d='F';
      return d;
}
    

void fractional_part(float frac,int base)
{
  int b,count=0;
   float a;
  while(frac!=0 || count<6)
  {
    a=frac*base;
    b=(int)a;
    if(base==16)
    {
      if(b>9 && b<16)
      {
        int l=rep(b);
        printf("%c",l);
      }
      else
      printf("%d",b);
    }
    else
    printf("%d",b);
    frac=(a-b);
    count++;
  }
}

void deci_in_bin_oct_hex(int num,int base,float frac)
{
    divi(num,base);
    int n=i-1;
    k=0;
    for(j=n;j>=0;j--)
    {
        d[k]=a[j];
        if(d[k]>=10 && base==16)
        {
        replace(d);
        printf("%c ",d[k]);
        }
         else
        printf("%d ",d[k]);
        
        k++;
    }
    printf(".");
    fractional_part(frac,base);
    printf("\n");
}

int to_deci(int num,int base)
{
    int x,i=0;
    float sum=0;
  while(num!=0)
  {
    x=num%10;
    int p=pow(base,i);
    sum=sum+(x*p);
    i++;
    num=(int)num/10;
  }
  return sum;
    
}


void deci_conversions(int num,float frac)
{
    printf("binary number is:");
    deci_in_bin_oct_hex(num,2,frac);         //dec->binary(divide by 2)
    printf("octal number is:");
    deci_in_bin_oct_hex(num,8,frac);        //dec->octal(div by 8)
    printf("heaxdecimal  number is:");
    deci_in_bin_oct_hex(num,16,frac);       //dec->hexa(div by 16)
}


float bin_conver(char fraBinary[max],int base)
{
    long double fraFactor=1.0/base;
    while(fraBinary[i]){
        
         if(fraBinary[i] == '.')
             flag = 1;
         else if(flag==0)
             bIntegral = bIntegral * 10 + (fraBinary[i] -48);
         else
              bFractional[k++] = fraBinary[i] -48;
         i++;
    }
   
    dIntegral=to_deci(bIntegral,base);
   
    for(i=0;i<k;i++){
         dFractional  = dFractional  + bFractional[i] * fraFactor;
         fraFactor = fraFactor / base;
    }

    fraDecimal = dIntegral + dFractional ;
     return fraDecimal;
    
}

float hex_deci(char hexdecnumber[max],int base)
{
    int m=0;
    char bIntegral[max];
    char bFractional[max];
    
    while(hexdecnumber[i]){
        
         if(hexdecnumber[i] == '.')
             flag = 1;
         else if(flag==0)
             bIntegral[m++] = hexdecnumber[i];
         else
              bFractional[k++] = hexdecnumber[i];
         i++;
    }
   
    
    
int decimalnumber, i;
    
    int cnt;
    int digit;
  
    cnt = 0;
    decimalnumber = 0;
    
    for (i = (strlen(bIntegral) - 1); i >= 0; i--) {
  
        switch (bIntegral[i]) {
        case 'A':
        case 'a':
            digit = 10;
            break;
        case 'B':
        case 'b':
            digit = 11;
            break;
        case 'C':
        case 'c':
            digit = 12;
            break;
        case 'D':
        case 'd':
            digit = 13;
            break;
        case 'E':
        case 'e':
            digit = 14;
            break;
        case 'F':
        case 'f':
            digit = 15;
            break;
        default:
            digit = bIntegral[i] - 0x30;
        }
        decimalnumber = decimalnumber + (digit)*pow((double)16, (double)cnt);
        cnt++;
    }
    float fractionalnumber=0.0;
    cnt=-1;
    digit=0;
    for (i=0;i<strlen(bFractional); i++) {
  
        switch (bFractional[i]) {
        case 'A':
        case 'a':
            digit = 10;
            break;
        case 'B':
        case 'b':
            digit = 11;
            break;
        case 'C':
        case 'c':
            digit = 12;
            break;
        case 'D':
        case 'd':
            digit = 13;
            break;
        case 'E':
        case 'e':
            digit = 14;
            break;
        case 'F':
        case 'f':
            digit = 15;
            break;
        default:
            digit = bFractional[i];
        }
        fractionalnumber = fractionalnumber + (digit)*pow((double)16, (double)cnt);
        cnt--;
    }
    float total=decimalnumber+fractionalnumber;
    printf("Decimal number is: %f", total);
    return total;
}



void bin_conversions(char fraBinary[max])

{   float fraDecimal;
    fraDecimal=bin_conver(fraBinary,2);
    printf("decimal number: %f",fraDecimal);
    int integer=(int)fraDecimal;
    float frac=fraDecimal-integer;
    printf("\noctal number is:");
    deci_in_bin_oct_hex(integer,8,frac);        //dec->octal(div by 8)
    printf("heaxdecimal  number is:");
    deci_in_bin_oct_hex(integer,16,frac); 
    
     
}

void oct_conversions(char fraoctal[max])
{
    float fraDecimal;
    fraDecimal=bin_conver(fraoctal,8);
    printf("decimal number is:%f",fraDecimal);
    int num=(int)fraDecimal;
    float frac=fraDecimal-num;
    printf("\nbinary number is:");
    deci_in_bin_oct_hex(num,2,frac);         //dec->binary(divide by 2)
    printf("heaxdecimal  number is:");
    deci_in_bin_oct_hex(num,16,frac);       //dec->hexa(div by 16)
}
void hex_conversions(char frahexa[max])
{
    float s=hex_deci(frahexa,16);
    int num=(int)s;
    float frac=s-num;
    printf("\nbinary number is:");
    deci_in_bin_oct_hex(num,2,frac);         //dec->binary(divide by 2)
    printf("octal number is:");
    deci_in_bin_oct_hex(num,8,frac);       //
    
           
}

int main()
{
    int ch,integer;
    float n,frac;
    printf("\nconversions!!");
    printf("\nenter\n1.decimal -->binary converters-->octal-->hexadecimal\n2.binary->decimal->octal->hexadecimal conversions\n3.octal->decimal->binary ->hexadecimal converters\n4.hexadecimal->decimal->binary->octal conversions\n5.exit\nenter the choice :");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                 printf("enter the decimal number:");
                 scanf("%f",&n);
                 integer=(int)n;
                 frac=n-integer;
                 deci_conversions(integer,frac);
                 break;
                 
            case 2:     
                printf("Enter any fractional binary number: ");
                scanf("%s",fraBinary);
                bin_conversions(fraBinary);
                break;
            
            case 3:  
                printf("Enter any fractional octal number: ");
                scanf("%s",fraoctal);
                oct_conversions(fraoctal);
                 break;
                 
            case 4:  
                printf("Enter any fractional hexadecimal number: ");
                scanf("%s",frahexa);
                hex_conversions(frahexa);
                 break;
            
            case 5:
                   exit(0);
            
            default:printf("enter crt ch!!");       
        

    }    
    

   return 0;
}

