# 1. Geef de minimale CMake-versie op die vereist is
cmake_minimum_required(VERSION 3.15)

# 2. Definieer de naam van het project en de programmeertaal (bijv. CXX voor C++)
project(practice_assignments LANGUAGES CXX)

# 3. Geef aan welke executable er gebouwd moet worden en welke bronbestanden daarvoor nodig zijn
add_executable(Graph
        FriendGraph/main.cpp
)

add_executable(Library
        Library/Book.cpp
        Library/Library.cpp
        Library/main.cpp
        Library/Lender.cpp
        Library/Books.txt
)