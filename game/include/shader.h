#ifndef SHADER_H
#define SHADER_H
#define GLM_ENABLE_EXPERIMENTAL

#include <vector>

#include "graphics_headers.h"

class Shader
{
  public:
    Shader();
    Shader(std::string vertexFile, std::string fragmentFile);
    ~Shader();
    bool Initialize();
    void Enable();
    bool AddShader(GLenum ShaderType);
    bool Finalize();
    GLint GetUniformLocation(const char* pUniformName);

  private:
    GLuint m_shaderProg;    
    std::vector<GLuint> m_shaderObjList;
    std::string m_vertexFile;
    std::string m_fragmentFile;
};

#endif  /* SHADER_H */
