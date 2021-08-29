#define _CRT_SECURE_NO_WARNINGS 1
#include"complex.h"

//��������ĸ���
void Scanfcomplex(Complex* p, float real, float imaginary) {
	p->real = real;
	p->imaginary = imaginary;
}
//�ӷ�
Complex Addition(Complex* p, Complex* q) {
	Complex S = { 0 };
	S.real = p->real + q->real;
	S.imaginary = p->imaginary + q->imaginary;
	return S;
}
//����
Complex Subtraction(Complex* p, Complex* q) {
	Complex S = { 0 };
	S.real = p->real - q->real;
	S.imaginary = p->imaginary - q->imaginary;
	return S;
}
//�˷�
Complex multiplication(Complex* p, Complex* q) {
	Complex S = { 0 };
	S.real = p->real * q->real - p->imaginary * q->imaginary;
	S.imaginary = p->real * q->imaginary + p->imaginary * q->real;
	return S;
}

//����
Complex Division(Complex* p, Complex* q) {
	Complex S = { 0 };
	if(q->real == 0 && q->imaginary == 0){
		printf("��ĸ����Ϊ0��\n");
	}
	else {
		S.real = (p->real * q->real - p->imaginary * q->imaginary) /
			((q->real * q->real) + (q->imaginary * q->imaginary));
		S.imaginary = (p->real * q->imaginary + p->imaginary * q->real) /
			((q->real * q->real) + (q->imaginary * q->imaginary));
	}
	return S;
}

int main() {
	Complex comp = { 0 };
	Complex  w = { 0 };
	Complex y = { 0 };
	Scanfcomplex(&w,1,6);
	Scanfcomplex(&comp, 8, 9);
	y = Addition(&w, &comp);
	printf("%.2f + %.2f i + %.2f + %.2f i = %.2f + %.2f i\n",comp.real,comp.imaginary,w.real,w.imaginary,y.real,y.imaginary);

	y = Subtraction(&w, &comp);
	printf("%.2f + %.2f i + %.2f + %.2f i = %.2f + %.2f i\n", comp.real, comp.imaginary, w.real, w.imaginary, y.real, y.imaginary);
	
	y = multiplication(&w, &comp);
	printf("%.2f + %.2f i + %.2f + %.2f i = %.2f + %.2f i\n", comp.real, comp.imaginary, w.real, w.imaginary, y.real, y.imaginary);
	y = Division(&w, &comp);
	printf("%.2f + %.2f i + %.2f + %.2f i = %.2f + %.2f i\n", comp.real, comp.imaginary, w.real, w.imaginary, y.real, y.imaginary);
}