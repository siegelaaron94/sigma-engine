#ifndef SIGMA_TRANSFORM_HPP
#define SIGMA_TRANSFORM_HPP

#include <sigma/config.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/vec3.hpp>

namespace sigma {

struct transform {
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    glm::mat4 matrix;

    transform(glm::vec3 position = glm::vec3 { 0 }, glm::quat rotation = glm::quat {}, glm::vec3 scale = glm::vec3 { 1 })
        : position(position)
        , rotation(rotation)
        , scale(scale)
    {
    }

    glm::mat4 get_matrix() const
    {
        return glm::translate(glm::mat4(1), position) * glm::mat4_cast(rotation) * glm::scale(glm::mat4(1), glm::vec3(scale));
    }
};
}

#endif // SIGMA_TRANSFORM_HPP
