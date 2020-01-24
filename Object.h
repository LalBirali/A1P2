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
	size_t hash_;

	Object() { hash_ = 0; } 

	virtual ~Object() {}

	size_t hash() { 
		if (hash_ == 0)
			hash_ = hash_me_();
		return hash_;
	}

	virtual size_t hash_me_() { 
		return reinterpret_cast<size_t>(this);
	}

	virtual bool equals(Object* other) {
		return this == other;
	}

    virtual char* to_string() {return NULL;}
};