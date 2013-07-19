#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

class MergeSort
{
public:
    MergeSort();
    ~MergeSort();
    void Sort(int *array, int length);
private:
    void SortRange(int *array, int start, int length);
    void Merge(int *array, int start1, int length1, int start2, int length2);
};

#endif // MERGE_SORT_H_
