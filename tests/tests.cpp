#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>

#include "string.hpp"

TEST_CASE("String, ConstructAssign")
{
  const char* data = "some string";

  String s0(data);
  s0[0] = 'S';
  String s1(s0);
  s1[5] = 'S';

  String s2;
  s2 = s1;
  s2[0] = 's';

  REQUIRE(String("Some string") == s0);
  REQUIRE(String("Some String") == s1);
  REQUIRE(String("some String") == s2);
  REQUIRE(String("some string") == String(data));
}



TEST_CASE("String, GetByIndex")
{
  const char* data = "some string";

  const String s1(data);

  REQUIRE('s' == s1[0]);
  REQUIRE('m' == s1[2]);
  REQUIRE('s' == s1[5]);

  String s(data);
  s[2] = 'M';
  s[5] = s[0] = 'S';

  REQUIRE('S' == s[0]);
  REQUIRE('M'== s[2]);
  REQUIRE('S'== s[5]);
}



TEST_CASE("String, Append")
{
  String s1("some");
  s1 = s1 + String(" ");
  s1 = s1 + String("string");

  String s2 = String("some ") + String("string");

  REQUIRE(s1 == s2);
}



TEST_CASE("String, Replace")
{
  String s1("some string");

  s1.replace('s', 'S');

  REQUIRE(String("Some String") == s1);
}



TEST_CASE("String, Size")
{
  String s1("some");

  REQUIRE(s1.size() == 4);
  REQUIRE(String{}.empty() == true);

  REQUIRE(s1.empty() == false);
}



TEST_CASE("String, Find")
{
  String s1("some string");

  REQUIRE(4 == s1.substr(String(" ")));
  REQUIRE(5 == s1.substr(String("str")));
  REQUIRE(0 == s1.substr(String("some")));

  REQUIRE(9 == String{"str stri string"}.substr(String{"string"}));
  REQUIRE(6 == String{"strinsstring"}.substr(String{"string"}));

  REQUIRE(static_cast<size_t>(-1) == s1.substr(String("not found")));
}



TEST_CASE("String, Stream")
{
  std::stringstream stream;
  String s1("some string");
  stream << s1 << " and " << String("stream");

  REQUIRE(String("some string and stream") == String(stream.str().c_str()));
}
