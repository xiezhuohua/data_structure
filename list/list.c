#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
//初始化顺序表
void Clearlist(List* list) {
	list->length = 0;
	memset(list->data, '\0', LONG);
}

//求顺序表长度
int Listlenght(List* list) {
	printf("表长：%d", list->length);
	return list->length;
}

//获取元素
char Getdata(List* list, int index) {
	if (index<0 || index>LONG) {
		printf("输入位置不合法\n");
		return -1;
	}
	return list->data[index-1];
}

//获取元素位置
int Listindex(List* list, char data) {
	
	for (int i = 0; i < list->length; i++) {
		if (data == list->data[i]) {
			return i;
		}
		else {
			printf("元素不存在\n");
			return -1;
		}
	}
	printf("元素不存在\n");
	return -1;
}

//增加元素
int Addata(List* list, int index,char data) {
	if (list->length == LONG) {
		printf("已满无法增加\n");
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

//删除元素
int Delete(List* list, char data) {
	int index = Listindex(list, data);
	if (list->length == 0) {
		printf("已无任何元素\n");
		return -1;
	}
	else if(index<0 || index > list->length){
		printf("删除失败\n");
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

//修改元素内容
int Changedata(List* list, char data, int index) {
	if (index<0 || index > list->length) {
		printf("删除失败\n");
		return -1;
	}
	else {
		list->data[index - 1] = data;
		return 1;
	}
}

//修改元素位置
int Changeseat(List* list, char data,int index) {
	int oldindex = Listindex(list, data);
	if (index > list->length || index < 0) {
		printf("位置超出范围，修改失败\n");
		return -1;
	}else {
		for (int i = oldindex - 1; i < index-1; i++) {
			list->data[i] = list->data[i + 1];
		}
		list->data[index - 1] = data;
		return 1;
	}
}

////顺序表排序
//int Sortlist(List* list) {
//
//}

//判断顺序表数据是否为空
int Ifdataempty(List* list, int index) {
	if (list->data[index - 1] == '\0') {
		printf("该位置元素为空\n");
		return 1;
	}
	else {
		printf("该位置元素不为空\n");
		return  -1;
	}
}

//释放顺序表
void Destroy(List* list) {
	free(list);
		list = NULL;
}