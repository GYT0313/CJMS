#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student                                                           //�ṹ��
{
    char ID[4];
    char Name[15];
    char Sex;
    int Chinese;
    int Math;
    int English;
    int All;
    float Ave;
} STUDENT;

STUDENT stu[30]=
{
    {"1","С��",'F',91,98,101},
    {"2","С��",'M',28,101,98},
    {"3","С��",'F',105,24,120},
    {"4","С��",'M',101,88,78},
};
int i=4;                                                                         //ȫ�ֱ���

char Jiemian()                                                                   //����
{
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n\n");
    printf("\t\t\t\t__________________________________________\n");
    printf("\t\t\t\t|    1:�����Ϣ      |    2:ɾ����Ϣ      |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|    3:��ѯ��Ϣ      |    4:�޸���Ϣ      |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|    5:��������      |    6:Exit          |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|         �����������ֽ���ý���          |\n");
    printf("\t\t\t\t|-----------------------------------------|\n");
    printf("*������(1-5):\n");
}

void Zhen()                                                                       //�������
{
    system("cls");
    char conversion1,conversion2;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ����ѧ����Ϣ��ӽ���\n");
    while(1)
    {
        printf("\t\t--------------------------------------------------------------------\n");
        printf("***��%d��ѧ������Ϣ:\n",i+1);
        while(1)
        {
            printf("*������ѧ��ID(1-99):");
            scanf(" %s",stu[i].ID);
            if(strlen(stu[i].ID)>0&&strlen(stu[i].ID)<=2)
                break;
            else
                printf("\n����ID�������ƣ�����������\n");
        }
        while(1)
        {
            printf("*������ѧ������(������10λ):");
            scanf("%s",stu[i].Name);
            if(strlen(stu[i].Name)<=10)
                break;
            else
                printf("\n����Name�������ƣ�����������\n");
        }
        while(1)
        {
            printf("*������ѧ���Ա�( F(Ů) or M(��) ):");
            scanf("%s",&stu[i].Sex);
            if(stu[i].Sex=='F'||stu[i].Sex=='M')
                break;
            else
                printf("\n����Ƿ�Sex������������\n");
        }
        while(1)
        {
            printf("*������ѧ�����ĳɼ�(0-150):");
            scanf("%d",&stu[i].Chinese);
            if(stu[i].Chinese>=0&&stu[i].Chinese<=150)
                break;
            else
                printf("\n����ɼ��������ƣ�����������\n");
        }
        while(1)
        {
            printf("*������ѧ����ѧ�ɼ�(0-150):");
            scanf("%d",&stu[i].Math);
            if(stu[i].Math>=0&&stu[i].Math<=150)
                break;
            else
                printf("\n����ɼ��������ƣ�����������\n");
        }
        while(1)
        {
            printf("*������ѧ������ɼ�(0-150):");
            scanf("%d",&stu[i].English);
            if(stu[i].English>=0&&stu[i].English<=150)
                break;
            else
                printf("\n����ɼ��������ƣ�����������\n");
        }
        i++;                                                     //�Ѵ�����ٸ�ѧ����Ϣ
        printf("\n");
        printf("*����'#'�������˵���y�������:");
        scanf(" %c",&conversion1);
        if(conversion1=='#')
            main();
        else if(conversion1=='y')
            continue;
        else
        {
            while(1)
            {
                printf("\t\t~~error!\n\n*����ȷ����:\n*����'#'�������˵���y�������:");
                scanf(" %c",&conversion2);
                conversion1=conversion2;
                if(conversion1=='#')
                    main();
                else if(conversion1=='y')
                    break;
            }
        }
    }
}

void Shan1()                                                                      //ɾ������ѧ��������Ϣ
{
    system("cls");
    int j;
    char choice;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ɾ��'����ѧ��������Ϣ��'��\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("��ȷ���Ƿ�ɾ��,��ɾ������'y','f'����ɾ���׽���,'#'�������˵�:");
    scanf(" %c",&choice);
    while(1)
    {
        if(choice=='y')
        {
            for(j=0; i>0; i--,j++)                                        //����i=0
            {
                stu[j]=stu[j+1];
            }
            printf("\n\t\t*����ѧ����Ϣ�ѱ�ɾ��\n\n");
            printf("����'f'����ɾ���׽���,'#'�������˵�:");
            scanf(" %c",&choice);
            if(choice=='f')
                Shan();
            else if(choice=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n����ȷ����:");
                    scanf("%c",&choice);
                    if(choice=='f')
                        Shan();
                    else if(choice=='#')
                        main();
                }
            }
        }
        else if(choice=='f')
            Shan();
        else if(choice=='#')
            main();
        else
        {
            while(1)
                {
                    printf("\t\t~~error\n����ȷ����:");
                    scanf(" %c",&choice);
                    if(choice=='y')
                        break;
                    else if(choice=='f')
                        Shan();
                    else if(choice=='#')
                        main();
                }
        }
    }
}

void Shan2()                                                                       //ɾ������ѧ����Ϣ
{
    system("cls");
    int j;
    char ID[4],conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n\n");
    printf("\t\t\t\t\t  ɾ������ѧ����Ϣ����\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("������Ҫɾ��ѧ����Ϣ��ѧ��:");
    scanf("%s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)
            {
                printf("����ɾ����ѧ������Ϣ:\n\n");
                printf("   ID      Name   Sex   Chinese   Math   English    Ave    ALL\n");
                stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
                stu[j].Ave=stu[j].All/3.0;
                printf("%5s",stu[j].ID);
                printf("%10s",stu[j].Name);
                printf("%5c",stu[j].Sex);
                printf("%9d",stu[j].Chinese);
                printf("%9d",stu[j].Math);
                printf("%9d",stu[j].English);
                printf("%10.2f",stu[j].Ave);
                printf("%6d",stu[j].All);
                printf("\n\n");
                break;
            }
            if(j>i)
                printf("�޸�����Ϣ,���ʵ�������ѧ���Ƿ���ȷ\n");
        }
        printf("\n");
        printf("ȷ���Ƿ�ɾ����λѧ����Ϣ,'y'ȷ��ɾ��,'f'����ɾ���׽���,'#'�������˵�:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')
            {
                for(; j<i; j++)
                    stu[j]=stu[j+1];
                printf("\n\t\t*��ѧ����Ϣ�ѱ�ɾ��!\n");
                i--;                                                           //λ����ǰ
                system("pause");
                printf("����'y'����ɾ��,'f'����ɾ���׽���,'c'���ز�ѯ�׽���,#'�������˵�:");
                scanf(" %c",&conversion1);
                while(1)
                {
                    if(conversion1=='y')
                        Shan2();
                    else if(conversion1=='f')
                        Shan();
                    else if(conversion1=='c')
                        Cha();
                    else if(conversion1=='#')
                        main();
                    else
                    {
                        while(1)
                        {
                            printf("\t\terror\n����ȷ����:");
                            scanf(" %c",&conversion1);
                            if(conversion1=='y')
                                break;
                            else if(conversion1=='f')
                                Shan();
                    else if(conversion1=='c')
                        Cha();
                            else if(conversion1=='#')
                                main();
                        }
                    }
                }

            }
            else if(conversion1=='f')
                Shan();
            else if(conversion1=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\terror\n����ȷ����:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        break;
                    else if(conversion1=='f')
                        Shan();
                    else if(conversion1=='#')
                        main();
                }
            }
        }
    }
}

void Shan()                                                                        //ɾ��ѧ����Ϣ�׽���
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n\n");
    printf("\t\t\t\t\t  ɾ��ѧ����Ϣ�׽���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*���κ�ѧ����Ϣ�޷�ɾ��\n");
        printf("*����'0'�������˵�");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                printf("\t\t~~error\n����ȷ����:");
                scanf(" %d",&choice);
            }
        }
    }
    printf("1:ɾ������ѧ��ȫ����Ϣ\n");
    printf("2:ɾ������ѧ��ȫ���ɼ���Ϣ\n");
//    printf("3:ɾ������ѧ�����Ƴɼ���Ϣ\n\n");
    printf("������1-2,'0'�������˵�:");
    scanf("%d",&choice);
    printf("%d",choice);
    switch(choice)
    {
    case 1:                                         //ɾ������ѧ��������Ϣ
        Shan1();
    case 2:                                          //ɾ������ѧ��������Ϣ
        Shan2();
    case 0:
        main();
//            case 3:                                   //����ѧ�����Ƴɼ�
//                Shan3();
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        Shan();
    }
}

void Cha1()                                                                        //��ѯȫ��ѧ����Ϣ
{
    system("cls");
    int j;
    char conversion1,conversion2;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��ѯѧ��'ȫ����Ϣ'����\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    while(1)
    {
        for(j=0; j<i; j++)
        {
            stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
            stu[j].Ave=stu[j].All/3.0;
            printf("%5s",stu[j].ID);
            printf("%10s",stu[j].Name);
            printf("%5c",stu[j].Sex);
            printf("%9d",stu[j].Chinese);
            printf("%9d",stu[j].Math);
            printf("%9d",stu[j].English);
            printf("%10.2f",stu[j].Ave);
            printf("%6d",stu[j].All);
            printf("\n\n");
        }
        printf("\n\n");
        printf("*����'#'�������˵�,'f'���ز�ѯ�׽���:");
        scanf(" %c",&conversion1);
        if(conversion1=='#')
            main();
        else if(conversion1=='f')
            Cha();
        else
        {
            while(1)
            {
                printf("\t\t~~error!\n*����ȷ����:");
                scanf(" %c",&conversion2);
                conversion1=conversion2;
                if(conversion1=='#')
                    main();
                else if(conversion1=='f')
                    Cha();
                else continue;
            }
        }
    }
}

void Cha2()                                                                        //������--��ѯ����ѧ����Ϣ
{
    system("cls");
    void Cha3()              //֧����--��ѧ�Ų�ѯ����ѧ����Ϣ
    {
        system("cls");
        int j;
        char ID[10];
        char conversion1,conversion2;
        printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
        printf("\t\t\t\t\t��'ѧ��'�鿴ѧ��ȫ����Ϣ����\n");
        printf("\t\t--------------------------------------------------------------------\n");
        while(1)
        {
            printf("*������ѧ��ѧ��:");
            scanf(" %s",ID);
            printf("   ID      Name   Sex   Chinese   Math   English    Ave    ALL\n");
            for(j=0; j<i; j++)
            {
                if(strcmp(stu[j].ID,ID)==0)
                {
                    stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
                    stu[j].Ave=stu[j].All/3.0;
                    printf("%5s",stu[j].ID);
                    printf("%10s",stu[j].Name);
                    printf("%5c",stu[j].Sex);
                    printf("%9d",stu[j].Chinese);
                    printf("%9d",stu[j].Math);
                    printf("%9d",stu[j].English);
                    printf("%10.2f",stu[j].Ave);
                    printf("%6d",stu[j].All);
                    printf("\n\n");
                    break;
                }
                if(j>=i)
                    printf("�޸�����Ϣ,���ʵ�������ѧ���Ƿ���ȷ\n");
            }
            printf("\n\n");
            printf("*����'y'������ѯ,'n'���ص���ѧ����Ϣ��ѯ���棬'f'���ز�ѯ�׽���,'#'�������˵�:");
            scanf(" %c",&conversion1);
            if(conversion1=='y')
                continue;
            else if(conversion1=='n')
                Cha2();
            else if(conversion1=='f')
                Cha();
            else if(conversion1=='#')
                main();
            else
            {
                while(1)
                {
                    while((conversion1=getchar())!='\n'&&conversion1!=EOF);
                    printf("\t\t~~error!\n*����ȷ����:");
                    scanf("%c",&conversion2);
                    conversion1=conversion2;
                    if(conversion1=='y')
                        break;
                    else if(conversion1=='n')
                        Cha2();
                    else if(conversion1=='f')
                        Cha();
                    else if(conversion1=='#')
                        main();
                    else continue;
                }
            }
        }
    }
    void Cha4()                      //֧����--���������ҵ���ѧ����Ϣ
    {
        system("cls");
        int j;
        char name[15];
        char conversion1;
        while(1)
        {
            printf("*������'����':");
            scanf(" %s",name);
            printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
            for(j=0; j<i; j++)
            {
                if(strcmp(stu[j].Name,name)==0)
                {
                    printf("%5s",stu[j].ID);
                    printf("%10s",stu[j].Name);
                    printf("%5c",stu[j].Sex);
                    printf("%9d",stu[j].Chinese);
                    printf("%9d",stu[j].Math);
                    printf("%9d",stu[j].English);
                    printf("%10.2f",stu[j].Ave);
                    printf("%6d",stu[j].All);
                    printf("\n\n");
                }
                if(j>=i)
                    printf("�޸�����Ϣ,���ʵ�������ѧ���Ƿ���ȷ\n");
            }
            printf("\n");
            printf("*����'y'������ѯ,'n'���ص���ѧ����Ϣ��ѯ���棬'f'���ز�ѯ�׽���,'#'�������˵�:");
            scanf(" %c",&conversion1);
            if(conversion1=='y')
                continue;
            else if(conversion1=='n')
                Cha2();
            else if(conversion1=='f')
                Cha();
            else if(conversion1=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error!\n*����ȷ����:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        break;
                    else if(conversion1=='n')
                        Cha2();
                    else if(conversion1=='f')
                        Shan();
                    else if(conversion1=='#')
                        main();
                }
            }
        }
    }
    int choice,choice1;                                          //������--���
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t��ѯ'����ѧ��'��Ϣ�׽���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("1:��'ѧ��'��ѯ\n");
    printf("2:��'����'��ѯ\n\n");
    printf("*������1-2,'0'�������˵�:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 1:
        Cha3();                         //��ѧ�Ų�ѯ����ѧ����Ϣ
    case 2:
        Cha4();                          //��������ѯ����ѧ����Ϣ
    case 0:
        main();
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        Cha();
    }
}

void Cha()                                                                       //��ѯ�׽���
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ѧ����Ϣ��ѯ�׽���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t�����κ�ѧ����Ϣ!\n\n");
        system("pause");
        printf("����'0'�������˵�:");
        scanf("%d",&choice);
        printf("\n");
        if(choice==0)
            main();
        else
        {
            while(1)
            {
                printf("\t\t~~error\n����ȷ����:");
                scanf(" %d",&choice);
                if(choice==0)
                    main();
            }
        }
    }
    printf("1:��ѯ'ȫ��'ѧ����Ϣ\n");
    printf("2:��ѯ'����'ѧ����Ϣ\n\n");
    printf("*������(1-2),'0'�������˵�:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:                        //��ѯȫ��ѧ����Ϣ
        Cha1();
    case 2:                       //��ѯ����ѧ����Ϣ
        Cha2();
    case 0:
        main();
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        Cha();
    }
}

void Gai1()                                                                      //���ĵ���ѧ��������Ϣ
{
    system("cls");
    int j,z;
    char ID[4],conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ����ѧ��������Ϣ���Ľ���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("������ѧ��ѧ��:");
    scanf(" %s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)                                              //������ѧ����ԭ��Ϣ
            {
                printf("\t\t*�����ڸ��ĵ�%d��ѧ����ȫ����Ϣ\n",j+1);
                printf("�����޸ĵ�ѧ������Ϣ:\n");
                printf("   ID      Name   Sex   Chinese   Math   English    Ave    ALL\n");
                stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
                stu[j].Ave=stu[j].All/3.0;
                printf("%5s",stu[j].ID);
                printf("%10s",stu[j].Name);
                printf("%5c",stu[j].Sex);
                printf("%9d",stu[j].Chinese);
                printf("%9d",stu[j].Math);
                printf("%9d",stu[j].English);
                printf("%10.2f",stu[j].Ave);
                printf("%6d",stu[j].All);
                printf("\n\n");
                z=j;
                break;
            }
            else if(i==j+1)
            {
                printf("\t\terror\n*�޸�ѧ��,���ʵ��������\n");
                printf("����'y'��������,'f'���ظ����׽���,'c'���ز�ѯ�׽���,#'�������˵�:");
                scanf(" %c",&conversion1);
                if(conversion1=='y')
                    Gai2();
                else if(conversion1=='f')
                    Gai();
                else if(conversion1=='c')
                    Cha();
                else if(conversion1=='#')
                    main();
                else
                {
                    while(1)
                    {
                        printf("\t\t~~error\n*����������:");
                        scanf(" %c",&conversion1);
                        if(conversion1=='y')
                            Gai2();
                        else if(conversion1=='f')
                            Gai();
                            else if(conversion1=='c')
                    Cha();
                        else if(conversion1=='#')
                            main();
                    }
                }
            }
        }
        printf("\n");
        printf("ȷ���Ƿ����,����'y'ȷ�ϸ���,'f'���ظ����׽���,'c'���ز�ѯ�׽���,'#'�������˵�:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')                                                        //���������Ϣ
            {
                while(1)
                {
                    while(1)
                    {
                        printf("*������ѧ��ID(1-99):");
                        scanf(" %s",stu[j].ID);
                        if(strlen(stu[j].ID)>0&&strlen(stu[j].ID)<=2)
                            break;
                        else
                            printf("\n����ID�������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ������(������10λ):");
                        scanf("%s",stu[j].Name);
                        if(strlen(stu[j].Name)<=10)
                            break;
                        else
                            printf("\n����Name�������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ���Ա�( F(Ů) or M(��) ):");
                        scanf("%s",&stu[j].Sex);
                        if(stu[j].Sex=='F'||stu[j].Sex=='M')
                            break;
                        else
                            printf("\n����Ƿ�Sex������������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ�����ĳɼ�(0-150):");
                        scanf("%d",&stu[j].Chinese);
                        if(stu[j].Chinese>=0&&stu[j].Chinese<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ����ѧ�ɼ�(0-150):");
                        scanf("%d",&stu[j].Math);
                        if(stu[j].Math>=0&&stu[j].Math<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ������ɼ�(0-150):");
                        scanf("%d",&stu[j].English);
                        if(stu[j].English>=0&&stu[j].English<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    printf("\n\t\t***���ĳɹ�\n");
                    printf("��%d��ѧ�����ĺ����ϢΪ:\n",z+1);                          //���ĺ����Ϣ
                    printf("   ID      Name   Sex   Chinese   Math   English    Ave    ALL\n");
                    stu[j].All=stu[z].Chinese+stu[z].Math+stu[z].English;
                    stu[j].Ave=stu[z].All/3.0;
                    printf("%5s",stu[j].ID);
                    printf("%10s",stu[j].Name);
                    printf("%5c",stu[j].Sex);
                    printf("%9d",stu[j].Chinese);
                    printf("%9d",stu[j].Math);
                    printf("%9d",stu[j].English);
                    printf("%10.2f",stu[j].Ave);
                    printf("%6d",stu[j].All);
                    printf("\n\n");
                    system("pause");
                    printf("����'y'��������,'f'���ظ����׽���,'#'�������˵�:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        Gai1();
                    else if(conversion1=='f')
                        Gai();
                        else if(conversion1=='c')
                    Cha();
                    else if(conversion1=='#')
                        main();
                    else
                    {
                        while(1)
                        {
                            printf("\t\t~~error\n*����ȷ����:");
                            scanf(" %c",&conversion1);
                            if(conversion1=='y')
                                Gai1();
                            else if(conversion1=='f')
                                Gai();
                                else if(conversion1=='c')
                    Cha();
                            else if(conversion1=='#')
                                main();
                        }
                    }
                }
            }
            else if(conversion1=='f')
                Gai();
            else if(conversion1=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n*����ȷ����:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        break;
                    else if(conversion1=='f')
                        Gai();
                    else if(conversion1=='#')
                        main();
                }
            }
        }
    }
}

void Gai2()                                                                     //���õ���ѧ�����гɼ�
{
    system("cls");
    char ID[4],conversion1;
    int j,z;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ����ѧ���ɼ���Ϣ���Ľ���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("������ѧ��ѧ��:");
    scanf(" %s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)                                              //������ѧ����ԭ��Ϣ
            {
                printf("\t\t*�����ڸ��ĵ�%d��ѧ���ĳɼ���Ϣ\n",j+1);
                printf("�����޸ĵ�ѧ���ĳɼ���Ϣ:\n\n");
                printf("   Chinese   Math   English    Ave    ALL\n");
                stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
                stu[j].Ave=stu[j].All/3.0;
                printf("%7d",stu[j].Chinese);
                printf("%9d",stu[j].Math);
                printf("%9d",stu[j].English);
                printf("%10.2f",stu[j].Ave);
                printf("%6d",stu[j].All);
                printf("\n\n");
                z=j;
                break;
            }
            else if(i==j+1)
            {
                printf("\t\terror\n*�޸�ѧ��,���ʵ��������\n");
                printf("����'y'��������,'f'���ظ����׽���,'c'���ز�ѯ�׽���,#'�������˵�:");
                scanf(" %c",&conversion1);
                if(conversion1=='y')
                    Gai2();
                else if(conversion1=='f')
                    Gai();
                    else if(conversion1=='c')
                    Cha();
                else if(conversion1=='#')
                    main();
                else
                {
                    while(1)
                    {
                        printf("\t\t~~error\n*����������:");
                        scanf(" %c",&conversion1);
                        if(conversion1=='y')
                            Gai2();
                        else if(conversion1=='f')
                            Gai();
                            else if(conversion1=='c')
                    Cha();
                        else if(conversion1=='#')
                            main();
                    }
                }
            }
        }
        printf("\n");
        printf("ȷ���Ƿ����,����'y'ȷ�ϸ���,'f'���ظ����׽���,'c'���ز�ѯ�׽���,#'�������˵�:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')                                                        //���������Ϣ
            {
                while(1)
                {
                    while(1)
                    {
                        printf("*������ѧ�����ĳɼ�(0-150):");
                        scanf("%d",&stu[j].Chinese);
                        if(stu[j].Chinese>=0&&stu[j].Chinese<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ����ѧ�ɼ�(0-150):");
                        scanf("%d",&stu[j].Math);
                        if(stu[j].Math>=0&&stu[j].Math<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    while(1)
                    {
                        printf("*������ѧ������ɼ�(0-150):");
                        scanf("%d",&stu[j].English);
                        if(stu[j].English>=0&&stu[j].English<=150)
                            break;
                        else
                            printf("\n����ɼ��������ƣ�����������\n");
                    }
                    printf("\n\t\t***���ĳɹ�\n");
                    printf("��%d��ѧ�����ĺ�ĳɼ���ϢΪ:\n",z+1);                          //���ĺ����Ϣ
                    printf("   Chinese   Math   English    Ave    ALL\n");
                    stu[j].All=stu[z].Chinese+stu[z].Math+stu[z].English;
                    stu[j].Ave=stu[z].All/3.0;
                    printf("%7d",stu[j].Chinese);
                    printf("%9d",stu[j].Math);
                    printf("%9d",stu[j].English);
                    printf("%10.2f",stu[j].Ave);
                    printf("%6d",stu[j].All);
                    printf("\n\n");
                    system("pause");
                    printf("����'y'��������,'f'���ظ����׽���,'c'���ز�ѯ�׽���,#'�������˵�:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        Gai1();
                    else if(conversion1=='f')
                        Gai();
                        else if(conversion1=='c')
                    Cha();
                    else if(conversion1=='#')
                        main();
                    else
                    {
                        while(1)
                        {
                            printf("\t\t~~error\n*����ȷ����:");
                            scanf(" %c",&conversion1);
                            if(conversion1=='y')
                                Gai1();
                            else if(conversion1=='f')
                                Gai();
                                else if(conversion1=='c')
                    Cha();
                            else if(conversion1=='#')
                                main();
                        }
                    }
                }
            }
            else if(conversion1=='f')
                Gai();
                else if(conversion1=='c')
                    Cha();
            else if(conversion1=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n*����ȷ����:");
                    scanf(" %c",&conversion1);
                    if(conversion1=='y')
                        break;
                    else if(conversion1=='f')
                        Gai();
                        else if(conversion1=='c')
                    Cha();
                    else if(conversion1=='#')
                        main();
                }
            }
        }
    }
}


void Gai()                                                                      //������Ϣ�׽���
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ����ѧ����Ϣ�����׽���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*���κ�ѧ����Ϣ�޷�����\n");
        printf("*����'0'�������˵�:");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n����ȷ����:");
                    scanf(" %d",&choice);
                    if(choice==0)
                        main();
                }
            }
        }
    }
    printf("1:���ĵ���ѧ��������Ϣ\n");
    printf("2:���ĵ���ѧ��Chinese,Math,English\n\n");
    printf("������1-2,'0'�������˵�:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 1:                                          //���ĵ���ѧ��������Ϣ
        Gai1();
    case 2:                                    //���ĵ���ѧ�����гɼ�
        Gai2();
    case 0:
        main();                                //���˵�
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        Gai();
    }
}

void Pai1()                                                                      //���ܳɼ�����
{
    system("cls");
    int j,z,h[30],t,c;
    char conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��'�ܳɼ�'�����������(����)\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    for(j=0; j<i; j++)
    {
        stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
        stu[j].Ave=stu[j].All/3.0;
    }
    for(j=0; j<i; j++)
        h[j]=stu[j].All;
    for(j=0; j<i; j++)
    {
        for(z=j+1; z<i; z++)
        {
            if(h[z]>h[j])
            {
                t=h[z];
                h[z]=h[j];
                h[j]=t;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        for(z=0; z<i; z++)
        {
            if(h[j]==stu[z].All)
            {
                printf("%5s",stu[z].ID);
                printf("%10s",stu[z].Name);
                printf("%5c",stu[z].Sex);
                printf("%9d",stu[z].Chinese);
                printf("%9d",stu[z].Math);
                printf("%9d",stu[z].English);
                printf("%10.2f",stu[z].Ave);
                printf("%6d",stu[z].All);
                printf("\n\n");
                break;
            }
        }
    }
    printf("\n");
    printf("����'f'���������׽���,'#'�������˵�:");
    scanf(" %c",&conversion1);
    while(1)
    {
        if(conversion1=='f')
            Pai();
        else if(conversion1=='#')
            main();
        else
        {
            while(1)
            {
                printf("\t\terror\n*����ȷ����:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai2()                                                                      //��ƽ���ּ�����
{
    system("cls");
    int j,z,c;
    float t, h[30];
    char conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��'ƽ����'�����������(����)\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    for(j=0; j<i; j++)
    {
        stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
        stu[j].Ave=stu[j].All/3.0;
    }
    for(j=0; j<i; j++)
        h[j]=stu[j].Ave;

    for(j=0; j<i; j++)
    {
        for(z=j+1; z<i; z++)
        {
            if(h[z]>h[j])
            {
                t=h[z];
                h[z]=h[j];
                h[j]=t;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        for(z=0; z<i; z++)
        {
            if(h[j]==stu[z].Ave)
            {
                printf("%5s",stu[z].ID);
                printf("%10s",stu[z].Name);
                printf("%5c",stu[z].Sex);
                printf("%9d",stu[z].Chinese);
                printf("%9d",stu[z].Math);
                printf("%9d",stu[z].English);
                printf("%10.2f",stu[z].Ave);
                printf("%6d",stu[z].All);
                printf("\n\n");
                break;
            }
        }
    }
    printf("\n");
    printf("����'f'���������׽���,'#'�������˵�:");
    scanf(" %c",&conversion1);
    while(1)
    {
        if(conversion1=='f')
            Pai();
        else if(conversion1=='#')
            main();
        else
        {
            while(1)
            {
                printf("\t\terror\n*����ȷ����:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}


void Pai3()                                                                     //����������
{
    system("cls");
    int j,z,h[30],t,c;
    char conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��'����'�����������(����)\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    for(j=0; j<i; j++)
    {
        stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
        stu[j].Ave=stu[j].All/3.0;
    }
    for(j=0; j<i; j++)
        h[j]=stu[j].Chinese;
    for(j=0; j<i; j++)
    {
        for(z=j+1; z<i; z++)
        {
            if(h[z]>h[j])
            {
                t=h[z];
                h[z]=h[j];
                h[j]=t;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        for(z=0; z<i; z++)
        {
            if(h[j]==stu[z].Chinese)
            {
                printf("%5s",stu[z].ID);
                printf("%10s",stu[z].Name);
                printf("%5c",stu[z].Sex);
                printf("%9d",stu[z].Chinese);
                printf("%9d",stu[z].Math);
                printf("%9d",stu[z].English);
                printf("%10.2f",stu[z].Ave);
                printf("%6d",stu[z].All);
                printf("\n\n");
                break;
            }
        }
    }
    printf("\n");
    printf("����'f'���������׽���,'#'�������˵�:");
    scanf(" %c",&conversion1);
    while(1)
    {
        if(conversion1=='f')
            Pai();
        else if(conversion1=='#')
            main();
        else
        {
            while(1)
            {
                printf("\t\terror\n*����ȷ����:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai4()                                                                     //����ѧ����
{
    system("cls");
    int j,z,t,c,h[30];
    char conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��'��ѧ'�����������(����)\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    for(j=0; j<i; j++)
    {
        stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
        stu[j].Ave=stu[j].All/3.0;
    }
    for(j=0; j<i; j++)
        h[j]=stu[j].Math;
    for(j=0; j<i; j++)
    {
        for(z=j+1; z<i; z++)
        {
            if(h[z]>h[j])
            {
                t=h[z];
                h[z]=h[j];
                h[j]=t;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        for(z=0; z<i; z++)
        {
            if(h[j]==stu[z].Math)
            {
                printf("%5s",stu[z].ID);
                printf("%10s",stu[z].Name);
                printf("%5c",stu[z].Sex);
                printf("%9d",stu[z].Chinese);
                printf("%9d",stu[z].Math);
                printf("%9d",stu[z].English);
                printf("%10.2f",stu[z].Ave);
                printf("%6d",stu[z].All);
                printf("\n\n");
                break;
            }
        }
    }
    printf("\n");
    printf("����'f'���������׽���,'#'�������˵�:");
    scanf(" %c",&conversion1);
    while(1)
    {
        if(conversion1=='f')
            Pai();
        else if(conversion1=='#')
            main();
        else
        {
            while(1)
            {
                printf("\t\terror\n*����ȷ����:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}

void Pai5()                                                                    //��Ӣ��ɼ�����
{
    system("cls");
    int j,z,t,c,h[30];
    char conversion1;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ��'����'�����������(����)\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("   ID      Name   Sex   Chinese   Math   English     Ave    ALL\n");
    for(j=0; j<i; j++)
    {
        stu[j].All=stu[j].Chinese+stu[j].Math+stu[j].English;
        stu[j].Ave=stu[j].All/3.0;
    }
    for(j=0; j<i; j++)
        h[j]=stu[j].English;
    for(j=0; j<i; j++)
    {
        for(z=j+1; z<i; z++)
        {
            if(h[z]>h[j])
            {
                t=h[z];
                h[z]=h[j];
                h[j]=t;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        for(z=0; z<i; z++)
        {
            if(h[j]==stu[z].English)
            {
                printf("%5s",stu[z].ID);
                printf("%10s",stu[z].Name);
                printf("%5c",stu[z].Sex);
                printf("%9d",stu[z].Chinese);
                printf("%9d",stu[z].Math);
                printf("%9d",stu[z].English);
                printf("%10.2f",stu[z].Ave);
                printf("%6d",stu[z].All);
                printf("\n\n");
                break;
            }
        }
    }
    printf("\n");
    printf("����'f'���������׽���,'#'�������˵�:");
    scanf(" %c",&conversion1);
    while(1)
    {
        if(conversion1=='f')
            Pai();
        else if(conversion1=='#')
            main();
        else
        {
            while(1)
            {
                printf("\t\terror\n*����ȷ����:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai()                                                                     //�����׽���
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t�ɼ�����ϵͳ\n\n\n");
    printf("\t\t\t\t\t  ѧ����Ϣ�����׽���\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*���κ�ѧ����Ϣ�޷�����\n");
        printf("*����'0'�������˵�:");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n����ȷ����:");
                    scanf(" %d",&choice);
                    if(choice==0)
                        main();
                }
            }
        }
    }
    printf("1:���ܳɼ�����\n");
    printf("2:��ƽ��������\n");
    printf("3:�����ĳɼ�����\n");
    printf("4:����ѧ�ɼ�����\n");
    printf("5:������ɼ�����\n\n");
    printf("*������(1-5)--'0'�������˵�:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 0:
        main();
    case 1:                                              //���ܳɼ�����
        Pai1();
    case 2:                                              // ��ƽ��������
        Pai2();
    case 3:                                              //�����ĳɼ�����
        Pai3();
    case 4:                                              //����ѧ�ɼ�����
        Pai4();
    case 5:                                              //������ɼ�����
        Pai5();
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        Pai();
    }
}

void main()                                                       //������
{
    system("cls");
    Jiemian();
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:                                      //���
        Zhen();
    case 2:                                    //ɾ��
        Shan();
    case 3:                                      //��ѯ
        Cha();
    case 4:                                   ////�޸�
        Gai();
    case 5:                                    ////����
        Pai();
    case 6:
        exit(1);                                // �˳�
    default:
        printf("*�������\n\n�������������...");
        char choice1;
        scanf(" %s",&choice1);
        main();
    }
}
