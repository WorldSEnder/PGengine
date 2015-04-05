/*
 * Any.h
 *
 *  Created on: 04.04.2015
 *      Author: Mareas
 */

#pragma once

#include <typeinfo>
#include <type_traits>

namespace util {
/**
 * Any is a typesafe but non-templated class that can be used as an element
 * in a collection.
 */
class Any {
	template<typename T>
	using Stored_t = typename ::std::decay<T>::type;

	typedef void* Ptr;
	typedef Ptr (*clone_op)(Ptr object);
    typedef void (*throw_op)(Ptr object);
	typedef void (*destructor_op)(Ptr object);

	/**
	 * Clones the object assuming its type is T.
	 */
	template<typename T>
	static Ptr clone_f(Ptr object);
	/**
	 * Throws an exception of type T*
	 */
    template<typename T>
    static void throw_f(Ptr object);
	/**
	 * Destructs the hold object.
	 */
	template<typename T>
	static void destruct_f(Ptr object);
public:
	/**
	 * Creates an empty Any that holds no value
	 */
	Any();
	/**
	 * Copy constructor
	 */
	Any(const Any& other);
	Any(Any&& other);
	/**
	 * Assignment operators, returns this. If this currently has a
	 * variable, the value is destructed.
	 *
	 * In the move-assignment, other doesn't hold a value after the
	 * assignment.
	 */
	Any& operator=(const Any& other);
	Any& operator=(Any&& other);
	/**
	 * Creates an any object. The object must be copy constructible.
	 * When calling this constructor the object is copy-constructed.
	 *
	 * Whenever the Any is copied, the copy constructor of the object
	 * is called. When the Any is deleted, the destructor is called.
	 *
	 * When the Any is move-copied, the object is simply handed over.
	 * //FIXME: probably call the move constructor in this case
	 */
	template<typename Stored>
	Any(Stored&& object);
	/**
	 * Clears the any and destructs the value it holds if any.
	 */
	template<typename Stored>
	Any& operator=(Stored&& object);
	/**
	 * Destructor
	 */
	virtual ~Any();
	/**
	 * Retrieves information about the stored type. If currently no object
	 * is stored typeid(void) is returned.
	 */
	const ::std::type_info& typeinfo() const;
	/**
	 * Returns true if this any holds a value, and false if it is empty
	 */
	bool empty() const;
	/**
	 * Retrieves a reference to the stored object. This operation is type-safe.
	 * When the object stored is not of the requested type, a std::bad_cast is
	 * thrown.
	 *
	 * Note: currently the object has to be retrieved
	 */
	template<typename T>
	Stored_t<T>& get();
	template<typename T>
	const Stored_t<T>& get() const;
    template<typename T>
    Stored_t<T>& poly_get();
    template<typename T>
    const Stored_t<T>& poly_get() const;
private:
	const ::std::type_info* storage_id;
	clone_op cloner;
	throw_op throwing;
	destructor_op destructor;

	Ptr managed;

	Ptr clone() const;
	void clear();
	Ptr release();
};

}

#include "utils/Any.tpp"
