cmake_minimum_required(VERSION 3.26)
project(airport_graphs_simulator C)

set(CMAKE_C_STANDARD 11)

add_executable(airport_graphs_simulator
        main.c
        entities/airports/airports.c
        entities/airports/airports.h
        files/readFile.c
        files/readFile.h
        structures/vertex/vertex.c
        structures/vertex/vertex.h
        entities/routes/routes.c
        entities/routes/routes.h
        entities/flights/flights.c
        entities/flights/flights.h)
