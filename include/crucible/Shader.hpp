#pragma once

#include <string>
#include <crucible/Math.hpp>

class Shader
{
private:
    // The program ID
    unsigned int id;

    std::string readShader(std::ifstream &file, std::string directory);

public:
    // Constructor reads and builds the shader
    Shader();

    void loadFile(const std::string &vertexPath, const std::string &fragmentPath);

    void load(std::string vertex, std::string fragment);

    void loadPostProcessing(std::string shader);

    // Use the program
    void bind() const;

    void uniformMat4(const std::string &location, const mat4 &mat) const;

    void uniformVec3(const std::string &location, const vec3 &vec) const;

    void uniformVec4(const std::string &location, const vec4 &vec) const;

    void uniformInt(const std::string &location, int value) const;

    void uniformFloat(const std::string &location, float value) const;

    void uniformBool(const std::string &location, bool value) const;
};
