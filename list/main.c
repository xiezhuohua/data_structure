#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
int Scanfindex() {
	int index = 0;
	printf("������Ҫ������λ��\n");
	scanf("%d", &index);
	return index;
}
char Scanfdata() {
	char data = '\0';
	printf("������Ҫ����������\n");
	scanf("%c",&data);
	return data;
}
void Menue(){
	printf("---------------------------------\n");
	printf("----	1.��ʼ��˳���				   ------\n");
	printf("----	2.��˳�����				   ------\n");
	printf("----	3.��ȡԪ��				   ------\n");
	printf("----	4.��ȡԪ��λ��				   ------\n");
	printf("----	5.����Ԫ��				   ------\n");
	printf("----	6.ɾ��Ԫ��				   ------\n");
	printf("----	7.�޸�Ԫ������				   ------\n");
	printf("----	8.�޸�Ԫ��λ��				   ------\n");
	printf("----	9.�ж�˳��������Ƿ�Ϊ��				   ------\n");
	printf("----	10.�ͷ�˳���				   ------\n");
	printf("--------11.�˳�                  -------------\n");
}

int main() {
	List* list = (List*)malloc(sizeof(List));
	int a = 0;
	int index = 0;
	
	char data = '\0';
	Clearlist(list);
	while (a != 11){
		Menue();
		printf("�������Ӧ�������\n");
		scanf("%d", &a);
		while (1) {
			if (a < 1 || a>11) {
				printf("���벻�Ϸ�������������\n");
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