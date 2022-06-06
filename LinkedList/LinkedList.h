#include <iostream>

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T _val;
		Node* _next;

		Node(const T& val) : _val(val), _next(nullptr) {}
		Node() = delete;
	};

	Node* _head;
	size_t _size;

public: 
	
	LinkedList() : _head(nullptr), _size(0) {}


	~LinkedList() {
		while (_head != nullptr) {
			Node* prev = _head;
			_head = _head->_next;
			delete prev;
		}
	}

	LinkedList(const LinkedList& other) : LinkedList() {
		Node* other_head = other.get_head();

		while (other_head != nullptr) {
			push_back(other_head->_val);
			other_head = other_head->_next;
		}
	}

	LinkedList(LinkedList&& other) noexcept : _head(std::move(other._head)), _size(other._size) {
		other._head = nullptr;
		other._size = 0;
	}

	LinkedList& operator=(LinkedList&& other) noexcept {
		if (&other == this)
			return *this;

		_head = std::move(other._head);
		other._head = nullptr;

		_size = other._size;
		other._size = 0;

		return *this;
	}

	LinkedList& operator=(const LinkedList& other) {
		if (this == &other || (other.get_head() == nullptr && _head == nullptr))
			return *this;

		Node* other_head = other.get_head();
		Node* this_head = _head;

		while (this_head != nullptr && other_head != nullptr) {
			this_head->_val = other_head->_val;
			this_head = this_head->_next;
			other_head = other_head->_next;

		}
		
		if (_size > other.get_size()) {
			Node* prev;

			while (this_head != nullptr) {
				prev = this_head;
				this_head = this_head->_next;
				delete prev;
			}
		}
		else if (_size < other.get_size()) {

			while (other_head != nullptr) {
				push_back(other_head->_val);
				other_head = other_head->_next;
			}
		}

		return *this;
	}

	void push_front(const T& data){
		Node* new_node = new Node(data);
		new_node->_next = _head;
		_head = new_node;
		++_size;
	}
	void push_back(const T& data) {
		if (_head == nullptr) {
			push_front(data);
			return;
		}

		Node* head_tmp = _head;

		while (head_tmp->_next != nullptr)
			head_tmp = head_tmp->_next;

		head_tmp->_next = new Node(data);
		++_size;
	}

	void pop_front() {
		if (_head == nullptr)
			return;

		Node* cur = _head;
		_head = _head->_next;
		delete cur;
		--_size;
	}
	void pop_back() {
		if (_head == nullptr)
			return;
		else if (_size == 1) {
			pop_front();
			return;
		}

		Node* head_tmp = _head;

		while (head_tmp->_next->_next != nullptr)
			head_tmp = head_tmp->_next;

		delete head_tmp->_next;
		head_tmp->_next = nullptr;

		--_size;
	}

	void reverse_list() {

		auto ptr = _head;
		auto prev = get_null();

		while (ptr != nullptr)
		{
			auto tmp_next = ptr->_next;
			ptr->_next = prev;
			prev = ptr;
			ptr = tmp_next;
		};

		_head = prev;
	}

	void display() const {
		Node* ptr = _head;

		while (ptr != nullptr) {
			std::cout << ptr->_val << " ";
			ptr = ptr->_next;
		}
	}

	Node* get_head() const {
		return _head;
	}
	Node* get_null() const {
		return nullptr;
	}
	const size_t& get_size() const {
		return _size;
	}
};