#include "gtest/gtest.h"

extern "C" {
    #include "structures/str/str.h"
}

TEST(Assert, ok) {
  ASSERT_EQ(1, 1);
}
