#include <pebble.h>
#include "fp.h"

typedef struct {
	uint16_t p0, p1, p2;
} Facet;

typedef struct {
	fp32_t x, y, z;
} GPoint3;

#include "Teapot.h"

#define M_PI 3.14159265358979323846
#define TIMER_DELAY 30
#define EYEZ 600

#define SIM

static Window *window;
static Layer *rootLayer, *layer;
//static TextLayer *textLayer;
//static char text[20];
static AppTimer *timer;
static int32_t a=0, b=0, c=0, da=119, db=-211, dc=87;
static int32_t cosa, sina, cosb, sinb, cosc, sinc;

#ifndef SIM
static const uint16_t __ACOS[1001] = {
	32768, 32108, 31834, 31624, 31447, 31291, 31150, 31020, 30899, 30785, 30678, 30576, 30478, 30384, 30293, 30206, 30122, 30040, 29960, 29883,
	29807, 29734, 29662, 29592, 29523, 29455, 29389, 29324, 29260, 29198, 29136, 29075, 29016, 28957, 28899, 28842, 28785, 28730, 28675, 28621,
	28567, 28514, 28462, 28410, 28359, 28308, 28258, 28209, 28160, 28111, 28063, 28015, 27968, 27922, 27875, 27829, 27784, 27738, 27694, 27649,
	27605, 27561, 27518, 27475, 27432, 27390, 27348, 27306, 27264, 27223, 27182, 27141, 27101, 27060, 27020, 26981, 26941, 26902, 26863, 26824,
	26786, 26747, 26709, 26671, 26633, 26596, 26559, 26522, 26485, 26448, 26411, 26375, 26339, 26303, 26267, 26231, 26196, 26161, 26125, 26090,
	26056, 26021, 25986, 25952, 25918, 25884, 25850, 25816, 25782, 25749, 25715, 25682, 25649, 25616, 25583, 25550, 25518, 25485, 25453, 25420,
	25388, 25356, 25324, 25292, 25261, 25229, 25198, 25166, 25135, 25104, 25073, 25042, 25011, 24980, 24949, 24919, 24888, 24858, 24828, 24798,
	24767, 24737, 24708, 24678, 24648, 24618, 24589, 24559, 24530, 24500, 24471, 24442, 24413, 24384, 24355, 24326, 24297, 24269, 24240, 24211,
	24183, 24155, 24126, 24098, 24070, 24042, 24014, 23986, 23958, 23930, 23902, 23874, 23847, 23819, 23791, 23764, 23736, 23709, 23682, 23655,
	23627, 23600, 23573, 23546, 23519, 23492, 23466, 23439, 23412, 23385, 23359, 23332, 23306, 23279, 23253, 23226, 23200, 23174, 23148, 23122,
	23095, 23069, 23043, 23017, 22992, 22966, 22940, 22914, 22888, 22863, 22837, 22811, 22786, 22760, 22735, 22710, 22684, 22659, 22634, 22608,
	22583, 22558, 22533, 22508, 22483, 22458, 22433, 22408, 22383, 22358, 22333, 22309, 22284, 22259, 22235, 22210, 22185, 22161, 22136, 22112,
	22087, 22063, 22039, 22014, 21990, 21966, 21941, 21917, 21893, 21869, 21845, 21821, 21797, 21773, 21749, 21725, 21701, 21677, 21653, 21629,
	21606, 21582, 21558, 21534, 21511, 21487, 21463, 21440, 21416, 21393, 21369, 21346, 21322, 21299, 21275, 21252, 21229, 21205, 21182, 21159,
	21136, 21112, 21089, 21066, 21043, 21020, 20997, 20974, 20951, 20927, 20904, 20882, 20859, 20836, 20813, 20790, 20767, 20744, 20721, 20699,
	20676, 20653, 20630, 20608, 20585, 20562, 20540, 20517, 20494, 20472, 20449, 20427, 20404, 20382, 20359, 20337, 20314, 20292, 20269, 20247,
	20225, 20202, 20180, 20158, 20135, 20113, 20091, 20069, 20046, 20024, 20002, 19980, 19958, 19936, 19913, 19891, 19869, 19847, 19825, 19803,
	19781, 19759, 19737, 19715, 19693, 19671, 19649, 19627, 19605, 19583, 19562, 19540, 19518, 19496, 19474, 19452, 19431, 19409, 19387, 19365,
	19344, 19322, 19300, 19278, 19257, 19235, 19213, 19192, 19170, 19149, 19127, 19105, 19084, 19062, 19041, 19019, 18998, 18976, 18954, 18933,
	18911, 18890, 18869, 18847, 18826, 18804, 18783, 18761, 18740, 18718, 18697, 18676, 18654, 18633, 18612, 18590, 18569, 18548, 18526, 18505,
	18484, 18462, 18441, 18420, 18399, 18377, 18356, 18335, 18314, 18292, 18271, 18250, 18229, 18208, 18186, 18165, 18144, 18123, 18102, 18081,
	18060, 18038, 18017, 17996, 17975, 17954, 17933, 17912, 17891, 17870, 17849, 17828, 17806, 17785, 17764, 17743, 17722, 17701, 17680, 17659,
	17638, 17617, 17596, 17575, 17554, 17533, 17512, 17491, 17470, 17449, 17428, 17407, 17386, 17365, 17344, 17324, 17303, 17282, 17261, 17240,
	17219, 17198, 17177, 17156, 17135, 17114, 17093, 17072, 17052, 17031, 17010, 16989, 16968, 16947, 16926, 16905, 16884, 16863, 16843, 16822,
	16801, 16780, 16759, 16738, 16717, 16696, 16676, 16655, 16634, 16613, 16592, 16571, 16550, 16530, 16509, 16488, 16467, 16446, 16425, 16404,
	16384, 16363, 16342, 16321, 16300, 16279, 16258, 16237, 16217, 16196, 16175, 16154, 16133, 16112, 16091, 16071, 16050, 16029, 16008, 15987,
	15966, 15945, 15924, 15904, 15883, 15862, 15841, 15820, 15799, 15778, 15757, 15736, 15715, 15695, 15674, 15653, 15632, 15611, 15590, 15569,
	15548, 15527, 15506, 15485, 15464, 15443, 15423, 15402, 15381, 15360, 15339, 15318, 15297, 15276, 15255, 15234, 15213, 15192, 15171, 15150,
	15129, 15108, 15087, 15066, 15045, 15024, 15003, 14982, 14961, 14939, 14918, 14897, 14876, 14855, 14834, 14813, 14792, 14771, 14750, 14729,
	14707, 14686, 14665, 14644, 14623, 14602, 14581, 14559, 14538, 14517, 14496, 14475, 14453, 14432, 14411, 14390, 14368, 14347, 14326, 14305,
	14283, 14262, 14241, 14219, 14198, 14177, 14155, 14134, 14113, 14091, 14070, 14049, 14027, 14006, 13984, 13963, 13941, 13920, 13898, 13877,
	13856, 13834, 13813, 13791, 13769, 13748, 13726, 13705, 13683, 13662, 13640, 13618, 13597, 13575, 13554, 13532, 13510, 13489, 13467, 13445,
	13423, 13402, 13380, 13358, 13336, 13315, 13293, 13271, 13249, 13227, 13205, 13184, 13162, 13140, 13118, 13096, 13074, 13052, 13030, 13008,
	12986, 12964, 12942, 12920, 12898, 12876, 12854, 12831, 12809, 12787, 12765, 12743, 12721, 12698, 12676, 12654, 12632, 12609, 12587, 12565,
	12542, 12520, 12498, 12475, 12453, 12430, 12408, 12385, 12363, 12340, 12318, 12295, 12273, 12250, 12227, 12205, 12182, 12159, 12137, 12114,
	12091, 12068, 12046, 12023, 12000, 11977, 11954, 11931, 11908, 11885, 11863, 11840, 11816, 11793, 11770, 11747, 11724, 11701, 11678, 11655,
	11631, 11608, 11585, 11562, 11538, 11515, 11492, 11468, 11445, 11421, 11398, 11374, 11351, 11327, 11304, 11280, 11256, 11233, 11209, 11185,
	11161, 11138, 11114, 11090, 11066, 11042, 11018, 10994, 10970, 10946, 10922, 10898, 10874, 10850, 10826, 10801, 10777, 10753, 10728, 10704,
	10680, 10655, 10631, 10606, 10582, 10557, 10532, 10508, 10483, 10458, 10434, 10409, 10384, 10359, 10334, 10309, 10284, 10259, 10234, 10209,
	10184, 10159, 10133, 10108, 10083, 10057, 10032, 10007, 9981, 9956, 9930, 9904, 9879, 9853, 9827, 9801, 9775, 9750, 9724, 9698,
	9672, 9645, 9619, 9593, 9567, 9541, 9514, 9488, 9461, 9435, 9408, 9382, 9355, 9328, 9301, 9275, 9248, 9221, 9194, 9167,
	9140, 9112, 9085, 9058, 9031, 9003, 8976, 8948, 8920, 8893, 8865, 8837, 8809, 8781, 8753, 8725, 8697, 8669, 8641, 8612,
	8584, 8556, 8527, 8498, 8470, 8441, 8412, 8383, 8354, 8325, 8296, 8267, 8237, 8208, 8178, 8149, 8119, 8089, 8059, 8030,
	8000, 7969, 7939, 7909, 7879, 7848, 7818, 7787, 7756, 7725, 7694, 7663, 7632, 7601, 7569, 7538, 7506, 7475, 7443, 7411,
	7379, 7347, 7314, 7282, 7249, 7217, 7184, 7151, 7118, 7085, 7052, 7018, 6985, 6951, 6917, 6883, 6849, 6815, 6781, 6746,
	6711, 6677, 6642, 6606, 6571, 6536, 6500, 6464, 6428, 6392, 6356, 6319, 6282, 6245, 6208, 6171, 6134, 6096, 6058, 6020,
	5981, 5943, 5904, 5865, 5826, 5786, 5747, 5707, 5666, 5626, 5585, 5544, 5503, 5461, 5419, 5377, 5335, 5292, 5249, 5206,
	5162, 5118, 5073, 5029, 4983, 4938, 4892, 4845, 4799, 4752, 4704, 4656, 4607, 4558, 4509, 4459, 4408, 4357, 4305, 4253,
	4200, 4146, 4092, 4037, 3982, 3925, 3868, 3810, 3751, 3692, 3631, 3569, 3507, 3443, 3378, 3312, 3244, 3175, 3105, 3033,
	2960, 2884, 2807, 2727, 2645, 2561, 2474, 2383, 2289, 2191, 2089, 1982, 1868, 1747, 1617, 1476, 1320, 1143, 933, 659, 0
};
#endif

GPoint3 eye = { 0, 0, numToFp(EYEZ) };
GPoint3 rotatedPoint[NPOINTS];
GPoint projectedPoint[NPOINTS];

//* ZERO
#define NFACETS 576	// 32 patches * 18
Facet facet[NFACETS];
//ZERO */


#ifndef SIM
static inline float mySqrtf(const float x) {
	const float xhalf = 0.5f*x;
	union { float x; int i; 	} u;
	u.x = x;
	u.i = 0x5f3759df - (u.i >> 1);
	return x*u.x*(1.5f - xhalf*u.x*u.x);
}


static inline float length(const GPoint3 *v) {
	return mySqrtf((float)(v->x*v->x + v->y*v->y + v->z*v->z));
}

static inline int32_t myArccos(float x) {
	if (x < -1.0) x = -1.0;
	if (x > 1.0) x = 1.0;
	
	int i = (int)(500.0*(x+1.0));
	//	APP_LOG(APP_LOG_LEVEL_DEBUG, "myArccos(%4d->%3d)", (int)(x*1000), i);
	
	return __ACOS[i];
}

static void angles(const GPoint3 *v, int32_t *ax, int32_t *ay, int32_t *az) {
	static int32_t TRIG_PI = TRIG_MAX_ANGLE/2;
	static int32_t TRIG_HALFPI = TRIG_MAX_ANGLE/4;
	
	float s = length(v);
	*ax = myArccos((float)v->y/s) + TRIG_PI;
	*ay = myArccos((float)v->x/s) - TRIG_HALFPI;
	*az = 0;

	//	APP_LOG(APP_LOG_LEVEL_DEBUG, "length(%d, %d, %d) = %d / angles : %d %d %d", v->x, v->y, v->z, (int)s, (int)*ax, (int)*ay, (int)*az);
}
#endif

static inline void rotatePoint(const GPoint3 *P, GPoint3 *R) {
	GPoint3 T, U;
	
	T.x = P->x;
	T.y = fpMul(P->y, cosa) + fpMul(P->z, sina);
	T.z = fpMul(P->z, cosa) - fpMul(P->y, sina);
	
	U.x = fpMul(T.x, cosb) - fpMul(T.z, sinb);
	U.y = T.y;
	U.z = fpMul(T.x, sinb) + fpMul(T.z, cosb);
	
	R->x = fpMul(U.x, cosc) + fpMul(U.y, sinc);
	R->y = fpMul(U.y, cosc) - fpMul(U.x, sinc);
	R->z = U.z;
	
	//APP_LOG(APP_LOG_LEVEL_DEBUG, "(%d, %d, %d) -> (%d, %d, %d)", (int)P->x, (int)P->y, (int)P->z, (int)R->x, (int)R->y, (int)R->z);
}

#define SCALE 20

static inline void projectPoint(const GPoint3 *P, GPoint *S) {
	// Avoid negative values for projection
	fp32_t z = fpAddInt(P->z, 3);
	fp32_t numX = fpMulInt(P->x, EYEZ);
	fp32_t numY = fpMulInt(P->y, EYEZ);
	fp32_t denom = fpAdd(eye.z, z);
	fp32_t X = fpDiv(numX, denom);
	fp32_t Y = fpDiv(numY, denom);
	
	S->x = fpToInt(fpMulInt(X, SCALE)) + 72;
	S->y = fpToInt(fpMulInt(Y, SCALE)) + 84;
	
/*	APP_LOG(APP_LOG_LEVEL_DEBUG, "(%d, %d, %d) -> (%d, %d) | z=%d, numX=%d, numY=%d, denom=%d, X=%d, Y=%d",
			(int)P->x, (int)P->y, (int)P->z, S->x, S->y,
			(int)z, (int)numX, (int)numY, (int)denom, (int)X, (int)Y	);
*/
}

/*
static inline void multVecFloat(GPoint3 *v, float f) {
	v->x *= f;
	v->y *= f;
	v->z *= f;
}
*/

static inline void normal(GPoint3 *n, int p0, int p1, int p2) {
	fp32_t ax, ay, az, bx, by, bz;

	ax = rotatedPoint[p1].x - rotatedPoint[p0].x;
	ay = rotatedPoint[p1].y - rotatedPoint[p0].y;
	az = rotatedPoint[p1].z - rotatedPoint[p0].z;
	
	bx = rotatedPoint[p2].x - rotatedPoint[p0].x;
	by = rotatedPoint[p2].y - rotatedPoint[p0].y;
	bz = rotatedPoint[p2].z - rotatedPoint[p0].z;
	
	// Normal
	n->x = fpMul(az, by) - fpMul(ay, bz);
	n->y = fpMul(ax, bz) - fpMul(az, bx);
	n->z = fpMul(ay, bx) - fpMul(ax, by);
}

/*
static inline void normalize(GPoint3 *v) {
	float l = length(v);
	
	v->x = v->x/l;
	v->y = v->y/l;
	v->z = v->z/l;
}
*/

static inline void middlePoint(GPoint3 *m, int p0, int p1) {
	m->x = fpDiv2(rotatedPoint[p0].x + rotatedPoint[p1].x);
	m->y = fpDiv2(rotatedPoint[p0].y + rotatedPoint[p1].y);
	m->z = fpDiv2(rotatedPoint[p0].z + rotatedPoint[p1].z);
}

static inline bool isVisible(int p0, int p1, int p2) {
	GPoint3 m, n;
	fp32_t dotproduct = 0;
	
	normal(&n, p0, p1, p2);
	
	middlePoint(&m, p1, p2);
	
	// This only works because eye is along Z-Axis, thus eye.x = eye.y = 0
	//v.x -= eye.x;
	//v.y -= eye.y;
	m.z -= eye.z;

	// Dot Product
	dotproduct = fpMul(m.x, n.x) + fpMul(m.y, n.y) + fpMul(m.z, n.z);
	return (dotproduct <= 0);
}

/*
static inline void addVecToPoint3(GPoint3 *d, const GPoint3 *s, const GPoint3 *v) {
	d->x = s->x + v->x;
	d->y = s->y + v->y;
	d->z = s->z + v->z;
}
*/

/*
static void drawPatch(GContext *ctx, const uint16_t *patch) {
	int i, j, p0, p1, p2, p3;
		
	for (j=0; j<PATCHDIM; j++) {
		for (i=0; i<PATCHDIM; i++) {
			p0 = patch[PATCHSIDE*j + i];
			p1 = patch[PATCHSIDE*j + i+1];
			p2 = patch[PATCHSIDE*j + i+PATCHSIDE];
			//p3 = patch[PATCHSIDE*j + i+PATCHSIDEPLUSONE];

			//if (isVisible(p0, p1, p2)) {
				graphics_draw_line(ctx, projectedPoint[p0], projectedPoint[p1]);
				graphics_draw_line(ctx, projectedPoint[p0], projectedPoint[p2]);
				//graphics_draw_line(ctx, projectedPoint[p2], projectedPoint[p3]);
			//}
			
			//if (isVisible(p1, p3, p2)) {
			//	graphics_draw_line(ctx, projectedPoint[p3], projectedPoint[p1]);
			//	graphics_draw_line(ctx, projectedPoint[p3], projectedPoint[p2]);
				//graphics_draw_line(ctx, projectedPoint[p2], projectedPoint[p1]);
			//}
		}
	}
}
*/

static inline void fillBottomFlatTriangle(GContext *ctx, GPoint *v1, GPoint *v2, GPoint *v3) {
	float d = (float)(v2->y - v1->y);
	float invslope1 = (float)(v2->x - v1->x) / d;
	float invslope2 = (float)(v3->x - v1->x) / d;

	float curx1 = v1->x;
	float curx2 = v1->x;

	for (int scanlineY = v1->y; scanlineY <= v2->y; scanlineY++) {
		graphics_draw_line(ctx, GPoint((int)curx1, scanlineY), GPoint((int)curx2, scanlineY));
		curx1 += invslope1;
		curx2 += invslope2;
	}
}

static inline void fillTopFlatTriangle(GContext *ctx, GPoint *v1, GPoint *v2, GPoint *v3) {
	float d = (float)(v3->y - v1->y);
	float invslope1 = (float)(v3->x - v1->x) / d;
	float invslope2 = (float)(v3->x - v2->x) / d;

	float curx1 = v3->x;
	float curx2 = v3->x;

	for (int scanlineY = v3->y; scanlineY > v1->y; scanlineY--) {
		curx1 -= invslope1;
		curx2 -= invslope2;
		graphics_draw_line(ctx, GPoint((int)curx1, scanlineY), GPoint((int)curx2, scanlineY));
	}
}

static inline void fillTriangle(GContext *ctx, GPoint *p) {
	GPoint v1, v2, v3, v4;
	
	// Sort points by increasing Y
	if (p[0].y < p[1].y) {
		if (p[0].y < p[2].y) {
			v1 = p[0];
			if (p[1].y < p[2].y) {
				v2 = p[1];
				v3 = p[2];
			} else {
				v2 = p[2];
				v3 = p[1];
			}
		} else {
			v1 = p[2];
			v2 = p[0];
			v3 = p[1];
		}
	} else {
		if (p[1].y < p[2].y) {
			v1 = p[1];
			if (p[0].y < p[2].y) {
				v2 = p[0];
				v3 = p[2];
			} else {
				v2 = p[2];
				v3 = p[0];
			}
		} else {
			v1 = p[2];
			v2 = p[1];
			v3 = p[0];
		}
	}

	// v1.y <= v2.y <= v3.y

	if (v2.y == v3.y) {
		fillBottomFlatTriangle(ctx, &v1, &v2, &v3);
	} else if (v1.y == v2.y) {
		fillTopFlatTriangle	(ctx, &v1, &v2, &v3);
	} else {
		v4.x = (int)(v1.x + ((float)(v2.y - v1.y) / (float)(v3.y - v1.y)) * (v3.x - v1.x));
		v4.y = v2.y;
		fillBottomFlatTriangle(ctx, &v1, &v2, &v4);
		fillTopFlatTriangle(ctx, &v2, &v4, &v3);
	}
}


#define swapFacets(a, b) { Facet t = facet[a]; facet[a] = facet[b]; facet[b] = t; }
	
static void qsortFacets(int start, int end) {
    int left = start-1;
    int right = end+1;
    const fp32_t pivot = rotatedPoint[facet[start].p0].z;
    
    if(start >= end) return;
    
    while(1) {
        do {
			right--;
		} while (rotatedPoint[facet[right].p0].z < pivot);
		
        do {
			left++;
		} while (rotatedPoint[facet[left].p0].z > pivot);
		
        if (left < right) {
			swapFacets(left, right);
		} else {
			break;
		}
    }
    qsortFacets(start, right);
    qsortFacets(right+1, end);
}

static void sortFacets() {
	qsortFacets(0, NFACETS-1);
}

static void drawFacets(GContext *ctx) {
	int i;
	GPoint trianglePoints[3];
	for (i=0; i<NFACETS; i++) {
		if (isVisible(facet[i].p0, facet[i].p1, facet[i].p2)) {
			graphics_context_set_stroke_color(ctx, GColorWhite);
			trianglePoints[0] = projectedPoint[facet[i].p0];
			trianglePoints[1] = projectedPoint[facet[i].p1];
			trianglePoints[2] = projectedPoint[facet[i].p2];
			fillTriangle(ctx, trianglePoints);

			graphics_context_set_stroke_color(ctx, GColorBlack);
			graphics_draw_line(ctx, trianglePoints[0], trianglePoints[1]);
			graphics_draw_line(ctx, trianglePoints[0], trianglePoints[2]);
			graphics_draw_line(ctx, trianglePoints[1], trianglePoints[2]);
		}
	}
}

//* ZERO
static void computeFacets() {
	int p, i, j, facetNum = 0;
	uint16_t *curPatch;
	
	for (p=0; p<NPATCHES; p++) {
		curPatch = patch[p];
		for (j=0; j<PATCHDIM; j++) {
			for (i=0; i<PATCHDIM; i++) {
				facet[facetNum].p0 = curPatch[PATCHSIDE*j + i];
				facet[facetNum].p1 = facet[facetNum+1].p2 = curPatch[PATCHSIDE*j + i+1];
				facet[facetNum].p2 = facet[facetNum+1].p1 = curPatch[PATCHSIDE*j + i+PATCHSIDE];
				facet[facetNum+1].p0 = curPatch[PATCHSIDE*j + i+PATCHSIDEPLUSONE];
				
				facetNum += 2;
			}
		}
	}
}
//ZERO */

static void updateLayer(Layer *layer, GContext *ctx) {
	int i = 0;
/*	
	int dt;
	uint32_t t1, t2;
	time_t ts;
	uint16_t tms;

	time_ms(&ts, &tms);
	t1 = 1000*(uint32_t)ts + (uint32_t)tms;
*/	
	//graphics_context_set_fill_color(ctx, GColorBlack);
	graphics_context_set_stroke_color(ctx, GColorWhite);
	
	cosa = numToFp(cos_lookup(a)) / TRIG_MAX_RATIO;
	cosb = numToFp(cos_lookup(b)) / TRIG_MAX_RATIO;
	cosc = numToFp(cos_lookup(c)) / TRIG_MAX_RATIO;
	sina = numToFp(sin_lookup(a)) / TRIG_MAX_RATIO;
	sinb = numToFp(sin_lookup(b)) / TRIG_MAX_RATIO;
	sinc = numToFp(sin_lookup(c)) / TRIG_MAX_RATIO;

	for (i=0; i<NPOINTS; i++) {
		rotatePoint(&point[i], &rotatedPoint[i]);
		projectPoint(&rotatedPoint[i], &projectedPoint[i]);
	}

	sortFacets();
	drawFacets(ctx);
/*
	for (i=0; i<NPATCHES; i++) {
		drawPatch(ctx, patch[i]);
	}
*/
/*
	time_ms(&ts, &tms);
	t2 = 1000*(uint32_t)ts + (uint32_t)tms;

	dt = t2 - t1;
	snprintf(text, sizeof(text), "%d ms", dt);
	text_layer_set_text(textLayer, text);
*/
}

static void timerCallback(void *data) {
#ifndef SIM
	static AccelData ad;
	static GPoint3 g;

	accel_service_peek(&ad);
	g.x = ad.x>>5;
	g.y = ad.y>>5;
	g.z = ad.z>>5;
	
	angles(&g, &a, &b, &c);
#else
	a += da;
	b += db;
	c += dc;
#endif

	layer_mark_dirty(layer);
	
	timer = app_timer_register(TIMER_DELAY, timerCallback, NULL);
}

/*
static void handleTick(struct tm *t, TimeUnits units_changed) {
	int h = t->tm_hour;
	hour = h;
	
	if (!clock_is_24h_style()) {
		h %= 12;
		if (h==0) h = 12;
	}
	
	d[0] = h/10;
	d[1] = h%10;
	d[2] = t->tm_min/10;
	d[3] = t->tm_min%10;
	d[4] = t->tm_sec/10;
	d[5] = t->tm_sec%10;
}
*/

#ifndef SIM
static void handleAccel(AccelData *data, uint32_t num_samples) {
	// return;
}
#endif

static void init(void) {
	time_t now;
	
	time(&now);
	//handleTick(localtime(&now), 0);

	//convertPointsToFp();
//* ZERO
	computeFacets();
//ZERO */
	window = window_create();
	window_set_background_color(window, GColorBlack);
	window_stack_push(window, true);
	rootLayer = window_get_root_layer(window);

	layer = layer_create(GRect(0, 0, 144, 168));
	layer_set_update_proc(layer, updateLayer);
	layer_add_child(rootLayer, layer);
	
/*
	textLayer = text_layer_create(GRect(0, 148, 144, 20));
	text_layer_set_background_color(textLayer, GColorClear);
	text_layer_set_text_color(textLayer, GColorWhite);
	text_layer_set_text(textLayer, "Patch 0");
	layer_add_child(rootLayer, text_layer_get_layer(textLayer));
*/
	//tick_timer_service_subscribe(SECOND_UNIT, handleTick);

#ifndef SIM
	accel_data_service_subscribe(0, handleAccel);
#endif
	timerCallback(NULL);
}

static void deinit(void) {
	app_timer_cancel(timer);
#ifndef SIM
	accel_data_service_unsubscribe();
#endif
	//tick_timer_service_unsubscribe();
	layer_destroy(layer);
	//text_layer_destroy(textLayer);
	window_destroy(window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
	
	return 0;
}
