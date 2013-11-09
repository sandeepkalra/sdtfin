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
 * 11/9/2013   | SANDEEP KALRA  | Date (can later be used as index for price)
 *             |                |
 *--------------------------------------------------------------------*/

#ifndef __STDFIN_DATE_H__
#define __STDFIN_DATE_H__

namespace stdfin {
	enum  Duration{ DAY, MONTH, YEAR, HR, MIN, SEC } ;

	class Date {
		int d; // range [1-31], except feb [1-28/29]
		int m; // range [1-12]
		int y; // 4 digit, range [1970-3000]
		int hr;  // range 0-23
		int min; // range 0-59
		int sec; // range 0-59

		public:

		~Date() { }
		explicit Date (int dd=1, int mm=1, int yyyy=1970,  int h=0,  int m=0,  int s=0) : d{dd}, m{mm}, y{yyyy}, min(m), hr(h), sec(s) { SmallestHop(0,0,0); SmallestDuration(); }
		Date(const Date&v):d{v.d},m{v.m},y{v.y},min{v.min},hr{v.hr},sec{v.sec} { }
		Date(const Date&&v):d{v.d},m{v.m},y{v.y},min{v.min},hr{v.hr},sec{v.sec} { }
		Date& operator++(); // increment by smallest hop ( for smallest duration, and subsequent sub-duration ).
		Date& operator--(); // decrement by smallest hop ( for smallest duration, and subsequent sub-duration )
		Date& operator++(int); 
		Date& operator--(int);
		Date& operator+(const Date&v); 
		Date& operator-(const Date&v);
		
		// if smallest duration is "HR", and smallest hop is  1 month 5 day, 1 hr 20 min 40 sec, then we pick operator()++/-- as 1 hr, 20 min, 40 sec
		// if smallest duration is "DAY", and smallest hop is  1 month 5 day, 1 hr 20 min 40 sec, then we pick operator()++/-- as "5 day" + 1 hr,  20 min, 40 sec
		void SmallestDuration(stdfin::Duration=SEC) {}
		void SmallestHop(int dd=0, int mm=0, int yyyy=0, int h=0, int m=0, int s=30) {}

	};

}; //namespace

#endif //__STDFIN_DATE_H__
