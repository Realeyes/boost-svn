//-----------------------------------------------------------------------------
// boost mpl/list/node.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-01
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_LIST_NODE_HPP
#define BOOST_MPL_LIST_NODE_HPP

#include "boost/config.hpp"

namespace boost {
namespace mpl {

template< typename T
        , typename NextNode
        , typename SequenceCategory
        , typename TraitsType
        >
struct list_node
{
    typedef SequenceCategory    sequence_category;
    typedef TraitsType          traits_type;
    typedef T                   value_type;
    typedef NextNode            next_node;

    BOOST_STATIC_CONSTANT(bool, is_null = false);
};


template< typename SequenceCategory
        , typename TraitsType
        >
struct null_node
{
    typedef SequenceCategory    sequence_category;
    typedef TraitsType          traits_type;

    BOOST_STATIC_CONSTANT(bool, is_null = true);
};


} // namespace mpl
} // namespace boost 

#endif // BOOST_MPL_LIST_NODE_HPP
