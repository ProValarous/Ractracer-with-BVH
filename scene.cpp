#include "scene.hpp"


dsRT::Scene::Scene() // constructor
{
    // Configure the camera.
	m_camera.SetPosition(	qbVector<double>{std::vector<double> {0.0, -10.0, 0.0}} );
	m_camera.set_look_at( qbVector<double>{std::vector<double> {0.0, 0.0, 0.0}} );
	m_camera.Setup( qbVector<double>{std::vector<double> {0.0, 0.0, 1.0}} );
	m_camera.SetHorizontalSize(0.25);
	m_camera.set_aspect_ratio(16.0 / 9.0);
	m_camera.UpdateCameraGeometry();
}


bool dsRT::Scene::Render(dsImage &outputImage)
{
    // Get dimension of output image
    int xSize = outputImage.GetXSize();
    int ySize = outputImage.GetYSize();




    /*--- Integrate BVH here ---*/
    

    // Loop over each pixel

    dsRT::Ray cameraRay;
	qbVector<double> intPoint(3);
	qbVector<double> localNormal(3);
	qbVector<double> localColor(3);
	double xFact = 1.0 / (static_cast<double>(xSize) / 2.0);
	double yFact = 1.0 / (static_cast<double>(ySize) / 2.0);
	double minDist = 1e6;
	double maxDist = 0.0;

    for (int x = 0; x<xSize; x++)
    {
        for(int y=0; y<ySize; y++)
        {
            // Normalize the x and y coordinates.
			double normX = (static_cast<double>(x) * xFact) - 1.0;
			double normY = (static_cast<double>(y) * yFact) - 1.0;
			
			// Generate the ray for this pixel.
			m_camera.GenerateRay(normX, normY, cameraRay);
			
			// Test if we have a valid intersection.
			bool validInt = m_sphere.TestIntersection(cameraRay, intPoint, localNormal, localColor);

            if (validInt)
			{
				
				// Compute the distance between the camera and the point of intersection.
				double dist = (intPoint - cameraRay.m_point1).norm();
				if (dist > maxDist)
					maxDist = dist;
				
				if (dist < minDist)
					minDist = dist;
				
				outputImage.SetPixel(x, y, 255.0 - ((dist - 9.0) / 0.94605) * 255.0, 0.0, 0.0);
			}
			else
			{
				outputImage.SetPixel(x, y, 0.0, 0.0, 0.0);
			}
        }
    }

    /*--- END ---*/

    // //!!!---Some fun colour testing---!!!
    // for (int x = 0; x<xSize; x++)
    // {
    //     for(int y=0; y<ySize; y++)
    //     {
    //         double red = (static_cast<double>(x)/static_cast<double>(xSize)) * 255.0;
    //         double green = (static_cast<double>(y)/static_cast<double>(ySize)) * 255.0;

    //         outputImage.SetPixel(x,y,red,green,0.0);
    //     }
    // }
    return true;
}