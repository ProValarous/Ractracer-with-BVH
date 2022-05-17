#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "lightbase.hpp"
#include <vector>

namespace dsRT
{
	class PointLight : public LightBase
	{
		public:
			// The default constructor.
			PointLight();
			
			// Override the default destructor.
			virtual ~PointLight() override;
			
			// Function to compute illumination.
			virtual bool ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal, const std::vector<std::shared_ptr<dsRT::Object>> &objectList, const std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity) override;
            // virtual bool ComputeIllumination(qbVector<double> &intPoint, qbVector<double> &localNormal,std::vector<std::shared_ptr<dsRT::Object>> &objectList, const std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity) override;
	};
}

#endif