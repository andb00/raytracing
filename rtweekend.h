//
// Created by Andrew Betancourt on 6/10/24.
//

#ifndef RAYTRACING_RTWEEKEND_H
#define RAYTRACING_RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <iostream>
#include <cstdlib>


// C++ Std Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::fabs;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1)
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max)
    return min + (max-min)*random_double();
}

// Common Headers

#include "ray.h"
#include "vec3.h"
#include "color.h"
#include "interval.h"

#endif //RAYTRACING_RTWEEKEND_H
