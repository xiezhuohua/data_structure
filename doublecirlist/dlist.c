#define _CRT_SECURE_NO_WARNINGS 1
#include"dlist.h"

//����˫ѭ������
void Create() {
	List list = (Node*)malloc(sizeof(Node));
	list->next = list;
	list->pion = list;
	list->data = 0;
}
//�������
void Clear(List list) {
	Node* p = list;
	Node* q = list->next;
	while (q!=list) {
		p = q;
		q = q->next;
		free(p);
	}
	p = NULL;
	q = NULL;

}

//��������
void desroy(List list) {
	Node* head = list;
	
	Node* p = list;
;
	do {
		
		list = list->next;
		free(p);
		p = list;
	} while (p!=head);
	head = NULL;
	p = NULL;
	list = NULL;
}
//�ж������Ƿ�Ϊ��
int IFemtpy(List list){
	if (list->next == list && list->pion ==list) {
		printf("����Ϊ��\n");
		return 1;
	}
	else {
		printf("����Ϊ��\n");
		return -1;
	}
}
//��������
int Getlength(List list) {
	Node* p = list;
	int i = 0;
	do
	{
		++i;
		p = p->next;
	} while (p!= list);
	p = NULL;
	return i;
}

//����Ԫ����λ��
int Datafindindex(List list, int data) {
	Node* p = list;
	int index = 0;
	do
	{
		if (p->data == data) {
			return index;
		}
		else {
			p = p->next;
		}
		++index;		
	} while (p != list);
	p = NULL;//û�ҵ�
	return 0;
}
//����Ԫ�����ַ
Node* Datafindadderss(List list, int data) {
	Node* p = list;
	int index = 0;
	do
	{
		if (p->data == data) {
			return p;
		}
		else {
			p = p->next;
		}
		++index;
	} while (p != list);
	p = NULL;//û�ҵ�
	return NULL;
}
//����λ����Ԫ��
int Indexfinddata(List list, int index) {
	int length = Getlength(list);
	if (index > length || index < 1) {
		printf("����Χ\n");
	}
	Node* p = list->next;
	++index;
	while (--index || p != list) {
		p = p->next;
	}
	if (index == 0) {
		return p->data;
	}
	else {
		printf("û���ҵ�\n");
		return -1;
	}

}
//����λ�����ַ
Node* Indexfindadderss(List list, int index) {
	int length = Getlength(list);
	if (index > length || index < 0) {
		printf("����Χ\n");
	}
	Node* p = list->next;
	++index;
	while (--index || p != list) {
		p = p->next;
	}
	if (index == 0) {
		return p;
	}
	else {
		printf("û���ҵ�\n");
		return NULL;
	}

}
//����Ԫ��
int Adddata(List list, int index, int data) {
	int  f = Indexfinddata(list, index);
	if (f==-1) {
		printf("�޷�����\n");
		return -1;
	}
	else {
		Node* now = (Node*)malloc(sizeof(Node));
		now->data = data;
		Node* prior = Indexfindadderss(list, index - 1);//��һ�����
		prior->next->pion = now;
		now->next = prior->next;
		prior->next = now;
		now->pion = prior;
		return 1;
	}
}
//ɾ��Ԫ��
int Deteldata(List list, int index) {
	int  f = Indexfinddata(list, index);
	if (f == -1) {
		printf("�޷�����\n");
		return -1;
	}
	else {
		Node* now = Indexfindadderss(list, index);
		now->pion->next = now->next;
		now->next->pion = now->pion;
		return 1;
	}
}
//�޸�Ԫ��
int Alterdata(List list, int index, int data) {
	int  f = Indexfinddata(list, index);
	if (f == -1) {
		printf("�޷�����\n");
		return -1;
	}
	else {
		Node* now = Indexfindadderss(list, index);
		now->data = data;
		return 1;
	}
}
//�޸�Ԫ��λ��
int Alterdataindex(List list, int oldindex, int newindex) {
		int  f = Indexfinddata(list, oldindex);
		if (f == -1||newindex>Getlength(list)+1||newindex<1) {
			printf("�޷�����\n");
			return -1;
		}
		else {
			Node* old = Indexfindadderss(list, oldindex);
			old->pion->next = old->next;
			old->next->pion = old->pion;
			Node* new = Indexfindadderss(list, oldindex);
			new->pion = old;
			old->pion = new->pion;
			old->next = new;
			new->pion = old;
			return 1;
		}
}
//ͷ�巨
void Haedinput(List list) {
	printf("������Ҫ����ĸ���\n");
	int n = 0;
	scanf("%d",&n);
	Node* new = (Node* )malloc(sizeof(Node));
	
	printf("������Ԫ��\n");
	scanf("%d",&new->data);
	list->next = new;
	new->pion = list;
	new->next = list;
	--n;
	do
	{
		new = (Node*)malloc(sizeof(Node));
		printf("������Ԫ��\n");
		scanf("%d", &new->data);
		list->next->pion = new;
		new->next = list->next;
		list->next = new;
		new->pion = list;

	} while (--n);
	//old = NULL;
	new = NULL;

}

//β�巨
void Tailinput(List list) {
	printf("������Ҫ����ĸ���\n");
	int n = 0;
	scanf("%d", &n);
	Node* new = (Node*)malloc(sizeof(Node));
	Node* old  = list;
	
	do
	{
		new = (Node*)malloc(sizeof(Node));
		printf("������Ԫ��\n");
		scanf("%d", &new->data);
		old->next = new;
		new->pion = old;
		new->next = old;
		old = new;
	} while (--n);
	old = NULL;
	new = NULL;
}
