#ifndef THREELISTCLASS_H
#define THREELISTCLASS_H

/*
 *  Class represents behavior of three lists of integers as a sequence
 */

class ThreeListClass
{
    int* first_list;
    const int first_list_size;
    int* second_list;
    const int second_list_size;
    int* third_list;
    const int third_list_size;
    // iterators for lists
    int first_list_itr;
    int second_list_itr;
    int third_list_itr;
    // Conditions show whether (true) or no (false) all elements in lists were iterated from start to finish
    bool first_list_fully_itereted;
    bool second_list_fully_itereted;
    bool third_list_fully_itereted;
public:
    ThreeListClass(int* list_1,int list_1_size, int* list_2, int list_2_size, int* list_3, int list_3_size);
    ~ThreeListClass();
    void reset();
    int getNext(); // returns the next element in the ascending sequence
};

#endif // THREELISTCLASS_H
