#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student                                                           //结构体
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
    {"1","小红",'F',91,98,101},
    {"2","小明",'M',28,101,98},
    {"3","小花",'F',105,24,120},
    {"4","小方",'M',101,88,78},
};
int i=4;                                                                         //全局变量

char Jiemian()                                                                   //界面
{
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n\n");
    printf("\t\t\t\t__________________________________________\n");
    printf("\t\t\t\t|    1:添加信息      |    2:删除信息      |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|    3:查询信息      |    4:修改信息      |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|    5:进入排序      |    6:Exit          |\n");
    printf("\t\t\t\t|____________________|____________________|\n");
    printf("\t\t\t\t|         输入以上数字进入该界面          |\n");
    printf("\t\t\t\t|-----------------------------------------|\n");
    printf("*请输入(1-5):\n");
}

void Zhen()                                                                       //增添界面
{
    system("cls");
    char conversion1,conversion2;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  单个学生信息添加界面\n");
    while(1)
    {
        printf("\t\t--------------------------------------------------------------------\n");
        printf("***第%d个学生的信息:\n",i+1);
        while(1)
        {
            printf("*请输入学生ID(1-99):");
            scanf(" %s",stu[i].ID);
            if(strlen(stu[i].ID)>0&&strlen(stu[i].ID)<=2)
                break;
            else
                printf("\n输入ID超出限制，请重新输入\n");
        }
        while(1)
        {
            printf("*请输入学生姓名(不超过10位):");
            scanf("%s",stu[i].Name);
            if(strlen(stu[i].Name)<=10)
                break;
            else
                printf("\n输入Name超出限制，请重新输入\n");
        }
        while(1)
        {
            printf("*请输入学生性别( F(女) or M(男) ):");
            scanf("%s",&stu[i].Sex);
            if(stu[i].Sex=='F'||stu[i].Sex=='M')
                break;
            else
                printf("\n输入非法Sex，请重新输入\n");
        }
        while(1)
        {
            printf("*请输入学生语文成绩(0-150):");
            scanf("%d",&stu[i].Chinese);
            if(stu[i].Chinese>=0&&stu[i].Chinese<=150)
                break;
            else
                printf("\n输入成绩超出限制，请重新输入\n");
        }
        while(1)
        {
            printf("*请输入学生数学成绩(0-150):");
            scanf("%d",&stu[i].Math);
            if(stu[i].Math>=0&&stu[i].Math<=150)
                break;
            else
                printf("\n输入成绩超出限制，请重新输入\n");
        }
        while(1)
        {
            printf("*请输入学生外语成绩(0-150):");
            scanf("%d",&stu[i].English);
            if(stu[i].English>=0&&stu[i].English<=150)
                break;
            else
                printf("\n输入成绩超出限制，请重新输入\n");
        }
        i++;                                                     //已存入多少个学生信息
        printf("\n");
        printf("*输入'#'返回主菜单，y继续添加:");
        scanf(" %c",&conversion1);
        if(conversion1=='#')
            main();
        else if(conversion1=='y')
            continue;
        else
        {
            while(1)
            {
                printf("\t\t~~error!\n\n*请正确输入:\n*输入'#'返回主菜单，y继续添加:");
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

void Shan1()                                                                      //删除所有学生所有信息
{
    system("cls");
    int j;
    char choice;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  删除'所有学生所有信息界'面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("请确认是否删除,若删除输入'y','f'返回删除首界面,'#'返回主菜单:");
    scanf(" %c",&choice);
    while(1)
    {
        if(choice=='y')
        {
            for(j=0; i>0; i--,j++)                                        //最终i=0
            {
                stu[j]=stu[j+1];
            }
            printf("\n\t\t*所有学生信息已被删除\n\n");
            printf("输入'f'返回删除首界面,'#'返回主菜单:");
            scanf(" %c",&choice);
            if(choice=='f')
                Shan();
            else if(choice=='#')
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n请正确输入:");
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
                    printf("\t\t~~error\n请正确输入:");
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

void Shan2()                                                                       //删除单个学生信息
{
    system("cls");
    int j;
    char ID[4],conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n\n");
    printf("\t\t\t\t\t  删除单个学生信息界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("请输入要删除学生信息的学号:");
    scanf("%s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)
            {
                printf("将被删除的学生的信息:\n\n");
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
                printf("无该生信息,请核实您输入的学号是否正确\n");
        }
        printf("\n");
        printf("确认是否删除该位学生信息,'y'确认删除,'f'返回删除首界面,'#'返回主菜单:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')
            {
                for(; j<i; j++)
                    stu[j]=stu[j+1];
                printf("\n\t\t*该学生信息已被删除!\n");
                i--;                                                           //位数向前
                system("pause");
                printf("输入'y'继续删除,'f'返回删除首界面,'c'返回查询首界面,#'返回主菜单:");
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
                            printf("\t\terror\n请正确输入:");
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
                    printf("\t\terror\n请正确输入:");
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

void Shan()                                                                        //删除学生信息首界面
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n\n");
    printf("\t\t\t\t\t  删除学生信息首界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*无任何学生信息无法删除\n");
        printf("*输入'0'返回主菜单");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                printf("\t\t~~error\n请正确输入:");
                scanf(" %d",&choice);
            }
        }
    }
    printf("1:删除所有学生全部信息\n");
    printf("2:删除单个学生全部成绩信息\n");
//    printf("3:删除单个学生单科成绩信息\n\n");
    printf("请输入1-2,'0'返回主菜单:");
    scanf("%d",&choice);
    printf("%d",choice);
    switch(choice)
    {
    case 1:                                         //删除所有学生所有信息
        Shan1();
    case 2:                                          //删除单个学生所有信息
        Shan2();
    case 0:
        main();
//            case 3:                                   //单个学生单科成绩
//                Shan3();
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        Shan();
    }
}

void Cha1()                                                                        //查询全部学生信息
{
    system("cls");
    int j;
    char conversion1,conversion2;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  查询学生'全部信息'界面\n");
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
        printf("*输入'#'返回主菜单,'f'返回查询首界面:");
        scanf(" %c",&conversion1);
        if(conversion1=='#')
            main();
        else if(conversion1=='f')
            Cha();
        else
        {
            while(1)
            {
                printf("\t\t~~error!\n*请正确输入:");
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

void Cha2()                                                                        //主函数--查询单个学生信息
{
    system("cls");
    void Cha3()              //支函数--以学号查询单个学生信息
    {
        system("cls");
        int j;
        char ID[10];
        char conversion1,conversion2;
        printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
        printf("\t\t\t\t\t以'学号'查看学生全部信息界面\n");
        printf("\t\t--------------------------------------------------------------------\n");
        while(1)
        {
            printf("*请输入学生学号:");
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
                    printf("无该生信息,请核实您输入的学号是否正确\n");
            }
            printf("\n\n");
            printf("*输入'y'继续查询,'n'返回单个学生信息查询界面，'f'返回查询首界面,'#'返回主菜单:");
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
                    printf("\t\t~~error!\n*请正确输入:");
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
    void Cha4()                      //支函数--以姓名查找单个学生信息
    {
        system("cls");
        int j;
        char name[15];
        char conversion1;
        while(1)
        {
            printf("*请输入'姓名':");
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
                    printf("无该生信息,请核实您输入的学号是否正确\n");
            }
            printf("\n");
            printf("*输入'y'继续查询,'n'返回单个学生信息查询界面，'f'返回查询首界面,'#'返回主菜单:");
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
                    printf("\t\t~~error!\n*请正确输入:");
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
    int choice,choice1;                                          //主函数--语句
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t查询'单个学生'信息首界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("1:以'学号'查询\n");
    printf("2:以'姓名'查询\n\n");
    printf("*请输入1-2,'0'返回主菜单:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 1:
        Cha3();                         //以学号查询单个学生信息
    case 2:
        Cha4();                          //以姓名查询单个学生信息
    case 0:
        main();
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        Cha();
    }
}

void Cha()                                                                       //查询首界面
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  学生信息查询首界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t暂无任何学生信息!\n\n");
        system("pause");
        printf("输入'0'返回主菜单:");
        scanf("%d",&choice);
        printf("\n");
        if(choice==0)
            main();
        else
        {
            while(1)
            {
                printf("\t\t~~error\n请正确输入:");
                scanf(" %d",&choice);
                if(choice==0)
                    main();
            }
        }
    }
    printf("1:查询'全部'学生信息\n");
    printf("2:查询'单个'学生信息\n\n");
    printf("*请输入(1-2),'0'返回主菜单:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:                        //查询全部学生信息
        Cha1();
    case 2:                       //查询单个学生信息
        Cha2();
    case 0:
        main();
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        Cha();
    }
}

void Gai1()                                                                      //更改单个学生所有信息
{
    system("cls");
    int j,z;
    char ID[4],conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  单个学生所有信息更改界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("请输入学生学号:");
    scanf(" %s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)                                              //被更改学生的原信息
            {
                printf("\t\t*你正在更改第%d个学生的全部信息\n",j+1);
                printf("将被修改的学生的信息:\n");
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
                printf("\t\terror\n*无该学生,请核实后再输入\n");
                printf("输入'y'重新输入,'f'返回更改首界面,'c'返回查询首界面,#'返回主菜单:");
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
                        printf("\t\t~~error\n*请重新输入:");
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
        printf("确认是否更改,输入'y'确认更改,'f'返回更改首界面,'c'返回查询首界面,'#'返回主菜单:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')                                                        //输入更改信息
            {
                while(1)
                {
                    while(1)
                    {
                        printf("*请输入学生ID(1-99):");
                        scanf(" %s",stu[j].ID);
                        if(strlen(stu[j].ID)>0&&strlen(stu[j].ID)<=2)
                            break;
                        else
                            printf("\n输入ID超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生姓名(不超过10位):");
                        scanf("%s",stu[j].Name);
                        if(strlen(stu[j].Name)<=10)
                            break;
                        else
                            printf("\n输入Name超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生性别( F(女) or M(男) ):");
                        scanf("%s",&stu[j].Sex);
                        if(stu[j].Sex=='F'||stu[j].Sex=='M')
                            break;
                        else
                            printf("\n输入非法Sex，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生语文成绩(0-150):");
                        scanf("%d",&stu[j].Chinese);
                        if(stu[j].Chinese>=0&&stu[j].Chinese<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生数学成绩(0-150):");
                        scanf("%d",&stu[j].Math);
                        if(stu[j].Math>=0&&stu[j].Math<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生外语成绩(0-150):");
                        scanf("%d",&stu[j].English);
                        if(stu[j].English>=0&&stu[j].English<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    printf("\n\t\t***更改成功\n");
                    printf("第%d个学生更改后的信息为:\n",z+1);                          //更改后的信息
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
                    printf("输入'y'继续更改,'f'返回更改首界面,'#'返回主菜单:");
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
                            printf("\t\t~~error\n*请正确输入:");
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
                    printf("\t\t~~error\n*请正确输入:");
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

void Gai2()                                                                     //更该单个学生所有成绩
{
    system("cls");
    char ID[4],conversion1;
    int j,z;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  单个学生成绩信息更改界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("请输入学生学号:");
    scanf(" %s",ID);
    while(1)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stu[j].ID,ID)==0)                                              //被更改学生的原信息
            {
                printf("\t\t*你正在更改第%d个学生的成绩信息\n",j+1);
                printf("将被修改的学生的成绩信息:\n\n");
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
                printf("\t\terror\n*无该学生,请核实后再输入\n");
                printf("输入'y'重新输入,'f'返回更改首界面,'c'返回查询首界面,#'返回主菜单:");
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
                        printf("\t\t~~error\n*请重新输入:");
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
        printf("确认是否更改,输入'y'确认更改,'f'返回更改首界面,'c'返回查询首界面,#'返回主菜单:");
        scanf(" %c",&conversion1);
        while(1)
        {
            if(conversion1=='y')                                                        //输入更改信息
            {
                while(1)
                {
                    while(1)
                    {
                        printf("*请输入学生语文成绩(0-150):");
                        scanf("%d",&stu[j].Chinese);
                        if(stu[j].Chinese>=0&&stu[j].Chinese<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生数学成绩(0-150):");
                        scanf("%d",&stu[j].Math);
                        if(stu[j].Math>=0&&stu[j].Math<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    while(1)
                    {
                        printf("*请输入学生外语成绩(0-150):");
                        scanf("%d",&stu[j].English);
                        if(stu[j].English>=0&&stu[j].English<=150)
                            break;
                        else
                            printf("\n输入成绩超出限制，请重新输入\n");
                    }
                    printf("\n\t\t***更改成功\n");
                    printf("第%d个学生更改后的成绩信息为:\n",z+1);                          //更改后的信息
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
                    printf("输入'y'继续更改,'f'返回更改首界面,'c'返回查询首界面,#'返回主菜单:");
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
                            printf("\t\t~~error\n*请正确输入:");
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
                    printf("\t\t~~error\n*请正确输入:");
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


void Gai()                                                                      //更该信息首界面
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  单个学生信息更改首界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*无任何学生信息无法更改\n");
        printf("*输入'0'返回主菜单:");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n请正确输入:");
                    scanf(" %d",&choice);
                    if(choice==0)
                        main();
                }
            }
        }
    }
    printf("1:更改单个学生所有信息\n");
    printf("2:更改单个学生Chinese,Math,English\n\n");
    printf("请输入1-2,'0'返回主菜单:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 1:                                          //更改单个学生所有信息
        Gai1();
    case 2:                                    //更改单个学生所有成绩
        Gai2();
    case 0:
        main();                                //主菜单
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        Gai();
    }
}

void Pai1()                                                                      //以总成绩排序
{
    system("cls");
    int j,z,h[30],t,c;
    char conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  以'总成绩'排序排序界面(降序)\n");
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
    printf("输入'f'返回排序首界面,'#'返回主菜单:");
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
                printf("\t\terror\n*请正确输入:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai2()                                                                      //以平均分绩排序
{
    system("cls");
    int j,z,c;
    float t, h[30];
    char conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  以'平均分'排序排序界面(降序)\n");
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
    printf("输入'f'返回排序首界面,'#'返回主菜单:");
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
                printf("\t\terror\n*请正确输入:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}


void Pai3()                                                                     //以语文排序
{
    system("cls");
    int j,z,h[30],t,c;
    char conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  以'语文'排序排序界面(降序)\n");
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
    printf("输入'f'返回排序首界面,'#'返回主菜单:");
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
                printf("\t\terror\n*请正确输入:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai4()                                                                     //以数学排序
{
    system("cls");
    int j,z,t,c,h[30];
    char conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  以'数学'排序排序界面(降序)\n");
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
    printf("输入'f'返回排序首界面,'#'返回主菜单:");
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
                printf("\t\terror\n*请正确输入:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}

void Pai5()                                                                    //以英语成绩排序
{
    system("cls");
    int j,z,t,c,h[30];
    char conversion1;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  以'外语'排序排序界面(降序)\n");
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
    printf("输入'f'返回排序首界面,'#'返回主菜单:");
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
                printf("\t\terror\n*请正确输入:");
                scanf(" %c",&conversion1);
                if(conversion1=='f')
                    Pai();
                else if(conversion1=='#')
                    main();
            }
        }
    }
}
void Pai()                                                                     //排序首界面
{
    system("cls");
    int choice;
    printf("\t\t\t\t\t\t成绩管理系统\n\n\n");
    printf("\t\t\t\t\t  学生信息排序首界面\n");
    printf("\t\t--------------------------------------------------------------------\n");
    if(i==0)
    {
        printf("\t\t*无任何学生信息无法更改\n");
        printf("*输入'0'返回主菜单:");
        scanf(" %d",&choice);
        while(1)
        {
            if(choice==0)
                main();
            else
            {
                while(1)
                {
                    printf("\t\t~~error\n请正确输入:");
                    scanf(" %d",&choice);
                    if(choice==0)
                        main();
                }
            }
        }
    }
    printf("1:以总成绩排序\n");
    printf("2:以平均分排序\n");
    printf("3:以语文成绩排序\n");
    printf("4:以数学成绩排序\n");
    printf("5:以外语成绩排序\n\n");
    printf("*请输入(1-5)--'0'返回主菜单:");
    scanf(" %d",&choice);
    switch(choice)
    {
    case 0:
        main();
    case 1:                                              //以总成绩排序
        Pai1();
    case 2:                                              // 以平均分排序
        Pai2();
    case 3:                                              //以语文成绩排序
        Pai3();
    case 4:                                              //以数学成绩排序
        Pai4();
    case 5:                                              //以外语成绩排序
        Pai5();
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        Pai();
    }
}

void main()                                                       //主函数
{
    system("cls");
    Jiemian();
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:                                      //添加
        Zhen();
    case 2:                                    //删除
        Shan();
    case 3:                                      //查询
        Cha();
    case 4:                                   ////修改
        Gai();
    case 5:                                    ////排序
        Pai();
    case 6:
        exit(1);                                // 退出
    default:
        printf("*输入错误\n\n输入任意键继续...");
        char choice1;
        scanf(" %s",&choice1);
        main();
    }
}
