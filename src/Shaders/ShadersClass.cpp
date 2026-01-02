#include "ShadersClass.hpp"
#include <cerrno>


[[ nodiscard ]]std::string GetFileContent(const std::string & file)
{
    using FileSize = int;
    std::ifstream in(file.c_str(), std::ios::binary);

    if(in)
    {
        std::string value;
        in.seekg(0,std::ios::end); //goes to the end of the file

        FileSize size = in.tellg();
        value.resize(size);

        in.seekg(0);

        in.read(&value[0], size);
        in.close();

        return value;
    }
    throw(errno);
}

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
{
    std::string vertexCode = GetFileContent(vertexFile);
    std::string fragmentCode = GetFileContent(fragmentFile);

    
}

EmptyReturn Shader::Activate()
{

}

EmptyReturn Shader::Delete()
{

}