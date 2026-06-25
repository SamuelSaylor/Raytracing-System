<table><tr>
<td><img src="./15projects_logo.svg" width="360"/></td>
<td><h1>Day 7/15 — Ray Tracing System</h1></td>
</tr></table>

This project is a raytracing system that puts out full on shapes on display in a .PPM file, written in C. Included inside are multiple different "phases" of development, and much of the concepts came from Peter Shirley's "Raytracing in One Weekend" book! While at its current stage its barebones, it can easily be expanded upon and might be something I touch up one day.

Pictured below is what the current product is. Rays of light interact with the spherical object to create the hue you see here.

<img width="256" height="144" alt="image" src="https://github.com/user-attachments/assets/2a0d77e3-1730-4ef6-abb6-a0b1fba27c5e" />

### Additionally a Vec3 C Library
Additionally I had to create a Vector 3 Library with many C-friendly features, as many native functionalities in C++ are not present in C. Here's a breakdown of every function below.

| Function | Definition | Example Usage |
|----------|------------|---------------|
| `Vec3 vec3_add(Vec3 a, Vec3 b)` | Adds two vectors component-wise. | `vec3_add((Vec3){1,2,3}, (Vec3){4,5,6}) → {5,7,9}` |
| `Vec3 vec3_sub(Vec3 a, Vec3 b)` | Subtracts vector `b` from vector `a` component-wise. | `vec3_sub((Vec3){5,7,9}, (Vec3){1,2,3}) → {4,5,6}` |
| `Vec3 vec3_scale(Vec3 a, double t)` | Multiplies a vector by scalar `t`, changing its magnitude. | `vec3_scale((Vec3){1,2,3}, 2) → {2,4,6}` |
| `double vec3_dot(Vec3 a, Vec3 b)` | Computes the **dot product** of two vectors. Measures alignment: positive = same direction, negative = opposite, zero = perpendicular. | `vec3_dot((Vec3){1,2,3}, (Vec3){4,5,6}) → 32` |
| `double vec3_length(Vec3 a)` | Returns the magnitude (length) of a vector using √(x²+y²+z²). | `vec3_length((Vec3){3,4,0}) → 5` |
| `Vec3 vec3_normalize(Vec3 a)` | Converts a vector into a **unit vector** (length = 1) while preserving direction. | `vec3_normalize((Vec3){3,0,0}) → {1,0,0}` |
| `Vec3 vec3_cross(Vec3 a, Vec3 b)` | Computes the **cross product**, producing a vector perpendicular to both inputs. | `vec3_cross((Vec3){1,0,0}, (Vec3){0,1,0}) → {0,0,1}` |
| `Vec3 vec3_negate(Vec3 a)` | Flips the direction of a vector by multiplying each component by `-1`. | `vec3_negate((Vec3){1,-2,3}) → {-1,2,-3}` |

### Credits
A massive thank you to Peter Shirley's C++ guide, "Ray Tracing in One Weekend", for being my guidance for this project! It reads well and the logic was easily applicable to C!
https://raytracing.github.io/books/RayTracingInOneWeekend.html
