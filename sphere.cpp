#include "sphere.hpp"
#include <cmath>

dsRT::Sphere::Sphere()
{

}

dsRT::Sphere::~Sphere()
{
    
}

bool dsRT::Sphere::TestIntersection(const dsRT::Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
    qbVector<double> vhat = castRay.m_lab;
    vhat.Normalize();

    double a = 1.0;

    double b = 2.0 * qbVector<double>::dot(castRay.m_point1,vhat);

    double c = qbVector<double>::dot(castRay.m_point1, castRay.m_point1) - 1.0; 

    double intersect = (b*b) - 4.0 * a * c;

    if (intersect > 0.0)
	{
		double numSQRT = sqrtf(intersect);
		double t1 = (-b + numSQRT) / 2.0;
		double t2 = (-b - numSQRT) / 2.0;
		
		/* If either t1 or t2 are negative, then at least part of the object is
			behind the camera and so we will ignore it. */
		if ((t1 < 0.0) || (t2 < 0.0))
		{
			return false;
		}
		else
		{
			// Determine which point of intersection was closest to the camera.
			if (t1 < t2)
			{
				intPoint = castRay.m_point1 + (vhat * t1);
			}
			else
			{
				intPoint = castRay.m_point1 + (vhat * t2);
			}
		}
		
		return true;
    }
    else
    {
        return false;
    }


}