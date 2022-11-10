#include<iostream>
#include"Clist.h"
#include<string>
#include<string.h>
using namespace std;
int main() {
	int N, k;
	cout << "请输入约瑟夫环游戏人数：";
	cin >> N;
	cout << "报数为k的人离开，请输入k值：";
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