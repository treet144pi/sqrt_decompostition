cmake_minimum_required(VERSION 3.10)
project(sqrt_decomposition C)

set(CMAKE_C_STANDARD 11)

add_executable(real_naive realization/simple.c)
add_executable(real_sqrt realization/sqrt_r.c)
target_link_libraries(real_sqrt m)

add_executable(bench_naive benchmarking/simple.c)
add_executable(bench_sqrt benchmarking/sqrt_bench.c)
target_link_libraries(bench_sqrt m)
