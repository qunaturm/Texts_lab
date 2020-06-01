#include <string>

class Node {
public:
	std::string data;
	Node* next;
	Node* down;
	int level;

	Node() {
		data = "";
		next = 0;
		down = 0;
		level = 0;
	}

	Node(std::string d, int l) {
		data = d;
		next = 0;
		down = 0;
		level = l;
	}
};
