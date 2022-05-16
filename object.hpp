#ifndef OBJECT_H
#define OBJECT_H

#include "./qbLinAlg/qbVector.h"
#include "ray.hpp"


namespace dsRT
{
	class Object
	{
		public:
			// Constructor and destructor.
			Object();
			virtual ~Object();
			
			// Function to test for intersections.
			virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor);
			
			// Function to test whether two floating-point numbers are close to being equal.
			bool CloseEnough(const double f1, const double f2);
			
            
			// The base colour of the object.
			qbVector<double> m_baseColor {3};
	};
}

#endif
