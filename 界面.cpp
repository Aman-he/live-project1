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
/
