#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	/*I/O函数*/
#include<stdlib.h>	/*其它说明*/
#include<string.h>	/*字符串函数*/

#define LEN 15		/* 学号和姓名最大字符数,实际请更改*/
#define N 50		/* 最大学生人数,实际请更改*/

int k = 1, n = 0, m = 0;/* n代表当前记录的学生人数*/

//函数声明
void seek();
void insert();
void display();
void save();
void menu();

//结构体保存学生信息
struct student{
	char StudentId[LEN+1];
	char StudentName[LEN+1];
	char StudentEnter;
	char StudentLeave;
}stu[N];

//主函数
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
//查找学生信息37
void seek() /*查找*/
{
	int i, item, flag;
	char s1[21]; /* 以姓名和学号最长长度+1为准*/
	printf("------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的学生的学号:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(s1,stu[i].StudentId) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\t进入时间\t离开时间\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%f\t%f\n", stu[i].StudentId,stu[i].StudentName,stu[i].StudentEnter,stu[i].StudentLeave);
			}
			if (0 == flag)
				printf("该学号不存在！\n"); break;
		case 2:
			printf("请输入要查询的学生的姓名:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(stu[i].StudentName, s1) == 0)
			{
				flag = 1;
				printf("学生学号\t学生姓名\t进入时间\t离开时间\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%f\t%f\n", stu[i].StudentId, stu[i].StudentName,stu[i].StudentEnter, stu[i].StudentLeave);
			}
			if (0 == flag)
				printf("该姓名不存在！\n"); break;
		case 3:return;
		default:printf("请在1-3之间选择\n");
		}
	}
}
void sort()
{
	int i, j, k, *p, *q, s;
	char temp[LEN + 1], ctemp;
	float ftemp;
	for (i = 0; i<n - 1; i++)
	{
		for (j = n - 1; j>i; j--)
		if (strcmp(stu[j - 1].StudentId, stu[j].StudentId)>0)
		{
			strcpy(temp, stu[j - 1].StudentId);
			strcpy(stu[j - 1].StudentId, stu[j].StudentId);
			strcpy(stu[j].StudentId, temp);
			strcpy(temp, stu[j - 1].StudentName);
			strcpy(stu[j - 1].StudentName, stu[j].StudentName);
			strcpy(stu[j].StudentName, temp);
			ctemp = stu[j - 1].StudentEnter;
			stu[j - 1].StudentSex = stu[j].StudentEnter;
			stu[j].StudentEnter = ctemp;
			p = &stu[j - 1].StudentLeave;
			q = &stu[j].StudentLeave;
			s = *q;
			*q = *p;
			*p = s;
			}
		}
	}
}
void insert() /*插入函数*/
{
	int i = n, j, flag;
	printf("请输入待增加的学生数:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位学生的学号:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++){
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0){
						printf("该学号已存在，请重新输入！\n");
						flag = 1;
						break;
					}
				}
			}
			printf("请输入第%d 个学生的姓名:\n", i+1);
			scanf("%s", stu[i].StudentName);
			printf("请输入第%d 个学生的进入校园的时间;
			scanf("%d", &stu[i].StudentEnter);
			printf("请输入第%d 个学生的离开校园的时间);
			scanf(" %c", &stu[i].StudentLeave);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("学生信息增加完毕！！！\n");
		system("pause");
}
//显示全部数据信息
void display()
{
	int i;
	printf("共有%d位学生的信息:\n", n);
	if (0 != n)
	{
		printf("学生学号 \t学生姓名 \t进校时间   \t离校时间   \n");
		printf("--------------------------------------------------------------------\n");
		for (i = 0; i<n; i++)
		{
			printf("%s \t%s \t%s   \t%s   \n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentEnter, stu[i].StudentLeave);
		}
	}
	system("pause");
}
void save(){
	int i;
	FILE *fp;
	char filename[LEN + 1];
	printf("请输入要保存的文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	for (i = 0; i < n; i++){
		fprintf(fp, "%s%s%s%s\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentEnter, stu[i].StudentLeave);
	}
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");
}
void menu()/* 界面*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                学生信息管理系统                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************系统功能菜单*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 1.查询学生信息    * * 2.增加学生信息    *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.显示当前信息    * *  4.保存当前学生信息*     \n");
	printf("     *********************************************     \n");
	printf("     * 5.退出系统        *                             \n");
	printf("     ********************** **********************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("请选择菜单编号:");
	scanf("%d", &num);
	switch (num)
	{

	case 1:seek(); break;
	case 2:insert(); break;
	case 3:display(); break;
	case 4:save(); break;
	case 5:
		k = 0; 
		printf("即将退出程序!\n");
		break;
	default:printf("请在1-5之间选择\n");
	}
}