//
// Created by Andrew Betancourt on 5/29/24.
//

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "interval.h"
using namespace std;

using color = vec3;

inline double linear_to_gamma(double linear_component){
    return linear_component > 0 ? sqrt(linear_component) : 0;
}

void write_color(ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Apply a linear to gamma transformation for gamma 2
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif //COLOR_H
