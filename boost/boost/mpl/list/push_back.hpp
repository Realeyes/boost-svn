//----------------------------------------------------------------------------
// boost mpl/list/push_back.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//----------------------------------------------------------------------------
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

#ifndef BOOST_MPL_LIST_PUSH_BACK_HPP
#define BOOST_MPL_LIST_PUSH_BACK_HPP

#include "boost/mpl/push_back.hpp"
#include "boost/mpl/list/traits.hpp"

namespace boost {
namespace mpl {

namespace detail {

template<bool>
struct list_push_back_algorithm_part1
{
    template<typename List, typename T> struct part2
    {
        typedef typename mpl::list_traits_tag<List>::type       tag;
        typedef typename mpl::list_traits<tag>                  traits;
        typedef typename traits::template next_node<List>::type next_node;
        typedef typename traits::template make_node< 
                      typename traits::template value_type_<List>::type
                    , typename mpl::push_back<next_node, T>::sequence
                    >::type type;
    };
};

template<>
struct list_push_back_algorithm_part1<true>
{
    template<typename List, typename T> struct part2
    {
        typedef typename mpl::list_traits_tag<List>::type tag;
        typedef typename mpl::list_traits<tag>            traits;
        typedef typename traits::template make_node< 
                      T
                    , typename traits::null_node
                    >::type type;
    };
};

} // namespace detail


template<>
struct push_back_algorithm_traits<list_sequence_tag>
{
    template<typename List, typename T> struct algorithm
    {
        typedef typename mpl::list_traits_tag<List>::type tag_;
        typedef typename mpl::detail::list_push_back_algorithm_part1< 
                    ::boost::mpl::list_traits<tag_>::template is_null<List>::value
                    >::template part2<List, T>::type sequence;
    };
};


} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_LIST_PUSH_BACK_HPP
