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
