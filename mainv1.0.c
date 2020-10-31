/****************************
**程序描述：学生成绩管理系统V1.0
**日期：2020/10/26
**作业题目：实验五
**输入：n（学生总数）,score[]（学生成绩）,num[]（学生学号）
**输入范围：n<=30,score<=100 && score>=0,num按规定学号格式输出
****************************/
#include <stdio.h>
#include <stdlib.h>
#define NUM 30
int ReadIDScore(long num[],int score[]);
int Sum(int score[],int n);
void Average(int n,int sum);
void DataDesSort(long num[],int score[],int n);
void DataAsSort(long num[],int score[],int n);
void IDAsSort(long num[],int score[],int n);
void IDSearch(long num[],int score[],int n);
void StatisticAna(int score[],int n);
void PrintIDScore(long num[],int score[],int n);

int main()
{
    printf("Number:200210332\nName:吴梦辰\nSubject No.5-program No.1\n\n");
    int choice;
    //循环输出任务列表直到用户输入9(Exit)
    do{
            printf("1.Input record\n");
            printf("2.Calculate total and average score of course\n");
            printf("3.Sort in descending order by score\n");
            printf("4.Sort in ascending order by score\n");
            printf("5.Sort in ascending order by student's ID\n");
            printf("6.Search by student's ID\n");
            printf("7.Statistic analysis\n");
            printf("8.List record\n");
            printf("9.Exit\n");
            printf("Please enter your choice:");

            //读取输入选项并通过switch选择结构执行相应任务
            scanf("%d",&choice);

            int score[NUM],n,sum;
            long num[NUM];

            switch(choice){
            case 1:
                //读取学生学号及对应成绩
                n=ReadIDScore(num,score);
                break;

            case 2:
                //计算学生总成绩及平均成绩
                sum=Sum(score,n);
                Average(n,sum);
                break;

            case 3:
                //按成绩从高到低排列名次表
                DataDesSort(num,score,n);
                int i;
                for(i=0; i<n; i++)
                {
                    printf("%d %ld %d\n",i+1,num[i],score[i]);
                }
                printf("\n");
                break;

            case 4:
                //按成绩由低到高排列名次表
                DataAsSort(num,score,n);
                break;

            case 5:
                //按学号由小到大排列成绩表
                IDAsSort(num,score,n);
                break;

            case 6:
                //按学号查询学生排名及其考试成绩
                IDSearch(num,score,n);
                break;

            case 7:
                //按优秀、良好、中等、及格、不及格5个类别统计每个类别的人数及其所占百分比
                StatisticAna(score,n);
                break;

            case 8:
                //输出学生学号及考试成绩
                PrintIDScore(num,score,n);
                break;

            case 9:
                //结束程序
                break;

            default:
                printf("Input wrong choice!\n\n");
                break;
            }

    }while(choice != 9);
    return 0;
}

/*************
**函数名：ReadIDScore
**输入：num[],score[]
**num[]：long int,学生学号
**score[]：int,学生成绩
**输出：n
**n：学生总数
**功能描述：读取学生学号及对应成绩
**调用模块：输入choice为1时
*************/
int ReadIDScore(long num[],int score[])
{
    int i,n,flag;
    printf("How many students?\n");
    scanf("%d",&n);

    //确保输入成绩正确（在0-100之间）
    do{
            flag=0;
            printf("Please input student's ID and score,format as:(20201111 89)\n");
            for(i=0; i<n; i++)
            {
                scanf("%ld %d",&num[i],&score[i]);
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
**函数名：DataDesSort
**输入：num[],score[],n
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按成绩从高到低排列名次表
**调用模块：输入choice为3时
*************/
void DataDesSort(long num[],int score[],int n)
{
    int i,j,k,temp1,temp2;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(score[j]>score[k])
                k=j;
        }

        if(k != i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }
}

/*************
**函数名：DataAsSort
**输入：num[],score[],n
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按成绩由低到高排列名次表
**调用模块：输入choice为4时
*************/
void DataAsSort(long num[],int score[],int n)
{
    int i,j,k,t,temp1,temp2;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(score[j]<score[k])
                k=j;
        }

        if(k != i)
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }

    //输出学生名次、学号、成绩
    for(t=0; t<n; t++)
    {
        printf("%d %ld %d\n",n-t,num[t],score[t]);
    }
    printf("\n");

}

/*************
**函数名：IDAsSort
**输入：num[],score[],n
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按学号由小到大排列成绩表
**调用模块：输入choice为5时
*************/
void IDAsSort(long num[],int score[],int n)
{
    int i,j,k,t,temp1,temp2;
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
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;

            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;
        }
    }

    //输出学生学号、成绩
    for(t=0; t<n; t++)
    {
        printf("%ld %d\n",num[t],score[t]);
    }
    printf("\n");

}

/*************
**函数名：IDSearch
**输入：num[],score[],n
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：按学号查询学生排名及其考试成绩
**调用模块：输入choice为6时
*************/
void IDSearch(long num[],int score[],int n)
{
    //按成绩由高到低排列
    DataDesSort(num,score,n);

    int i,flag=0;
    long forsearch;
    printf("Please input the ID you want to search:");
    scanf("%ld",&forsearch);

    for(i=0; i<n; i++)
    {
        if(num[i]==forsearch)
            {
                printf("%d %ld %d\n",i+1,num[i],score[i]);
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
**调用模块：输入choice为7时
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
**函数名：PrintIDScore
**输入：num[],score[],n
**num[]：long int,学生学号
**score[]：int,学生成绩
**n：int,学生总数
**功能描述：输出学生学号及考试成绩
**调用模块：当输入choice为8时
*************/
void PrintIDScore(long num[],int score[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%ld %d\n",num[i],score[i]);
    }
    printf("\n");
}

/*测试数据：
2020111111 86
2020111113 49
2020111114 68
2020111112 90
2020111117 88
2020111115 96
2020111116 78
2020111120 56
2020111119 48
2020111118 74
2020111123 84
2020111122 66
2020111121 72
*/
