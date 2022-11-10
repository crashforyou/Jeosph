#pragma once
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

template<typename T>
struct node {
	T number;
	node* next;
	node<T>(int num, node* ptr = nullptr) {
		number = num;
		next = nullptr;
	}
};

template<typename T>
class Clist {
private:
	node<T>* front;
	node<T>* tail;
	node<T>* head;
	int size;
public:
	Clist();//默认构造函数
	Clist(int N);//N人约瑟夫环的构造
	void insert(T target, T number);//插入成员
	void display();//遍历人的编号
	void deleteout(node<T>* tg);//删除出局的人
	int getSize();//求表长
	node<T>* search(T target);//查找
	node<T>* getFront();
	node<T>* getHead();
};

#include"Clist.h"
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

template<typename T>
Clist<T>::Clist() {
	size = 0;
	head = nullptr;
	front = tail = nullptr;
}

template<typename T>
Clist<T>::Clist(int N) {
	size = N;
	head = new node<T>(0, nullptr);
	head->next = new node<T>(1);
	front = tail = head->next;
	for (int i = 2; i <= N; i++) {
		node<T>* Node = new node<T>(i, nullptr);
		tail->next = Node;
		tail = tail->next;
	}
	tail->next = front;
}

template<typename T>
void Clist<T>::insert(T target, T number) {
	node<T>* ptr = search(number);
	node<T>* prev = front;
	while (prev->next != ptr) {
		prev = prev->next;
	}
	node<T>* Nnode = new node<T>(target);
	Nnode->next = ptr;
	prev->next = Nnode;
	size++;
}

template<typename T>
void Clist<T>::display() {
	node<T>* ptr = front;
	while (ptr->next != front) {
		cout << ptr->number << " ";
		ptr = ptr->next;
	}
	cout << ptr->number << endl;
}

template<typename T>
int Clist<T>::getSize() {
	return size;
}

template<typename T>
node<T>* Clist<T>::getHead() {
	return head;
}

template<typename T>
node<T>* Clist<T>::search(T target) {
	node<T>* ptr = front;
	for (int i = 1; i < getSize(); i++) {
		if (ptr->number == target) {
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}


template<typename T>
void Clist<T>::deleteout(node<T>* tg) {
	node<T>* prev = head;
	node<T>* curr = tg->next;
	while (prev->next != tg) {
		prev = prev->next;
	}
	if (tg != tail) {
		prev->next = curr;
		delete tg;
		front = head->next;
		tail->next = head->next;
		size--;
	}
	else {
		prev->next = curr;
		tail = prev;
		delete tg;
		size--;
	}
}

template<typename T>
node<T>* Clist<T>::getFront() {
	return front;
}

template<typename T>
void josephus(int N, int k) {
	Clist<int> listJeosph(N);
	cout << "局内玩家为："; listJeosph.display();
	node<T>* curr = listJeosph.getFront();
	node<T>* prev = listJeosph.getHead();
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= k - 1;j++) {
			curr = curr->next;
			prev = prev->next;
		}
		cout << "Delete contestant " << curr->number << endl;
		curr = curr->next;
		listJeosph.deleteout(prev->next);
		cout << "局内玩家为："; listJeosph.display();
		prev->next = curr;
	}
	cout << "Contestant "<<curr->number<< " win the game!!!" << endl;
	delete curr;
	delete listJeosph.getHead();
}
