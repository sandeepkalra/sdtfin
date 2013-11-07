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
 * 11/5/2013   | SANDEEP KALRA	| Application for testing SMA
 *             |                |
 *--------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include "SimpleMovingAverage.h"
using namespace std;
using namespace stdfin;
vector<float> v {1.1, 21.0, 81.91, 211.09, 83.63, 21.0 , 9.0,-5.0};

int main()
{
	vector<float> results = SimpleMovingAverage<float, int, vector, vector<float>::const_iterator> ( v, 0, 8, 2);
	for(float f: results) cout<<" " << f;
	cout<<endl<<endl;
}
/* g++ -std=c++11 TestSimpleMovingAverage.cpp -o TestSMA.bin */
