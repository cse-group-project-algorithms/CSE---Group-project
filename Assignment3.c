#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define S 21
int i,d=1,week=1,o,j,k=0,p,p1=1,o1,used[80],C,temp[10],not_available[10],not_a,E,count=0,f1,f2,f3,f4;
char* dress[S]={'\0',"blue_jeans","black_jeans","brown_pants","black_pants",
    "blue_shirt","red_shirt","sweatshirt","sweater",
    "sandals","shoes","sneakers","boots",
    "white_socks","black_socks","orange_socks","wool_socks",
    "shorts","t_shirt","belt","jacket"};
int hot[4]={17,18,13,9};
int warm[9]={3,4,5,6,19,14,15,10,11};
int cold[7]={1,2,7,8,20,16,12};
void put_on(int clothing);
int is_dirty(int clothing);
int is_missing(int clothing);
void printC(int temp[],int p,int not_available[],int not_a);
int main()
{
    printf("WELCOME\n");
    do
    {
        printf("WEEK: %d Day: %d\n",week,d);
        printf("Enter the temperature outside(in Celsius):\n");
        scanf("%d",&C);
        if(C>=40)
        {
            not_a=0;
            p=0;
            printf("It's very hot outside\nChoose Your dress from below\n");
            for(i=0;i<4;i++)
            {
                printf("%d. %s  ",i+1,dress[hot[i]]);
            }
            printf("\nEnter:(-1 when you're done)\n");
            do
            {
                scanf("%d",&o1);
                if(o1==-1)
                {
                    break;
                }
                if(o1<0 || o1>4)
                {
                    printf("Wrong Input\n");
                }
                else
                {
                    put_on(hot[o1-1]);
                }
            }while(1);
        }
        if(C>=26 && C<=39)
        {
            not_a=0;
            p=0;
            printf("It's very warm outside\nChoose Your dress from below\n");
            for(i=0;i<9;i++)
            {
                printf("%d. %s  ",i+1,dress[warm[i]]);
            }
            printf("\nEnter:(-1 when you're done)\n");
            do
            {
                scanf("%d",&o1);
                if(o1==-1)
                {
                    break;
                }
                if(o1<0 || o1>9)
                {
                    printf("Wrong Input\n");
                }
                else
                {
                    put_on(warm[o1-1]);
                }
            }while(1);
        }
        if(C<0 || (C>=0 && C<=25))
        {
            not_a=0;
            p=0;
            printf("It's very cold outside\nChoose Your dress from below\n");
            for(i=0;i<7;i++)
            {
                printf("%d. %s  ",i+1,dress[cold[i]]);
            }
            printf("\nEnter:(-1 when you're done)\n");
            do
            {
                scanf("%d",&o1);
                if(o1==-1)
                {
                    break;
                }
                if(o1<0 || o1>7)
                {
                    printf("Wrong Input\n");
                }
                else
                {
                    put_on(cold[o1-1]);
                }
            }while(1);
        }
        printC(temp,p,not_available,not_a);
        printf("1. Exit 2. Not Exit\n");
        scanf("%d",&E);
        d++;
        if(d>7)
        {
            d=1;
            week++;
        }
        f1=0;
        f2=0;
        f3=0;
        f4=0;

    }while(E!=1);
    return 0;
}
void put_on(int clothing)
{
    if(is_dirty(clothing)==1 || is_missing(clothing)==1)
    {
        not_available[not_a]=clothing;
        not_a++;
    }
    else
    {
        used[k]=clothing;
        k++;
        temp[p]=clothing;
        p++;
    }
}
int is_dirty(int clothing)
{
    count=0;
    for(p1=0;used[p1]!=0;p1++)
    {
        if(used[p1]==clothing)
        {
            count++;
        }
    }
    if(count>=3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_missing(int clothing)
{
    for(p1=0;used[p1]!=0;p1++)
    {
        if(clothing>S)
        {
            return 1;
        }
    }
    return 0;
}
void printC(int temp[],int p,int not_available[],int not_a)
{
    if(p==0)
    {
        printf("No cloth is available\n");
    }
    else
    {
        printf("Available dresses are:\n");
        for(p1=0;p1<p;p1++)
        {
            if((f1==0) && (temp[p1]==1 || temp[p1]==2 || temp[p1]==3 || temp[p1]==4))
            {
                printf("%s\n",dress[temp[p1]]);
                f1=1;
            }
            if((f2==0) && (temp[p1]==5 || temp[p1]==6))
            {
                printf("%s\n",dress[temp[p1]]);
                f2=1;
            }
            if((f3==0) && (temp[p1]==9 || temp[p1]==10 || temp[p1]==11 || temp[p1]==12))
            {
                printf("%s\n",dress[temp[p1]]);
                f3=1;
            }
            if((f4==0) && (temp[p1]==13 || temp[p1]==14 || temp[p1]==15 || temp[p1]==16))
            {
                printf("%s\n",dress[temp[p1]]);
                f4=1;
            }
            if(temp[p1]==7 || temp[p1]==8 || temp[p1]==17 || temp[p1]==18 || temp[p1]==19 || temp[p1]==20)
            {
                printf("%s\n",dress[temp[p1]]);
            }
        }
        printf("\n");
    }
    if(not_a>0)
    {
        printf("Unavailable dress are:\n");
        for(p1=0;p1<not_a;p1++)
        {
            printf("%s\n",dress[not_available[p1]]);
        }
        printf("\n");
    }
}
