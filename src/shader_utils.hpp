#pragma once

#include <glad/gl.h>
#include <string>
#include <iostream>
#include <array>
#include "file_utils.hpp"

namespace ShaderUtils {
    template<size_t N>
    static inline GLuint createShaderProgram(const std::array<GLenum, N>& shaderTypes, const std::array<std::string_view, N>& filepaths) {
        GLint success;
        GLchar infoLog[512];

        std::array<GLuint, N> shaderIDs;
        const std::array<std::string, N> shaderCode = FileUtils::readFiles(filepaths);

        //c'est possible de compiler des shaders en parralèle, mais ce n'est pas élégant à implanter
        //ça ne vaut pas la peine pour seulement 2 shaders simples
        //QUESTION : quel autre optimisation par rapport aux shaders pouvons-nous faire ?
        for (size_t i = 0; i < N; ++i) {
            GLuint id = glCreateShader(shaderTypes[i]);
            shaderIDs[i] = id;

            const GLchar* code = shaderCode[i].c_str();
            glShaderSource(id, 1, &code, NULL);
            glCompileShader(id);

            glGetShaderiv(id, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(id, 512, NULL, infoLog);
                std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
            }
        }

        GLuint shaderProgram = glCreateProgram();
        for (size_t i = 0; i < N; ++i) {
            glAttachShader(shaderProgram, shaderIDs[i]);
        }

        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        for (size_t i = 0; i < N; ++i) {
            glDeleteShader(shaderIDs[i]);
        }

        return shaderProgram;
    }
}
