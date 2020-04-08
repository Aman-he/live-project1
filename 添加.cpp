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