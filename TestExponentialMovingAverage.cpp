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
 * 11/7/2013   | SANDEEP KALRA	| Application to Test Expo Mov.Average
 *             |                |
 *--------------------------------------------------------------------*/

#include "ExponentialMovingAverage.h"
using namespace std;
using namespace stdfin;
int main()
{
	vector<float> f = { 2.0,21.89,20.1,1.122,9.1,8.22,84.1,2.0,2.1,2.2,2.1,2,1};
	//vector<float> f = { 1,1,1,1,1,1,1,1,1,1,1};
	vector<float> results = ExponentialMovingAverage<float, int, vector, vector<float>::const_iterator> ( f , 0 , f.size(), int(3));
	cout<<"\ndatums:"<<endl;
	for(float i: f) cout<<" "<<i;
	cout<<endl;
	cout<<"\nresults:"<<endl;
	for(float i: results) cout<<" "<<i;
	cout<<endl;
}
/* g++ -std=c++11 TestExponentialMovingAverage.cpp -o TestEMA.bin */
