cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp IClientHandler.h ISolver.h ICacheManager.h IServer.h FileCacheManager.h MyTestClientHandler.cpp MyTestClientHandler.h FileCacheManager.cpp ISearchable.h State.h ISearcher.h CompareCost.h MyMatrixSearchable.cpp MyMatrixSearchable.h PriorityBasedSearcher.h StackBasedSearcher.h QueueBasedSearcher.h SearchableMatrixFactory.cpp SearchableMatrixFactory.h BestFirstSearcher.h AStarSearcher.h TCPServer.cpp TCPServer.h MyParallelServer.cpp MyParallelServer.h SearcherSolver.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")