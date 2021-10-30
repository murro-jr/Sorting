#include "profiling/Profiling.h"

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{
    Profiling::SORT_TYPE sortType = Profiling::SELECTION;
    Profiling::DATASET_TYPE dataSet = Profiling::RANDOM;
    int size = 10000;

    //TODO: Handling for invalid string arguments
    size = stoi(argv[1]);
    string options = argv[2];

    if (options.at(0) == '-') {
        options = options.substr(1);
        for (int index = 0; index < options.length(); index++) {
            switch (options.at(index)) {
                case 'i':
                    sortType = Profiling::INSERTION;
                    break;
                case 's':
                    sortType = Profiling::SELECTION;
                    break;
                case 'q':
                    sortType = Profiling::QUICKSORT;
                    break;
                case 'a':
                    dataSet = Profiling::SORTED;
                    break;
                case 'v':
                    dataSet = Profiling::REVERSE;
                    break;
                case 'r':
                    dataSet = Profiling::RANDOM;
                    break;
                case 'n':
                    sortType = Profiling::NONE;
                    break;
            }
        }
    }

    Profiling profiling = Profiling(size, dataSet);
    profiling.display_set();
    profiling.run_sort(sortType);
    cout << "Set after running sort: " << endl;
    profiling.display_set();
    cout << "Normalized count: " << profiling.normalized_count() << endl;
    cout << "Execution time (microseconds): " << profiling.execution_time() << endl;
    return 0;
}
