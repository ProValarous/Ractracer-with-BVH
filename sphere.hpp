#ifndef SPHERE_H
#define SPHERE_H
#include "object.hpp"
#include "transform.hpp"


namespace dsRT
{
    class Sphere: public Object
    {
        public:
            Sphere(); //define a  unit sphere centered at origin

        // Override the destructor.
			virtual ~Sphere() override;
			
			// Override the function to test for intersections.
			virtual bool TestIntersection(const dsRT::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor) override;
    };
} // namespace dsRT


#endif