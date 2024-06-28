# Raytracing Image Generator

This is a simple raytracing image generator written in C++. It is based on the book "Ray Tracing in One Weekend" by Peter Shirley.

## Features
- Diffuse materials
- Renders metal and dielectric textures
- Depth of field
- Motion blur

## Usage

The default image that will render will take a significant amount of time to generate. You can choose to
generate a smaller image by changing `cam.image_width` and
`cam.aspect_ratio` in the `main.cpp` file.

For example:
```cpp
cam.image_width = 1280;
cam.aspect_ratio = 16.0 / 9.0;
```
To compile the program, run the following command:
```bash
g++ main.cpp -std=c++17 -o raytracer
```

To generate an image, run the following command:
```bash
./raytracer > image.ppm
```

To view the image, you can use an image viewer like `feh`:
```bash
feh image.ppm
```


## Example

![final](https://github.com/andb00/raytracing/assets/135753876/927e0197-5676-4e68-9ef0-a4bafb9b6e35)
