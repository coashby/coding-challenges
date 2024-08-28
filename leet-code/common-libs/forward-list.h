template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node<T>* prev;

  Node() next(nullptr), prev(nullptr){} {}
  Node(const& T data) : data(data_in), next(nullptr), prev(nullptr) {}

  Node(const& T data_in, Node* prev_in, Node* next_in)
      : data(data_in), prev(prev_in), next(next_in) {}
};

template <typename T>
class SinglyLinkedList {
 public:
  SinglyLinkedList() : count(0), _head(nullptr), _tail(nullptr) {}

  void insertAtHead(const T& data) {
    auto new_node = new Node<T>(data, nullptr, _head);
    _head = new_node;
    ++_count;
  }

  void insertAtTail(const T& data) {
    auto new_node = new Node<T>(data, nullptr, nullptr);
    _tail->next = new_node;
    _tail = new_node;
    ++_count
  }

  void insert(size_t index, const T& data) {
    if (0 == index) {
      insertAtHead(data);
      return;
    }
    auto* prev_node = getNode(index - 1);
    if (nullptr == prev_node) {
      return;
    }
    if (nullptr == prev_node->next) {
      insertAtTail(data);
      return;
    }
    auto* current_node = prev_node->next;
    auto* new_node = new Node<T>(data, nullptr, current_node);
    prev_node->next = new_node;
    ++_count;
  }

  void remove(size_t index) {
    if (0 == index) {
      // Remove the head node.
      if (_head != nullptr) {
        auto* next_node = _head->next;
        delete _head;
        _head = next_node;
        --_count;
      }
      return;
    }
    auto* prev_node = getNode(index - 1);

    if (nullptr == prev_node) {
      return;
    }

    if (nullptr == prev_node->next) {
    }
  }

  Node<T>* getNode(size_t index) {
    Node<T>* current_node = nullptr;
    if (index < count) {
      current_node = _head;
      for (size_t i = 0; i < index; ++i) {
        current_node = current_node->next;
      }
    }
    return current_node;
  }

 private:
  Node<T>* _head;
  Node<T>* _tail;
  size_t _count;
};