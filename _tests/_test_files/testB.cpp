#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//@TODO: include all files we are testing:
#include "../../includes/stub/stub.h"



//------------------------------------------------------------------------------

using namespace std;

bool test_stub(bool debug=false)
{
  if (debug) {
    cout << "testB::test_stub()" << endl;
  }
  return stub(); // returns true
}

//------------------------------------------------------------------------------
//@TODO: add more test functions here:



//------------------------------------------------------------------------------


// Lord help me! 
const bool debug = false;

TEST(TEST_STUB, TestStub)
{
  bool success = test_stub(debug);
  EXPECT_EQ(success, true);
}

//------------------------------------------------------------------------------
//@TODO: add more test cases to call test functions here:



//------------------------------------------------------------------------------
