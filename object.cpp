#include "object.hpp"
#include "math.h"

#define EPSILON 1e-21f;

// Default constructor.
dsRT::Object::Object()
{

}

// The destructor.
dsRT::Object::~Object()
{

}

// Function to test for intersections.
bool dsRT::Object::TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
	return false;
}

// Function to test whether two floating-point numbers are close to being equal.
bool dsRT::Object::CloseEnough(const double f1, const double f2)
{
	return fabs(f1-f2) < EPSILON;
}


void dsRT::Object::SetTransformMatrix(const dsRT::Transform &transformMatrix)
{
	m_transformMatrix = transformMatrix;
}
