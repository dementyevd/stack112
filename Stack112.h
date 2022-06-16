#pragma once
#include<iostream>
using namespace std;

class stack112
{
	char* arr = nullptr;
	int current_size = 0;
	int max_size = 0;

public:
	stack112(size_t max_size) {
		this->max_size = max_size;
		this->arr = new char[max_size];
	}

	~stack112() {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
			this->current_size = 0;
			this->max_size = 0;
		}
	}

	stack112(const stack112& obj) {
		this->current_size = obj.current_size;
		this->max_size = obj.max_size;
		this->arr = new char[this->max_size];
		for (size_t i = 0; i < this->current_size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}

	stack112& operator=(const stack112& obj) {
		if (this == &obj)
			return *this;
		this->~stack112();
		this->current_size = obj.current_size;
		this->max_size = obj.max_size;
		this->arr = new char[this->max_size];
		for (size_t i = 0; i < this->current_size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
		return *this;
	}

	stack112(stack112&& obj) {
		swap(this->arr, obj.arr);
		swap(this->current_size, obj.current_size);
		swap(this->max_size, obj.max_size);
	}

	stack112& operator=(stack112&& obj) {
		swap(this->arr, obj.arr);
		swap(this->current_size, obj.current_size);
		swap(this->max_size, obj.max_size);
		return *this;
	}

	bool full() const {
		return this->current_size == this->max_size;
	}

	bool empty() const {
		return this->current_size == 0;
	}

	void push(char ch) {
		if (!this->full()) {
			this->arr[this->current_size++] = ch;
		}
		else {
			cout << "Stack overflow!" << endl;
		}
	}

	void pop() {
		if (!this->empty()) {
			this->current_size--;
		}
		else
			cout << "Stack is empty!" << endl;
	}

	char top() const {
		return this->arr[this->current_size - 1];
	}

	char& top() {
		return this->arr[this->current_size - 1];
	}

	int size() const {
		return this->current_size;
	}

	int get_max_size() const {
		return this->max_size;
	}
};

