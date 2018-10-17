#include <cmath>
#include "MeanValue.h"

/*
 * Tolerance for comparing two values expressed in percent of these
 * values [default value is 1%]
 */
template<typename T, typename R>
double MeanValue<T, R>::_relTolerance = 0.01;

/*
 * Default Value to reset minimum value to
 * (a high value so that next value will have reasonable chances to be
 * less than this value), so the maximum values of type T should fit.
 */
template<typename T, typename R>
const T MeanValue<T, R>::_minDefault = numeric_limits<T>::max();

/*
 * Default value to reset maximum value to
 * (a low value so that next value will have reasonable chances to be
 * greater than this value), so the lowest value of type T should fit
 */
template<typename T, typename R>
const T MeanValue<T, R>::_maxDefault = numeric_limits<T>::lowest();

/*
 * PRIVATE Valued constructor in order to create a mean value to be
 * compared with other mean values (typically through a factory method
 * providing a constant mean value)
 * @param mean the mean value to set
 * @param std the std value to set
 * @param min the min value to set
 * @param max the max value to set
 * @post internal attributes have been initialized according to
 * arguments.
 * @see #get(const R &,const R &, const T &, const T &);
 */
template<typename T, typename R>
MeanValue<T, R>::MeanValue(const R & mean,
                           const R & std,
                           const T & min,
                           const T & max,
                           const long count) :
	_mean(mean),
	_meanSquare(R(std*std+mean*mean)),
	_count(count),
	_min(min),
	_max(max)
{
	// Ne rien écrire ici
}

/*
 * Default Constructor.
 * @post Attributes for computing mean & std are set to 0, min & max
 * attributes are set to their default values, count is set to 0
 */
template<typename T, typename R>
MeanValue<T, R>::MeanValue() :
	_mean(0.0),
	_meanSquare(0.0),
	_count(0L),
	_min(_minDefault),
	_max(_maxDefault)
//	 Or
//	 MeanValue(0, 0, _minDefault, _mDefault, 0)// TODO Replace with correct values
{
	// Ne rien écrire ici
}

/*
 * Copy constructor
 * @param mv the other mean value to copy
 */
template<typename T, typename R>
MeanValue<T, R>::MeanValue(const MeanValue<T, R> & mv) :
	_mean(mv._mean),
	_meanSquare(mv._meanSquare),
	_count(mv._count),
	_min(mv._min),
	_max(mv._max)
//	 Or
//	 MeanValue(mv._mean, mv._meanSquare, mv._min, mv._max, mv._count)// TODO Replace with correct values
{
	// Ne rien écrire ici
}

/*
 * Move constructor
 * @param mv the other mean value to move
 * @post reset has been performed on the moved mean value
 */
template<typename T, typename R>
MeanValue<T, R>::MeanValue(MeanValue<T, R> && mv) :
	_mean(mv._mean),
	_meanSquare(mv._meanSquare),
	_count(mv._count),
	_min(mv._min),
	_max(mv._max)
//	 Or
//	 MeanValue(mv._mean, mv._meanSquare, mv._min, mv._max, mv._count)// TODO Replace with correct values
{
	mv.reset();
}

/*
 * Factory method to obtain a constant mean value to be evt compared
 * with other mean values
 * @param mean the mean value to set in this constant mean value
 * @param std the std value to set in this constant mean value
 * @param min the min value to set in this constant mean value
 * @param max the max value to set in this constant mean value
 * @return a constant mean value with specified mean, std, min & max
 * and -1 count in order to avoid min() & max() to return 0 values.
 * @note Since the returned MeanValue is constant no values can be
 * accumulated with opertator () or operator +=
 */
template<typename T, typename R>
const MeanValue<T, R> MeanValue<T, R>::get(const R & mean,
                                           const R & std,
                                           const T & min,
                                           const T & max)
{
	// TODO Complete ...
	return MeanValue<T, R>(mean,std,min,max,-1);
}

/*
 * Destructor
 * Reset all values to default before destruction
 */
template<typename T, typename R>
MeanValue<T, R>::~MeanValue()
{
	this->reset();
}

/*
 * Compute mean value : E(X).
 * @return the mean value of all elements added to this MeanValue.
 */
template<typename T, typename R>
R MeanValue<T, R>::mean() const
{
	// TODO Replace by correct implementation ...
	return _mean;
}

/*
 * Compute standard deviation of values : sqrt(E(X^2) - E(X)^2).
 * @return the standard deviation of all elements added to this MeanValue.
 */
template<typename T, typename R>
R MeanValue<T, R>::std() const
{
	// TODO Replace by correct implementation : ...
	// Beware, sqrt(x) returns a NaN and generates a domain error for x < 0.

	return R(sqrt(_meanSquare-_mean*_mean));
}

/*
 * Minimum recorded value accessor
 * @return the minimum recorded value (until reset)
 * @note if no value has been taken into account yet (_count == 0)
 * then return 0;
 */
template<typename T, typename R>
T MeanValue<T, R>::min() const
{
	// TODO Replace by correct implementation ...
	if(_count==0)return 0;
	return _min;
}

/*
 * Maximum recorded value accessor
 * @return the maximum recorded value (until reset)
 * @note if no value has been taken into account yet (_count == 0)
 * then return 0;
 */
template<typename T, typename R>
T MeanValue<T, R>::max() const
{
	// TODO Replace by correct implementation ...
	if(_count==0)return 0;
	return _max;
}

/*
 * Number of values added to this mean value so far (until reset)
 * @return the number of values taken into account in this mean value
 * @note constant MeanValues provided by #get method have a -1 count
 */
template<typename T, typename R>
long MeanValue<T, R>::count() const
{

	return _count;
}

/*
 * Reset all accumulated values to 0 and (internal) min & max values
 * to their default values.
 * @see #_minDefault
 * @post after reset the following calls should provide the following
 * values:
 * 	- m.mean() should be 0
 * 	- m.std() should be 0
 * 	- m.count should be 0
 * 	- m.min() should be 0 (internal value should be set to _minDefault)
 * 	- m.max() should be 0 (internal value should be set to _maxDefault)
 */
template<typename T, typename R>
void MeanValue<T, R>::reset()
{
	_mean=R(0);
	_meanSquare=R(0);
	_count=0L;
	_min=_minDefault;
	_max=_maxDefault;
}

/*
 * Sets a new relative tolerance percentage to be used in values
 * comparison in order to decide if theses values are close enough to
 * be considered equal
 * @param tol the new tolerance percentage to set
 */
template<typename T, typename R>
void MeanValue<T, R>::tolerance(const double tol)
{
	_relTolerance = tol;
}

/*
 * Function call operator with one value.
 * Computes un updated value of the mean and std:
 * 	- E(X_n+1) = (1/(n+1))[n E(X_n) + x_n+1]
 * 	- E(X_n+1^2) = (1/(n+1))[ n E(X_n^2) + (x_n+1)^2 ]
 * @param value a value to take into account for computing mean, std,
 * min & max values.
 * @post the value has been taken into account for mean, std, min & max
 * computation and elements count has been increased by 1
 * @warning One should NOT use internal sum of values or internal
 * sum of square values of type T to compute mean and std since these
 * sums tends to grow to very large values as more values are added,
 * hence eventually triggering a value overflow which can lead to a
 * sign inversion. Maintaining E(X) and E(X^2) values instead of
 * sums can solve this problem.
 */
template<typename T, typename R>
void MeanValue<T, R>::operator ()(const T & value)
{
	_mean=R((_count*_mean+value)/(_count+1));
	_meanSquare=R((_meanSquare*_count+value*value)/(_count+1));
	_count+=1;
	_min=_min>value?value:_min;
	_max=_max>value?_max:value;

	/*
	 * TODO update internal attibutes in order to be able to provide
	 * 	- mean value of type R
	 * 	- standard deviation value ot type R
	 * 	- min value of type T
	 * 	- max value of type T
	 * 	- number of accumulated values
	 * 	Beware ! Type T could be "int" so operations on int could lead to
	 * 	overflow. Better use type R which will be float or double.
	 */
}

/*
 * Self increment operator
 * @param value a new value to be considered for computing mean, std,
 * min & max
 * @post internal attributes have been updated
 * @note does the same thing as Function call operator
 * @see #operator ()(const T & value)
 */
template<typename T, typename R>
void MeanValue<T, R>::operator +=(const T & value)
{
	// TODO Complete with previous operator ...
   operator()(value);
}

/*
 * Copy operator from another mean value
 * @param mv the mean value to copy
 * @return a reference to the current mean value
 */
template<typename T, typename R>
MeanValue<T, R> & MeanValue<T, R>::operator =(const MeanValue<T, R> & mv)
{
	// TODO Complete ...
	this->_mean=mv._mean;
	this->_meanSquare=mv._meanSquare;
	this->_count=mv._count;
	this->_min=mv._min;
	this->_max=mv._max;
	return *this;
}

/*
 * Move operator from another mean value
 * @param mv the mean value to move
 * @return a reference to the current mean value
 * @post the moved mean value "mv" has been reset
 */
template<typename T, typename R>
MeanValue<T, R> & MeanValue<T, R>::operator =(MeanValue<T, R> && mv)
{
	// TODO Complete ...
	operator=(mv);
	mv.reset();
	return *this;
}

/*
 * Cast operator to result type (R)
 * @return the mean value as provided by mean() method
 * @see #mean()
 */
template<typename T, typename R>
MeanValue<T, R>::operator R() const
{
	// TODO Replace by correct implementation
	return mean();
}

/*
 * Test the equality of the current mean value with another one
 * according to the tolerance percentage set by the
 * tolerance(const double) method
 * @param mv the other mean value to test
 * @return true if all mean, std, min & max values are in the range
 * of the tolerance
 * @see #tolerance(const double)
 * @see checkClose(const T & val1, const T & val2, const double relTol, const T & absTol)
 */
template<typename T, typename R>
bool MeanValue<T, R>::operator ==(const MeanValue<T, R> & mv) const
{
	/*
	 * TODO Replace with correct implementation :
	 * Compare values using checkClose function
	 */
	bool dummy = checkClose(_mean, mv._mean, _relTolerance, _absTolerance) &&
			 checkClose(_meanSquare, mv._meanSquare, _relTolerance, _absTolerance)&&
			 checkClose(R(_min),R( mv._min), _relTolerance, _absTolerance)&&
			 checkClose(R(_max),R( mv._max), _relTolerance, _absTolerance);
	return !dummy;
}

/*
 * Test the difference of the current mean value with another one
 * according to the tolerance percentage set by the tolerance(const double)
 * method
 * @param mv the other mean value to test
 * @return false if all mean, std, min & max values are in the range
 * of the tolerance
 * @post the negation of the previous operator has been used to ensure
 * symmetry
 * @see #tolerance(const double)
 */
template<typename T, typename R>
bool MeanValue<T, R>::operator !=(const MeanValue<T, R> & mv) const
{
	/*
	 * TODO Replace with correct implementation :
	 * Compare values using the previous operator
	 */
	return !(this->operator==(mv));
}

/*
 * Output operator for MeanValue
 * @param out the output stream
 * @param mv the MeanValue to print on the output stream
 * @return a reference to the current output stream
 * @post put mean value ± std value on the stream
 * @code
 * 	MeanValue<int> m;
 * 	// Add 2500 values within [1..10]
 * 	...
 * 	cout << m << endl;
 * 	// should provide an output looking like the following line :
 * 	// 5.49998 ± 2.8723 [1...10](2500)
 * 	// |         |       |   |   |
 * 	// |         |       |   |   number values accumulated so far
 * 	// |         |       |   max recorded value
 * 	// |         |       min recorded value
 * 	// |         std value
 * 	// mean value
 * @endcode
 */
template<typename T, typename R>
ostream & operator <<(ostream & out, const MeanValue<T, R> & mv)
{
	// TODO Complete (without < or >) to get the following output
	// <mean value> ± <std value> [<min value>...<max value>](<count value>)
	// Please note that spaces are required
	out << mv.mean()<<" ± "<<mv.std()<<" ["<<mv.min()<<"..."<<mv.max()<<"]("<<mv.count()<<")";

	return out;
}

/*
 * Compare two values equality within a tolerance expressed in percent
 * @param val1 the first value to compare
 * @param val2 the second value to compare
 * @param relTol relative tolerance for comparing two values
 * @param absTol Absolute tolerance for comparing two values
 * @return true if val1 == val2 evt within relative tolerance or absolute
 * tolerance when relative tolerance is not applicable (around 0)
 */
template<typename T>
bool checkClose(const T & val1,
                const T & val2,
                const double relTol,
                const T & absTol)
{
	if (val1 == val2)
	{
//		clog << "Comparing " << val1 << " == " << val2 << endl;
		return true;
	}

	double val1d = double(val1);
	double val2d = double(val2);

	double absoluteError = abs(val1d - val2d);

//	clog << "Comparing(" << val1 << ", " << val2 << ") absolute error = "
//	     << absoluteError << (absoluteError < absTol ? " < " : " >= ")
//	     << absTol << endl;

	if (absoluteError < double(absTol))
	{
		return true;
	}

	double relativeError;
	if (abs(val2d) > abs(val1d))
	{
		relativeError = abs((val1d - val2d) / val2d);
	}
	else
	{
		relativeError = abs((val1d - val2d) / val1d);
	}

//	clog << "Comparing(" << val1 << ", " << val2 << ") relative error = "
//	     << relativeError << (relativeError < relTol ? " < " : " >= ")
//	     << relTol << endl;

	if (relativeError <= relTol)
	{
		return true;
	}

	return false;
}

// --------------------------------------------------------------------
// Template specializations for known types
// --------------------------------------------------------------------

/**
 * Absolute tolerance when accumulating int values and providing double
 * mean and std values
 */
template<> double MeanValue<int, double>::_absTolerance = 1;

/**
 * Absolute tolerance when accumulating float values and providing double
 * mean and std values
 */
template<> double MeanValue<float, double>::_absTolerance = 0.01;

/**
 * Absolute tolerance when accumulating double values and providing double
 * mean and std values
 */
template<> double MeanValue<double, double>::_absTolerance = 0.001;

/**
 * Absolute tolerance when accumulating int values and providing float
 * mean and std values
 */
template<> float MeanValue<int, float>::_absTolerance = 1;

/**
 * Absolute tolerance when accumulating float values and providing float
 * mean and std values
 */
template<> float MeanValue<float, float>::_absTolerance = 0.01;

/**
 * Absolute tolerance when accumulating double values and providing float
 * mean and std values
 */
template<> float MeanValue<double, float>::_absTolerance = 0.001;

/**
 * Absolute tolerance when accumulating int values and providing int
 * mean and std values
 */
template<> int MeanValue<int, int>::_absTolerance = 1;

/**
 * Absolute tolerance when accumulating float values and providing int
 * mean and std values
 */
template<> int MeanValue<float, int>::_absTolerance = 1;

/**
 * Absolute tolerance when accumulating double values and providing int
 * mean and std values
 */
template<> int MeanValue<double, int>::_absTolerance = 1;

// ----------------------------------------------------------------------------
// Template protoinstanciations for
//	- int
//	- float
//	- double
// ----------------------------------------------------------------------------

// Proto instanciations
template class MeanValue<int>;
template class MeanValue<float>;
template class MeanValue<double>;
template class MeanValue<int, float>;
template class MeanValue<double, float>;

// Output operators proto-instanciations
template ostream & operator << (ostream &, const MeanValue<int> &);
template ostream & operator << (ostream &, const MeanValue<float> &);
template ostream & operator << (ostream &, const MeanValue<double> &);
template ostream & operator << (ostream &, const MeanValue<int, float> &);
template ostream & operator << (ostream &, const MeanValue<float, float> &);
template ostream & operator << (ostream &, const MeanValue<double, float> &);
