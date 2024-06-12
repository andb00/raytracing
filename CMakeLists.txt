cmake_minimum_required(VERSION 3.28)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracing main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        rtweekend.h
        interval.h
        camera.h)
