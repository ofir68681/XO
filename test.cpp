#include "catch.hpp"
#include "Board.h"
#include
<
std::string BoardToString(const Board & b)
{
std::stringstream ss;
ss <b ;
return ss.str();
}
<
TEST_CASE("constraction","ctor")
{
Board board1{4}; //4x4 board
std::string emptyBoard = "....\n....\n....\n....\n" ;//representation of empty 4x4 board
SECTION("Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n Please use endline (\\n) at the end of the last line \n ")
{
CHECK(BoardToString(board1) == emptyBoard);
}
Board board2{4}; //4x4 board same as board1
<
CHECK(BoardToString(board1) == BoardToString(board2));
<
}
TEST_CASE("operator[]1", "[]")
{
Board board1{6}; //6X6 board
board1[{5,5}] = 'X';
std::string expectedBoard1 = "......\n......\n......\n......\n......\n.....X\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard1);
board1[{5, 5}] = 'O';
std::string expectedBoard2 = "......\n......\n......\n......\n......\n.....O\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard2);
board1[{0, 0}] = 'O';
std::string expectedBoard3 = "O.....\n......\n......\n......\n......\n.....O\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard3);
board1[{0, 0}] = '.';
std::string expectedBoard4 = "......\n......\n......\n......\n......\n.....O\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard4);
}
TEST_CASE("operator[]2", "[]")
{
Board board1{6}; //6X6 board
board1[{5, 5}] = 'X';
std::string expectedBoard1 = "......\n......\n......\n......\n......\n.....X\n"; //representation of empty 4x4 board
CHECK(board1[{5 , 5}] == 'X');
<
}
<
/* void assign (Board& b ,)
{
<
} */
<
TEST_CASE("operator[]3", "illegal char")
{
Board board1{6};
CHECK_THROWS([&]() {
board1[{5,5}]='1';
}());
CHECK_THROWS([&]() {
board1[{5, 5}] = '0';
}());
CHECK_THROWS([&]() {
board1[{5, 5}] = 'x';
}());
CHECK_THROWS([&]() {
board1[{5, 5}] = 'o';
}());
<
std::string expectedBoard1 = "......\n......\n......\n......\n......\n......\n"; //representation of empty 6X6 board
CHECK(BoardToString(board1) == expectedBoard1);
// wrong exeption
bool currectexeption = false;
try {
board1[{5, 5}] = '1';
}
//catch (const IllegalCharException &ex)
//{
// currectexeption = true;
//}
catch (...)
{
//currectexeption = false;
}
//CHECK(currectexeption);
}
<
<
TEST_CASE("operator[]4", "illegal Coordinate")
{
Board board1{6}; //6x6 board
CHECK_THROWS([&]() {
board1[{5, 10}] = 'X';
}());
CHECK_THROWS([&]() {
board1[{15, 5}] = 'O';
}());
<
std::string expectedBoard1 = "......\n......\n......\n......\n......\n......\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard1);
<
bool currectexeption = false ;
// wrong exeption
try
{
board1[{ 5, 10}] = 'X';
}
//catch (const IllegalCoordinateException &ex)
//{
// currectexeption = true;
//}
catch (...)
{
// currectexeption = false;
}
//CHECK(currectexeption);
}
<
TEST_CASE("operator[]5", "illegal char and Coordinate")
{
Board board1{6}; //6x6 board
CHECK_THROWS([&]() {
board1[{5, 10}] = 'M';
}());
CHECK_THROWS([&]() {
board1[{5, 5}] = 'I';
}());
std::string expectedBoard1 = "......\n......\n......\n......\n......\n......\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard1);
}
<
TEST_CASE("operator=", "=")
{
Board board1{6}; //6x6 board
board1[{5, 5}] = 'X';
std::string expectedBoard = "......\n......\n......\n......\n......\n.....X\n"; //representation of empty 4x4 board
CHECK(BoardToString(board1) == expectedBoard);
<
Board board2 = board1;
CHECK(BoardToString(board2) == expectedBoard);
<
Board board3{6}; //6x6 board
board3 = board1 ;
CHECK(BoardToString(board3) == expectedBoard);
<
Board board4{3}; //3x3 board
board4 = board1;
CHECK(BoardToString(board4) == expectedBoard);
<
// TODO: add a vilgrind test for memory leak
<
//make sure that board1 is not changed ( no shallow copy allowed )
board2[{0, 0}] = 'O';
CHECK(BoardToString(board1) == expectedBoard);
board3[{1, 1}] = 'O';
CHECK(BoardToString(board1) == expectedBoard);
board4[{2, 2}] = 'O';
CHECK(BoardToString(board1) == expectedBoard);
}
<
TEST_CASE("copy ctor", "copy ctor ")
{
Board board1{6}; //6x6 board
board1[{5, 5}] = 'X';
<
Board board2 (board1);
<
std::string expectedBoard = "......\n......\n......\n......\n......\n.....X\n"; //representation of empty 4x4 board
CHECK(BoardToString(board2) == expectedBoard);
<
//make sure that only board4 is changed ( no shallow copy allowed )
board2[{0, 0}] = 'O';
CHECK(BoardToString(board1) == expectedBoard);
}