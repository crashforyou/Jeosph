#include<iostream>
#include"Clist.h"
#include<string>
#include<string.h>
using namespace std;
int main() {
	int N, k;
	cout << "������Լɪ����Ϸ������";
	cin >> N;
	cout << "����Ϊk�����뿪��������kֵ��";
	cin >> k;

	/*
	Clist<int> list(15);
	list.display();
	list.deleteout(list.getFront());
	list.display();
	
	cout << list.getSize() << endl;
	list.deleteout(list.getFront());
	list.display();
	*/
	josephus<int>(N, k);
}