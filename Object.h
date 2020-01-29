// lang::Cwc
#pragma once
#include <stdlib.h>

/**
 * This is a representation of a global object in the universe of all classes implemented in CwC. 
 * There are only a few key functionalities we see needing to be offered by this class:
 * Hashing: represented by hash()
 * Equality: represented by equals(Object)
 * ToString: represented by to_string()
 **/
class Object {
public:

	Object(); 

	virtual ~Object();

	/**
	 * Done for hashing this object. 
	 **/
	size_t hash();

	/**
	 * Is this object equal to the passed in argument. 
	 * @args the object for comparison
	 * @return whether or not this object is equivalent to the given one 
	 **/
	virtual bool equals(Object* other);

	/**
	 * @return a char* representation of this given object
	 **/
    virtual char* to_string();

	virtual void print(); //for printing a representation of this Object to the console.

};