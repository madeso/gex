#include "catch2/catch_all.hpp"
#include "gex/chip8.hh"

TEST_CASE("chip8")
{
	gex::Chip8 c;

	CHECK(c.calc() == 42);
}
