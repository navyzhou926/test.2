#include <stdio.h>

int main(int argc, const char *argv[])
{
    char x, y, z;
    char a[2];
    char b[2];
    int c[3];
    int i = 0, j = 0;

    while ((x = getchar()) != '\n') 
    {
        if (i < 2) 
        {
            a[i] = x;
        }
        i++;
    }
    i = 0;
    while ((x = getchar()) != '\n') 
    {
        if (i < 2) 
        {
            b[i] = x;
        }
        i++;
    }
/*  while ((x=getchar())!='\n') 
    {
        a[i++]=x;
        if (i>2) 
        {
            break;
        }
    }
    i=0;
    //getchar();
    while ((x=getchar())!='\n') 
    {
        b[i++]=x;
        if (i>2) 
        {
            break;
        }
    }*/
    for (i = 0; i < 2; i++) 
    {
        if((a[i] > 96)&&(a[i] < 123))
        {
            a[i] = a[i]-87;
        }
        if((b[i] > 96)&&(b[i] < 123))
        {
            b[i] = b[i]-87;    
        }
        if((a[i]>64)&&(a[i]<91)) 
        {
            a[i]=a[i]-45;
        }
        if((a[i]>64)&&(a[i]<91)) 
        {
            b[i]=b[i]-45;    
        }
        if((a[i]>47)&&(a[i]<58))
        {
            a[i]=a[i]-48;
        }
        if((b[i]>47)&&(b[i]<58))
        {
            b[i]=b[i]-48;    
        }
    }
    c[0]=(a[0]+b[0])/16;
    c[1]=(a[0]+b[0])%16+(a[1]+b[1])/16;
    c[2]=(a[1]+b[1])%16;
    if(c[0]>0)
        printf("0x%x%x%x\n",c[0],c[1],c[2]);
    else
        printf("0x%x%x\n",c[1],c[2]);

    return 0;
}
