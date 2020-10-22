cmake_minimum_required(VERSION 3.13)
project(CardTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardTest
        PokerHand.hpp
        52Cards.hpp
        catch.hpp
        Player.hpp
        Dealer.hpp
        Card.cpp
        Game.cpp)