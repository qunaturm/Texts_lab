#include "Node.h"
#include <iostream>
#include <string>
#include <stack>


struct Iterator
{
	Node* it;

	Node& operator*() {
		return *it;
	}

	Node& operator->() {
		return *it;
	}

	Iterator() { it = 0; }

	Iterator(Node* n) {
		it = n;
	}

	Iterator next() {
		if (it->next != 0) {
			it = it->next;
			return *this;
		}
		else return NULL;
	}

	Iterator next_end() {
		while (it->next != 0) {
			it = it->next;
		}
		return *this;
	}

	Iterator down() {
		if (it->down != 0) {
			it = it->down;
			return *this;
		}
		else return NULL;
	}

	Iterator down_end() {
		next_end();
		while (it->down != 0) {
			it = it->down;
			next_end();
		}
		return *this;
	}

	bool isNext() {
		return it->next != 0;
	}

	bool isDown() {
		return it->down != 0;
	}

	void delNext(std::string data) {
		delete it->next;
		it->next = new Node(data, it->level);
	}

	void delDown(std::string data) {
		delete it->down;
		it->down = new Node(data, it->level + 1);
	}

	bool operator==(const Iterator& iterator) {
		return it == iterator.it;
	}

	bool operator!=(const Iterator& iterator) {
		return it != iterator.it;
	}

	friend std::ostream& operator<<(std::ostream& os, const Iterator it);
};

class Texts
{
	Node* head;
	Node* tail;

public:
	Iterator begin() {
		Iterator res(head);
		return res;
	}

	Iterator end() {
		Iterator res(head);
		res.down_end();
		return res;
	}

	Texts() {
		head = new Node();
		tail = head;
	}

	void pushback_this_level(std::string data) {
		if (head == tail) {
			head->data = data;
			head->level = 0;
			head->next = 0;
		}
		else {
			tail->next = new Node(data, tail->level);
			tail = tail->next;
			tail->next = 0;
		}
	}

	void pushback_next_level(std::string data) {
		if (head == tail) {
			head->down = new Node(data, head->level + 1);
			tail = head->down;
			tail->next = 0;
		}
		else {
			tail->down = new Node(data, tail->level + 1);
			tail = tail->down;
			tail->next = 0;
		}
	}

	std::pair<std::string, int> pop() {
		if (head == tail) throw "";

		std::pair<std::string, int> res(tail->data, tail->level);
		tail = 0;
		return res;
	}

	void print() {
		Node* cur_next = head;
		Node* cur_down = head;
		std::stack<Node*> way;
		int c = 1;

		while (cur_next != 0) {
			cur_down = cur_next;
			c++;

			while (cur_down != 0) {

				if (cur_down->next != 0) {
					way.push(cur_down->next);
					c--;
				}

				for (int i = 0; i < cur_down->level; i++) std::cout << " ";
				std::cout << c << ". " << cur_down->data << std::endl;
				cur_down = cur_down->down;
			}

			if (way.size() > 0) {
				cur_next = way.top();
				way.pop();
			}
			else cur_next = cur_next->next;
		}

	}

};

