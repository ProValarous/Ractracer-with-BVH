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
    
    // Copy the ray and apply the backwards transform.
	dsRT::Ray bckRay = m_transformMatrix.Apply(castRay, false);
    
    qbVector<double> vhat = bckRay.m_lab;
    vhat.Normalize();

    double a = 1.0;

    double b = 2.0 * qbVector<double>::dot(bckRay.m_point1,vhat);

    double c = qbVector<double>::dot(bckRay.m_point1, bckRay.m_point1) - 1.0; 

    double intersect = (b*b) - 4.0 * a * c;

    qbVector<double> poi;

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
				poi = bckRay.m_point1 + (vhat * t1);
			}
			else
			{
				poi = bckRay.m_point1 + (vhat * t2);
			}

            intPoint =  m_transformMatrix.Apply(poi,true);

            // compute local normal
			qbVector<double> objOrigin = qbVector<double>{std::vector<double>{0.0, 0.0, 0.0}};
			qbVector<double> newObjOrigin = m_transformMatrix.Apply(objOrigin, true);
			localNormal = intPoint - newObjOrigin;
			localNormal.Normalize();
			
			// Return the base color.
			localColor = m_baseColor;
		}
		
		return true;
    }
    else
    {
        return false;
    }


}