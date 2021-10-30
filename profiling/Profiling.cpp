#include "Profiling.h"

Profiling::Profiling(int size, DATASET_TYPE set)
: _list(new LinkedList())
{
    switch (set) {
        case Profiling::RANDOM:
            random_set(size);
            break;
        case Profiling::SORTED:
            sorted_set(size);
            break;
        case Profiling::REVERSE:
            reverse_sorted(size);
            break;
    }
}

void Profiling::run_sort(SORT_TYPE sort)
{
    auto baseTime = chrono::high_resolution_clock::now();

    switch (sort) {
        case Profiling::SELECTION:
            _list->selectionSort();
            break;
        case Profiling::INSERTION:
            _list->insertionSort();
            break;
        case Profiling::QUICKSORT:
            _list->quickSort(_list->front(), _list->back());
            break;
        case Profiling::NONE:
            break;
    }

    auto stopTime = chrono::high_resolution_clock::now();
    _executionTime = chrono::duration_cast<chrono::microseconds>(stopTime - baseTime);
}

void Profiling::random_set(int size)
{
    srand((unsigned) time(0));
    for (int count = 0; count < size; count++) {
        LinkedList::Node* node = new LinkedList::Node(rand());
        _list->insert(node);
    }
}

void Profiling::sorted_set(int size)
{
    for (int count = 0; count < size; count++) {
        LinkedList::Node* node = new LinkedList::Node(count);
        _list->insert(node);
    }
}

void Profiling::reverse_sorted(int size)
{
    for (int count = size; count > 0; count--) {
        LinkedList::Node* node = new LinkedList::Node(count);
        _list->insert(node);
    }
}
