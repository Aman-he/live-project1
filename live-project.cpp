#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>	/*I/O����*/
#include<stdlib.h>	/*����˵��*/
#include<string.h>	/*�ַ�������*/

#define LEN 15		/* ѧ�ź���������ַ���,ʵ�������*/
#define N 50		/* ���ѧ������,ʵ�������*/

int k = 1, n = 0, m = 0;/* n����ǰ��¼��ѧ������*/

//��������
void seek();
void insert();
void display();
void save();
void menu();

//�ṹ�屣��ѧ����Ϣ
struct student{
	char StudentId[LEN+1];
	char StudentName[LEN+1];
	char StudentEnter;
	char StudentLeave;
}stu[N];

//������
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}
//����ѧ����Ϣ37
void seek() /*����*/
{
	int i, item, flag;
	char s1[21]; /* ��������ѧ�������+1Ϊ׼*/
	printf("------------------\n");
	printf("-----1.��ѧ�Ų�ѯ-----\n");
	printf("-----2.��������ѯ-----\n");
	printf("-----3.�˳����˵�-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(s1,stu[i].StudentId) == 0)
			{
				flag = 1;
				printf("ѧ��ѧ��\tѧ������\t����ʱ��\t�뿪ʱ��\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%f\t%f\n", stu[i].StudentId,stu[i].StudentName,stu[i].StudentEnter,stu[i].StudentLeave);
			}
			if (0 == flag)
				printf("��ѧ�Ų����ڣ�\n"); break;
		case 2:
			printf("������Ҫ��ѯ��ѧ��������:\n");
			scanf("%s", s1);
			for (i = 0; i<n; i++)
			if (strcmp(stu[i].StudentName, s1) == 0)
			{
				flag = 1;
				printf("ѧ��ѧ��\tѧ������\t����ʱ��\t�뿪ʱ��\n");
				printf("--------------------------------------------------------------------\n");
				printf("%s\t%s\t%f\t%f\n", stu[i].StudentId, stu[i].StudentName,stu[i].StudentEnter, stu[i].StudentLeave);
			}
			if (0 == flag)
				printf("�����������ڣ�\n"); break;
		case 3:return;
		default:printf("����1-3֮��ѡ��\n");
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
void insert() /*���뺯��*/
{
	int i = n, j, flag;
	printf("����������ӵ�ѧ����:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("�������%dλѧ����ѧ��:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++){
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0){
						printf("��ѧ���Ѵ��ڣ����������룡\n");
						flag = 1;
						break;
					}
				}
			}
			printf("�������%d ��ѧ��������:\n", i+1);
			scanf("%s", stu[i].StudentName);
			printf("�������%d ��ѧ���Ľ���У԰��ʱ��;
			scanf("%d", &stu[i].StudentEnter);
			printf("�������%d ��ѧ�����뿪У԰��ʱ��);
			scanf(" %c", &stu[i].StudentLeave);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("ѧ����Ϣ������ϣ�����\n");
		system("pause");
}
//��ʾȫ��������Ϣ
void display()
{
	int i;
	printf("����%dλѧ������Ϣ:\n", n);
	if (0 != n)
	{
		printf("ѧ��ѧ�� \tѧ������ \t��Уʱ��   \t��Уʱ��   \n");
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
	printf("������Ҫ������ļ�����\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	for (i = 0; i < n; i++){
		fprintf(fp, "%s%s%s%s\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentEnter, stu[i].StudentLeave);
	}
	printf("����ɹ�������\n");
	fclose(fp);
	system("pause");
}
void menu()/* ����*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                ѧ����Ϣ����ϵͳ                    *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 1.��ѯѧ����Ϣ    * * 2.����ѧ����Ϣ    *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.��ʾ��ǰ��Ϣ    * *  4.���浱ǰѧ����Ϣ*     \n");
	printf("     *********************************************     \n");
	printf("     * 5.�˳�ϵͳ        *                             \n");
	printf("     ********************** **********************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("��ѡ��˵����:");
	scanf("%d", &num);
	switch (num)
	{

	case 1:seek(); break;
	case 2:insert(); break;
	case 3:display(); break;
	case 4:save(); break;
	case 5:
		k = 0; 
		printf("�����˳�����!\n");
		break;
	default:printf("����1-5֮��ѡ��\n");
	}
}