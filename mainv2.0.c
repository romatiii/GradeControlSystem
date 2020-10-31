/****************************
**程序描述：学生成绩管理系统V2.0
**日期：2020/10/30
**作业题目：实验六
**输入：n（学生总数）,name[][MAX_LEN]（学生姓名）,score[]（学生成绩）,num[]（学生学号）
**输入范围：n<=30,score<=100 && score>=0,num按规定学号格式输出,name不超过10个字符（5个汉字）
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 30
#define MAX_LEN 10
int ReadNameIDScore(char name[][MAX_LEN],long num[],int score[]);
int Sum(int score[],int n);
void Average(int n,int sum);
void DataScoreSort(char name[][MAX_LEN],long num[],int score[],int n,int (*compare)(int a,int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void SwapScore(int *a,int *b);
void SwapNum(long *a,long *b);
void SwapName(char a[],char b[]);
void IDAsSort(char name[][MAX_LEN],long num[],int score[],int n);
void NameAsSort(char name[][MAX_LEN],long num[],int score[],int n);
void IDSearch(char name[][MAX_LEN],long num[],int score[],int n);
void NameSearch(char name[][MAX_LEN],long num[],int score[],int n);
void StatisticAna(int score[],int n);
void PrintNameIDScore(char name[][MAX_LEN],long num[],int score[],int n);

int main()
{
    printf("Number:200210332\nName:吴梦辰\nSubject No.6-program No.1\n\n");
    int choice;
    //循环输出任务列表直到用户输入11(Exit)
    do{
            printf("1.Input record\n");
            printf("2.Calculate total and average score of course\n");
            printf("3.Sort in descending order by score\n");
            printf("4.Sort in ascending order by score\n");
            printf("5.Sort in ascending order by student's ID\n");
            printf("6.Sort in dictionary order by name\n");
            printf("7.Search by number\n");
            printf("8.Search by name\n");
            printf("9.Statistic analysis!\n");
            printf("10.List record\n");
            printf("11.Exit\n");
            printf("Please enter your choice:");

            //读取输入选项并通过switch选择结构执行相应任务
            scanf("%d",&choice);

            int score[NUM],n,sum;
            long num[NUM];
            char name[NUM][MAX_LEN];

            switch(choice){
            case 1:
                //读取学生学号及对应成绩
                n=ReadNameIDScore(name,num,score);
                break;

            case 2:
                //计算学生总成绩及平均成绩
                sum=Sum(score,n);
                Average(n,sum);
                break;

            case 3:
                //按成绩从高到低排列名次表
                DataScoreSort(name,num,score,n,Descending);
                int i;
                for(i=0; i<n; i++)
                {
                    printf("%d %s %ld %d\n",i+1,name[i],num[i],score[i]);
                }
                printf("\n");
                break;

            case 4:
                //按成绩由低到高排列名次表
                DataScoreSort(name,num,score,n,Ascending);
                int j;
                for(j=0; j<n; j++)
                {
                    printf("%d %s %ld %d\n",n-j,name[j],num[j],score[j]);
                }
                printf("\n");
                break;

            case 5:
                //按学号由小到大排列成绩表
                IDAsSort(name,num,score,n);
                int k;
                for(k=0; k<n; k++)
                {
                    printf("%s %ld %d\n",name[k],num[k],score[k]);
                }
                printf("\n");
                break;

            case 6:
                //按姓名字母顺序排列成绩表
                NameAsSort(name,num,score,n);
                break;

            case 7:
                //按学号查询学生排名及其考试成绩
                IDSearch(name,num,score,n);
                break;

            case 8:
                //按姓名查询学生排名及其考试成绩
                NameSearch(name,num,score,n);
                break;

            case 9:
                //按优秀、良好、中等、及格、不及格5个类别统计每个类别的人数及其所占百分比
                StatisticAna(score,n);
                break;

            case 10:
                //输出学生姓名、学号及考试成绩
                PrintNameIDScore(name,num,score,n);
                break;

            case 11:
                //结束程序
                break;

            default:
                printf("Input wrong choice!\n\n");
                break;
            }

        }while(choice != 11);
    return 0;
}

/*************
**函数名：ReadNameIDScore
**输入：name[][MAX_LEN],num[],score[]
**name[][MAX_LEN]:char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**输出：n
**n：学生总数
**功能描述：读取学生学号及对应成绩
**调用模块：输入choice为1时
*************/
int ReadNameIDScore(char name[][MAX_LEN],long num[],int score[])
{
    int i,n,flag;
    printf("How many students?\n");
    scanf("%d",&n);

    do{
            flag=0;
            printf("Please input student's ID and score,format as:(王天宇 20201111 89)\n");
            for(i=0; i<n; i++)
            {
                scanf("%s %ld %d",name[i],&num[i],&score[i]);
            }

            for(i=0; i<n; i++)
            {
                if(score[i]<0 || score[i]>100)
                    flag++;
            }
            if(flag)
                printf("Score input wrong!\n\n");
    }while(flag);

    printf("Have stored the data successfully,thanks!\n\n");

    return n;
}

/*************
**函数名：Sum
**输入：n,score[]
**n：int,学生总数
**score[]：int,学生成绩
**输出：sum
**sum：学生总成绩
**功能描述：计算学生总成绩
**调用模块：输入choice为2时
*************/
int Sum(int score[],int n)
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum += score[i];
    }

    printf("The total score of course is %d\n",sum);
    return sum;
}

/*************
**函数名：Average
**输入：n,sum
**n：int,学生总数
**sum：int,学生总成绩
**功能描述：计算学生平均成绩
**调用模块：输入choice为2时
*************/
void Average(int n,int sum)
{
    float average;
    average=(float)sum/n;
    printf("The average score of course is %f\n\n",average);
}

/*************
**函数名：SwapScore
**输入：*a,*b
** *a：分数1地址
** *b：分数2地址
**功能描述：交换分数1、2
**调用模块：进行排序（输入choice为3、4、5、6、7、8时）
*************/
void SwapScore(int *a,int *b)
{
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}

/*************
**函数名：SwapNum
**输入：*a,*b
** *a：学号1地址
** *b：学号2地址
**功能描述：交换学号1、2
**调用模块：进行排序（输入choice为3、4、5、6、7、8时）
*************/
void SwapNum(long *a,long *b)
{
    long temp;
    temp=*b;
    *b=*a;
    *a=temp;
}

/*************
**函数名：SwapName
**输入：a[],b[]
** a[]：char,姓名1所在行地址
** b[]：char,姓名2所在行地址
**功能描述：交换姓名1、2
**调用模块：进行排序（输入choice为3、4、5、6、7、8时）
*************/
void SwapName(char a[],char b[])
{
    char temp[MAX_LEN];
    strcpy(temp,b);
    strcpy(b,a);
    strcpy(a,temp);
}

/*************
**函数名：DataScoreSort
**输入：name[][MAX_LEN],num[],score[],n,*compare(int a,int b)
**name[][MAX_LEN]:char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
** *compare(int a,int b)：函数指针，判断ab大小决定升降序
**功能描述：按成绩（从高到低或从低到高）排列名次表
**调用模块：输入choice为3、4时
*************/
void DataScoreSort(char name[][MAX_LEN],long num[],int score[],int n,int (*compare)(int a,int b))
{
    int i,j,k;

    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if((*compare)(score[k],score[j]))
            {
                k=j;
            }
        }
        if(k != i)
        {
            SwapScore(&score[i],&score[k]);
            SwapNum(&num[i],&num[k]);
            SwapName(name[i],name[k]);
        }
    }
}

/*************
**函数名：Ascending
**输入：a,b
**a：int,成绩1
**b：int,成绩2
**功能描述：判断成绩为升序排列
**调用模块：进行按成绩排序（输入choice为4时）
*************/
int Ascending(int a,int b)
{
    return a > b;
}

/*************
**函数名：Descending
**输入：a,b
**a：int,成绩1
**b：int,成绩2
**功能描述：判断成绩为降序排列
**调用模块：进行按成绩排序（输入choice为3时）
*************/
int Descending(int a,int b)
{
    return a < b;
}

/*************
**函数名：IDAsSort
**输入：name[][MAX_LEN],num[],score[],n
**name[][MAX_LEN]：char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按学号由小到大排列成绩表
**调用模块：输入choice为5时
*************/
void IDAsSort(char name[][MAX_LEN],long num[],int score[],int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(num[j]<num[k])
                k=j;
        }

        if(k != i)
        {
            SwapScore(&score[i],&score[k]);
            SwapNum(&num[i],&num[k]);
            SwapName(name[i],name[k]);
        }
    }
}

/*************
**函数名：NameAsSort
**输入：name[][MAX_LEN],num[],score[],n
**name[][MAX_LEN]：char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按姓名字母顺序排列成绩表
**调用模块：输入choice为6时
*************/
void NameAsSort(char name[][MAX_LEN],long num[],int score[],int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j],name[k])<0)
                k=j;
        }
        if(k != i)
        {
            SwapScore(&score[i],&score[k]);
            SwapNum(&num[i],&num[k]);
            SwapName(name[i],name[k]);
        }
    }

    //输出学生姓名、名次、学号、成绩
    for(i=0; i<n; i++)
    {
        printf("%s %ld %d\n",name[i],num[i],score[i]);
    }
    printf("\n");
}

/*************
**函数名：IDSearch
**输入：name[][MAX_LEN],num[],score[],n
**name[][MAX_LEN]：char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按学号查询学生排名及其考试成绩
**调用模块：输入choice为7时
*************/
void IDSearch(char name[][MAX_LEN],long num[],int score[],int n)
{
    //按成绩由高到低排列
    DataScoreSort(name,num,score,n,Descending);

    int i,flag=0;
    long forsearch;
    printf("Please input the ID you want to search:");
    scanf("%ld",&forsearch);

    for(i=0; i<n; i++)
    {
        if(num[i]==forsearch)
            {
                printf("%d %s %ld %d\n",i+1,name[i],num[i],score[i]);
                flag++;
            }
    }
    if(flag==0)
            printf("No Found!\n");

    printf("\n");
}

/*************
**函数名：NameSearch
**输入：name[][MAX_LEN],num[],score[],n
**name[][MAX_LEN]：char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按姓名查询学生排名及其考试成绩
**调用模块：输入choice为8时
*************/
void NameSearch(char name[][MAX_LEN],long num[],int score[],int n)
{
    //按成绩由高到低排列
    DataScoreSort(name,num,score,n,Descending);

    printf("Please input the name you want to search:");
    getchar();
    char nameforsearch[10];
    gets(nameforsearch);

    int i,flag=0;
    for(i=0; i<n-1; i++)
    {
        if(strcmp(name[i],nameforsearch)==0)
        {
            printf("%d %s %ld %d\n",i+1,name[i],num[i],score[i]);
            flag++;
        }
    }
    if(flag==0)
            printf("No Found!\n");

    printf("\n");
}

/*************
**函数名：StatisticAna
**输入：score[],n
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按优秀、良好、中等、及格、不及格5个类别统计每个类别的人数及其所占百分比
**调用模块：输入choice为9时
*************/
void StatisticAna(int score[],int n)
{
    int i,A,B,C,D,E;
    float A_,B_,C_,D_,E_;
    A=B=C=D=E=0;
    for(i=0; i<n; i++)
    {
        if(score[i]<=100 && score[i]>=90)
            A++;
        else if(score[i]<=89 && score[i]>=80)
            B++;
        else if(score[i]<=79 && score[i]>=70)
            C++;
        else if(score[i]<=69 && score[i]>=60)
            D++;
        else
            E++;
    }

    A_=100 * ((float)A / n);
    B_=100 * ((float)B / n);
    C_=100 * ((float)C / n);
    D_=100 * ((float)D / n);
    E_=100 * ((float)E / n);

    printf("优秀人数为%d\n良好人数为%d\n中等人数为%d\n及格人数为%d\n不及格人数为%d\n\n",A,B,C,D,E);
    printf("优秀人数占比为%f%%\n良好人数占比为%f%%\n中等人数占比为%f%%\n及格人数占比为%f%%\n不及格人数占比为%f%%\n\n",A_,B_,C_,D_,E_);
}

/*************
**函数名：PrintNameIDScore
**输入：name[][MAX_LEN],num[],score[],n
**name[][MAX_LEN]：char,学生姓名
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：输出学生姓名、学号及考试成绩
**调用模块：当输入choice为10时
*************/
void PrintNameIDScore(char name[][MAX_LEN],long num[],int score[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s %ld %d\n",name[i],num[i],score[i]);
    }
    printf("\n");
}

/*
王天宇 20201111 89
吴梦涵 20201114 98
朱雨萌 20201116 76
刘玉婷 20201117 48
王家玉 20201112 66
孙进荣 20201123 77
马希乐阳 20201121 90
何宇 20201115 82
佐友明 20201113 92
杨丰赫 20201118 86
郝承霖 20201122 70
张钰朋 20201119 88
胡荣辉 20201120 65
*/

