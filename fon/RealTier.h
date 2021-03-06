#ifndef _RealTier_h_
#define _RealTier_h_
/* RealTier.h
 *
 * Copyright (C) 1992-2011,2015,2016 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AnyTier.h"
#include "Graphics.h"
#include "TableOfReal.h"
#include "Vector.h"
Thing_declare (Interpreter);

/********** class RealPoint **********/

#include "RealTier_def.h"

autoRealPoint RealPoint_create (double time, double value);
/*
	Postconditions:
		result -> time == time;
		result -> value == value;
*/

/********** class RealTier **********/

void RealTier_init (RealTier me, double tmin, double tmax);
autoRealTier RealTier_create (double tmin, double tmax);
autoRealTier RealTier_createWithClass (double tmin, double tmax, ClassInfo klas);
/*
	Postconditions:
		result -> xmin == tmin;
		result -> xmax == tmax;
		result -> points.size == 0;
*/

double RealTier_getValueAtIndex (RealTier me, long point);
/* No points or 'point' out of range: NUMundefined. */

double RealTier_getValueAtTime (RealTier me, double t);
/* Inside points: linear intrapolation. */
/* Outside points: constant extrapolation. */
/* No points: NUMundefined. */

double RealTier_getMinimumValue (RealTier me);
double RealTier_getMaximumValue (RealTier me);
double RealTier_getArea (RealTier me, double tmin, double tmax);
double RealTier_getMean_curve (RealTier me, double tmin, double tmax);
double RealTier_getMean_points (RealTier me, double tmin, double tmax);
double RealTier_getStandardDeviation_curve (RealTier me, double tmin, double tmax);
double RealTier_getStandardDeviation_points (RealTier me, double tmin, double tmax);

void RealTier_addPoint (RealTier me, double t, double value);
void RealTier_draw (RealTier me, Graphics g, double tmin, double tmax,
	double ymin, double ymax, int garnish, const char32 *method, const char32 *quantity);
autoTableOfReal RealTier_downto_TableOfReal (RealTier me, const char32 *timeLabel, const char32 *valueLabel);

void RealTier_interpolateQuadratically (RealTier me, long numberOfPointsPerParabola, int logarithmically);

autoTable RealTier_downto_Table (RealTier me, const char32 *indexText, const char32 *timeText, const char32 *valueText);
autoRealTier Vector_to_RealTier (Vector me, long channel, ClassInfo klas);
autoRealTier Vector_to_RealTier_peaks (Vector me, long channel, ClassInfo klas);
autoRealTier Vector_to_RealTier_valleys (Vector me, long channel, ClassInfo klas);
autoRealTier PointProcess_upto_RealTier (PointProcess me, double value, ClassInfo klas);

void RealTier_formula (RealTier me, const char32 *expression, Interpreter interpreter, RealTier thee);
void RealTier_multiplyPart (RealTier me, double tmin, double tmax, double factor);
void RealTier_removePointsBelow (RealTier me, double level);

/* End of file RealTier.h */
#endif
