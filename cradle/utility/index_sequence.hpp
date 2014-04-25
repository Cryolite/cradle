//  (C) Copyright Cryolite 2014. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CRADLE_UTILITY_INDEX_SEQUENCE_HPP_INCLUDE_GUARD)
#define CRADLE_UTILITY_INDEX_SEQUENCE_HPP_INCLUDE_GUARD

#include <cradle/utility/integer_sequence.hpp>
#include <cstddef>


namespace cradle{

template<std::size_t... Is>
using index_sequence = cradle::integer_sequence<std::size_t, Is...>;

template<std::size_t N>
using make_index_sequence = cradle::make_integer_sequence<std::size_t, N>;

}


#endif // !defined(CRADLE_UTILITY_INDEX_SEQUENCE_HPP_INCLUDE_GUARD)
