# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_VARIADIC_ELEM_HPP
# define BOOST_PREPROCESSOR_VARIADIC_ELEM_HPP
#
# include <boost/preprocessor/config/variadics.hpp>
#
#if BOOST_PP_VARIADICS
#
#include "detail/elem.hpp"
#
#define BOOST_PP_VARIADIC_ELEM(n,...) \
  BOOST_PP_VARIADIC_DETAIL_DATA_ELEM(n,__VA_ARGS__) \
/**/
#
#endif // BOOST_PP_VARIADICS
#endif // BOOST_PREPROCESSOR_VARIADIC_ELEM_HPP
