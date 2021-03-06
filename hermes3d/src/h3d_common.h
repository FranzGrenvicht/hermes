// This file is part of Hermes3D.
//
// Copyright (c) 2009 hp-FEM group at the University of Nevada, Reno (UNR).
// Email: hpfem-group@unr.edu, home page: http://hpfem.org/.
//
// Hermes3D is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 2 of the License,
// or (at your option) any later version.
//
// Hermes3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hermes3D. If not, see <http://www.gnu.org/licenses/>.

#ifndef __H3D_COMMON_H_
#define __H3D_COMMON_H_

#include "../../hermes_common/common.h"

// H3D-specific error codes.
#define H3D_ERR_FACE_INDEX_OUT_OF_RANGE         "Face index out of range."
#define H3D_ERR_EDGE_INDEX_OUT_OF_RANGE         "Edge index out of range."
#define H3D_ERR_TETRA_NOT_COMPILED              "hermes3d was not built with tetra elements."
#define H3D_ERR_HEX_NOT_COMPILED                "hermes3d was not built with hex elements."
#define H3D_ERR_PRISM_NOT_COMPILED              "hermes3d was not built with prism elements."

// 1D element modes
enum ElementMode1D {
	MODE_LINE = 0
};

// 2D element modes
enum ElementMode2D {
	MODE_TRIANGLE = 0,
	MODE_QUAD = 1
};

// 3D element modes
enum ElementMode3D {
	MODE_TETRAHEDRON = 0,
	MODE_HEXAHEDRON = 1,
	MODE_PRISM = 2
};

enum ESpaceType {
	H1 = 1,
	Hcurl = 2,
	Hdiv = 3,
	L2 = 4
};

// points
struct HERMES_API Point1D {
	double x;			// coordinates of a point
};

struct HERMES_API Point2D {
	double x, y;		// coordinates of a point
};

struct HERMES_API Point3D {
	double x, y, z;		// coordinates of a point
};

inline double dot_product(const Point3D &a, const Point3D &b) { return a.x * b.x + a.y * b.y + a.z * b.z;}

inline Point3D cross_product(Point3D a, Point3D b) {
	Point3D r = {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
	return r;
}

inline Point3D lin_comb(Point3D a, double coef_a, Point3D b, double coef_b) {
	Point3D r = {
		coef_a * a.x + coef_b * b.x,
		coef_a * a.y + coef_b * b.y,
		coef_a * a.z + coef_b * b.z,
	};
	return r;
}

inline double norm(const Point3D &pt) { return sqrt(dot_product(pt, pt)); }

inline Point3D normalize(const Point3D &pt) {
	double n = norm(pt);
	Point3D res = { pt.x / n, pt.y / n, pt.z / n };
	return res;
}


struct Vector3D {
	scalar x, y, z;		// coordinates of a point

	Vector3D() {
		x = y = z = 0;
	}

	Vector3D(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	scalar dot_product(Vector3D vec2) {return x * vec2.x + y * vec2.y + z * vec2.z;};
	scalar dot_product(Point3D vec2) {return x * vec2.x + y * vec2.y + z * vec2.z;};
	double norm() { return sqrt(REAL(dot_product(*this)));};
	void cross_product(Vector3D a, Vector3D b) {
		x = a.y * b.z - a.z * b.y;
		y = a.z * b.x - a.x * b.z;
		z = a.x * b.y - a.y * b.x;
	}
	void cross_product(Point3D a, Vector3D b) {
		x = a.y * b.z - a.z * b.y;
		y = a.z * b.x - a.x * b.z;
		z = a.x * b.y - a.y * b.x;
	}
	void cross_product(Vector3D a, Point3D b) {
		x = a.y * b.z - a.z * b.y;
		y = a.z * b.x - a.x * b.z;
		z = a.x * b.y - a.y * b.x;
	}

	void normalize(){
		double n = norm();
		x /= n;
		y /= n;
		z /= n;
	}

	void subtract(Vector3D b){
		x -= b.x;
		y -= b.y;
		z -= b.z;
	}
};

// maximal polynomial order of elements
#define H3D_MAX_ELEMENT_ORDER							10

#endif
