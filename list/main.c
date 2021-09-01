#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
int Scanfindex() {
	int index = 0;
	printf("请输入要操作的位置\n");
	scanf("%d", &index);
	return index;
}
char Scanfdata() {
	char data = '\0';
	printf("请输入要操作的数据\n");
	scanf("%c",&data);
	return data;
}
void Menue(){
	printf("---------------------------------\n");
	printf("----	1.初始化顺序表				   ------\n");
	printf("----	2.求顺序表长度				   ------\n");
	printf("----	3.获取元素				   ------\n");
	printf("----	4.获取元素位置				   ------\n");
	printf("----	5.增加元素				   ------\n");
	printf("----	6.删除元素				   ------\n");
	printf("----	7.修改元素内容				   ------\n");
	printf("----	8.修改元素位置				   ------\n");
	printf("----	9.判断顺序表数据是否为空				   ------\n");
	printf("----	10.释放顺序表				   ------\n");
	printf("--------11.退出                  -------------\n");
}

int main() {
	List* list = (List*)malloc(sizeof(List));
	int a = 0;
	int index = 0;
	
	char data = '\0';
	Clearlist(list);
	while (a != 11){
		Menue();
		printf("请输入对应功能序号\n");
		scanf("%d", &a);
		while (1) {
			if (a < 1 || a>11) {
				printf("输入不合法，请重新输入\n");
				scanf("%d", &a);
			}
			break;
		}
		switch (a)
		{
		case 1:Clearlist(list);
			break;
		case 2:Listlenght( list);
			break;
		case 3: index = Scanfindex();
			Getdata(list, index);
			break;
		case 4:data = Scanfdata();
			Listindex(list, data);
			break;
		case 5: index = Scanfindex(); 
			data = Scanfdata();
			Addata( list,  index,  data);
			break;
		case 6: data = Scanfdata(); 
			Delete( list,   data);
			break;
		case 7:index = Scanfindex(); 
			data = Scanfdata();
			Changedata( list,  data,  index);
			break;
		case 8:index = Scanfindex(); 
			data = Scanfdata();
			Changeseat( list, data,  index);
			break;
		case 9:index = Scanfindex(); 
			Ifdataempty( list, index);

			break;
		case 10:Destroy( list);
			break;
		case 11:
			break;
		}
	}

	Destroy(list);
}