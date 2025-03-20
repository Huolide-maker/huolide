#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>    //引用//
#define long sizeof(struct student)

void look();



struct student
{
	int num;
	char name[15];
	double chinese;
	double math;
	double english;

	double sum;
};

struct student stu[50];

//菜单功能

void caidan()
{

    printf("**********************************************\n");
    printf("---------------学生信息管理系统----------------\n");
    printf("**********************************************\n");
    printf("               1.导入学生信息                \n");
    printf("               2.查找学生信息               \n");
    printf("               3.删除学生信息               \n");
    printf("               4.修改学生信息               \n");
    printf("               5.插入学生信息               \n");
    printf("               6.排序                    \n");
    printf("               7.统计学生总数               \n");
    printf("               8.显示所有学生信息           \n");
    printf("               0.退出系统               \n");

	printf("----------------------------------------------|\n");
	printf("选择0-8\n");
}

//导入信息

void into()
{
	int i,m=0;
	char ch[2];
	FILE*fp;

	if((fp=fopen("data.txt","a+"))==NULL)
	{
		printf("找不到文件\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&stu[m],long,1,fp)==1)
		{
			m++;
			}
	}
	fclose(fp);
	if(m==0)

	{
	printf("文件无内容\n");
 }
 else
 {
 	look();
 }
 if((fp=fopen("data.txt","wb"))==NULL)

 {
 	printf("找不到文件\n");
 	return;
 }
 printf("输入学生信息请按(y)其他键可以返回:");
 scanf("%s",ch);

 while(strcmp(ch,"y")==0)
 {
    printf("number:");
 	scanf("%d",&stu[m].num);
for(i=0;i<m;i++)
	if(stu[i].num==stu[m].num)
	{
		printf("学号已经存在了，按任意键继续!");
		getch();
		fclose(fp);
		return;

	}
	printf("name:");
	scanf("%s",stu[m].name);
	printf("chinese:");

    scanf("%lf",&stu[m].chinese);
	printf("math:");

    scanf("%lf",&stu[m].math);
	printf("english:");

    scanf("%lf",&stu[m].english);
	stu[m].sum=stu[m].chinese+stu[m].math+stu[m].english;
	if(fwrite(&stu[m],long,1,fp)!=1)
	{
		printf("不能保存!");
		getch();

	 }
	 else
	 	{
	 		printf("%s被保存!\n",stu[m].name);
	 		m++;

		 }
		printf("继续请按(y)返回请按任意键:\n");
		scanf("%s",ch);
 }
 fclose(fp);
 printf("OK!\n");
}
//查询信息

void see()
{
	FILE*fp;
	int snum,i,m=0;
	if((fp=fopen("data.txt","rb"))==NULL)
	{
		printf("找不到文件\n");
		return;
	}
	while(!feof(fp))
	if(fread(&stu[m],long,1,fp)==1)
	m++;
	fclose(fp);
	if(m==0)
	{
		printf("文件没有内容\n");
		return;

	}

    printf("请输入number:");
    scanf("%d",&snum);
    for(i=0;i<m;i++)
   if(snum==stu[i].num)
   {
	printf("学号    姓名            语文      数学       英语         总分\t\n");
	printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum);
	break;
}
    if(i==m)printf("找不到学生！\n");

}


//删除学生信息

void del()
{
	FILE*fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("data.txt","r+"))==NULL)          //data.txt文件不存在
	{
		printf("找不到文件\n");
		return;

	}
	 while(!feof(fp)) if(fread(&stu[m],long,1,fp)==1)m++;
	 fclose(fp);
	 if(m==0)
	{
	 	printf("文件夹中没有记录！\n");           //data.txt文件存在，但里面没有内容
		return;
	}

    look();
	printf("请输入学生number：");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
	if(snum==stu[i].num)
	{
		printf("找到了这个学生，是否删除？删除请按(y)返回请按任意键\n");
		scanf("%s",ch);

	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)//判断是否要进行删除
	{
		for(j=i;j<m;j++)
		stu[j]=stu[j+1];                          //将后一个记录移到前一个记录的位置
		m--;
		if((fp=fopen("data.txt","wb"))==NULL)
		{
			printf("找不到文件\n");
			return;
		 }
		 for(j=0;j<m;j++)                         //将更改后的记录重新写入指定的磁盘文件中
		 if(fwrite(&stu[j],long,1,fp)!=1)
		 {
		 	printf("无法保存\n");
		 	getch();
		  }
		  fclose(fp);
		  printf("删除成功！\n");
	}else{
		printf("有学生但不删除！\n");
	}
	break;
	}

 }


//修改学生信息

void modify()//自定义修改函数
{
  	FILE *fp;
  	struct student t;

  	int i=0,j=0,m=0,snum;
  	if((fp=fopen("data.txt","r+"))==NULL)
    {
		printf("找不到文件\n");
        return;
  	}
  	while(!feof(fp))
  		if(fread(&stu[m] ,long,1,fp)==1)
			m++;
  	if(m==0)
  	{
	  	printf("文件无记录！\n");
		fclose(fp);
	  	return;

  	}
  	look();
  	printf("输入学生的号码： ");

  	scanf("%d",&snum);
  	for(i=0;i<m;i++)
	  	if(snum==stu[i].num)//检索记录中是否有要修改的信息
		  {
	  		printf("找到了这名学生,可以修改他的信息!\n");
	  		printf("name:");
	  		scanf("%s",stu[i].name);//输入名字
       	   	printf("chinese:");
	  		scanf("%lf",&stu[i].chinese);//输入语文课成绩
      	    printf("math:");
	  		scanf("%lf",&stu[i].math);//输入数学课成绩
      	    printf("english:");
	  		scanf("%lf",&stu[i].english);//输入英语课成绩
	  		printf("修改成功!\n");
	  		stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;

			if((fp=fopen("data.txt","wb"))==NULL)
     		{
		 		printf("不能打开\n");
			 	return;
			}
	  		for(j=0;j<m;j++)//将新修改的信息写入指定的磁盘文件中
	  		if(fwrite(&stu[j] ,long,1,fp)!=1)
       		{
		   		printf("不能保存\n");
		   		getch();
			}
	 		fclose(fp);
	 		break;
  		}
  		if(i==m)
		  	printf("没有找到这名学生!\n");//未找到要查找的信息
}

//插入学生信息

void insert()
{
	FILE *fp;

  	int i,j,k,m=0,snum;
  	if((fp=fopen("data.txt","r+"))==NULL)
    {
		printf("找不到文件\n");
		return;
	}
  	while(!feof(fp))
 		if(fread(&stu[m],long,1,fp)==1)
		 m++;
  	if(m==0)
	{
	  	printf("文件无记录!\n");
  		fclose(fp);
  		return;

  	}
  	look();
  	printf("请输入要插入的位置(number)：\n");
  	scanf("%d",&snum);//输入要插入的位置
  	for(i=0;i<m;i++)
	  	if(snum==stu[i].num)
		  	break;
	  	for(j=m-1;j>i;j--)
           	stu[j+1]=stu[j];//从最后一条记录开始均向后移一位
	  	printf("现在请输入要插入的学生信息.\n");
          	printf("number:");
	  	scanf("%d",&stu[i+1].num);
	  	for(k=0;k<m;k++)
	    	if(stu[k].num==stu[m].num)
	    	{

	    		printf("该学生已经存在，按任意键继续!\n");
	    		getch();
	    		fclose(fp);
	    		return;

	    	}
	  	printf("name:");
	  	scanf("%s",stu[i+1].name);
         	 printf("chinese:");
	  	scanf("%lf",&stu[i+1].chinese);
          	printf("math:");
	  	scanf("%lf",&stu[i+1].math);
          	printf("required course:");
	  	scanf("%lf",&stu[i+1].english);
	 	 stu[i+1].sum=stu[i+1].chinese+stu[i+1].math+stu[i+1].english;
	 	 printf("插入成功！按任意键返回主界面！\n");
	 	 if((fp=fopen("data.txt","wb"))==NULL)
    	{
	 		printf("不能打开！\n");
			 return;
		}
	  	for(k=0;k<=m;k++)
	  	if(fwrite(&stu[k] ,long,1,fp)!=1)
	  	//将修改后的信息导入文件中
       	{

		   printf("不能保存!\n");
		   getch();

		}
  	fclose(fp);
}

//学生排名

void line()
{
	FILE *fp;
	struct student t;
	int i = 0,j = 0,m = 0;
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("找不到文件\n");
		return;
	}
	while(!feof(fp))
	if(fread(&stu[m],long,1,fp)==1)
	m++;
	fclose(fp);
	if(m==0)
	{
		printf("文件无记录！\n");
		return;
	}
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("找不到文件\n");
		return;
	}
	for(i=0;i<m-1;i++)
	for(j=i+1;j<m;j++)
	if(stu[i].sum<stu[j].sum)
	{
		t=stu[i];stu[i]=stu[j];stu[j]=t;
	}
   if((fp = fopen("data.txt","wb"))==NULL)
   {
   	printf("找不到文件\n");
   	return;
   }
	for(i=0;i<m;i++)
	if(fwrite(&stu[i],long,1,fp)!=1)
	{
		printf("%s 不能保存文件！\n");
		getch();
	}
	fclose(fp);
	printf("保存成功!\n");

}

//统计学生个数
void all()
{
	FILE *fp;
  	int m=0;
  	if((fp=fopen("data.txt","r+"))==NULL)
     {
	 	printf("找不到文件\n");
		 return;
	}
  	while(!feof(fp))
	  	if(fread(&stu[m],long,1,fp)==1)
		  	m++;
		  				//统计记录个数即学生个数
  	if(m==0) {printf("no record!\n");fclose(fp);return;}
  	printf("这个班级一共有 %d 名学生!\n",m);//将统计的个数输出
  	fclose(fp);
}

//显示所有学生信息

void look()
{
	FILE*fp;
	int i,m=0;
	fp=fopen("data.txt","rb");
	while(!feof(fp))
	{
		if(fread(&stu[m],long,1,fp)==1)
		m++;
	}
	fclose(fp);
	printf("学号   姓名            语文          数学        英语        总分\t\n");
	for(i=0;i<m;i++)
	{
		printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum);
	}
}



//主函数

 int main(int argc,const char *argv[],const char *env[])
{   int j;
    char user[10],ps[7];

    printf("请输入用户名：\n");

    gets(user);

    printf("请输入密码：\n");
    j=0;
    while((ps[j]=getch())!='\r'){
        printf("*");
        j++;
    }
    ps[j]='\0';
    printf("\n");
    if((strcmp(user,"admin")==0)&&(strcmp(ps,"123")==0)){

	int n;
	caidan();
	scanf("%d",&n);
	while(n)
	{

		switch(n)
		{
			case 1:
				into();
				break;
			case 2:
				see();
				break;
			case 3:
				del();
				break;
			case 4:
				modify();
				break;
			case 5:
				insert();
				break;
			case 6:
				line();
				break;
			case 7:
				all();
				break;
			case 8:
				look();
				break;
			default:
				break;

		}
	getch();
	caidan();//返回菜单界面
	scanf("%d",&n);
	}
 }
 else
    {
    printf("用户名或密码错误！\n");

 }

}
