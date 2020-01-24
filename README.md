This class represents an Array, more akin to a dynamic ArrayList type
versus a fixed-sized array, which may already be represented or built-in in CwC.
This interface offers the overall main functionalities:
    Addition of elements
    Addition of Arrays
    Removal of elements
    Indexing by Element
    Get Element by Index
    Equality
    Replacing elements at an Index
This class can be implemented using an underlying array structure that is dynamically resized. 
Note that the inital memory outlay is an array of pointers of size 10. We wish to reduce
the amount of resizing of the array, which would make several operations have O(n) time instead
of O(1) time. 
There are several STUB implementations in this API: In order to write a StringArray
you will need to extend Array and correctly override the virtual functions. 

Methods available:

    Object* get(size_t index)
    void clear()
    void resize()
    int indexOf(Object* to_find)
    void add(Object* to_add)
    void addAll(Array* to_add)
    void add(Object* to_add, size_t index)
    void addAll(Array* to_add, size_t index)
    Array* subArray(size_t index)
    Array* subArray(size_t startIndex, size_t endIndex)
    void remove(Object* to_remove)
    void removeAll(Object* to_remove)
    size_t getSize()
    bool equals(Object* other)
    size_t hash_me_()

Example of usage:

    Array* arr = new Array();
    StringArray* strarr = new Array();
    String* s1 = new String("Hello");
    String* s2 = new String("World");
    Object* a = new Object();
    Object* b = new Object();
    
    arr->add(a);
    arr->add(b);
    arr->remove(a);
    arr->remove(b);
    arr->add(b);
    arr->add(b);
    arr->removeAll(b);


