//  (C) Copyright Gennadiy Rozental 2011.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : tests singleton dataset
// ***************************************************************************

// Boost.Test
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
namespace data=boost::unit_test::data;

#include "test_datasets.hpp"

//____________________________________________________________________________//

int samples1[] = {1,2,3};
int index1 = 0;

BOOST_DATA_TEST_CASE( test_case_interface_01, samples1 )
{   
    BOOST_CHECKA( sample == samples1[index1++] );
}

//____________________________________________________________________________//

char const* samples2[] = {"qwerty","asdfg"};
int index2 = 0;

BOOST_DATA_TEST_CASE( test_case_interface_02, samples2 )
{
    BOOST_CHECKA( sample == samples2[index2++] );
}

//____________________________________________________________________________//

int samples3[] = {7,9};
int index3 = 0;

BOOST_DATA_TEST_CASE( test_case_interface_03, data::make(samples1)+samples3 )
{
    if( index3 < 3 )
        BOOST_CHECKA( sample == samples1[index3] );
    else
        BOOST_CHECKA( sample == samples3[index3-3] );

    ++index3;
}

//____________________________________________________________________________//

int index4 = 0;

BOOST_DATA_TEST_CASE_N( 2, test_case_interface_04, data::make(samples2)^samples3 )
{
    BOOST_CHECKA( sample0 == samples2[index4] );
    BOOST_CHECKA( sample1 == samples3[index4] );

    ++index4;
}

//____________________________________________________________________________//

int index5 = 0;

BOOST_DATA_TEST_CASE_N( 2, test_case_interface_05, data::make(samples1) * samples2 )
{
    BOOST_CHECKA( sample0 == samples1[index5/2] );
    BOOST_CHECKA( sample1 == samples2[index5%2] );

    ++index5;
}

//____________________________________________________________________________//

int index6 = 0;

BOOST_DATA_TEST_CASE_N( 3, test_case_interface_06, data::make(samples1) * samples2 * samples3 )
{
    BOOST_CHECKA( sample0 == samples1[index6/4] );
    BOOST_CHECKA( sample1 == samples2[(index6/2)%2] );
    BOOST_CHECKA( sample2 == samples3[index6%2] );

    ++index6;
}

//____________________________________________________________________________//

// EOF
