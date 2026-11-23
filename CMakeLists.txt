cmake_minimum_required(VERSION 4.4)
project(DefinitelyNotPlagiarized)

set(CMAKE_CXX_STANDARD 20)

add_executable(DefinitelyNotPlagiarized main.cpp
        Creature.h
        SubCreature.h
        MoveSet.h
        Battle.h
        BattleState.h
        BattleInterface.h
)
