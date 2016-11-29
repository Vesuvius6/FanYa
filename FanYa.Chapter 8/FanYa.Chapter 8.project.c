#include<stdio.h>
#include<stdlib.h>
#define N 40//�涨��С�ڵ���30��
void ReadScore(int score[],int num[],int n);//�������ܣ������������Ͷ�Ӧ��ѧ������
int Sum(int score[],int n);//�������ܣ� ��������ܺ�
float Aver(int score[],float aver,int n);//��������: ����ƽ������
void ScoresortAndPrint(int score[],int num[],int n);//��������ѧ������ �ų����β������
void NumsortAndPrint(int score[],int num[],int n);//��ѧ�Ž�ѧ������ �ų����β������
void BinSearchNum(int score[],int num[],int x,int n);//�ö��ַ�����ѧ��ѧ�Ų��� ��������ɼ�ѧ��
void StatisticAnalysis(int score[],int n);//��������(90-100)(80-89)(70-79)(60-69)�ֳ�ѧ���ȼ� ��ͳ��ÿ������������ٷֱ�
void listRecord(int score[],int num[],int n);//���ÿ��ѧ�� ѧ�� ���Գɼ� �γ��ܷ� ƽ����
int chack1(int a);//����������1 ��ǿ����׳��
int chack2(int a);//����������2 ��ǿ����׳��
int main()
{
    int score[N],num[N],n,choice,sum,x;//�����Ƿ������飬ѧ�����飬������ѡ��Ӻͣ�Ҫ�Ĳ���ѧ��
    double aver;//ƽ����
    printf("Input the total number of the students(1<=n<=30):\n");
    scanf("%d",&n);//����ѧ������
    n=chack1(n);//�������������ӳ���׳��
    printf("1.Input record\n2.Caculate total and average score of course\n3.Sort in descending order by score\n4.Sort in ascending order by number\n5.Search by number\n6.Statistic analysis\n7.List record\n0.Exit\nPlease enter your choice:\n");
    scanf("%d",&choice);//��������г����ѡ��
    int i=1;
    while(i==1)//��Ϊǰ����Ҫѡ1.�������ܷ���ִ��1��0������ѡ��
    {
        if(choice==1)
        {
            ReadScore(score,num,n);//�������ܣ������������Ͷ�Ӧ��ѧ������
            i=0;
        }
        else if(choice==0)
        {
            exit(0);//ԭ�����Զ�����������������к���exit(0)�˳�����
            i=0;
        }
        else
        {
            printf("Please choose 1 and input Data:\n");//��Ʒ��������벢�涨��һ��ѡ���Ϊ��1����
            getchar();//����ĸ�������ѭ��
            scanf("%d",&choice);
            i=1;
        }
    }
    while(choice!=0)
    {
        printf("Please choose one from 2,3,4,5,6,7,0:\n");
        scanf("%d",&choice);//ϣ�����ҵ��Ľ�����choice����
        choice=chack2(choice);//��choice��������
        switch(choice)//ѡ��2��3��4��5��6��7
        {
        case 2:
            sum=Sum(score,n);//�������ܣ� ��������ܺ�
            aver=Aver(score,aver,n);//��������: ����ƽ������
            printf("sum=%d\naverage=%lf\n",sum,aver);
            break;
        case 3:
            ScoresortAndPrint(score,num,n);//��������ѧ������ �ų����β������
            break;
        case 4:
            NumsortAndPrint(score,num,n);//��ѧ�Ž�ѧ������ �ų����β������
            break;
        case 5:
            printf("Input which student you want to search:\n");
            scanf("%d",&x);
            BinSearchNum(score,num,x,n);//�ö��ַ�����ѧ��ѧ�Ų��� ��������ɼ�ѧ��
            break;
        case 6:
            StatisticAnalysis(score,n);//��������(90-100)(80-89)(70-79)(60-69)�ֳ�ѧ���ȼ� ��ͳ��ÿ������������ٷֱ�
            break;
        case 7:
            listRecord(score,num,n);//���ÿ��ѧ�� ѧ�� ���Գɼ� �γ��ܷ� ƽ����
            break;
        }
    }
    return 0;//���������
}
void ReadScore(int score[N],int num[],int n)//�������ܣ������������Ͷ�Ӧ��ѧ������
{
    int i;
    printf("Input student's ID and score as:\nID score\n");
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&num[i],&score[i]);
    }
}
int Sum(int score[],int n)//�������ܣ� ��������ܺ�
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+score[i];
    }
    return sum;
}
float Aver(int score[],float aver,int n)//��������: ����ƽ������
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+score[i];
    }
    aver=(float)sum/n;
    return aver;
}
void ScoresortAndPrint(int score[],int num[],int n)//�������� ԭ������������ �����ĳ�ѡ�񷨡���������ѧ������ �ų����β������
{
    int i,j,k,temp1,temp2;
    for(i=0; i<n-1; i++)//�Ƚ�ѧ������������
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
            score[i]=temp1;//�����ɼ�
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//����ѧ��
        }
    }
    for(i=0; i<n; i++)//������� ѧ�� ����
    {
        printf("rank %d num: %4d score: %4d\n",i+1,num[i],score[i]);//��ӡ ע��ռλ
    }
}
void NumsortAndPrint(int score[],int num[],int n)//ѧ������ ��ѧ�Ž�ѧ������ �ų����β������
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
            score[i]=temp1;//�����ɼ�
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//����ѧ��
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%4d %4d\n",num[i],score[i]);//��ӡ ע��ռλ
    }
}
void BinSearchNum(int score[],int num[],int x,int n)//x��Ҫ����ѧ����ѧ�� n��ѧ���� �ö��ַ�����ѧ��ѧ�Ų��� ��������ɼ�ѧ��
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
            score[i]=temp1;//�����ɼ�
            temp2=num[k];
            num[k]=num[i];
            num[i]=temp2;//����ѧ��
        }
    }
    while(low<=high)//�����������۰����
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
            break;//����ȱʧ������ѭ��
        }
    }
    if(low>high)//��low>high����Ҳ���
    {
        printf("Not found!\n");
    }
    else
    {

    }
}
void StatisticAnalysis(int score[],int n)//��������(90-100)(80-89)(70-79)(60-69)�ֳ�ѧ���ȼ� ��ͳ��ÿ������������ٷֱ�
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
    printf("A��%d   %.2f%%\n",level5,(float)level5/n);
    printf("B��%d   %.2f%%\n",level4,(float)level4/n);
    printf("C��%d   %.2f%%\n",level3,(float)level3/n);
    printf("D��%d   %.2f%%\n",level2,(float)level2/n);
    printf("E��%d   %.2f%%\n",level1,(float)level1/n);
}
void listRecord(int score[],int num[],int n)//���ÿ��ѧ�� ѧ�� ���Գɼ� �γ��ܷ� ƽ����
{
    int i,total=0;
    for(i=0; i<n; i++)
    {
        printf("%d %d\n",num[i],score[i]);
        total=total+score[i];
    }
    printf("Total score:%d\nAverage score:%.2f\n",total,(float)total/n);

}
int chack1(int n)//�Ӻ�������������1
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
int chack2(int n)//�Ӻ�������������2
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
