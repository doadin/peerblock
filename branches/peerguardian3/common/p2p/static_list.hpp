/*
	Copyright (C) 2007 Cory Nelson

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
	2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3. This notice may not be removed or altered from any source distribution.
*/

#pragma once

#include "ip.hpp"
#include "range.hpp"
#include "list.hpp"
#include "string_pool.hpp"
#include "basic_static_list.hpp"
#include "../platform.hpp"

namespace p2p {

/*
	static_list wraps two basic_static_lists, one for IPv4 and one for IPv6.
	static_list stores IP ranges with a label in a compact fashion made for
	minimal memory and CPU usage.  a string_pool is used to pool labels.
*/
class static_list {
public:
	COMMON_EXPORT static_list();
	COMMON_EXPORT static_list(const list &list);
	COMMON_EXPORT ~static_list();

	COMMON_EXPORT const static_range4* operator()(const ip4 &ip) const;
	COMMON_EXPORT const static_range6* operator()(const ip6 &ip) const;

	COMMON_EXPORT const static_range4* operator()(const compact_range4 &r) const;
	COMMON_EXPORT const static_range6* operator()(const compact_range6 &r) const;

	COMMON_EXPORT void swap(static_list &list);

//private:
	static_list4 m_list4;
	static_list6 m_list6;

private:
	string_pool m_pool;
};

}