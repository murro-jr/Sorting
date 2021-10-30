class LinkedList {
public:
    struct Node {
        Node(int data):
            _data(data), _prev(0), _next(0)
        {}

        int _data;
        Node* _prev;
        Node* _next;
    };

    LinkedList():
        _head(0), _tail(0), _swaps(0), _compares(0), _size(0)
    {}

    void display();

    Node* front() { return _head; }
    Node* back() { return _tail; }
    int swaps() { return _swaps; }
    int compares() { return _compares; }
    int restructures() { return _restructures; }
    int size() { return _size; }

    Node* findMinimum(Node* cursor = 0);
    Node* findMaximum(Node* cursor = 0);

    void insert(Node* item);
    void insertBefore(Node* cursor, Node* item);
    void insertAfter(Node* cursor, Node* item);
    void swap(Node* left, Node* right);

    void selectionSort();
    void quickSort(Node* low, Node* high);
    void insertionSort();

private:
    Node* _partition(Node* low, Node* high);
    void _insertionSort(Node* item);

    Node* _head;
    Node* _tail;

    int _swaps;
    int _compares;
    int _restructures;
    int _size;
};
