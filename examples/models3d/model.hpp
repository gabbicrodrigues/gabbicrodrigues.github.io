#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <string_view>
#include <vector>

#include "abcg.hpp"

struct Vertex {
  glm::vec3 position{};

  bool operator==(const Vertex& other) const noexcept {
    return position == other.position;
  }
};

class Model {
 public:
  void loadObj(std::string_view path, bool standardize = true);
  void render();
  void setupVAO(GLuint program);

  void terminateGL();  

 private:
  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};

  // GLuint m_diffuseTexture{};

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;

  void createBuffers();
  void standardize();
};

#endif