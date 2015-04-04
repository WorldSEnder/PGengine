/*
 * Expected.hpp
 *
 *  Created on: 04.04.2015
 *      Author: Mareas
 */

#pragma once

/**
 * An expected describes an object that is the result of an operation
 * that may fail. It is a simple wrapper that can be used to make
 * an implementation exception-safe and/or transport exceptions over
 * time, thread and stack borders.
 *
 * The Expected is initialized with the expected value or an exception.
 * The value can later be retrieved using the get() function. In case
 * the Expected was initialized with an exception the stored exception
 * is thrown, else the expected value is returned.
 */
template<typename T>
class Expected {
public:
	Expected();
	virtual ~Expected();
};
