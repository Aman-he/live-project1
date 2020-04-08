//查找学生信息
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