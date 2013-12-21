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
 * 11/5/2013   | SANDEEP KALRA	| Simple Moving Average.Draft0.02
 *             |                |
 *--------------------------------------------------------------------*/

#ifndef _SIMPLE_MOVING_AVERAGE_H_
#define _SIMPLE_MOVING_AVERAGE_H_

#include <algorithm>

namespace stdfin 
{

	template< typename SampleType, typename IndexType,
		  template <typename E, typename = std::allocator<E>> class CONTAINER, 
		  typename Iterator >
		const CONTAINER<SampleType> SimpleMovingAverage ( 
			const CONTAINER<SampleType>& v, 
			IndexType start_pos, 
			IndexType end_pos, 
			IndexType window)
		{

			CONTAINER<SampleType> results; 
			SampleType result = SampleType(); //temp

			// check boundary
			if(start_pos < SampleType() || start_pos > v.size()) start_pos = SampleType();
			if(end_pos < SampleType() || end_pos > v.size()) end_pos = v.size();
			if(start_pos+window > end_pos) window = end_pos - start_pos;
			if(start_pos+window > v.size()) window = v.size()-start_pos;
			if(window <=  SampleType() ) window = SampleType() + 1;

			// set indexes correctly
			Iterator i = v.begin(); 
			Iterator j = v.begin(); 
			Iterator k = v.begin(); 
			std::advance(i, start_pos);
			std::advance(j, window);
			std::advance(k, end_pos);

			// First, Calcluate simple average
			result = std::accumulate<Iterator, SampleType>(i,j, SampleType())/window;
			results.push_back(result);

			// Now, Calculate rolling average!
			while(i<k)
			{
				result = result + (*j - *i)/window;
				results.push_back(result);
				if(j+1!=v.end()) ++j; // peek ahead
				else window--;
				if(!window) break; //cannot allow divide by zero!
				if(i!=j) ++i;
			}
			return move(results);
		} 
};

#endif // _SIMPLE_MOVING_AVERAGE_H_
