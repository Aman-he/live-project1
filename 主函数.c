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
	int StudentAge;
	char StudentSex;
	float score[3];
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
