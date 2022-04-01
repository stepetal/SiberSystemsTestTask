#include "threelistclass.h"

ThreeListClass::ThreeListClass(int *list_1, int list_1_size,
                               int *list_2, int list_2_size,
                               int *list_3, int list_3_size) :          first_list(list_1),
                                                                        first_list_size(list_1_size),
                                                                        second_list(list_2),
                                                                        second_list_size(list_2_size),
                                                                        third_list(list_3),
                                                                        third_list_size(list_3_size),
                                                                        first_list_itr(0),
                                                                        second_list_itr(0),
                                                                        third_list_itr(0),
                                                                        first_list_fully_itereted(false),
                                                                        second_list_fully_itereted(false),
                                                                        third_list_fully_itereted(false)
{

}

ThreeListClass::~ThreeListClass()
{
    reset();
}

void ThreeListClass::reset()
{
    first_list = nullptr;
    second_list = nullptr;
    third_list = nullptr;
    first_list_fully_itereted = false;
    second_list_fully_itereted = false;
    third_list_fully_itereted = false;
}

int ThreeListClass::getNext()
{
    if(first_list_fully_itereted && second_list_fully_itereted && third_list_fully_itereted)
    {
        return 0; // if all elements are iterated return default value
    }
    else if(((((first_list[first_list_itr] < second_list[second_list_itr]) && (first_list[first_list_itr] < third_list[third_list_itr])) && !first_list_fully_itereted)) || // this is regular comparison between three values of three list
                                                                                                                                                                            // which takes into account finish of first list iteration
       ((first_list[first_list_itr] < second_list[second_list_itr]) && third_list_fully_itereted && !first_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                   // fully iterated third list and checks finish of first list iteration
        ((first_list[first_list_itr] < third_list[third_list_itr]) && second_list_fully_itereted && !first_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                   // fully iterated second list and checks finish of first list iteration
        (third_list_fully_itereted && second_list_fully_itereted) // this condition is necessary for the last element
      )
    {
        int min_value = first_list[first_list_itr];
        first_list_itr++;
        if(first_list_itr >= first_list_size)
        {
            first_list_fully_itereted = true;
            first_list_itr = first_list_size - 1;
        }
        return min_value;
    }
    else if((((second_list[second_list_itr] < first_list[first_list_itr]) && (second_list[second_list_itr] < third_list[third_list_itr])) && !second_list_fully_itereted) || // this is regular comparison between three values of three list
                                                                                                                                                                             // which takes into account finish of second list iteration
            ((second_list[second_list_itr] < first_list[first_list_itr]) && third_list_fully_itereted && !second_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                        // fully iterated third list and checks finish of second list iteration
            ((second_list[second_list_itr] < third_list[third_list_itr]) && first_list_fully_itereted && !second_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                         // fully iterated first list and checks finish of second list iteration
            (third_list_fully_itereted && first_list_fully_itereted) // this condition is necessary for the last element
            )
    {
        int min_value = second_list[second_list_itr];
        second_list_itr++;
        if(second_list_itr >= second_list_size)
        {
            second_list_fully_itereted = true;
            second_list_itr = second_list_size - 1;
        }
        return min_value;
    }
    else if((((third_list[third_list_itr] < first_list[first_list_itr]) && (third_list[third_list_itr] < second_list[second_list_itr])) && !third_list_fully_itereted) || // this is regular comparison between three values of three list
                                                                                                                                                                          // which takes into account finish of third list iteration
            ((third_list[third_list_itr] < first_list[first_list_itr]) && second_list_fully_itereted && !third_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                       // fully iterated second list and checks finish of third list iteration
            ((third_list[third_list_itr] < second_list[second_list_itr]) && first_list_fully_itereted && !third_list_fully_itereted) || // this condition excludes from comparison
                                                                                                                                        // fully iterated first list and checks finish of third list iteration
            (second_list_fully_itereted && first_list_fully_itereted) // this condition is necessary for the last element
            )
    {
        int min_value = third_list[third_list_itr];
        third_list_itr++;
        if(third_list_itr >= third_list_size)
        {
            third_list_fully_itereted = true;
            third_list_itr = third_list_size - 1;
        }
        return min_value;
    }
    else
        return 0;
}
