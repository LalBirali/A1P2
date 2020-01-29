// lang::Cwc
#pragma once
#include <stdlib.h>
#include "Object.h"
#include <string.h>

/**
 * This represnts a String Class, which extends from the Object Class. 
 * It's internal representation is a char* for it's value. 
 * It is essentially an immutable class. 
 * 
 **/
class String : public Object {
public:

    /**
     * Default constructor.  
     **/
	String();

    /**
     * Constructor to initalize the value that this String object will hold.  
     **/
	String(const char* c);

    /**
     * Override of Object's hash(). 
     **/
	size_t hash(); 

    /**
     * Comparing String equality. 
     **/
	bool equals(Object* other);

    /**
     * Destructor for the String class. frees up memory from the char*.  
     **/
	~String();

    /**
     * Returns length of the char*.  
     **/
	size_t size();

    /**
     * Concats two Strings together. It does not mutate either String pointers, 
     * but instead it creates a new String* with add's val_ appended to the end
     * of this->val_..
     **/
	String* concat(String* add);

	/**
	 * Lexicographically comparing two Strings. 
	 * Returns -1 if this string appears before the given one
	 * Returns 0 if this string is equal to the other string
	 * Returns 1 if this string appears after the given string
	 **/
	int compare(String* other);

	
	// Exists for printing this String to console. 
	void print();


	/**
	 * @return a char* representation of this given String
	 **/
    char* to_string();
	
};