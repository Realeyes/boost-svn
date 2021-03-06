//  (C) Copyright Gennadiy Rozental 2011-2012.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : defines monomorphic dataset based on stl sequence
// ***************************************************************************

#ifndef BOOST_TEST_DATA_MONOMORPHIC_COLLECTION_HPP_102211GER
#define BOOST_TEST_DATA_MONOMORPHIC_COLLECTION_HPP_102211GER

// Boost.Test
#include <boost/test/data/config.hpp>
#include <boost/test/data/monomorphic/dataset.hpp>

#include <boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace boost {
namespace unit_test {
namespace data {
namespace monomorphic {

// ************************************************************************** //
// **************                  collection                  ************** //
// ************************************************************************** //

template<typename C>
class collection : public monomorphic::dataset<typename std::decay<C>::type::value_type> {
    typedef typename std::decay<C>::type col_type;
    typedef typename col_type::value_type T;
    typedef monomorphic::dataset<T> base;

    struct iterator : public base::iterator {
        // Constructor
        explicit    iterator( collection<C> const& owner )
        : m_iter( owner.col().begin() )
        , m_singleton( owner.col().size() == 1 )
        {}

        // forward iterator interface 
        virtual T const&    operator*()     { return *m_iter; }
        virtual void        operator++()    { if( !m_singleton ) ++m_iter; }

    private:
        // Data members
        typename col_type::const_iterator m_iter;
        bool            m_singleton;
    };

public:
    enum { arity = 1 };

    // Constructor
    explicit        collection( C&& col ) : m_col( std::forward<C>(col) ) {}

    // Move constructor
    collection( collection&& c ) : m_col( std::forward<C>( c.m_col ) ) {}

    // Access methods
    C const&        col() const                     { return m_col; }

    // dataset interface
    virtual data::size_t    size() const            { return m_col.size(); } 
    virtual iter_ptr        begin() const           { return std::make_shared<iterator>( *this ); }

private:
    // Data members
    C               m_col;
};

//____________________________________________________________________________//

template<typename C>
struct is_dataset<collection<C>> : std::true_type {};

} // namespace monomorphic

template<typename C>
inline monomorphic::collection<typename std::enable_if<ds_detail::is_std_collection<C>::value,C>::type>
make( C&& c )
{
    return monomorphic::collection<C>( std::forward<C>(c) );
}

//____________________________________________________________________________//

} // namespace data
} // namespace unit_test
} // namespace boost

#include <boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_DATA_MONOMORPHIC_COLLECTION_HPP_102211GER

