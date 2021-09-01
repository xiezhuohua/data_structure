#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
//��ʼ��˳���
void Clearlist(List* list) {
	list->length = 0;
	memset(list->data, '\0', LONG);
}

//��˳�����
int Listlenght(List* list) {
	printf("����%d", list->length);
	return list->length;
}

//��ȡԪ��
char Getdata(List* list, int index) {
	if (index<0 || index>LONG) {
		printf("����λ�ò��Ϸ�\n");
		return -1;
	}
	return list->data[index-1];
}

//��ȡԪ��λ��
int Listindex(List* list, char data) {
	
	for (int i = 0; i < list->length; i++) {
		if (data == list->data[i]) {
			return i;
		}
		else {
			printf("Ԫ�ز�����\n");
			return -1;
		}
	}
	printf("Ԫ�ز�����\n");
	return -1;
}

//����Ԫ��
int Addata(List* list, int index,char data) {
	if (list->length == LONG) {
		printf("�����޷�����\n");
		return -1;
	}
	if (list->length == 0) {
		list->data[0] = data;
		list->length++;
		return 1;
	}
	else if(index>list->length || index< 0){
		list->data[list->length] = data;
		list->length++;
		return 1;
	}
	else {
		for (int i = list->length - 1; i <= index - 1;i--) {
			list->data[i + 1] = list->data[i];
		}
		list->data[index - 1] = data;
		list->length++;
		return 1;
	}
}

//ɾ��Ԫ��
int Delete(List* list, char data) {
	int index = Listindex(list, data);
	if (list->length == 0) {
		printf("�����κ�Ԫ��\n");
		return -1;
	}
	else if(index<0 || index > list->length){
		printf("ɾ��ʧ��\n");
		return -1;
	}
	else if (index == list->length) {
		list->data[index - 1] = '\0';
		list->length--;
		return 1;
	}
	else {
		for (int i = index - 1; i < list->length-1; i++) {
			list->data[i] = list->data[i + 1];
		}
		list->data[list->length - 1] = '\0';
		list->length--;
		return 1;
	}

}

//�޸�Ԫ������
int Changedata(List* list, char data, int index) {
	if (index<0 || index > list->length) {
		printf("ɾ��ʧ��\n");
		return -1;
	}
	else {
		list->data[index - 1] = data;
		return 1;
	}
}

//�޸�Ԫ��λ��
int Changeseat(List* list, char data,int index) {
	int oldindex = Listindex(list, data);
	if (index > list->length || index < 0) {
		printf("λ�ó�����Χ���޸�ʧ��\n");
		return -1;
	}else {
		for (int i = oldindex - 1; i < index-1; i++) {
			list->data[i] = list->data[i + 1];
		}
		list->data[index - 1] = data;
		return 1;
	}
}

////˳�������
//int Sortlist(List* list) {
//
//}

//�ж�˳��������Ƿ�Ϊ��
int Ifdataempty(List* list, int index) {
	if (list->data[index - 1] == '\0') {
		printf("��λ��Ԫ��Ϊ��\n");
		return 1;
	}
	else {
		printf("��λ��Ԫ�ز�Ϊ��\n");
		return  -1;
	}
}

//�ͷ�˳���
void Destroy(List* list) {
	free(list);
		list = NULL;
}