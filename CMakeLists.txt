cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp IClientHandler.h ISolver.h ICacheManager.h IServer_Side.h FileCacheManager.h MyTestClientHandler.cpp MyTestClientHandler.h FileCacheManager.cpp ISearchable.h State.h ISearcher.h CompareCost.h MyMatrixProblem.cpp MyMatrixProblem.h PriorityBasedSearcher.h)