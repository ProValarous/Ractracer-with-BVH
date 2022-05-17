#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL.h>
#include "dsImage.hpp"
#include "camera.hpp"
#include "sphere.hpp"
#include "pointlight.hpp"

namespace dsRT
{
    class Scene
    {
        public:
            Scene(); // Defualt constructor

            bool Render(dsImage &outputImage); // Function that performs rendering

        private:
            dsRT::Camera m_camera; // Create out camera

            // dsRT::Sphere m_sphere; // A Unit sphere

            // The list of objects in the scene.
			std::vector<std::shared_ptr<dsRT::Object>> m_objectList;
            std::vector<std::vector<double>> m_RADobject;


            // The list of lights in the scene.
			std::vector<std::shared_ptr<dsRT::LightBase>> m_lightList;
    };
    
} // namespace dsRT

#endif


