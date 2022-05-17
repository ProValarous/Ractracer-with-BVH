#pragma once
#include "camera.hpp"
#include "ray.hpp"
#include <math.h>

dsRT::Camera::Camera() // Cobstructor
{
    m_cameraPosition = qbVector<double>	{std::vector<double> {0.0, -10.0, 0.0}};
	m_cameraLookAt = qbVector<double> {std::vector<double> {0.0, 0.0, 0.0}};
	m_cameraUp = qbVector<double> {std::vector<double> {0.0, 0.0, 1.0}};
	m_cameraLength = 1.0;
	m_cameraHorizontalSize = 1.0;
	m_cameraAspectRatio = 1.0;
}


//Setters

void dsRT::Camera::SetPosition(const qbVector<double> &newPosition)
{
	m_cameraPosition = newPosition;
}

void dsRT::Camera::set_look_at(const qbVector<double> &set_look_at)
{
	m_cameraLookAt = set_look_at;
}

void dsRT::Camera::Setup(const qbVector<double> &upVector)
{
	m_cameraUp = upVector;
}

void dsRT::Camera::SetLength(double newLength)
{
	m_cameraLength = newLength;
}

void dsRT::Camera::SetHorizontalSize(double newHorizontalSize)
{
	m_cameraHorizontalSize = newHorizontalSize;
}

void dsRT::Camera::set_aspect_ratio(double newAspect)
{
	m_cameraAspectRatio = newAspect;
}




//Getters

// Method to return the position of the camera.
qbVector<double> dsRT::Camera::GetPosition()
{
    return m_cameraPosition;
}

// Method to return the look at of the camera.
qbVector<double> dsRT::Camera::GetLookAt()
{
    return m_cameraLookAt;
}

// Method to return the up vector of the camera.
qbVector<double> dsRT::Camera::GetUp()
{
    return m_cameraUp;
}

// Method to return the length of the camera.
double dsRT::Camera::GetLength()
{
    return m_cameraLength;
}

double dsRT::Camera::GetHorizontalSize()
{
	return m_cameraHorizontalSize;
}

double dsRT::Camera::Get_aspect_ratio()
{
	return m_cameraAspectRatio;
}

qbVector<double> dsRT::Camera::GetU()
{
	return m_projectionScreenU;
}

qbVector<double> dsRT::Camera::GetV()
{
	return m_projectionScreenV;
}

qbVector<double> dsRT::Camera::GetScreenCenter()
{
	return m_projectionScreenCenter;
}




// Compute camera geometry

void dsRT::Camera::UpdateCameraGeometry()
{
    m_alignmentVector = m_cameraLookAt - m_cameraPosition; // compute vector from camera postion to the position you are looking at from
    m_alignmentVector.Normalize();

    m_projectionScreenU = qbVector<double>::cross(m_alignmentVector, m_cameraUp); // Compute U vector
    m_projectionScreenU.Normalize();

    m_projectionScreenV = qbVector<double>::cross(m_projectionScreenU, m_alignmentVector); // Compute V vector
    m_projectionScreenV.Normalize();

    m_projectionScreenCenter = m_cameraPosition + (m_cameraLength * m_alignmentVector); // Compute position of center of the camera

    m_projectionScreenU = m_projectionScreenU * m_cameraHorizontalSize;
    m_projectionScreenV = m_projectionScreenV * (m_cameraHorizontalSize/m_cameraAspectRatio);

}


bool dsRT::Camera::GenerateRay(float proScreenX, float proScreenY, dsRT::Ray &cameraRay)
{
    // Compute the location of the screen point in world coordinates.
	qbVector<double> screenWorldPart1 = m_projectionScreenCenter + (m_projectionScreenU * proScreenX);
	qbVector<double> screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);
	
	// Use this point along with the camera position to compute the ray.

	cameraRay.m_point1 =  m_cameraPosition;
	cameraRay.m_point2 = screenWorldCoordinate;
	cameraRay.m_lab =  screenWorldCoordinate - m_cameraPosition;

	return true;
}