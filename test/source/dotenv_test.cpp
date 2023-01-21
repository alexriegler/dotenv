#include "dotenv/dotenv.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Name is dotenv", "[library]")
{
  REQUIRE(name() == "dotenv");
}
