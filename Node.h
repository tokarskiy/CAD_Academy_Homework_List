

template<class T>
class Node {
private:
	Node<T>* _next;
	Node<T>* _prev;
public:
	///<summary>
	///		Хранимое значение
	///</summary>
	T Element;

	Node(T element) {
		this->Element = element;
		this->_next = nullptr;
		this->_prev = nullptr;
	}

	///<summary>
	///		Установить указатель на следующий узел		
	///</summary>
	void SetNext(Node<T>* node) {
		_next = node;
		if (node != nullptr) {
			node->_prev = this;
		}
	}

	///<summary>
	///		Установить указатель на предыдущий узел
	///</summary>
	void SetPrev(Node<T>* node) {
		_prev = node;
		if (node != nullptr) {
			node->_next = this;
		}
	}

	///<summary>
	///		Получить указатель на следующий узел
	///</summary>
	Node<T>* GetNext() {
		return _next;
	}

	///<summary>
	///		Получить указатель на предыдущий узел
	///</summary>
	Node<T>* GetPrev() {
		return _prev;
	}
};