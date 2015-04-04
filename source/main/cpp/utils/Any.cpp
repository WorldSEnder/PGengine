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
	  destructor(),
	  managed(nullptr)
{}

Any::Any(const Any& other)
	: storage_id(other.storage_id),
	  cloner(other.cloner),
	  destructor(other.destructor),
	  managed(other.clone())
{}

Any::Any(Any&& other)
	: storage_id(other.storage_id),
	  cloner(other.cloner),
	  destructor(other.destructor),
	  managed(other.managed)
{
	other.managed = nullptr;
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
	this->managed = other.clone();
	this->cloner = other.cloner;
	this->destructor = other.destructor;
	this->storage_id = other.storage_id;
	return *this;
}

Any& Any::operator=(Any&& other)
{
	if(this == &other)
		return *this;
	clear();
	this->managed = other.managed;
	other.managed = nullptr;
	this->cloner = other.cloner;
	this->destructor = other.destructor;
	this->storage_id = other.storage_id;
	return *this;
}

const ::std::type_info&
Any::typeinfo() const
{
	if(empty())
		return typeid(void);
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

void Any::clear()
{
	if(empty())
		return;
	destructor(managed);
}

}
