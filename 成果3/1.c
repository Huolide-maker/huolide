#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>    //����//
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

//�˵�����

void caidan()
{

    printf("**********************************************\n");
    printf("---------------ѧ����Ϣ����ϵͳ----------------\n");
    printf("**********************************************\n");
    printf("               1.����ѧ����Ϣ                \n");
    printf("               2.����ѧ����Ϣ               \n");
    printf("               3.ɾ��ѧ����Ϣ               \n");
    printf("               4.�޸�ѧ����Ϣ               \n");
    printf("               5.����ѧ����Ϣ               \n");
    printf("               6.����                    \n");
    printf("               7.ͳ��ѧ������               \n");
    printf("               8.��ʾ����ѧ����Ϣ           \n");
    printf("               0.�˳�ϵͳ               \n");

	printf("----------------------------------------------|\n");
	printf("ѡ��0-8\n");
}

//������Ϣ

void into()
{
	int i,m=0;
	char ch[2];
	FILE*fp;

	if((fp=fopen("data.txt","a+"))==NULL)
	{
		printf("�Ҳ����ļ�\n");
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
	printf("�ļ�������\n");
 }
 else
 {
 	look();
 }
 if((fp=fopen("data.txt","wb"))==NULL)

 {
 	printf("�Ҳ����ļ�\n");
 	return;
 }
 printf("����ѧ����Ϣ�밴(y)���������Է���:");
 scanf("%s",ch);

 while(strcmp(ch,"y")==0)
 {
    printf("number:");
 	scanf("%d",&stu[m].num);
for(i=0;i<m;i++)
	if(stu[i].num==stu[m].num)
	{
		printf("ѧ���Ѿ������ˣ������������!");
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
		printf("���ܱ���!");
		getch();

	 }
	 else
	 	{
	 		printf("%s������!\n",stu[m].name);
	 		m++;

		 }
		printf("�����밴(y)�����밴�����:\n");
		scanf("%s",ch);
 }
 fclose(fp);
 printf("OK!\n");
}
//��ѯ��Ϣ

void see()
{
	FILE*fp;
	int snum,i,m=0;
	if((fp=fopen("data.txt","rb"))==NULL)
	{
		printf("�Ҳ����ļ�\n");
		return;
	}
	while(!feof(fp))
	if(fread(&stu[m],long,1,fp)==1)
	m++;
	fclose(fp);
	if(m==0)
	{
		printf("�ļ�û������\n");
		return;

	}

    printf("������number:");
    scanf("%d",&snum);
    for(i=0;i<m;i++)
   if(snum==stu[i].num)
   {
	printf("ѧ��    ����            ����      ��ѧ       Ӣ��         �ܷ�\t\n");
	printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum);
	break;
}
    if(i==m)printf("�Ҳ���ѧ����\n");

}


//ɾ��ѧ����Ϣ

void del()
{
	FILE*fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("data.txt","r+"))==NULL)          //data.txt�ļ�������
	{
		printf("�Ҳ����ļ�\n");
		return;

	}
	 while(!feof(fp)) if(fread(&stu[m],long,1,fp)==1)m++;
	 fclose(fp);
	 if(m==0)
	{
	 	printf("�ļ�����û�м�¼��\n");           //data.txt�ļ����ڣ�������û������
		return;
	}

    look();
	printf("������ѧ��number��");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
	if(snum==stu[i].num)
	{
		printf("�ҵ������ѧ�����Ƿ�ɾ����ɾ���밴(y)�����밴�����\n");
		scanf("%s",ch);

	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)//�ж��Ƿ�Ҫ����ɾ��
	{
		for(j=i;j<m;j++)
		stu[j]=stu[j+1];                          //����һ����¼�Ƶ�ǰһ����¼��λ��
		m--;
		if((fp=fopen("data.txt","wb"))==NULL)
		{
			printf("�Ҳ����ļ�\n");
			return;
		 }
		 for(j=0;j<m;j++)                         //�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���
		 if(fwrite(&stu[j],long,1,fp)!=1)
		 {
		 	printf("�޷�����\n");
		 	getch();
		  }
		  fclose(fp);
		  printf("ɾ���ɹ���\n");
	}else{
		printf("��ѧ������ɾ����\n");
	}
	break;
	}

 }


//�޸�ѧ����Ϣ

void modify()//�Զ����޸ĺ���
{
  	FILE *fp;
  	struct student t;

  	int i=0,j=0,m=0,snum;
  	if((fp=fopen("data.txt","r+"))==NULL)
    {
		printf("�Ҳ����ļ�\n");
        return;
  	}
  	while(!feof(fp))
  		if(fread(&stu[m] ,long,1,fp)==1)
			m++;
  	if(m==0)
  	{
	  	printf("�ļ��޼�¼��\n");
		fclose(fp);
	  	return;

  	}
  	look();
  	printf("����ѧ���ĺ��룺 ");

  	scanf("%d",&snum);
  	for(i=0;i<m;i++)
	  	if(snum==stu[i].num)//������¼���Ƿ���Ҫ�޸ĵ���Ϣ
		  {
	  		printf("�ҵ�������ѧ��,�����޸�������Ϣ!\n");
	  		printf("name:");
	  		scanf("%s",stu[i].name);//��������
       	   	printf("chinese:");
	  		scanf("%lf",&stu[i].chinese);//�������Ŀγɼ�
      	    printf("math:");
	  		scanf("%lf",&stu[i].math);//������ѧ�γɼ�
      	    printf("english:");
	  		scanf("%lf",&stu[i].english);//����Ӣ��γɼ�
	  		printf("�޸ĳɹ�!\n");
	  		stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;

			if((fp=fopen("data.txt","wb"))==NULL)
     		{
		 		printf("���ܴ�\n");
			 	return;
			}
	  		for(j=0;j<m;j++)//�����޸ĵ���Ϣд��ָ���Ĵ����ļ���
	  		if(fwrite(&stu[j] ,long,1,fp)!=1)
       		{
		   		printf("���ܱ���\n");
		   		getch();
			}
	 		fclose(fp);
	 		break;
  		}
  		if(i==m)
		  	printf("û���ҵ�����ѧ��!\n");//δ�ҵ�Ҫ���ҵ���Ϣ
}

//����ѧ����Ϣ

void insert()
{
	FILE *fp;

  	int i,j,k,m=0,snum;
  	if((fp=fopen("data.txt","r+"))==NULL)
    {
		printf("�Ҳ����ļ�\n");
		return;
	}
  	while(!feof(fp))
 		if(fread(&stu[m],long,1,fp)==1)
		 m++;
  	if(m==0)
	{
	  	printf("�ļ��޼�¼!\n");
  		fclose(fp);
  		return;

  	}
  	look();
  	printf("������Ҫ�����λ��(number)��\n");
  	scanf("%d",&snum);//����Ҫ�����λ��
  	for(i=0;i<m;i++)
	  	if(snum==stu[i].num)
		  	break;
	  	for(j=m-1;j>i;j--)
           	stu[j+1]=stu[j];//�����һ����¼��ʼ�������һλ
	  	printf("����������Ҫ�����ѧ����Ϣ.\n");
          	printf("number:");
	  	scanf("%d",&stu[i+1].num);
	  	for(k=0;k<m;k++)
	    	if(stu[k].num==stu[m].num)
	    	{

	    		printf("��ѧ���Ѿ����ڣ������������!\n");
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
	 	 printf("����ɹ�������������������棡\n");
	 	 if((fp=fopen("data.txt","wb"))==NULL)
    	{
	 		printf("���ܴ򿪣�\n");
			 return;
		}
	  	for(k=0;k<=m;k++)
	  	if(fwrite(&stu[k] ,long,1,fp)!=1)
	  	//���޸ĺ����Ϣ�����ļ���
       	{

		   printf("���ܱ���!\n");
		   getch();

		}
  	fclose(fp);
}

//ѧ������

void line()
{
	FILE *fp;
	struct student t;
	int i = 0,j = 0,m = 0;
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("�Ҳ����ļ�\n");
		return;
	}
	while(!feof(fp))
	if(fread(&stu[m],long,1,fp)==1)
	m++;
	fclose(fp);
	if(m==0)
	{
		printf("�ļ��޼�¼��\n");
		return;
	}
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("�Ҳ����ļ�\n");
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
   	printf("�Ҳ����ļ�\n");
   	return;
   }
	for(i=0;i<m;i++)
	if(fwrite(&stu[i],long,1,fp)!=1)
	{
		printf("%s ���ܱ����ļ���\n");
		getch();
	}
	fclose(fp);
	printf("����ɹ�!\n");

}

//ͳ��ѧ������
void all()
{
	FILE *fp;
  	int m=0;
  	if((fp=fopen("data.txt","r+"))==NULL)
     {
	 	printf("�Ҳ����ļ�\n");
		 return;
	}
  	while(!feof(fp))
	  	if(fread(&stu[m],long,1,fp)==1)
		  	m++;
		  				//ͳ�Ƽ�¼������ѧ������
  	if(m==0) {printf("no record!\n");fclose(fp);return;}
  	printf("����༶һ���� %d ��ѧ��!\n",m);//��ͳ�Ƶĸ������
  	fclose(fp);
}

//��ʾ����ѧ����Ϣ

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
	printf("ѧ��   ����            ����          ��ѧ        Ӣ��        �ܷ�\t\n");
	for(i=0;i<m;i++)
	{
		printf("%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n",stu[i].num,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum);
	}
}



//������

 int main(int argc,const char *argv[],const char *env[])
{   int j;
    char user[10],ps[7];

    printf("�������û�����\n");

    gets(user);

    printf("���������룺\n");
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
	caidan();//���ز˵�����
	scanf("%d",&n);
	}
 }
 else
    {
    printf("�û������������\n");

 }

}
