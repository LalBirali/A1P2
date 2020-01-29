#pragma once
#include <stdlib.h>
#include "Object.h"


/**
 * This class represents an Array, more akin to a dynamic ArrayList type
 * versus a fixed-sized array, which may already be represented or built-in in CwC.
 * This interface offers the overall main functionalities:
 *      Addition of elements
 *      Addition of Arrays
 *      Removal of elements
 *      Indexing by Element
 *      Get Element by Index
 *      Equality
 *      Replacing elements at an Index
 * This class CAN be implemented using an underlying array structure that is dynamically resized. 
 * Note that the inital memory outlay is an array of pointers of size 10. We wish to reduce
 * the amount of resizing of the array, which would make several operations have O(n) time instead
 * of O(1) time. The below fields exist to serve as an example of how to implement. 
 * There are several STUB implementations in this API: In order to write a StringArray
 * you will need to extend Array and correctly override the virtual functions. 
 **/
class Array : public Object {
public:

    /**
     * Default constructor which will set the initial max-capacity to the array to 10. 
     **/
    Array();

    /**
     * Initalized this array with the characteristics of the passed in array.
     * @arg arr Array containing values to be used in initialization. 
     **/
    Array(Array* arr);

    /**
     * Destructor which will free the memory of the underlying array as well. 
     **/
    ~Array();

    /**
     * Will return the Object pointer at the provided index. if the index is invalid, 
     * then the method will return NULL.
     * @arg index Location to get the value in the array at. 
     **/
     Object* get(size_t index);


    /**
     * Clears the array and reinitializes the underlying array to 10 spots with no elements. 
     * Reinitializes the size to 0. 
     **/
    virtual void clear();

    /**
     * Resizing the underlying array. And then copying over the elements to a new array with
     * the updated size. 
     * Default is doubling the array size when the max capacity of the 
     * underlying array less the number of elements is 2. 
     **/
    virtual void resize();

    /**
     * Returns the first index of the of given Object pointer. 
     * If the object pointer is not found then -1 is returned.
     * @arg to_find Object to find the index of. 
     **/
    virtual int indexOf(Object* to_find);

    /**
     * Adds the element provided to the end of the list, unless the given element is NULL, 
     * then it will not be added. The size is incremented by 1. If resizing the array is necessary, 
     * then that should be done.
     * @arg to_add Object to be added to the array. 
     **/
    virtual void add(Object* to_add);

    /**
     * Adds the provided array to the end of the list, unless the given array is NULL, 
     * then it will not be added. 
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array. If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects that all need to be added to this array. 
     **/
    virtual void addAll(Array* to_add);

    /**
     * Adds the provided object at the given index, unless the given object is NULL, 
     * then it will not be added. Otherwise, all elements previously at the index and
     * to the right will be shifted accordingly. 
     * If the index is invalid, then nothing will be added/shifted. 
     * The size of this array is incremented by 1. 
     * If resizing the array is necessary, then that should be done. 
     * @arg to_add Object to be added to the array
     * @arg index Location to add the Object at
     **/
    virtual void add(Object* to_add, size_t index);

    /**
     * Adds all the elements of the provided array at the given index, 
     * unless the given array is NULL, then it will not be added. Otherwise, 
     * all elements previously at the index and
     * to the right will be shifted accordingly by the size of the procided array, 
     * If the index is invalid, then nothing will be added/shifted.
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array.  If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects to be added to the array
     * @arg index Location to add the objects to the array at
     **/
    virtual void addAll(Array* to_add, size_t index);

    /**
     * Returns the subarray starting from the provided index to the end of the array. 
     * If the index is invalid, then the method returns NULL
     * @arg index Starting place for the subarray
     **/
    virtual Array* subArray(size_t index);

    /**
     * Returns the subarray starting from the provided index to the ending index
     * The starting index must always be greater than the ending index. If either index is invalid, 
     * then NULL is returned. The set is [start, end)
     * @arg startIndex starting place for the subarray
     * @arg endIndex location of the last object to be put in the subarray
     **/
    virtual Array* subArray(size_t startIndex, size_t endIndex);

    /**
     * Removes the first instance of the given Object in this array. If nothing 
     * is found, then no action will occur. The size reduces by 1 if the 
     * element is found.
     * @arg to_remove Object to be removed from the array
     **/
    virtual void remove(Object* to_remove);

    /**
     * Removes all instances of the given Object in this array. If nothing 
     * is found, then no action will occur. The size reduces the number of found
     * elements there are.
     * @arg to_remove Object that all instances in the array will be removed of
     **/
    virtual void removeAll(Object* to_remove);

    /**
     * Returns number of elements in the array. 
     **/
    virtual size_t getSize();

    /**
     * Overriding the Object equals method. 
     * Returns if all the elements in this array and the given object are equal and 
     * in the same other. 
     * If the given object is NULL or not an array, then false will be returned.
     * @arg other Object to check if this array is equal to
     **/
    bool equals(Object* other);

    /**
     * Overriding the Object hash_me() method. 
     * Hashes the array based on user specifications. Default implementation is
     * to hash all internal elements and sum them up. 
     **/
    size_t hash_me_();
};

/**
 * Incomplete implementation of String Array. No methods overriden from
 * Array. Created for testing purposes, so we can design tests. 
 **/
class StringArray : public Array {
    public:

     /**
     * Default constructor which will set the initial max-capacity to the array to 10. 
     **/
    StringArray();

    /**
     * Initalized this array with the characteristics of the passed in array.
     * @arg arr Array containing values to be used in initialization. 
     **/
    StringArray(StringArray* arr);

    /**
     * Destructor which will free the memory of the underlying array as well. 
     **/
    ~StringArray();

    /**
     * Will return the String pointer at the provided index. if the index is invalid, 
     * then the method will return NULL.
     * @arg index Location to get the value in the array at. 
     **/
     String* get(size_t index);


    /**
     * Clears the array and reinitializes the underlying array to 10 spots with no elements. 
     * Reinitializes the size to 0. 
     **/
    void clear();

    /**
     * Resizing the underlying array. And then copying over the elements to a new array with
     * the updated size. 
     * Default is doubling the array size when the max capacity of the 
     * underlying array less the number of elements is 2. 
     **/
     void resize();

    /**
     * Returns the first index of the of given String pointer. 
     * If the pointer is not a String, return -1. 
     * If the string pointer is not found then -1 is returned.
     * @arg to_find String to find the index of. 
     **/
    int indexOf(Object* to_find);

    /**
     * Adds the element provided to the end of the list, unless the given element is NULL, 
     * then it will not be added. The size is incremented by 1. If resizing the array is necessary, 
     * then that should be done.
     * @arg to_add Object to be added to the array. 
     **/
    void add(Object* to_add);

    /**
     * Adds the provided array to the end of the list, unless the given array is NULL, 
     * then it will not be added. 
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array. If resizing the array is necessary, then that should be done.
     * @arg to_add Array of String that all need to be added to this array. 
     **/
     void addAll(StringArray* to_add);

    /**
     * Adds the provided String at the given index, unless the given object is NULL, 
     * then it will not be added. Otherwise, all elements previously at the index and
     * to the right will be shifted accordingly. 
     * If the index is invalid, then nothing will be added/shifted. 
     * The size of this array is incremented by 1. 
     * If resizing the array is necessary, then that should be done.
     * If the object provided is not a String, then do nothing.  
     * @arg to_add Object to be added to the array
     * @arg index Location to add the Object at
     **/
     void add(Object* to_add, size_t index);

    /**
     * Adds all the elements of the provided array at the given index, 
     * unless the given array is NULL, then it will not be added. Otherwise, 
     * all elements previously at the index and
     * to the right will be shifted accordingly by the size of the procided array, 
     * If the index is invalid, then nothing will be added/shifted.
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array.  If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects to be added to the array
     * @arg index Location to add the objects to the array at
     **/
     void addAll(StringArray* to_add, size_t index);

    /**
     * Returns the subarray starting from the provided index to the end of the array. 
     * If the index is invalid, then the method returns NULL
     * @arg index Starting place for the subarray
     **/
     StringArray* subArray(size_t index);

    /**
     * Returns the subarray starting from the provided index to the ending index
     * The starting index must always be greater than the ending index. If either index is invalid, 
     * then NULL is returned. The set is [start, end)
     * @arg startIndex starting place for the subarray
     * @arg endIndex location of the last object to be put in the subarray
     **/
     StringArray* subArray(size_t startIndex, size_t endIndex);

    /**
     * Removes the first instance of the given Object in this array. If nothing 
     * is found, then no action will occur. The size reduces by 1 if the 
     * element is found.
     * If the object to be removed is not a string, do nothing. 
     * @arg to_remove String to be removed from the array
     **/
     void remove(Object* to_remove);

    /**
     * Removes all instances of the given Object in this array. If nothing 
     * is found, then no action will occur. The size reduces the number of found
     * elements there are.
     * If the object to remove is not a string, do nothing. 
     * @arg to_remove String that all instances in the array will be removed of
     **/
     void removeAll(Object* to_remove);

    /**
     * Returns number of elements in the array. 
     **/
     size_t getSize();

    /**
     * Overriding the String equals method. 
     * Returns if all the elements in this array and the given object are equal and 
     * in the same other. 
     * If the given object is NULL or not an array, then false will be returned.
     * @arg other Object to check if this array is equal to
     **/
    bool equals(Object* other);

    /**
     * Overriding the Object hash_me() method. 
     * Hashes the array based on user specifications. Default implementation is
     * to hash all internal elements and sum them up. 
     **/
    size_t hash_me_();

};


class IntArray : public Array {
    public:
     /**
     * Default constructor which will set the initial max-capacity to the array to 10. 
     **/
    IntArray();

    /**
     * Initalized this array with the characteristics of the passed in array.
     * @arg arr Array containing values to be used in initialization. 
     **/
    IntArray(IntArray* arr);

    /**
     * Destructor which will free the memory of the underlying array as well. 
     **/
    ~IntArray();

    /**
     * Will return the int pointer at the provided index. if the index is invalid, 
     * then the method will return NULL.
     * @arg index Location to get the value in the array at. 
     **/
    int get(size_t index);


    /**
     * Clears the array and reinitializes the underlying array to 10 spots with no elements. 
     * Reinitializes the size to 0. 
     **/
    void clear();

    /**
     * Resizing the underlying array. And then copying over the elements to a new array with
     * the updated size. 
     * Default is doubling the array size when the max capacity of the 
     * underlying array less the number of elements is 2. 
     **/
    void resize();

    /**
     * Returns the first index of the of given Object pointer. 
     * If the object pointer is not found then -1 is returned.
     * @arg to_find Object to find the index of. 
     **/
    int indexOf(int to_find);

    /**
     * Adds the element provided to the end of the list.
     *  The size is incremented by 1. If resizing the array is necessary, 
     * then that should be done.
     * @arg to_add int to be added to the array. 
     **/
    void add(int to_add);

    /**
     * Adds the provided array to the end of the list, unless the given array is NULL, 
     * then it will not be added. 
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array. If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects that all need to be added to this array. 
     **/
    virtual void addAll(IntArray* to_add);

    /**
     * Adds the provided int at the given index. All elements previously at the index and
     * to the right will be shifted accordingly. 
     * If the index is invalid, then nothing will be added/shifted. 
     * The size of this array is incremented by 1. 
     * If resizing the array is necessary, then that should be done. 
     * @arg to_add Object to be added to the array
     * @arg index Location to add the Object at
     **/
    virtual void add(int to_add, size_t index);

    /**
     * Adds all the elements of the provided array at the given index, 
     * unless the given array is NULL, then it will not be added. Otherwise, 
     * all elements previously at the index and
     * to the right will be shifted accordingly by the size of the procided array, 
     * If the index is invalid, then nothing will be added/shifted.
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array.  If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects to be added to the array
     * @arg index Location to add the objects to the array at
     **/
    virtual void addAll(IntArray* to_add, size_t index);

    /**
     * Returns the subarray starting from the provided index to the end of the array. 
     * If the index is invalid, then the method returns NULL
     * @arg index Starting place for the subarray
     **/
    virtual IntArray* subArray(size_t index);

    /**
     * Returns the subarray starting from the provided index to the ending index
     * The starting index must always be greater than the ending index. If either index is invalid, 
     * then NULL is returned. The set is [start, end)
     * @arg startIndex starting place for the subarray
     * @arg endIndex location of the last object to be put in the subarray
     **/
    virtual IntArray* subArray(size_t startIndex, size_t endIndex);

    /**
     * Removes the first instance of the given int in this array. If nothing 
     * is found, then no action will occur. The size reduces by 1 if the 
     * element is found.
     * @arg to_remove int to be removed from the array
     **/
     void remove(int to_remove);

    /**
     * Removes all instances of the given int in this array. If nothing 
     * is found, then no action will occur. The size reduces the number of found
     * elements there are.
     * @arg to_remove int that all instances in the array will be removed of
     **/
     void removeAll(int to_remove);

    /**
     * Returns number of elements in the array. 
     **/
    virtual size_t getSize();

    /**
     * Overriding the Object equals method. 
     * Returns if all the elements in this array and the given object are equal and 
     * in the same other. 
     * If the given object is NULL or not an array, then false will be returned.
     * @arg other Object to check if this array is equal to
     **/
    bool equals(Object* other);

    /**
     * Overriding the Object hash_me() method. 
     * Hashes the array based on user specifications. Default implementation is
     * to hash all internal elements and sum them up. 
     **/
    size_t hash_me_();
};



class FloatArray : public Array {
    public:
     /**
     * Default constructor which will set the initial max-capacity to the array to 10. 
     **/
    FloatArray();

    /**
     * Initalized this array with the characteristics of the passed in array.
     * @arg arr Array containing values to be used in initialization. 
     **/
    FloatArray(FloatArray* arr);

    /**
     * Destructor which will free the memory of the underlying array as well. 
     **/
    ~FloatArray();

    /**
     * Will return the float pointer at the provided index. if the index is invalid, 
     * then the method will return -1
     * @arg index Location to get the value in the array at. 
     **/
    float get(size_t index);


    /**
     * Clears the array and reinitializes the underlying array to 10 spots with no elements. 
     * Reinitializes the size to 0. 
     **/
    void clear();

    /**
     * Resizing the underlying array. And then copying over the elements to a new array with
     * the updated size. 
     * Default is doubling the array size when the max capacity of the 
     * underlying array less the number of elements is 2. 
     **/
    void resize();

    /**
     * Returns the first index of the of given float pointer. 
     * If the object pointer is not found then -1 is returned.
     * @arg to_find Object to find the index of. 
     **/
    int indexOf(float to_find);

    /**
     * Adds the element provided to the end of the list.
     *  The size is incremented by 1. If resizing the array is necessary, 
     * then that should be done.
     * @arg to_add int to be added to the array. 
     **/
    void add(float to_add);

    /**
     * Adds the provided array to the end of the list, unless the given array is NULL, 
     * then it will not be added. 
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array. If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects that all need to be added to this array. 
     **/
    void addAll(FloatArray* to_add);

    /**
     * Adds the provided float at the given index. All elements previously at the index and
     * to the right will be shifted accordingly. 
     * If the index is invalid, then nothing will be added/shifted. 
     * The size of this array is incremented by 1. 
     * If resizing the array is necessary, then that should be done. 
     * @arg to_add Object to be added to the array
     * @arg index Location to add the Object at
     **/
    void add(float to_add, size_t index);

    /**
     * Adds all the elements of the provided array at the given index, 
     * unless the given array is NULL, then it will not be added. Otherwise, 
     * all elements previously at the index and
     * to the right will be shifted accordingly by the size of the procided array, 
     * If the index is invalid, then nothing will be added/shifted.
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array.  If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects to be added to the array
     * @arg index Location to add the objects to the array at
     **/
    void addAll(FloatArray* to_add, size_t index);

    /**
     * Returns the subarray starting from the provided index to the end of the array. 
     * If the index is invalid, then the method returns NULL
     * @arg index Starting place for the subarray
     **/
     FloatArray* subArray(size_t index);

    /**
     * Returns the subarray starting from the provided index to the ending index
     * The starting index must always be greater than the ending index. If either index is invalid, 
     * then NULL is returned. The set is [start, end)
     * @arg startIndex starting place for the subarray
     * @arg endIndex location of the last object to be put in the subarray
     **/
    FloatArray* subArray(size_t startIndex, size_t endIndex);

    /**
     * Removes the first instance of the given float in this array. If nothing 
     * is found, then no action will occur. The size reduces by 1 if the 
     * element is found.
     * @arg to_remove float to be removed from the array
     **/
     void remove(float to_remove);

    /**
     * Removes all instances of the given float in this array. If nothing 
     * is found, then no action will occur. The size reduces the number of found
     * elements there are.
     * @arg to_remove int that all instances in the array will be removed of
     **/
     void removeAll(float to_remove);

    /**
     * Returns number of elements in the array. 
     **/
    virtual size_t getSize();

    /**
     * Overriding the Object equals method. 
     * Returns if all the elements in this array and the given object are equal and 
     * in the same other. 
     * If the given object is NULL or not an array, then false will be returned.
     * @arg other Object to check if this array is equal to
     **/
    bool equals(Object* other);

    /**
     * Overriding the Object hash_me() method. 
     * Hashes the array based on user specifications. Default implementation is
     * to hash all internal elements and sum them up. 
     **/
    size_t hash_me_();
};


class BoolArray : public Array {
    public:
     /**
     * Default constructor which will set the initial max-capacity to the array to 10. 
     **/
    BoolArray();

    /**
     * Initalized this array with the characteristics of the passed in array.
     * @arg arr Array containing values to be used in initialization. 
     **/
    BoolArray(BoolArray* arr);

    /**
     * Destructor which will free the memory of the underlying array as well. 
     **/
    ~BoolArray();

    /**
     * Will return the bool at the provided index. if the index is invalid, 
     * then the method will return -1
     * @arg index Location to get the value in the array at. 
     **/
    bool get(size_t index);


    /**
     * Clears the array and reinitializes the underlying array to 10 spots with no elements. 
     * Reinitializes the size to 0. 
     **/
    void clear();

    /**
     * Resizing the underlying array. And then copying over the elements to a new array with
     * the updated size. 
     * Default is doubling the array size when the max capacity of the 
     * underlying array less the number of elements is 2. 
     **/
    void resize();

    /**
     * Returns the first index of the of given bool. 
     * If the object pointer is not found then -1 is returned.
     * @arg to_find Object to find the index of. 
     **/
    int indexOf(bool to_find);

    /**
     * Adds the element provided to the end of the list.
     *  The size is incremented by 1. If resizing the array is necessary, 
     * then that should be done.
     * @arg to_add int to be added to the array. 
     **/
    void add(bool to_add);

    /**
     * Adds the provided array to the end of the list, unless the given array is NULL, 
     * then it will not be added. 
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array. If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects that all need to be added to this array. 
     **/
    void addAll(BoolArray* to_add);

    /**
     * Adds the provided bool at the given index. All elements previously at the index and
     * to the right will be shifted accordingly. 
     * If the index is invalid, then nothing will be added/shifted. 
     * The size of this array is incremented by 1. 
     * If resizing the array is necessary, then that should be done. 
     * @arg to_add Object to be added to the array
     * @arg index Location to add the Object at
     **/
    void add(bool to_add, size_t index);

    /**
     * Adds all the elements of the provided array at the given index, 
     * unless the given array is NULL, then it will not be added. Otherwise, 
     * all elements previously at the index and
     * to the right will be shifted accordingly by the size of the procided array, 
     * If the index is invalid, then nothing will be added/shifted.
     * Assuming a valid move, the size of this array is incremented by the size of the 
     * added array.  If resizing the array is necessary, then that should be done.
     * @arg to_add Array of Objects to be added to the array
     * @arg index Location to add the objects to the array at
     **/
    void addAll(BoolArray* to_add, size_t index);

    /**
     * Returns the subarray starting from the provided index to the end of the array. 
     * If the index is invalid, then the method returns NULL
     * @arg index Starting place for the subarray
     **/
     BoolArray* subArray(size_t index);

    /**
     * Returns the subarray starting from the provided index to the ending index
     * The starting index must always be greater than the ending index. If either index is invalid, 
     * then NULL is returned. The set is [start, end)
     * @arg startIndex starting place for the subarray
     * @arg endIndex location of the last object to be put in the subarray
     **/
    BoolArray* subArray(size_t startIndex, size_t endIndex);

    /**
     * Removes the first instance of the given bool in this array. If nothing 
     * is found, then no action will occur. The size reduces by 1 if the 
     * element is found.
     * @arg to_remove float to be removed from the array
     **/
     void remove(bool to_remove);

    /**
     * Removes all instances of the given bool in this array. If nothing 
     * is found, then no action will occur. The size reduces the number of found
     * elements there are.
     * @arg to_remove int that all instances in the array will be removed of
     **/
     void removeAll(bool to_remove);

    /**
     * Returns number of elements in the array. 
     **/
    virtual size_t getSize();

    /**
     * Overriding the Object equals method. 
     * Returns if all the elements in this array and the given object are equal and 
     * in the same other. 
     * If the given object is NULL or not an array, then false will be returned.
     * @arg other Object to check if this array is equal to
     **/
    bool equals(Object* other);

    /**
     * Overriding the Object hash_me() method. 
     * Hashes the array based on user specifications. Default implementation is
     * to hash all internal elements and sum them up. 
     **/
    size_t hash_me_();
};

