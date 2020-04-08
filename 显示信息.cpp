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
