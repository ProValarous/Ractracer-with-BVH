#ifndef LIGHTBASE_H
#define LIGHTBASE_H

#include <memory>
#include "./qbLinAlg/qbVector.h"
#include "ray.hpp"
#include "object.hpp"
#include <vector>

namespace dsRT
{
	class LightBase
	{
		public:
			// Constructor / destructor.
			LightBase();
			virtual ~LightBase();
			
			// Function to compute illumination contribution.
			virtual bool ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal, const std::vector<std::shared_ptr<dsRT::Object>> &objectList, const std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity);
			// virtual bool ComputeIllumination(qbVector<double> &intPoint, qbVector<double> &localNormal, std::vector<std::shared_ptr<dsRT::Object>> &objectList, std::shared_ptr<dsRT::Object> &currentObject, qbVector<double> &color, double &intensity);
			

		public:
			qbVector<double>m_color	{3};
			qbVector<double>m_location {3};
			double m_intensity;
	};
}

#endif