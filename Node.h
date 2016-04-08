

template<class T>
class Node {
private:
	Node<T>* _next;
	Node<T>* _prev;
public:
	///<summary>
	///		�������� ��������
	///</summary>
	T Element;

	Node(T element) {
		this->Element = element;
		this->_next = nullptr;
		this->_prev = nullptr;
	}

	///<summary>
	///		���������� ��������� �� ��������� ����		
	///</summary>
	void SetNext(Node<T>* node) {
		_next = node;
		if (node != nullptr) {
			node->_prev = this;
		}
	}

	///<summary>
	///		���������� ��������� �� ���������� ����
	///</summary>
	void SetPrev(Node<T>* node) {
		_prev = node;
		if (node != nullptr) {
			node->_next = this;
		}
	}

	///<summary>
	///		�������� ��������� �� ��������� ����
	///</summary>
	Node<T>* GetNext() {
		return _next;
	}

	///<summary>
	///		�������� ��������� �� ���������� ����
	///</summary>
	Node<T>* GetPrev() {
		return _prev;
	}
};