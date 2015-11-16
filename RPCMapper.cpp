#include "RPCMapper.h"


RPCMapper::RPCMapper()
{
	//initialize the arrays to NaNs so that we can check them in the processing chain
	//and make sure that they have been changed
	for (int i = 0; i < this->sCoefficientSize;i++){
		if (i < this->sPixelSize){
			this->aSetPixelOffsetsElement(i, std::numeric_limits<double>::quiet_NaN());
			this->aSetPixelScaleFactorsElement(i, std::numeric_limits<double>::quiet_NaN());
		}
		if (i < this->sLLASize){
			this->aSetLLAScaleFactorsElement(i, std::numeric_limits<double>::quiet_NaN());
			this->aSetLLAOffsetsElement(i, std::numeric_limits<double>::quiet_NaN());
			this->aSetRPCBoundingBoxElement(i, std::numeric_limits<double>::quiet_NaN());
			this->aSetRPCBoundingBoxElement(i+3, std::numeric_limits<double>::quiet_NaN());
		}

		this->aSetLLAMultiplesElement(i, std::numeric_limits<double>::quiet_NaN());
		this->aSetXDenCoefficientsElement(i, std::numeric_limits<double>::quiet_NaN());
		this->aSetXNumCoefficientsElement(i, std::numeric_limits<double>::quiet_NaN());
		this->aSetYDenCoefficientsElement(i, std::numeric_limits<double>::quiet_NaN());
		this->aSetYNumCoefficientsElement(i, std::numeric_limits<double>::quiet_NaN());

	}
}

RPCMapper::~RPCMapper()
{
}

//return the Offset LLA array without giving modification access 
const double * RPCMapper::aGetLLAOffsets(){
	return (const double *)&(this->mLLAOffsets);
}

//return a copy of the ith element of the LLAOffsets array
double  RPCMapper::aGetLLAOffsetsElement(int i){
	double rvalue = 0.0;

	if (i<this->sLLASize && i >= 0){
		rvalue = this->mLLAOffsets[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  LLAScaleFactors array without giving modification access 
const double * RPCMapper::aGetLLAScaleFactors(){
	return (const double *)&(this->mLLAScaleFactors);
}

//return a copy of the ith element of the LLAScaleFactors array
double  RPCMapper::aGetLLAScaleFactorsElement(int i){
	double rvalue = 0.0;

	if (i<this->sLLASize && i >= 0){
		rvalue = this->mLLAScaleFactors[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the Offset LLA array without giving modification access 
const double * RPCMapper::aGetLLAMultiples(){
	return (const double *)&(this->mLLAMultiples);
}

//return a copy of the ith element of the LLA array
double  RPCMapper::aGetLLAMultiplesElement(int i){
	double rvalue = 0.0;

	if (i<this->sCoefficientSize && i >= 0){
		rvalue = this->mLLAMultiples[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the Offset Pixel array without giving modification access 
const double * RPCMapper::aGetPixelOffsets(){
	return (const double *)&(this->mPixelOffsets);
}

//return a copy of the ith element of the PixelOffset array
double  RPCMapper::aGetPixelOffsetsElement(int i){
	double rvalue = 0.0;

	if (i<this->sPixelSize && i >= 0){
		rvalue = this->mPixelOffsets[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  PixelScaleFactors array without giving modification access 
const double * RPCMapper::aGetPixelScaleFactors(){
	return (const double *)&(this->mPixelScaleFactors);
}

//return a copy of the ith element of the PixelScaleFactors array
double  RPCMapper::aGetPixelScaleFactorsElement(int i){
	double rvalue = 0.0;

	if (i<this->sPixelSize && i >= 0){
		rvalue = this->mPixelScaleFactors[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  RPC Bounding Box array without giving modification access 
const double * RPCMapper::aGetRPCBoundingBox(){
	return (const double *)&(this->mRPCBoundingBox);
}

//return a copy of the ith element of the RPC Bounding Box array
double  RPCMapper::aGetRPCBoundingBoxElement(int i){
	double rvalue = 0.0;

	if (i<this->sLLASize * 2 && i >= 0){
		rvalue = this->mRPCBoundingBox[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  X Denomenator array without giving modification access 
const double * RPCMapper::aGetXDenCoefficients(){
	return (const double *)&(this->mXDenCoefficients);
}

//return a copy of the ith element of the X Denomenator array
double  RPCMapper::aGetXDenCoefficientsElement(int i){
	double rvalue = 0.0;

	if (i<this->sCoefficientSize  && i >= 0){
		rvalue = this->mXDenCoefficients[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  X Numerator array without giving modification access 
const double * RPCMapper::aGetXNumCoefficients(){
	return (const double *)&(this->mXNumCoefficients);
}

//return a copy of the ith element of the X Numerator array
double  RPCMapper::aGetXNumCoefficientsElement(int i){
	double rvalue = 0.0;

	if (i<this->sCoefficientSize  && i >= 0){
		rvalue = this->mXNumCoefficients[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  Y Denomenator array without giving modification access 
const double * RPCMapper::aGetYDenCoefficients(){
	return (const double *)&(this->mYDenCoefficients);
}

//return a copy of the ith element of the Y Denomenator array
double  RPCMapper::aGetYDenCoefficientsElement(int i){
	double rvalue = 0.0;

	if (i<this->sCoefficientSize  && i >= 0){
		rvalue = this->mYDenCoefficients[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//return the  Y Numerator array without giving modification access 
const double * RPCMapper::aGetYNumCoefficients(){
	return (const double *)&(this->mYNumCoefficients);
}

//return a copy of the ith element of the Y Numerator array
double  RPCMapper::aGetYNumCoefficientsElement(int i){
	double rvalue = 0.0;

	if (i<this->sCoefficientSize  && i >= 0){
		rvalue = this->mYNumCoefficients[i];
	}
	else{
		rvalue = std::numeric_limits<double>::quiet_NaN();
	}
	return rvalue;
}

//all set functions take an index and a double for the value to be set to
bool RPCMapper::aSetLLAOffsetsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sLLASize && index >= 0){
		this->mLLAOffsets[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetLLAScaleFactorsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sLLASize && index >= 0){
		this->mLLAScaleFactors[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetLLAMultiplesElement(int index, double value){
	bool rvalue = false;

	if (index < this->sCoefficientSize && index >= 0){
		this->mLLAMultiples[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetPixelOffsetsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sPixelSize && index >= 0){
		this->mPixelOffsets[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetPixelScaleFactorsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sPixelSize && index >= 0){
		this->mPixelScaleFactors[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetRPCBoundingBoxElement(int index, double value){
	bool rvalue = false;

	if (index < this->sLLASize * 2 && index >= 0){
		this->mRPCBoundingBox[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetXDenCoefficientsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sCoefficientSize && index >= 0){
		this->mXDenCoefficients[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetXNumCoefficientsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sCoefficientSize && index >= 0){
		this->mXNumCoefficients[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetYDenCoefficientsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sCoefficientSize && index >= 0){
		this->mYDenCoefficients[index] = value;
		rvalue = true;
	}
	return rvalue;
}
bool RPCMapper::aSetYNumCoefficientsElement(int index, double value){
	bool rvalue = false;

	if (index < this->sCoefficientSize && index >= 0){
		this->mYNumCoefficients[index] = value;
		rvalue = true;
	}
	return rvalue;
}

//update Accessors
bool RPCMapper::aUpdateLLAMultiples(double scaledLat, double scaledLon, double scaledAlt){
	bool rvalue = false;

	if (
		//bias term
		this->aSetLLAMultiplesElement(0, 1.0) &&
		//linear terms
		this->aSetLLAMultiplesElement(1, scaledLon) &&
		this->aSetLLAMultiplesElement(2, scaledLat) &&
		this->aSetLLAMultiplesElement(3, scaledAlt) &&
		//quadratic terms
		this->aSetLLAMultiplesElement(4, scaledLon * scaledLat) &&
		this->aSetLLAMultiplesElement(5, scaledLon * scaledAlt) &&
		this->aSetLLAMultiplesElement(6, scaledLat * scaledAlt) &&
		this->aSetLLAMultiplesElement(7, scaledLon * scaledLon) &&
		this->aSetLLAMultiplesElement(8, scaledLat * scaledLat) &&
		this->aSetLLAMultiplesElement(9, scaledAlt * scaledAlt) &&
		//cubic terms
		this->aSetLLAMultiplesElement(10, scaledLon * scaledLat * scaledAlt) &&
		this->aSetLLAMultiplesElement(11, scaledLon * scaledLon * scaledLon) &&
		this->aSetLLAMultiplesElement(12, scaledLon * scaledLat * scaledLat) &&
		this->aSetLLAMultiplesElement(13, scaledLon * scaledAlt * scaledAlt) &&
		this->aSetLLAMultiplesElement(14, scaledLon * scaledLon * scaledLat) &&
		this->aSetLLAMultiplesElement(15, scaledLat * scaledLat * scaledLat) &&
		this->aSetLLAMultiplesElement(16, scaledLat * scaledAlt * scaledAlt) &&
		this->aSetLLAMultiplesElement(17, scaledLon * scaledLon * scaledAlt) &&
		this->aSetLLAMultiplesElement(18, scaledLat * scaledLat * scaledAlt) &&
		this->aSetLLAMultiplesElement(19, scaledAlt * scaledAlt * scaledAlt)
		){
		rvalue = true;
		}

	return rvalue;
}

// generates the bounding box over which to RPC are valid
bool RPCMapper::cGenerateBoundingBox(){
	bool rvalue = false;
	//generate values for -1 boundings from 
	// -1 = (value - valueoffset)/valuescale which can be rewritten as
	// -valuescale + valueoffset = value
	double lNegLat = -this->aGetLLAScaleFactorsElement(0) + this->aGetLLAOffsetsElement(0);
	double lNegLon = -this->aGetLLAScaleFactorsElement(1) + this->aGetLLAOffsetsElement(1);
	double lNegAlt = -this->aGetLLAScaleFactorsElement(2) + this->aGetLLAOffsetsElement(2);

	//generate values for +1 boundings
	double lPosLat = this->aGetLLAScaleFactorsElement(0) + this->aGetLLAOffsetsElement(0);
	double lPosLon = this->aGetLLAScaleFactorsElement(1) + this->aGetLLAOffsetsElement(1);
	double lPosAlt = this->aGetLLAScaleFactorsElement(2) + this->aGetLLAOffsetsElement(2);

	//swap values if needed
	double swap = 0.0;
	if (lNegLat > lPosLat){
		swap = lNegLat;
		lNegLat = lPosLat;
		lPosLat = swap;
	}
	swap = 0.0;
	if (lNegLon > lPosLon){
		swap = lNegLon;
		lNegLon = lPosLon;
		lPosLon = swap;
	}
	swap = 0.0;
	if (lNegAlt > lPosAlt){
		swap = lNegAlt;
		lNegAlt = lPosAlt;
		lPosAlt = swap;
	}

	//set RPC Bound Box Array as LLA Min and then LLA Max values
	if (this->aSetRPCBoundingBoxElement(0, lNegLat) && this->aSetRPCBoundingBoxElement(1, lNegLon) && this->aSetRPCBoundingBoxElement(2, lNegAlt)
		&& this->aSetRPCBoundingBoxElement(3, lPosLat) && this->aSetRPCBoundingBoxElement(4, lPosLon) && this->aSetRPCBoundingBoxElement(5, lPosAlt)){
		rvalue = true;
	}
	//return only if there is a successful set
	return rvalue;
}
// returns true if the LLA is within the valid bounding box
bool RPCMapper::cIsMappable(double lat, double lon, double alt){
	bool rvalue = false;

	if (lat >= this->aGetRPCBoundingBoxElement(0) && lon >= this->aGetRPCBoundingBoxElement(1) && alt >= this->aGetRPCBoundingBoxElement(2)
		&& lat <= this->aGetRPCBoundingBoxElement(3) && lon <= this->aGetRPCBoundingBoxElement(4) && alt <= this->aGetRPCBoundingBoxElement(5)){
		rvalue = true;
	}

	return rvalue;
}
//returns a value scaled between +/-1 in the Bounding box
double RPCMapper::cScaleAltitude(double alt){
	//we are going to use NaN so that we can be sure any number coming out isn't a default value
	double rvalue = std::numeric_limits<double>::quiet_NaN();
	
	//the equations is scalevalue = (value - valueoffset)/valuescale
	rvalue = (alt - this->aGetLLAOffsetsElement(2)) / this->aGetLLAScaleFactorsElement(2);

	return rvalue;
}
//returns a value scaled between +/-1 in the Bounding box
double RPCMapper::cScaleLatitude(double lat){
	//we are going to use NaN so that we can be sure any number coming out isn't a default value
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	//the equations is scalevalue = (value - valueoffset)/valuescale
	rvalue = (lat - this->aGetLLAOffsetsElement(0)) / this->aGetLLAScaleFactorsElement(0);

	return rvalue;
}
//returns a value scaled between +/-1 in the Bounding box
double RPCMapper::cScaleLongitude(double lon){
	//we are going to use NaN so that we can be sure any number coming out isn't a default value
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	//the equations is scalevalue = (value - valueoffset)/valuescale
	rvalue = (lon - this->aGetLLAOffsetsElement(1)) / this->aGetLLAScaleFactorsElement(1);

	return rvalue;
}
//returns a value between +/-1 corresponding to the image plane
double RPCMapper::cScaledX(){
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	double lNum = 0.0;
	double lDen = 0.0;
	double lRatio = 0.0;

	//Run RPC mapping function
	for (int i = 0; i < this->sCoefficientSize; i++){
		lNum += this->aGetXNumCoefficientsElement(i) * this->aGetLLAMultiplesElement(i);
		lDen += this->aGetXDenCoefficientsElement(i) * this->aGetLLAMultiplesElement(i);
	}
	lRatio = lNum / lDen;

	//santy check the Ratio before assignmet
	if (lRatio >= -1.0 && lRatio <= 1.0){
		rvalue = lRatio;
	}

	return rvalue;
}
//returns a value between +/-1 corresponding to the image plane
double RPCMapper::cScaledY(){
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	double lNum = 0.0;
	double lDen = 0.0;
	double lRatio = 0.0;

	//Run RPC mapping function
	for (int i = 0; i < this->sCoefficientSize; i++){
		lNum += this->aGetYNumCoefficientsElement(i) * this->aGetLLAMultiplesElement(i);
		lDen += this->aGetYDenCoefficientsElement(i) * this->aGetLLAMultiplesElement(i);
	}
	lRatio = lNum / lDen;

	//santy check the Ratio before assignmet
	if (lRatio >= -1.0 && lRatio <= 1.0){
		rvalue = lRatio;
	}

	return rvalue;
}
//calculate S coordinate
double RPCMapper::cSValue(double scaledX){
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	rvalue = scaledX*this->aGetPixelScaleFactorsElement(0) + this->aGetPixelOffsetsElement(0);
	return rvalue;
}
//calculate L coordinate
double RPCMapper::cLValue(double scaledY){
	double rvalue = std::numeric_limits<double>::quiet_NaN();

	rvalue = scaledY*this->aGetPixelScaleFactorsElement(1) + this->aGetPixelOffsetsElement(1);
	return rvalue;
}
//Full Chain processing
RPCMapper::ImageCoordinates RPCMapper::MapLLA(double lat, double lon, double alt){
	// use of this function assumes that all the coefficients have been set
	ImageCoordinates rvalue;
	rvalue.XValue = std::numeric_limits<int>::quiet_NaN();
	rvalue.YValue = std::numeric_limits<int>::quiet_NaN();

	bool lprocess = true;

	//check to make sure that there are no NaNs which would indicate that a value we need for processing is missing
	//to use this function it is required that none of the checks fail, which would indicate that you have not set all the 
	//variables required for RPC mapping
	for (int i = 0; i < this->sCoefficientSize; i++){
		if (i < this->sPixelSize){
			if(
				std::isnan( this->aGetPixelOffsetsElement(i)) ||
				std::isnan(this->aGetPixelScaleFactorsElement(i))){
				i = this->sCoefficientSize;
				lprocess = false;
			}
		}
		if (i < this->sLLASize){
			if (
				std::isnan(this->aGetLLAScaleFactorsElement(i)) ||
				std::isnan(this->aGetLLAOffsetsElement(i)) ||
				std::isnan(this->aGetRPCBoundingBoxElement(i)) ||
				std::isnan(this->aGetRPCBoundingBoxElement(i + 3))
			){
				i = this->sCoefficientSize; 
				lprocess = false;
			}
		}
		if (
			std::isnan(this->aGetXDenCoefficientsElement(i)) ||
			std::isnan(this->aGetXNumCoefficientsElement(i)) ||
			std::isnan(this->aGetYDenCoefficientsElement(i)) ||
			std::isnan(this->aGetYNumCoefficientsElement(i))
		){
			i = this->sCoefficientSize;
			lprocess = false;
		}
	//end of for loop
	}

	//if we are free of NaNs and the point is mappable we can process it
	if (lprocess && this->cIsMappable(lat, lon, alt)){
		
		//update the LLA Multiples
		this->aUpdateLLAMultiples(this->cScaleLatitude(lat), this->cScaleLongitude(lon), this->cScaleAltitude(alt));
		
		//map the values to integer values as you cannot have part of a pixel
		rvalue.XValue = (int) this->cSValue(this->cScaledX());
		rvalue.YValue = (int) this->cLValue(this->cScaledY());
	}

	return rvalue;
}