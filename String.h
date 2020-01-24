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

	char* val_;
	size_t size_;

    /**
     * Default constructor.  
     **/
	String() {
		val_ = new char[0];
		size_ = 0;
	}

    /**
     * Constructor to initalize the value that this String object will hold.  
     **/
	String(const char* c) {
		size_ = strlen(c);
		val_ = new char[size_];
		for (size_t i = 0; i < size_; i++) {
			val_[i] = c[i];
		}
	}

    /**
     * Override of Object's hash_me(). 
     **/
	size_t hash_me() {
		size_t res = 0;
		for (size_t i = 0; i < size_; i++) {
			res += val_[i];
		}
		return res;
	}

    /**
     * Comparing String equality. 
     **/
	bool equals(Object* other) {
		if (other == nullptr) return false;
		String* s = dynamic_cast<String*>(other);
		if (s == nullptr) return false;
		return strcmp(val_, s->val_) == 0;
	}

    /**
     * Destructor for the String class. frees up memory from the char*.  
     **/
	~String() {
		delete[] val_;
	}

    /**
     * Returns length of the char*.  
     **/
	size_t get_size() {
		return size_;
	}

    /**
     * Concats two Strings together. It does not mutate either String pointers, 
     * but instead it creates a new String* with add's val_ appended to the end
     * of this->val_..
     **/
	String* concat(String* add) {
		size_t desired = strlen(add->val_) + size_;
		char * new_val = new char[desired];
		for (size_t i = 0; i < size_; i++) {
			new_val[i] = val_[i];
		}
		size_t index = 0;
		for (size_t ii = size_; ii < desired; ii++) {
			new_val[ii] = add->val_[index];
			index++;
		}
		return new String(new_val);
	}
	
};