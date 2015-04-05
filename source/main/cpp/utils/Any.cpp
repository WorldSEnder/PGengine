/*
 * Any.cpp
 *
 *  Created on: 04.04.2015
 *      Author: Mareas
 */

#include "utils/Any.hpp"

namespace util {

Any::Any()
	: storage_id(&typeid(void)),
	  cloner(),
	  throwing(),
	  destructor(),
	  managed(nullptr)
{}

Any::Any(const Any& other)
	: storage_id(other.storage_id),
	  cloner(other.cloner),
	  throwing(other.throwing),
	  destructor(other.destructor),
	  managed(other.clone())
{}

Any::Any(Any&& other)
	: storage_id(other.storage_id),
	  cloner(other.cloner),
	  throwing(other.throwing),
	  destructor(other.destructor),
	  managed(other.managed)
{
    other.release();
}

Any::~Any()
{
	clear();
}

Any& Any::operator=(const Any& other)
{
	if(this == &other)
		return *this;
	clear();
	this->cloner = other.cloner;
	this->throwing = other.throwing;
	this->destructor = other.destructor;
	this->storage_id = other.storage_id;
    this->managed = other.clone();
	return *this;
}

Any& Any::operator=(Any&& other)
{
	if(this == &other)
		return *this;
	clear();
	this->cloner = other.cloner;
	this->throwing = other.throwing;
	this->destructor = other.destructor;
    this->storage_id = other.storage_id;
    this->managed = other.release();
	return *this;
}

const ::std::type_info&
Any::typeinfo() const
{
	return *storage_id;
}

bool Any::empty() const
{
	return managed == nullptr;
}

auto Any::clone() const
-> Ptr
{
	if(empty())
		return nullptr;
	return cloner(managed);
}

inline void Any::clear()
{
	if(empty())
		return;
	destructor(managed);
	release();
}

inline auto Any::release()
-> Ptr
{
    Ptr tmp = managed;
    managed = nullptr;
    storage_id = &typeid(void);
    return tmp;
}

}
