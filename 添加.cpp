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