//
// Created by Göksu Güvendiren on 2019-05-09.
//

#pragma once

#include <glm/vec3.hpp>

namespace rtr
{
    class light
    {
    public:
        light(const glm::vec3& pos, const glm::vec3& col) : position(pos), color(col) {}
        glm::vec3 position;
        glm::vec3 color;

        glm::vec3 direction(const glm::vec3& hit_pos) const
        {
            return glm::normalize(position - hit_pos);
        }

        float distance(const glm::vec3& hit_pos) const
        {
            return glm::length(position - hit_pos);
        }

        float attenuate(const glm::vec3& hit_pos) const
        {
            auto distance = glm::length(position - hit_pos);
            float c_1 = 0.25;
            float c_2 = 0.1;
            float c_3 = 0.01;

            auto attenuation = 1.f / float(c_1 + c_2 * distance + c_3 * distance * distance);
            return std::min(1.f, attenuation);
        }
    };
}