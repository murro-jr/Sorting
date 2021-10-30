#include "LinkedList.h"

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

class Profiling {
public:
    enum SORT_TYPE {
        NONE,
        INSERTION,
        SELECTION,
        QUICKSORT
    };

    enum DATASET_TYPE {
        RANDOM,
        SORTED,
        REVERSE
    };

    Profiling(
        int size = 10000,
        DATASET_TYPE set = Profiling::RANDOM
    );

    void run_sort(SORT_TYPE sort = Profiling::SELECTION);
    void display_set()
    {
        cout << "SET: ";
        _list->display();
        cout << endl;
    }

    double normalized_count()
    {
        return (double)_list->compares()/_list->size();
    }

    double execution_time()
    {
        return _executionTime.count();
    }

private:
    void random_set(int size);
    void sorted_set(int size);
    void reverse_sorted(int size);

    LinkedList* _list;
    chrono::microseconds _executionTime;
};
