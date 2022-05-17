#include "lightbase.hpp"


// Constructor.
dsRT::LightBase::LightBase()
{

}

// Destructor.
dsRT::LightBase::~LightBase()
{

}

// Function to compute illumination.
bool dsRT::LightBase::ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal, const std::vector<std::shared_ptr<dsRT::Object>> &objectList, const std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity)
// bool dsRT::LightBase::ComputeIllumination(qbVector<double> &intPoint, qbVector<double> &localNormal, std::vector<std::shared_ptr<dsRT::Object>> &objectList, std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity)
{
	return false;
}