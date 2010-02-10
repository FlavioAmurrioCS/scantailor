/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C)  Joseph Artsimovich <joseph.artsimovich@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DESPECKLE_H_
#define DESPECKLE_H_

class Dpi;
class TaskStatus;
class DebugImages;

namespace imageproc
{
	class BinaryImage;
}

class Despeckle
{
public:
	enum Level { CAUTIOUS, NORMAL, AGGRESSIVE };

	/**
	 * \brief Removes small speckles from a binary image.
	 *
	 * \param src The image to despeckle.  Must not be null.
	 * \param big_object_threshold The number of pixels which indicates
	 *        the object having them is definitely not a speckle.
	 *        Objects that have less pixels may or may not be considered
	 *        as speckles, but if all objects consist of less pixels
	 *        then this threshold, all of them will be considered as speckles
	 *        and be removed.
	 * \param dbg An optional sink for debugging images.
	 * \return The despeckled image.
	 */
	static imageproc::BinaryImage despeckle(
		imageproc::BinaryImage const& src, Dpi const& dpi, Level level,
		TaskStatus const& status, DebugImages* dbg = 0);

	/**
	 * \brief A slightly faster, in-place version of despeckle().
	 */
	static void despeckleInPlace(
		imageproc::BinaryImage& image, Dpi const& dpi,
		Level level, TaskStatus const& status, DebugImages* dbg = 0);
};

#endif
