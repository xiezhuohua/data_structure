#define _CRT_SECURE_NO_WARNINGS 1
#include"cirlist.h"
//����ѭ������
Clist Createlist() {
	Clist list = (Clist)malloc(sizeof(Cnode));
	list->data = '\0';
	list->next = list;
	return list;
}

//�������
int Clearlist(Clist list) {
	Cnode* p = NULL;
	Cnode* q = NULL;
	list = list->next;
	p = list->next;
	while (p != (Cnode*)list) {
		q = p->next;
		free(p);
		p = q;
	}
	return 1;
}
//β�巨
int Tailinsert(Clist list, char data) {
	Cnode* old = NULL;
	Cnode* new = NULL;
	list->next = (Clist)old;
	list->next = (Clist)new;
	printf("�����롤��Ҫ����Ԫ�صĸ���\n");
	int n = 0;
	scanf("%d",&n);

	while (n) {
		
		new = (Cnode*)malloc(sizeof(Cnode));
		printf("������Ԫ��\n");
		scanf("\n%c", &new->data);
		old->next = (Clist) new;
		old = new;
		--n;
	}
	list = (Clist)old;
	old = NULL;
	new = NULL;
	return 1;
}
//ͷ�巨
int Headinsert(Clist list, char data) {

	Cnode* new = NULL;
	list->next = (Clist)new;
	printf("�����롤��Ҫ����Ԫ�صĸ���\n");
	int n = 0;
	scanf("%d", &n);
	
	
	while (n) {

		new = (Cnode*)malloc(sizeof(Cnode));
		printf("������Ԫ��\n");
		scanf("\n%c", &new->data);
		new->next = (Clist)list->next;
		list->next = (Clist)new->next;
		--n;
	}
	list = (Clist)new;

	new = NULL;
	return 1;
}
//��������
int Listlength(Clist list) {
	Cnode* p = NULL;
	int lenght = 0;
	p =(Cnode*)list->next;
	p = p->next;
	while (p != (Cnode*)list->next) {
		++lenght;
		p = p->next;
	}
	return lenght;
}
//�ж������Ƿ�Ϊ��
int Iflistemtpy(Clist list) {
	if (list->next = (Cnode*)list) {
		printf("����Ϊ��\n");
		return 1;
	}
	else {
		printf("����Ϊ��\n");
		return 0;
	}
}
//����Ԫ�ز��������λ��
int Datafindindex(Clist list, char data) {
	int index = 1;
	Cnode*  p = (Cnode*)list->next;
	p = p->next;
	while (p!= (Cnode*)list->next) {
		
		if (p->data==data) {
			return index;
		}
		else {
			p = p->next;
		}
		++index;
	}
	return -1;
}
//����Ԫ�ز�������ĵ�ַ
Cnode* Datafindaddress(Clist list, char data) {
	Cnode* p = (Cnode*)list->next;
	while (p!= (Cnode*)list->next) {
		if (p->data!=data) {
			p = (Cnode*)p->next;
		}
		else {
			return p;
		}
	}
	return NULL;	
}
//����λ�ò���Ԫ��
char Indexfinddata(Clist list, int index) {
	int length = Listlength(list);
	if (index<1 || index>length) {
		printf("������Χ\n");
		return '\0';
	}
	Cnode* p = (Cnode*)list->next;
	p = p->next;
	while (--index&&p!= (Cnode*)list->next) {
		p = p->next;
	}
	if (index == 0) {
		return p->data;
	}
	else {
		printf("û���ҵ�\n");
		return '\0';
	}
}
//����λ�ò���Ԫ�ص�ַ
Cnode* Indexfindaddress(Clist list, int index) {
	int length = Listlength(list);
	if (index<0 || index>length) {//����ͷͷ���
		printf("������Χ\n");
		return NULL;
	}
	Cnode* p = list;
	while (index!=-1 && p != (Cnode*)list->next) {
		p = p->next;
		--index;
	}
	if (index == -1) {
		return p;
	}
	else {
		printf("û���ҵ�\n");
		return NULL;
	}
}

//����λ������Ԫ��
int Indexadddata(Clist list, int index) {
	Cnode* p = (Cnode*)malloc(sizeof(Cnode));
	printf("������Ԫ��\n");
	scanf("%c",&p->data);
	Cnode* q = Indexfindaddress(list,  index-1);
	int length = Listlength(list);
	if (index<1||index>length+1) {
		printf("������Χ\n");
		return -1;
	}
	p = q->next;
	q->next = (Clist)p;
	return 1;
}
//����λ��ɾ��Ԫ��
int Deletdata(Clist list, int index) {
	int length = Listlength(list);
	if (index<1 || index>length ) {
		printf("������Χ\n");
		return -1;
	}
	Cnode* persent = Indexfindaddress(list, index );
	Cnode* oldnode = Indexfindaddress(list, index - 1);
	oldnode->next = persent->next;
	free(persent);
	persent = NULL;
	oldnode = NULL;
	return 1;
}
///����λ���޸�Ԫ������
int Alterdata(Clist list, int index,char data) {
	int length = Listlength(list);
	if (index<1 || index>length) {
		printf("������Χ\n");
		return -1;
	}
	Cnode* persent = Indexfindaddress(list, index);
	printf("�������޸ĺ�Ԫ��\n");
	scanf("%c",&persent->data);
	return 1;
}
//����λ���޸�Ԫ��λ��
int Alterdataindex(Clist list, int oldindex, int newindex) {
	int length = Listlength(list);
	if (oldindex<1 || oldindex>length) {
		printf("������Χ\n");
		return -1;
	}
	if (newindex<0 || newindex>length+1) {
		printf("������Χ\n");
		return -1;
	}
	Cnode* old  = Indexfindaddress(list, oldindex);
	Cnode* oldnode = Indexfindaddress(list, oldindex - 1);
	oldnode->next = old->next;
	oldnode = Indexfindaddress(list, newindex - 1);
	old->next = oldnode->next;
	oldnode->next = (Clist)old;
	return 1;
}
//����ѭ������
void Destroy(Clist list) {
	Cnode* p = (Cnode*)list;
	int length = Listlength(list)+1;
	while (--length) {
		list = list->next;
		free(p);
		p = (Cnode*)list;
	}
	list = NULL;
	p = NULL;
}

//�ϲ�����ѭ������
void combinelist(Clist list1, Clist list2) {
	Cnode* p = list1->next;
	list1->next = list2->next->next;
	free(list2->next);
	list2->next = p;
	p = NULL;
}