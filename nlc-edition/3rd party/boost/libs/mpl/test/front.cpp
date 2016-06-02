//-----------------------------------------------------------------------------
// boost mpl/test/front.cpp source file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-02
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#include "boost/mpl/front.hpp"
#include "boost/mpl/list.hpp"
#include "boost/mpl/list_c.hpp"
#include "boost/mpl/assert_is_same.hpp"
#include "boost/static_assert.hpp"

namespace mpl = boost::mpl;

int main()
{
    typedef mpl::list<long>::type types1;
    typedef mpl::list<int,long>::type types2;
    typedef mpl::list<char,int,long>::type types3;

    BOOST_MPL_ASSERT_IS_SAME(mpl::front<types1>::type, long);
    BOOST_MPL_ASSERT_IS_SAME(mpl::front<types2>::type, int);
    BOOST_MPL_ASSERT_IS_SAME(mpl::front<types3>::type, char);

    typedef mpl::list_c<int,1>::type values1;
    typedef mpl::list_c<int,2,1>::type values2;
    typedef mpl::list_c<int,3,2,1>::type values3;

    BOOST_STATIC_ASSERT(mpl::front<values1>::type::value == 1);
    BOOST_STATIC_ASSERT(mpl::front<values2>::type::value == 2);
    BOOST_STATIC_ASSERT(mpl::front<values3>::type::value == 3);

    return 0;
}
