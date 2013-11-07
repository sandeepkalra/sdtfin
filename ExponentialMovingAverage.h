/* --------------------------------------------------------------------
 * Creator: Sandeep Kalra (Sandeep.Kalra@Gmail.Com)
 * --------------------------------------------------------------------
 * Copyright(c) 2013 Sandeep Kalra
 * --------------------------------------------------------------------
 * License Term:          FREE FOR THE MANKIND    
 *
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell copies of the 
 * Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS 
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF 
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *
 * ------------+----------------+--------------------------------------
 * DATE        |   AUTHOR       |DETAILS 
 *-------------+----------------+--------------------------------------
 * 11/7/2013   | SANDEEP KALRA	| Exponential Moving Average.Draft0.01
 *             |                |
 *--------------------------------------------------------------------*/

#ifndef _EXPONENTIAL_MOVING_AVERAGE_H__
#define _EXPONENTIAL_MOVING_AVERAGE_H__

#include <iostream>
#include <algorithm>

namespace stdfin 
{
	template< typename SampleType, typename IndexType,
		template <typename E, typename = std::allocator<E>> class CONTAINER, 
		typename Iterator >
			const CONTAINER<SampleType> ExponentialMovingAverage 
			(
			 const CONTAINER<SampleType>& v, 
			 IndexType start_pos, 
			 IndexType end_pos, 
			 float alpha // coefficient can be anything between 0.0 and 1.0 (Another way is 2/(N+1)), wish i could use 'explicit' here
			)
			{
				CONTAINER<SampleType> results; 

				// check boundary
				if(alpha > 1 || alpha < 0) alpha = 0.5; float one_minus_alpha = 1.0 - alpha;
				if(start_pos < SampleType() || start_pos > v.size()) start_pos = SampleType();
				if(end_pos < SampleType() || end_pos > v.size()) end_pos = v.size();

				// set indexes correctly
				Iterator i = v.begin(); 
				Iterator j = v.begin(); 
				std::advance(i, start_pos);
				std::advance(j, end_pos);

				SampleType result  = *i;  //  t=1; S1 = Y1 (wikipedia)
				SampleType temp;  //  t=1; S1 = Y1 (wikipedia)
				results.push_back(result);

				for(Iterator idx = i+1; idx != j; ++idx)  // t>1; Sn = alpha x Yt  + (1- alpha) x Y(t-1)
				{
					temp = (result)*(one_minus_alpha) + (*idx) * (alpha);
					result = temp;
					results.push_back(result);
				}
				return std::move(results); 
			}

	// Another version with 4th Argument as "int N" (ref: Wikipedia)
	template< typename SampleType, typename IndexType,
		template <typename E, typename = std::allocator<E>> class CONTAINER, 
		typename Iterator >
			const CONTAINER<SampleType> ExponentialMovingAverage 
			(
			 const CONTAINER<SampleType>& v, 
			 IndexType start_pos, 
			 IndexType end_pos, 
			 int N
			)
			{
				if (N < int()) N = int();
				float alpha = (double(2))/(N+1); 
				return std::move(stdfin::ExponentialMovingAverage<SampleType,IndexType,CONTAINER,Iterator>(v,start_pos,end_pos,float(alpha)));
			}
};



#endif // _EXPONENTIAL_MOVING_AVERAGE_H__
