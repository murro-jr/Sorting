#include "LinkedList.h"
#include <iostream>

void LinkedList::display()
{
    Node* temp = _head;
    
    std::cout << "[ ";

    while(temp) {
        std::cout << temp->_data << " ";
        temp = temp->_next;
    }

    std::cout << "]" << std::endl;
}

void LinkedList::insert(Node* item)
{
    if (!_head) {
        _tail = item->_next;
        _head = item;
    } else if (!_tail) {
        item->_prev = _head;
        _head->_next = item;
        _tail = item;
    } else {
        item->_prev = _tail;
        _tail->_next = item;
        _tail = item;
    }

    _size++;
}

void LinkedList::insertBefore(Node* cursor, Node* item)
{
    if (cursor && item)
    {
        Node* cursor_prev = cursor->_prev;
        Node* item_prev = item->_prev;
        Node* item_next = item->_next;

        item->_prev = cursor_prev;
        item->_next = cursor;
        cursor->_prev = item;
        cursor_prev->_next = item;

        item_prev->_next = item_next;

        if (item_next)
            item_next->_prev = item_prev;
    }
}

void LinkedList::insertAfter(Node* cursor, Node* item)
{
    if (cursor && item)
    {
        Node* cursor_next = cursor->_next;
        Node* item_prev = item->_prev;
        Node* item_next = item->_next;

        item->_next = cursor_next;
        item->_prev = cursor;
        cursor->_next = item;
        cursor_next->_prev = item;

        item_next->_prev = item_prev;

        if (item_prev)
            item_prev->_next = item_next;
    }
}

void LinkedList::swap(Node* left, Node* right)
{
    if (left && right)
    {
        int data = left->_data;
        left->_data = right->_data;
        right->_data = data;

        _swaps++;
    }
}

LinkedList::Node* LinkedList::findMinimum(Node* cursor)
{
    Node *temp, *minimumNode;

    if (cursor) {
        temp = cursor;
        minimumNode = cursor;
    } else {
        temp = _head;
        minimumNode = _head;
    }

    if (!temp) return 0;

    while(temp) {
        temp = temp->_next;
        if (temp) {
            _compares++;
            if (temp->_data < minimumNode->_data)
                minimumNode = temp;
        }
    }

    return minimumNode;
}

LinkedList::Node* LinkedList::findMaximum(Node* cursor)
{
    Node *temp, *maximumNode;

    if (cursor) {
        temp = cursor;
        maximumNode = cursor;
    } else {
        temp = _head;
        maximumNode = _head;
    }

    if (!temp) return 0;

    while(temp) {
        temp = temp->_next;
        if (temp) {
            _compares++;
            if (temp->_data > maximumNode->_data)
                maximumNode = temp;
        }
    }

    return maximumNode;
}

LinkedList::Node* LinkedList::_partition(Node* low, Node* high)
{
    Node* temp = low->_prev;
    for (Node* cursor = low; cursor != high; cursor = cursor->_next)
    {
        _compares++;
        if (cursor->_data <= high->_data)
        {
            temp = !temp? low: temp->_next;
            swap(temp, cursor);
        }
    }

    temp = !temp? low: temp->_next;
    swap(temp, high);
    return temp;
}

void LinkedList::_insertionSort(Node* item) {
    Node* current = item->_prev;

    while (current) {
        _compares++;
        if (current->_data >= item->_data)
        {
            swap(current, item);
            item = current;
        }

        current = current->_prev;
    }

    _restructures++;
}

void LinkedList::selectionSort()
{
    Node* minimum, *cursor = _head;

    while(cursor) {
        minimum = findMinimum(cursor);

        if (minimum != cursor)
        {
            swap(cursor, minimum);
            _restructures++;
        }

        cursor = cursor->_next;
    }
}

void LinkedList::quickSort(Node* low, Node* high)
{
    if (high && low != high && low != high->_next)
    {
        Node* p = _partition(low, high);
        quickSort(low, p->_prev);
        quickSort(p->_next, high);
        _restructures++;
    }
}

void LinkedList::insertionSort()
{
    Node *current = _head;

    while (current && current->_next) {
        current = current->_next;
        _insertionSort(current);
    }
}
