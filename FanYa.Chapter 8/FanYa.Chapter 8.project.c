#include<stdio.h>
#include<stdlib.h>
#define N 40//规定了小于等于30人
void ReadScore(int score[],int num[],int n);//函数功能：读入分数数组和对应的学号数组
int Sum(int score[],int n);//函数功能： 计算分数总和
float Aver(int score[],float aver,int n);//函数功能: 计算平均分数
void ScoresortAndPrint(int score[],int num[],int n);//按分数将学生排列 排出名次并且输出
void NumsortAndPrint(int score[],int num[],int n);//按学号将学生排列 排出名次并且输出
void BinSearchNum(int score[],int num[],int x,int n);//用二分法输入学生学号查找 并且输出成绩学号
void StatisticAnalysis(int score[],int n);//按五个类别(90-100)(80-89)(70-79)(60-69)分出学生等级 并统计每个类别人数及百分比
void listRecord(int score[],int num[],int n);//输出每个学生 学号 考试成绩 课程总分 平均分
int chack1(int a);//防错误输入1 增强程序健壮性
int chack2(int a);//防错误输入2 增强程序健壮性
int main()
{
    int score[N],num[N],n,choice,sum,x;//依次是分数数组，学号数组，人数，选项，加和，要的查找学号
    double aver;//平均分
    printf("Input the total number of the students(1<=n<=30):\n");
    scanf("%d",&n);//输入学生总数
    n=chack1(n);//防错误输入增加程序健壮性
    printf("1.Input record\n2.Caculate total and average score of course\n3.Sort in descending order by score\n4.Sort in ascending order by number\n5.Search by number\n6.Statistic analysis\n7.List record\n0.Exit\nPlease enter your choice:\n");
    scanf("%d",&choice);//输入想进行程序的选项
    int i=1;
    while(i==1)//因为前提是要选1.按程序功能分类执行1或0或其他选项
    {
        if(choice==1)
        {
            ReadScore(score,num,n);//函数功能：读入分数数组和对应的学号数组
            i=0;
        }
        else if(choice==0)
        {
            exit(0);//原本想自定义个函数，但有现有函数exit(0)退出函数
            i=0;
        }
        else
        {
            printf("Please choose 1 and input Data:\n");//设计防错误输入并规定第一个选项必为“1”。
            getchar();//防字母输入错误循环
            scanf("%d",&choice);
            i=1;
        }
    }
    while(choice!=0)
    {
        printf("Please choose one from 2,3,4,5,6,7,0:\n");
        scanf("%d",&choice);//希望能找到改进储存choice方法
        choice=chack2(choice);//防choice错误输入
        switch(choice)//选项2，3，4，5，6，7
        {
        case 2:
            sum=Sum(score,n);//函数功能： 计算分数总和
            aver=Aver(score,aver,n);//函数功能: 计算平均分数
            printf("sum=%d\naverage=%lf\n",sum,aver);
            break;
        case 3:
            ScoresortAndPrint(score,num,n);//按分数将学生排列 排出名次并且输出
            break;
        case 4:
            NumsortAndPrint(score,num,n);//按学号将学生排列 排出名次并且输出
            break;
        case 5:
            printf("Input which student you want to search:\n");
            scanf("%d",&x);
            BinSearchNum(score,num,x,n);//用二分法输入学生学号查找 并且输出成绩学号
            break;
        case 6:
            StatisticAnalysis(score,n);//按五个类别(90-100)(80-89)(70-79)(60-69)分出学生等级 并统计每个类别人数及百分比
            break;
        case 7:
            listRecord(score,num,n);//输出每个学生 学号 考试成绩 课程总分 平均分
            break;
        }
    }
    return 0;//主程序结束
}
void ReadScore(int score[N],int num[],int n)//函数功能：读入分数数组和对应的学号数组
{
    int i;
    printf("Input student's ID and score as:\nID score\n");
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&num[i],&score[i]);
    }
}
int Sum(int score[],int n)//函数功能： 计算分数总和
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+score[i];
    }
    return sum;
}
float Aver(int score[],float aver,int n)//函数功能: 计算平均分数
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+score[i];
    }
    aver=(float)sum/n;
    return aver;
}
void ScoresortAndPrint(int score[],int num[],int n)//分数排名 原本交换法排序 后来改成选择法。安分数将学生排列 排出名次并且输出
{
    int i,j,k,temp1,temp2;
    for(i=0; i<n-1; i++)//先将学生按分数排序
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(score[j]>score[k])//
            {
                k=j;//
            }
        }
        if(k!=i)//
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;//交换成绩
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//交换学号
        }
    }
    for(i=0; i<n; i++)//输出名次 学号 分数
    {
        printf("rank %d num: %4d score: %4d\n",i+1,num[i],score[i]);//打印 注意占位
    }
}
void NumsortAndPrint(int score[],int num[],int n)//学号排名 安学号将学生排列 排出名次并且输出
{
    int i,j,k,temp1,temp2;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(num[j]<num[k])//
            {
                k=j;//
            }
        }
        if(k!=i)//
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;//交换成绩
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//交换学号
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%4d %4d\n",num[i],score[i]);//打印 注意占位
    }
}
void BinSearchNum(int score[],int num[],int x,int n)//x是要查找学生的学号 n是学生数 用二分法输入学生学号查找 并且输出成绩学号
{
    int i,j,k,temp1,temp2,low=0,high=n-1,mid;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(num[j]<num[k])//
            {
                k=j;//
            }
        }
        if(k!=i)//
        {
            temp1=score[k];
            score[k]=score[i];
            score[i]=temp1;//交换成绩
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//交换学号
        }
    }
    while(low<=high)//排完序后进行折半查找
    {
        mid=(high+low)/2;//printf("%d\n",mid);
        if(x>num[mid])

        {
            low=mid+1;
        }
        else if(x<num[mid])
            high=mid-1;
        else
        {
            printf("num=%d score=%d\n",mid+1,score[mid]);
            break;//曾经缺失进入死循环
        }
    }
    if(low>high)//若low>high则查找不到
    {
        printf("Not found!\n");
    }
    else
    {

    }
}
void StatisticAnalysis(int score[],int n)//按五个类别(90-100)(80-89)(70-79)(60-69)分出学生等级 并统计每个类别人数及百分比
{
    int i,level1=0,level2=0,level3=0,level4=0,level5=0;
    for(i=0; i<n; i++)
    {
        if(score[i]>=0&&score[i]<60)level1++;
        else if(score[i]<70)level2++;
        else if(score[i]<80)level3++;
        else if(score[i]<90)level4++;
        else if(score[i]<=100)level5++;
    }
    printf("A：%d   %.2f%%\n",level5,(float)level5/n);
    printf("B：%d   %.2f%%\n",level4,(float)level4/n);
    printf("C：%d   %.2f%%\n",level3,(float)level3/n);
    printf("D：%d   %.2f%%\n",level2,(float)level2/n);
    printf("E：%d   %.2f%%\n",level1,(float)level1/n);
}
void listRecord(int score[],int num[],int n)//输出每个学生 学号 考试成绩 课程总分 平均分
{
    int i,total=0;
    for(i=0; i<n; i++)
    {
        printf("%d %d\n",num[i],score[i]);
        total=total+score[i];
    }
    printf("Total score:%d\nAverage score:%.2f\n",total,(float)total/n);

}
int chack1(int n)//子函数防错误输入1
{
    if(n>0&&n<30)
    {
        return n;
    }
    else

        printf("Wrong!\n");
    printf("Input number(1<=n<=30):\n");
    getchar();
    scanf("%d",&n);
    n=chack1(n);
}
int chack2(int n)//子函数防错误输入2
{
    if(n==2||n==3||n==4||n==5||n==6||n==7||n==0)
    {
        return n;
    }
    else

        printf("Wrong!\n");
    printf("Input number(2,3,4,5,6,7,0):\n");
    getchar();
    n=0;
    scanf("%d",&n);
    n=chack2(n);
}
