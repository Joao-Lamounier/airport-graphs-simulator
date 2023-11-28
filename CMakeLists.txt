cmake_minimum_required(VERSION 3.22.1)
project(airport_graphs_simulator C)

set(CMAKE_C_STANDARD 11)

add_executable(airport_graphs_simulator
        main.c
        entities/airports/Airport.c
        entities/airports/Airport.h
        files/ReadFile.c
        files/ReadFile.h
        structures/vertex/Vertex.c
        structures/vertex/Vertex.h
        entities/routes/Route.c
        entities/routes/Route.h
        entities/flights/Flight.c
        entities/flights/Flight.h
        structures/graph_matrix/GraphMatrix.c
        structures/graph_matrix/GraphMatrix.h
        structures/edge/Edge.c
        structures/edge/Edge.h
        structures/graph_list/GraphList.c
        structures/graph_list/GraphList.h
        structures/array_list/ArrayList.c
        structures/array_list/ArrayList.h
        utils/utils.c
        utils/utils.h
        services/path_graph_matrix_service/PathGraphsMatrix.c
        services/path_graph_matrix_service/PathGraphsMatrix.h
        services/airports_service/AirportsServices.c
        services/airports_service/AirportsServices.h
        structures/queue/queue.c
        structures/queue/queue.h
        services/payh_graph_list_service/PathGraphList.c
        services/payh_graph_list_service/PathGraphList.h
        services/payh_graph_list_service/PathGraphList.c
        services/payh_graph_list_service/PathGraphList.c
        views/menu.c
        views/menu.h
        sounds/soundManipulator.c
        sounds/soundManipulator.h)

target_link_libraries(airport_graphs_simulator m)