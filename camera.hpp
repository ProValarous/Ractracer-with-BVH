#ifndef CAMERA_H
#define CAMERA_H

#include "./qbLinAlg/qbVector.h"
#include "ray.hpp"

namespace dsRT
{
    class Camera
    {
        public:
            Camera(); // Defualt constructor

            // Setting camera parameters
            void SetPosition(const qbVector<double> &newPosition);
            void set_look_at(const qbVector<double> &set_look_at);
            void Setup (const qbVector<double> &upVector);
            void SetLength (double newLength);
            void SetHorizontalSize(double newHorizontalSize);
            void set_aspect_ratio(double newAspect);

            // Getting camera parameters
            qbVector<double> GetPosition();
            qbVector<double> GetLookAt();
            qbVector<double> GetUp();
            qbVector<double> GetU();
            qbVector<double> GetV();
            qbVector<double> GetScreenCenter();

            double GetLength();
            double GetHorizontalSize();
            double Get_aspect_ratio();


            bool GenerateRay(float proScreenX, float proScreenY, dsRT::Ray &cameraRay); // Generate Ray

            void UpdateCameraGeometry();


        private:
            qbVector<double> m_cameraPosition{3};
            qbVector<double> m_cameraLookAt{3};
            qbVector<double> m_cameraUp{3};

            double m_cameraLength;
            double m_cameraHorizontalSize;
            double m_cameraAspectRatio;

            qbVector<double> m_alignmentVector{3};
            qbVector<double> m_projectionScreenU{3};
            qbVector<double> m_projectionScreenV{3};
            qbVector<double> m_projectionScreenCenter{3};


    };
}




#endif




