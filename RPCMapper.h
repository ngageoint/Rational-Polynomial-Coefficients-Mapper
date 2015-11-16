#pragma once
/*
RPC Background:
Rapid Positioning Coefficients (RPCs) are a set of floating point numbers that allow one to determine
where a point in object space will be imaged in a sensor's space.

Example:
If an image was taken of the Colosseum in Rome and RPC data was calculated for the image,
the RPCs would allow you to determine which pixel 41.8902° N, 12.4923° E maps to in the image. In this
way you can think of RPCs as analogous to the Camera matrix used in many computer vision applications.

What this class does:
This class is a GIS utility function that maps a set of Geodetic coordinates (Latitude, Longitude, and Altitude)
to their corresponding pixel locations for an image that has both pixel data and RPC data associate with it. 

Why this class exists:
This class was written to support PATHFINDER - a program of the United States's National Geospatial Intelligence Agency (NGA).
Some of the commercial satellite data being used for PATHFINDER contained RPC Data and so this class was written to support the Orthorectification of
that data.

Implementation Specific Information:
- This class only supports the RPC-B standard. By modifying the mLLAMultiple array's index order it can be made to support RPCA.
- LLA arrays assume Latitude in index 0, Longitude in index 1, and Altitude in index 2. 

Class Style Guide:
- Readability was chosen over efficiency so that debuggers and porters could follow the algorithm easily 
- the class members and methods are grouped by overall function and then alphabetically
- all member variables are private.
- all member variables have public get/set accessor functions.
- when appropriate member variables have update accessor functions.
- static variables start with a lowercase "s".
- member variables start with a lowercase "m".
- local  variables start with a lowercase "l".
- loop   variables are a single lowercase letter. In our case we used "i"
- method return variables are all labeled "rvalue". they are used to insure that a method only has 1 exit point.
- rvalues are defaulted to indicate failure either through assinment to "false" or "NaN"
- accessor methods start with a lowercase "a".
- calculation methods start with a lowercase "c".
- void returns are discouraged.

Author:
Clayton H. Davis (CHD)
Data Scientist
Associate
Booz Allen Hamilton

Licensing:
Use of this class is subject to the following license terms:
-Talk to the NGA lawyers

*/

#include <limits>

class RPCMapper
{
	public:
	struct ImageCoordinates{
		int XValue;
		int YValue;
	};

public:
	// index array maximums that are known at compile time
	const static int sLLASize = 3;
	const static int sCoefficientSize = 20;
	const static int sPixelSize = 2;

private:

	//Coefficients for transforming the LLA coordinates to +/-1 as required by the RPC algorithm
	// -1 <= (LLA[i] - mLLAOffsets[i])/mLLAScaleFactors <= 1; for i = 0,1,2
	double mLLAOffsets[sLLASize];
	double mLLAScaleFactors[sLLASize];

	//The array holds LLA[0]^i * LLA[1]^j * LLA[2]^k for the 20 permutations that exist when the indexes
	//i, j, and k are allowed to take any integer value between 0 and 3 inclusive 
	double mLLAMultiples[sCoefficientSize];
	
	// holds the actual pixel location within the image of the the location that the LLA mapped to.
	// this is what the mapper is ultimately designed to calculate.
	double mPixelOffsets[sPixelSize];
	double mPixelScaleFactors[sPixelSize];


	//LLAs min and max values for the 3D volume in which the RPC model is valid. It's primary
	//function is to make sure we are processing in regions where the RPCs are valid. the *2 
	// is because we have 2 LLAs one each for the min and max of the variable.
	double mRPCBoundingBox[sLLASize * 2];
	
	//Coefficients for calculating the +/- 1 scaled pixel location. 
	double mXDenCoefficients[sCoefficientSize];
	double mXNumCoefficients[sCoefficientSize];
	double mYDenCoefficients[sCoefficientSize];
	double mYNumCoefficients[sCoefficientSize];

public:
	RPCMapper();
	~RPCMapper();

	//################
	//Accessor methods
	//################
	
	//get methods for both full array return and element wise return
	const double *	aGetLLAOffsets();
	double			aGetLLAOffsetsElement(int i);
	const double *	aGetLLAScaleFactors();
	double			aGetLLAScaleFactorsElement(int i);
	const double *	aGetLLAMultiples();
	double			aGetLLAMultiplesElement(int i);
	const double *	aGetPixelOffsets();
	double			aGetPixelOffsetsElement(int i);
	const double *	aGetPixelScaleFactors();
	double			aGetPixelScaleFactorsElement(int i);
	const double *	aGetRPCBoundingBox();
	double			aGetRPCBoundingBoxElement(int i);
	const double *	aGetXDenCoefficients();
	double			aGetXDenCoefficientsElement(int i);
	const double *	aGetXNumCoefficients();
	double			aGetXNumCoefficientsElement(int i);
	const double *	aGetYDenCoefficients();
	double			aGetYDenCoefficientsElement(int i);
	const double *	aGetYNumCoefficients();
	double			aGetYNumCoefficientsElement(int i);

	//set methods for element wise assignment 
	bool aSetLLAOffsetsElement(int index, double value);
	bool aSetLLAScaleFactorsElement(int index, double value);
	bool aSetLLAMultiplesElement(int index, double value);
	bool aSetPixelOffsetsElement(int index, double value);
	bool aSetPixelScaleFactorsElement(int index, double value);
	bool aSetRPCBoundingBoxElement(int index, double value);
	bool aSetXDenCoefficientsElement(int index, double value);
	bool aSetXNumCoefficientsElement(int index, double value);
	bool aSetYDenCoefficientsElement(int index, double value);
	bool aSetYNumCoefficientsElement(int index, double value);

	//update methods for derived Array Elements
	bool aUpdateLLAMultiples(double scaledLat, double scaledLon, double scaledAlt);

	//###################
	//Calculation Methods
	//###################

	//Calculate Bounding Box for Valid RPCs
	bool cGenerateBoundingBox();
	
	//Determine if LLA is within Bounding Box
	//this must be done for each LLA as the scaling methods assume that the point is valid
	bool cIsMappable(double lat, double lon, double alt);
	
	//scale the altitude to +/- 1 within the bounding box
	double cScaleAltitude(double alt);
	//scale the latitude to +/- 1 within the bounding box
	double cScaleLatitude(double lat);
	//scale the longitude to +/- 1 within the bounding box
	double cScaleLongitude(double lon);
	//Calculate the +/- 1 scaled X value
	double cScaledX();
	//Calculate the +/- 1 scaled Y value
	double cScaledY();

	//Calculate Sample Coordinate
	double cSValue(double scaledX);
	//Calculate Line Coordinate
	double cLValue(double scaledY);

	//####################
	//Full Chain Processor
	//####################
	ImageCoordinates MapLLA(double lat, double lon, double alt);

};

