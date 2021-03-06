#pragma once

#include <iostream>
#include <math.h>

#undef near
#undef far

const float PI = 3.141592f;

/**
 * Convert degrees to radians.
 */
inline float radians(float degrees)
{
    return degrees / 180.0f * PI;
}

/**
 * Convert Radians to degrees.
 */
inline float degrees(float radians)
{
    return radians / PI * 180.0f;
}

enum class EnumDirection {
    POSITIVE_X,
    NEGATIVE_X,
    POSITIVE_Y,
    NEGATIVE_Y,
    POSITIVE_Z,
    NEGATIVE_Z
};

template <class T>
struct matrix4 {
    T m00, m01, m02, m03;
    T m10, m11, m12, m13;
    T m20, m21, m22, m23;
    T m30, m31, m32, m33;

    matrix4() {
        m00 = 1;
        m11 = 1;
        m22 = 1;
        m33 = 1;

        m01 = 0;
        m02 = 0;
        m03 = 0;
        m10 = 0;
        m12 = 0;
        m13 = 0;
        m20 = 0;
        m21 = 0;
        m23 = 0;
        m30 = 0;
        m31 = 0;
        m32 = 0;
    }
};

template <class T>
struct vector2;

template <class T>
struct vector3;

template <class T>
struct vector4;

template <class T>
struct vector2 {
    T x;
    T y;

    vector2() {
        this->x = 0;
        this->y = 0;
    }

    vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    vector2<T> operator-();
};

template <class T>
struct vector3 {
    T x;
    T y;
    T z;

    vector3(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vector3(vector4<T> v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }

    vector3() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    vector3(T i) {
        this->x = i;
        this->y = i;
        this->z = i;
    }

    vector3<T> operator-();
};

template <class T>
struct vector4 {
    T x;
    T y;
    T z;
    T w;

    vector4(T x, T y, T z, T w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    vector4(vector3<T> v, T w) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = w;
    }

    vector4() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    vector4<T> operator-();
};


//typedef's because nobody likes typing vector3<float>
typedef vector2<float> vec2;
typedef vector3<float> vec3;
typedef vector4<float> vec4;
typedef vector2<int> vec2i;
typedef vector3<int> vec3i;
typedef vector4<int> vec4i;
typedef matrix4<float> mat4;

//--------IO operator--------//

template <typename T>
inline std::ostream& operator<<(std::ostream &lhs, const vector2<T> &rhs) {
    lhs << "(" << rhs.x << ", " << rhs.y << ")";

    return lhs;
}

template <typename T>
inline std::ostream& operator<<(std::ostream &lhs, const vector3<T> &rhs) {
    lhs << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";

    return lhs;
}

template <typename T>
inline std::ostream& operator<<(std::ostream &lhs, const vector4<T> &rhs) {
    lhs << "(" << rhs.x << ", " << rhs.y << rhs.z << ", " << rhs.w << ")";

    return lhs;
}




//--------addition--------//

//vec2
template <typename T>
inline vector2<T> operator+(const vector2<T> &lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template <typename T>
inline vector2<T> operator+(const vector2<T> &lhs, T rhs) {
    return vector2<T>(lhs.x + rhs, lhs.y + rhs);
}

template <typename T>
inline vector2<T> operator+(T lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs + rhs.x, lhs + rhs.y);
}

//vec3
template <typename T>
inline vector3<T> operator+(const vector3<T> &lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename T>
inline vector3<T> operator+(const vector3<T> &lhs, T rhs) {
    return vector3<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

template <typename T>
inline vector3<T> operator+(T lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
}

//vec4
template <typename T>
inline vector4<T> operator+(const vector4<T> &lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

template <typename T>
inline vector4<T> operator+(const vector4<T> &lhs, T rhs) {
    return vector4<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
}

template <typename T>
inline vector4<T> operator+(T lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
}




//--------subtraction--------//

//vec2
template <typename T>
inline vector2<T> operator-(const vector2<T> &lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template <typename T>
inline vector2<T> operator-(const vector2<T> &lhs, T rhs) {
    return vector2<T>(lhs.x - rhs, lhs.y - rhs);
}

template <typename T>
inline vector2<T> operator-(T lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs - rhs.x, lhs - rhs.y);
}

//vec3
template <typename T>
inline vector3<T> operator-(const vector3<T> &lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <typename T>
inline vector3<T> operator-(const vector3<T> &lhs, T rhs) {
    return vector3<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

template <typename T>
inline vector3<T> operator-(T lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
}

//vec4
template <typename T>
inline vector4<T> operator-(const vector4<T> &lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

template <typename T>
inline vector4<T> operator-(const vector4<T> &lhs, T rhs) {
    return vector4<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
}

template <typename T>
inline vector4<T> operator-(T lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
}




//--------multiplication--------//

//vec2
template <typename T>
inline vector2<T> operator*(const vector2<T> &lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename T>
inline vector2<T> operator*(const vector2<T> &lhs, T rhs) {
    return vector2<T>(lhs.x * rhs, lhs.y * rhs);
}

template <typename T>
inline vector2<T> operator*(T lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs * rhs.x, lhs * rhs.y);
}

//vec3
template <typename T>
inline vector3<T> operator*(const vector3<T> &lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

template <typename T>
inline vector3<T> operator*(const vector3<T> &lhs, T rhs) {
    return vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

template <typename T>
inline vector3<T> operator*(T lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

//vec4
template <typename T>
inline vector4<T> operator*(const vector4<T> &lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

template <typename T>
inline vector4<T> operator*(const vector4<T> &lhs, T rhs) {
    return vector4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

template <typename T>
inline vector4<T> operator*(T lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}




//--------division--------//

//vec2
template <typename T>
inline vector2<T> operator/(const vector2<T> &lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
}

template <typename T>
inline vector2<T> operator/(const vector2<T> &lhs, T rhs) {
    return vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template <typename T>
inline vector2<T> operator/(T lhs, const vector2<T> &rhs) {
    return vector2<T>(lhs / rhs.x, lhs / rhs.y);
}

//vec3
template <typename T>
inline vector3<T> operator/(const vector3<T> &lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

template <typename T>
inline vector3<T> operator/(const vector3<T> &lhs, T rhs) {
    return vector3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template <typename T>
inline vector3<T> operator/(T lhs, const vector3<T> &rhs) {
    return vector3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
}

//vec4
template <typename T>
inline vector4<T> operator/(const vector4<T> &lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

template <typename T>
inline vector4<T> operator/(const vector4<T> &lhs, T rhs) {
    return vector4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

template <typename T>
inline vector4<T> operator/(T lhs, const vector4<T> &rhs) {
    return vector4<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w);
}



//--------equality---------//

template <typename T>
inline bool operator==(const vector2<T> &lhs, const vector2<T> &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
inline bool operator==(const vector3<T> &lhs, const vector3<T> &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

template <typename T>
inline bool operator==(const vector4<T> &lhs, const vector4<T> &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
}


//--------negate--------//

template <typename T>
inline vector2<T> vector2<T>::operator-()
{
    return vector2<T>(-x, -y);
}

template <typename T>
inline vector3<T> vector3<T>::operator-()
{
    return vector3<T>(-x, -y, -z);
}

template <typename T>
inline vector4<T> vector4<T>::operator-()
{
    return vector4<T>(-x, -y, -z, -w);
}



//-------mat4 operations--------//

template <typename T>
inline matrix4<T> operator*(const matrix4<T> &lhs, const matrix4<T> &rhs) {
    matrix4<T> result;

    result.m00 = lhs.m00 * rhs.m00 + lhs.m01 * rhs.m10 + lhs.m02 * rhs.m20 + lhs.m03 * rhs.m30;
    result.m10 = lhs.m10 * rhs.m00 + lhs.m11 * rhs.m10 + lhs.m12 * rhs.m20 + lhs.m13 * rhs.m30;
    result.m20 = lhs.m20 * rhs.m00 + lhs.m21 * rhs.m10 + lhs.m22 * rhs.m20 + lhs.m23 * rhs.m30;
    result.m30 = lhs.m30 * rhs.m00 + lhs.m31 * rhs.m10 + lhs.m32 * rhs.m20 + lhs.m33 * rhs.m30;

    result.m01 = lhs.m00 * rhs.m01 + lhs.m01 * rhs.m11 + lhs.m02 * rhs.m21 + lhs.m03 * rhs.m31;
    result.m11 = lhs.m10 * rhs.m01 + lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31;
    result.m21 = lhs.m20 * rhs.m01 + lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31;
    result.m31 = lhs.m30 * rhs.m01 + lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31;

    result.m02 = lhs.m00 * rhs.m02 + lhs.m01 * rhs.m12 + lhs.m02 * rhs.m22 + lhs.m03 * rhs.m32;
    result.m12 = lhs.m10 * rhs.m02 + lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32;
    result.m22 = lhs.m20 * rhs.m02 + lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32;
    result.m32 = lhs.m30 * rhs.m02 + lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32;

    result.m03 = lhs.m00 * rhs.m03 + lhs.m01 * rhs.m13 + lhs.m02 * rhs.m23 + lhs.m03 * rhs.m33;
    result.m13 = lhs.m10 * rhs.m03 + lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33;
    result.m23 = lhs.m20 * rhs.m03 + lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33;
    result.m33 = lhs.m30 * rhs.m03 + lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33;

    return result;
}

template <typename T>
inline vector4<T> operator*(const matrix4<T> &lhs, const vector4<T> &rhs) {
    float x = lhs.m00 * rhs.x + lhs.m01 * rhs.y + lhs.m02 * rhs.z + lhs.m03 * rhs.w;
    float y = lhs.m10 * rhs.x + lhs.m11 * rhs.y + lhs.m12 * rhs.z + lhs.m13 * rhs.w;
    float z = lhs.m20 * rhs.x + lhs.m21 * rhs.y + lhs.m22 * rhs.z + lhs.m23 * rhs.w;
    float w = lhs.m30 * rhs.x + lhs.m31 * rhs.y + lhs.m32 * rhs.z + lhs.m33 * rhs.w;
    return vec4(x, y, z, w);
}

template <typename T>
inline vector4<T> operator*(const vector4<T> &lhs, const matrix4<T> &rhs) {
    return rhs * lhs;
}








//--------operators--------//

template <typename T>
inline T lengthSquared(const vector3<T> &vec) {
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

template <typename T>
inline float length(const vector3<T> &vec) {
    return sqrt(lengthSquared(vec));
}

template <typename T>
inline vector3<T> normalize(const vector3<T> &vec) {
    return vec / length(vec);
}


template <typename T>
inline vector3<T> cross(const vector3<T> &lhs, const vector3<T> &rhs) {
    float x = lhs.y * rhs.z - lhs.z * rhs.y;
    float y = lhs.z * rhs.x - lhs.x * rhs.z;
    float z = lhs.x * rhs.y - lhs.y * rhs.x;
    return vec3(x, y, z);
}

template <typename T>
inline T dot(const vector3<T> &lhs, const vector3<T> &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

template <typename T>
inline matrix4<T> translate(const matrix4<T> &mat, const vector3<T> &vec) {
    matrix4<T> temp;

    temp.m03 = vec.x;
    temp.m13 = vec.y;
    temp.m23 = vec.z;

    return mat * temp;
}

template <typename T>
inline matrix4<T> rotate(const matrix4<T> &mat, const vector3<T>& axis, const T& angle) {
    matrix4<T> result;

    const float c = cos(radians(angle));
    const float s = sin(radians(angle));
    const float t = 1.0f - c;

    result.m00 = t*axis.x*axis.x + c;
    result.m10 = t*axis.x*axis.y + s*axis.z;
    result.m20 = t*axis.x*axis.z - s*axis.y;

    result.m01 = t*axis.x*axis.y - s*axis.z;
    result.m11 = t*axis.y*axis.y + c;
    result.m21 = t*axis.y*axis.z + s*axis.x;

    result.m02 = t*axis.x*axis.z + s*axis.y;
    result.m12 = t*axis.y*axis.z - s*axis.x;
    result.m22 = t*axis.z*axis.z + c;

    return mat * result;
}

template <typename T>
inline matrix4<T> scale(const matrix4<T> &mat, const vector3<T> &scale) {
    matrix4<T> scaling;

    scaling.m00 = scale.x;
    scaling.m11 = scale.y;
    scaling.m22 = scale.z;

    return mat * scaling;
}

template <typename T>
inline matrix4<T> scale(const matrix4<T> &mat, T scale) {
    matrix4<T> scaling;

    scaling.m00 = scale;
    scaling.m11 = scale;
    scaling.m22 = scale;

    return mat * scaling;
}

template <typename T>
inline matrix4<T> transpose(const matrix4<T> &mat) {
    matrix4<T> temp;

    temp.m00 = mat.m00;
    temp.m10 = mat.m01;
    temp.m20 = mat.m02;
    temp.m30 = mat.m03;

    temp.m01 = mat.m10;
    temp.m11 = mat.m11;
    temp.m21 = mat.m12;
    temp.m31 = mat.m13;

    temp.m02 = mat.m20;
    temp.m12 = mat.m21;
    temp.m22 = mat.m22;
    temp.m32 = mat.m23;

    temp.m03 = mat.m30;
    temp.m13 = mat.m31;
    temp.m23 = mat.m32;
    temp.m33 = mat.m33;

    return temp;
}

inline mat4 perspective(float fov, float aspect, float near, float far) {
    mat4 result;

    float top    =  near * tan(radians(fov) / 2.0);
    float bottom = -top;
    float right  =  top * aspect;
    float left   = -top * aspect;

    result.m00 = (2.0f*near) / (right - left);

    result.m11 = (2.0f*near) / (top - bottom);

    result.m22 = -(far + near) / (far - near);
    result.m32 = -1.0f;

    result.m23 = -(2.0f*near*far) / (far - near);
    result.m33 = 0.0f;


    return result;
}

inline mat4 orthographic(float left, float right, float bottom, float top, float near, float far) {
    mat4 ortho;

    float tx = -(right + left) / (right - left);
    float ty = -(top + bottom) / (top - bottom);
    float tz = -(far + near) / (far - near);

    ortho.m00 = 2.0f / (right - left);
    ortho.m11 = 2.0f / (top - bottom);
    ortho.m22 = -2.0f / (far - near);
    ortho.m03 = tx;
    ortho.m13 = ty;
    ortho.m23 = tz;

    return ortho;
}

inline mat4 LookAt(const vec3 &eye, const vec3 &center, const vec3 &up) {
    vec3 forward = vec3(0, 0, -1);
    vec3 upVec = vec3(0, 1, 0);
    vec3 side = vec3(1, 0, 0);

    forward.x = center.x - eye.x;
    forward.y = center.y - eye.y;
    forward.z = center.z - eye.z;

    upVec.x = up.x;
    upVec.y = up.y;
    upVec.z = up.z;
    forward = normalize(forward);

    /* Side = forward x up */
    side = cross(forward, upVec);
    side = normalize(side);

    /* Recompute up as: up = side x forward */
    upVec = cross(side, forward);

    mat4 mat;
    mat.m00 = side.x;
    mat.m01 = side.y;
    mat.m02 = side.z;

    mat.m10 = upVec.x;
    mat.m11 = upVec.y;
    mat.m12 = upVec.z;

    mat.m20 = -forward.x;
    mat.m21 = -forward.y;
    mat.m22 = -forward.z;

    return translate(mat, vec3(-eye.x, -eye.y, -eye.z));
}

inline float determinant3x3(float t00, float t01, float t02, float t10, float t11, float t12, float t20, float t21, float t22) {
    return   t00 * (t11 * t22 - t12 * t21) + t01 * (t12 * t20 - t10 * t22) + t02 * (t10 * t21 - t11 * t20);
}

inline float determinant(const mat4 &mat) {
    float f =
            mat.m00
            * ((mat.m11 * mat.m22 * mat.m33 + mat.m12 * mat.m23 * mat.m31 + mat.m13 * mat.m21 * mat.m32)
               - mat.m13 * mat.m22 * mat.m31
               - mat.m11 * mat.m23 * mat.m32
               - mat.m12 * mat.m21 * mat.m33);
    f -= mat.m01
         * ((mat.m10 * mat.m22 * mat.m33 + mat.m12 * mat.m23 * mat.m30 + mat.m13 * mat.m20 * mat.m32)
            - mat.m13 * mat.m22 * mat.m30
            - mat.m10 * mat.m23 * mat.m32
            - mat.m12 * mat.m20 * mat.m33);
    f += mat.m02
         * ((mat.m10 * mat.m21 * mat.m33 + mat.m11 * mat.m23 * mat.m30 + mat.m13 * mat.m20 * mat.m31)
            - mat.m13 * mat.m21 * mat.m30
            - mat.m10 * mat.m23 * mat.m31
            - mat.m11 * mat.m20 * mat.m33);
    f -= mat.m03
         * ((mat.m10 * mat.m21 * mat.m32 + mat.m11 * mat.m22 * mat.m30 + mat.m12 * mat.m20 * mat.m31)
            - mat.m12 * mat.m21 * mat.m30
            - mat.m10 * mat.m22 * mat.m31
            - mat.m11 * mat.m20 * mat.m32);
    return f;
}

inline mat4 inverse(const mat4 &src) {
    mat4 dest;

    float d = determinant(src);

    if (d != 0) {
        /*
         * m00 m01 m02 m03
         * m10 m11 m12 m13
         * m20 m21 m22 m23
         * m30 m31 m32 m33
         */
        float determinant_inv = 1.0f/d;

        // first row
        float t00 =  determinant3x3(src.m11, src.m12, src.m13, src.m21, src.m22, src.m23, src.m31, src.m32, src.m33);
        float t01 = -determinant3x3(src.m10, src.m12, src.m13, src.m20, src.m22, src.m23, src.m30, src.m32, src.m33);
        float t02 =  determinant3x3(src.m10, src.m11, src.m13, src.m20, src.m21, src.m23, src.m30, src.m31, src.m33);
        float t03 = -determinant3x3(src.m10, src.m11, src.m12, src.m20, src.m21, src.m22, src.m30, src.m31, src.m32);
        // second row
        float t10 = -determinant3x3(src.m01, src.m02, src.m03, src.m21, src.m22, src.m23, src.m31, src.m32, src.m33);
        float t11 =  determinant3x3(src.m00, src.m02, src.m03, src.m20, src.m22, src.m23, src.m30, src.m32, src.m33);
        float t12 = -determinant3x3(src.m00, src.m01, src.m03, src.m20, src.m21, src.m23, src.m30, src.m31, src.m33);
        float t13 =  determinant3x3(src.m00, src.m01, src.m02, src.m20, src.m21, src.m22, src.m30, src.m31, src.m32);
        // third row
        float t20 =  determinant3x3(src.m01, src.m02, src.m03, src.m11, src.m12, src.m13, src.m31, src.m32, src.m33);
        float t21 = -determinant3x3(src.m00, src.m02, src.m03, src.m10, src.m12, src.m13, src.m30, src.m32, src.m33);
        float t22 =  determinant3x3(src.m00, src.m01, src.m03, src.m10, src.m11, src.m13, src.m30, src.m31, src.m33);
        float t23 = -determinant3x3(src.m00, src.m01, src.m02, src.m10, src.m11, src.m12, src.m30, src.m31, src.m32);
        // fourth row
        float t30 = -determinant3x3(src.m01, src.m02, src.m03, src.m11, src.m12, src.m13, src.m21, src.m22, src.m23);
        float t31 =  determinant3x3(src.m00, src.m02, src.m03, src.m10, src.m12, src.m13, src.m20, src.m22, src.m23);
        float t32 = -determinant3x3(src.m00, src.m01, src.m03, src.m10, src.m11, src.m13, src.m20, src.m21, src.m23);
        float t33 =  determinant3x3(src.m00, src.m01, src.m02, src.m10, src.m11, src.m12, src.m20, src.m21, src.m22);

        // transpose and divide by the determinant
        dest.m00 = t00*determinant_inv;
        dest.m11 = t11*determinant_inv;
        dest.m22 = t22*determinant_inv;
        dest.m33 = t33*determinant_inv;
        dest.m01 = t10*determinant_inv;
        dest.m10 = t01*determinant_inv;
        dest.m20 = t02*determinant_inv;
        dest.m02 = t20*determinant_inv;
        dest.m12 = t21*determinant_inv;
        dest.m21 = t12*determinant_inv;
        dest.m03 = t30*determinant_inv;
        dest.m30 = t03*determinant_inv;
        dest.m13 = t31*determinant_inv;
        dest.m31 = t13*determinant_inv;
        dest.m32 = t23*determinant_inv;
        dest.m23 = t32*determinant_inv;
    }

    return dest;
}


//---------less than----------//

template <typename T>
inline bool operator<(const vector3<T> &lhs, const vector3<T> &rhs) {
    float l1 = length(lhs);
    float l2 = length(rhs);

    return l1 < l2;
}


//---------quaternions----------//

struct quaternion {
    float w;
    float x;
    float y;
    float z;

    quaternion() {
        w = 0;
        x = 0;
        y = 0;
        z = 0;
    }


    quaternion(float w, float x, float y, float z) {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    quaternion(vec3 axis, float radians) {
        const float halfAngle = 0.5f * radians;
        w = cos(halfAngle);
        x = axis.x * sin(halfAngle);
        y = axis.y * sin(halfAngle);
        z = axis.z * sin(halfAngle);
    }
};

inline mat4 toMatrix(const quaternion &q)
{
    mat4 mat;

    mat.m00 = 1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z;
    mat.m10 = 2.0f*q.x*q.y + 2.0f*q.w*q.z;
    mat.m20 = 2.0f*q.x*q.z - 2.0f*q.w*q.y;

    mat.m01 = 2.0f*q.x*q.y - 2.0f*q.w*q.z;
    mat.m11 = 1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z;
    mat.m21 = 2.0f*q.y*q.z + 2.0f*q.w*q.x;

    mat.m02 = 2.0f*q.x*q.z + 2.0f*q.w*q.y;
    mat.m12 = 2.0f*q.y*q.z - 2.0f*q.w*q.x;
    mat.m22 = 1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y;

    return mat;
}

inline float dot(const quaternion& lhs, const quaternion& rhs)
{
    return lhs.w*rhs.w + lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

inline quaternion operator*(const quaternion& lhs, const float scalar)
{
    return quaternion(scalar*lhs.w, scalar*lhs.x, scalar*lhs.y, scalar*lhs.z);
}
inline quaternion operator*(const float scalar, const quaternion& rhs)
{
    return quaternion(scalar*rhs.w, scalar*rhs.x, scalar*rhs.y, scalar*rhs.z);
}

inline quaternion operator*(const quaternion& q1, const quaternion& q2)
{
    float x =  q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
    float y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
    float z =  q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
    float w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;

    return quaternion(w, x, y, z);
}

inline vec3 operator*(const quaternion& quat, const vec3& vec) {
    float num = quat.x * 2.0f;
    float num2 = quat.y * 2.0f;
    float num3 = quat.z * 2.0f;
    float num4 = quat.x * num;
    float num5 = quat.y * num2;
    float num6 = quat.z * num3;
    float num7 = quat.x * num2;
    float num8 = quat.x * num3;
    float num9 = quat.y * num3;
    float num10 = quat.w * num;
    float num11 = quat.w * num2;
    float num12 = quat.w * num3;
    vec3 result;
    result.x = (1.0f - (num5 + num6)) * vec.x + (num7 - num12) * vec.y + (num8 + num11) * vec.z;
    result.y = (num7 + num12) * vec.x + (1.0f - (num4 + num6)) * vec.y + (num9 - num10) * vec.z;
    result.z = (num8 - num11) * vec.x + (num9 + num10) * vec.y + (1.0f - (num4 + num5)) * vec.z;
    return result;
}


inline float length(const quaternion& quat)
{
    return sqrt(quat.w*quat.w + quat.x*quat.x + quat.y*quat.y + quat.z*quat.z);
}

inline quaternion normalize(const quaternion& quat)
{
    const float l = length(quat);
    return quat * (1.0f / l);

}

struct Transform {
    Transform(vec3 position=vec3(), quaternion rotation=quaternion(), vec3 scale=vec3(1.0f)) {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;
    }

    mat4 getMatrix() const {
        mat4 mat;
        mat = translate(mat, position);
        mat = ::scale(mat, this->scale);
        mat = mat * toMatrix(rotation);

        return mat;
    }

    vec3 position;
    quaternion rotation;
    vec3 scale;
};