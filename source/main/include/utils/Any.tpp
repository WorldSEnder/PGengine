/*
 * Any.tpp
 *
 *  Created on: 04.04.2015
 *      Author: Mareas
 */

#pragma once

#include "utils/Any.hpp"

#include <utility>

namespace util {

template<typename S>
Any::Any(S&& object)
	: storage_id(&typeid(object)),
	  cloner(clone_f<Stored_t<S>>),
	  destructor(destruct_f<Stored_t<S>>),
	  managed(new Stored_t<S>{std::forward<S>(object)})
{}

template<typename S>
Any& Any::operator=(S&& object)
{
	clear();
	using _S = Stored_t<S>;
	storage_id = &typeid(object);
	cloner = clone_f<_S>;
	destructor = destruct_f<_S>;
	managed = new _S{std::forward<S>(object)};
	return *this;
}

template<typename T>
auto Any::clone_f(Ptr in)
	-> Ptr
{
	return new T{*static_cast<T*>(in)};
}
/**
 * Destructs the hold object.
 */
template<typename T>
void Any::destruct_f(Ptr in)
{
	delete static_cast<T*>(in);
}

template<typename T>
Any::Stored_t<T>& Any::get()
{
	auto ptr = dynamic_cast<Stored_t<T>*>(managed);
	if(ptr == nullptr)
		throw new ::std::bad_cast{};
	return *ptr;
}

template<typename T>
const Any::Stored_t<T>& Any::get() const
{
	auto ptr = dynamic_cast<Stored_t<T>*>(managed);
	if(ptr == nullptr)
		throw new ::std::bad_cast{};
	return *ptr;
}

}
