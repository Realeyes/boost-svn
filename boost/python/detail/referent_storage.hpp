// Copyright David Abrahams 2002. Permission to copy, use,
// modify, sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided
// "as is" without express or implied warranty, and with no claim as
// to its suitability for any purpose.
#ifndef REFERENT_STORAGE_DWA200278_HPP
# define REFERENT_STORAGE_DWA200278_HPP
# include <boost/mpl/select_type.hpp>
# include <boost/preprocessor/list/for_each_i.hpp>
# include <boost/preprocessor/tuple/to_list.hpp>
# include <boost/preprocessor/cat.hpp>
# include <cstddef>

namespace boost { namespace python { namespace detail {

struct alignment_dummy;
typedef void (*function_ptr)();
typedef int (alignment_dummy::*member_ptr);
typedef int (alignment_dummy::*member_function_ptr)();

# define BOOST_PYTHON_ALIGNER(T, n)                     \
        typename mpl::select_type<                      \
           sizeof(T) <= size, T, char>::type t##n

// Storage for size bytes, aligned to all fundamental types no larger than size
template <std::size_t size>
union aligned_storage
{
    BOOST_PYTHON_ALIGNER(char, 0);
    BOOST_PYTHON_ALIGNER(short, 1);
    BOOST_PYTHON_ALIGNER(int, 2);
    BOOST_PYTHON_ALIGNER(long, 3);
    BOOST_PYTHON_ALIGNER(float, 4);
    BOOST_PYTHON_ALIGNER(double, 5);
    BOOST_PYTHON_ALIGNER(long double, 6);
    BOOST_PYTHON_ALIGNER(void*, 7);
    BOOST_PYTHON_ALIGNER(function_ptr, 8);
    BOOST_PYTHON_ALIGNER(member_ptr, 9);
    BOOST_PYTHON_ALIGNER(member_function_ptr, 10);
    char bytes[size];
};

# undef BOOST_PYTHON_ALIGNER

// A metafunction returning a POD type which can store U, where T ==
// U&. If T is not a reference type, returns a POD which can store T.
template <class T>
struct referent_storage
{
    typedef aligned_storage<sizeof(T)> type;
};

}}} // namespace boost::python::detail

#endif // REFERENT_STORAGE_DWA200278_HPP
