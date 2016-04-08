#include "Node.h"

template<class T>
class List {
private:
	Node<T>* _head;
	Node<T>* _tail;
	Node<T>* _current;
	size_t _size;
	
public:
	List() {
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}

	///<summary>
	///		�������� ������� � ����� ������
	///</summary>
	void PushBack(T element) {
		if (_size == 0) {
			_head = new Node<T>(element);
			_tail = _head;
			_current = _head;
			_size++;
			return;
		}

		Node<T>* newnode = new Node<T>(element);
		_tail->SetNext(newnode);
		_tail = newnode;
		_size++;
		_current = _head;
	}

	///<summary>
 	///		�������� ������� � ������ ������
	///</summary>
	void PushFront(T element) {
		if (_size == 0) {
			_head = new Node<T>(element);
			_tail = _head;
			_current = _head;
			_size++;
			return;
		}
		Node<T>* newnode = new Node<T>(element);
		_head->SetPrev(newnode);
		_head = newnode;
		_size++;
		_current = _head;
	}

	///<summary>
	/// 	������� ������� �� ����� ������
	///</summary>
	void PopBack() {
		Node<T>* newTail = _tail->GetPrev();
		_size = _size == 0 ? 0 : _size - 1;
		
		if (_size == 0) {
			_head = nullptr;
			_tail = nullptr;
			_current = nullptr;
			return;
		}
		newTail->SetNext(nullptr);
		delete _tail;
		_tail = newTail;
		_current = _head;
	}

	///<summary>
	///		������� ������� �� ������ ������
	///</summary>
	void PopFront() {
		Node<T>* newHead = _head->GetNext();
		_size = _size == 0 ? 0 : _size - 1;
		
		if (_size == 0) {
			_head = nullptr;
			_tail = nullptr;
			_current = nullptr;
			return;
		}
		newHead->SetPrev(nullptr);
		delete _head;
		_head = newHead;
		_current = _head;
	}

	///<summary>
	///		������� � ���������� ��������
	///</summary>
	void IncCurrent() {
		_current = _current->GetNext();
	}

	///<summary>
	///		������� � ����������� ��������
	///</summary>
	void DecCurrent() {
		_current = _current->GetPrev();
	}

	///<summary>
	///		���������, �������� �� ������� ������� NULL
	///</summary>
	bool IsCurrentNull() {
		if (_current == nullptr) {
			_current = _head;
			return true;
		}
		return false;
	}

	///</summary>
	///		���������� ������ �������� ��������
	///</summary>
	bool SetCurrentIndex(size_t index) {
		if (index >= _size) {
			return false;
		}

		_current = _head;
		for (size_t i = 0; i < index; i++) {
			this->IncCurrent();
		}
	}

	///<summary>
	///		� ������
	///</summary>
	bool GoToStart() {
		return this->SetCurrentIndex(0);
	}

	///<summary>
	///		� �����
	///</summary>
	bool GoToEnd() {
		return this->SetCurrentIndex(_size - 1);
	}

	///<summary>
	///		���������� ������� �������
	///</summary>
	T Current() {
		return _current->Element;
	}

	///<summary>
	///		������
	///</summary>
	size_t Size() {
		return _size;
	}
	///<summary>
	///		���������, �������� �� ������ ������
	///</summary>
	bool Empty() {
		return _size == 0;
	}
};
