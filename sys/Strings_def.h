/* Strings_def.h
 *
 * Copyright (C) 1992-2011,2015 Paul Boersma
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


#define ooSTRUCT Strings
oo_DEFINE_CLASS (Strings, Daata)

	oo_LONG (numberOfStrings)
	oo_STRING_VECTOR (strings, numberOfStrings)

	#if oo_DECLARING
		void v_info ()
			override;
		bool v_hasGetVectorStr ()
			override { return true; }
		const char32 * v_getVectorStr (long icol)
			override;
	#endif

oo_END_CLASS (Strings)
#undef ooSTRUCT


/* End of file Strings_def.h */
