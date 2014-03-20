#define NPOINTS 306

GPoint3 point[NPOINTS] = {
	{ 358, -230, 0 }, { 310, -230, -182 }, { 182, -230, -310 }, { 0, -230, -358 }, 
	{ 359, -245, 0 }, { 306, -252, -180 }, { 180, -252, -306 }, { 0, -245, -359 }, 
	{ 368, -245, 0 }, { 317, -252, -186 }, { 186, -252, -317 }, { 0, -245, -368 }, 
	{ 384, -230, 0 }, { 304, -230, -174 }, { 174, -230, -304 }, { 0, -230, -384 }, 
	{ -182, -230, -310 }, { -310, -230, -182 }, { -358, -230, 0 }, { -180, -250, -308 }, 
	{ -306, -252, -180 }, { -359, -245, 0 }, { -186, -250, -317 }, { -317, -252, -186 }, 
	{ -368, -245, 0 }, { -174, -230, -304 }, { -304, -230, -174 }, { -384, -230, 0 }, 
	{ -310, -230, 182 }, { -182, -230, 310 }, { 0, -230, 358 }, { -308, -250, 180 }, 
	{ -180, -252, 306 }, { 0, -245, 359 }, { -317, -250, 186 }, { -186, -252, 317 }, 
	{ 0, -245, 368 }, { -304, -230, 174 }, { -174, -230, 304 }, { 0, -230, 384 }, 
	{ 182, -230, 310 }, { 310, -230, 182 }, { 180, -250, 308 }, { 308, -250, 180 }, 
	{ 186, -250, 317 }, { 317, -250, 186 }, { 174, -230, 304 }, { 304, -230, 174 }, 
	{ 440, -98, 0 }, { 377, -96, -220 }, { 220, -96, -377 }, { 0, -98, -440 }, 
	{ 484, 30, 0 }, { 425, 32, -249 }, { 249, 32, -425 }, { 0, 30, -484 }, 
	{ 512, 153, 0 }, { 406, 153, -233 }, { 233, 153, -406 }, { 0, 153, -512 }, 
	{ -220, -97, -375 }, { -377, -96, -220 }, { -440, -98, 0 }, { -249, 31, -422 }, 
	{ -425, 32, -249 }, { -484, 30, 0 }, { -233, 153, -406 }, { -406, 153, -233 }, 
	{ -512, 153, 0 }, { -375, -97, 220 }, { -220, -96, 377 }, { 0, -98, 440 }, 
	{ -422, 31, 249 }, { -249, 32, 425 }, { 0, 30, 484 }, { -406, 153, 233 }, 
	{ -233, 153, 406 }, { 0, 153, 512 }, { 220, -97, 375 }, { 375, -97, 220 }, 
	{ 249, 31, 422 }, { 422, 31, 249 }, { 233, 153, 406 }, { 406, 153, 233 }, 
	{ 471, 239, 0 }, { 403, 250, -235 }, { 235, 250, -403 }, { 0, 239, -471 }, 
	{ 424, 302, 0 }, { 359, 312, -210 }, { 210, 312, -359 }, { 0, 302, -424 }, 
	{ 384, 345, 0 }, { 332, 345, -195 }, { 195, 345, -332 }, { 0, 345, -384 }, 
	{ -235, 246, -401 }, { -403, 249, -234 }, { -471, 239, 0 }, { -210, 309, -361 }, 
	{ -359, 312, -211 }, { -424, 302, 0 }, { -195, 345, -332 }, { -332, 345, -195 }, 
	{ -384, 345, 0 }, { -401, 246, 235 }, { -234, 249, 403 }, { 0, 239, 471 }, 
	{ -361, 309, 210 }, { -211, 312, 359 }, { 0, 302, 424 }, { -332, 345, 195 }, 
	{ -195, 345, 332 }, { 0, 345, 384 }, { 234, 246, 401 }, { 401, 246, 234 }, 
	{ 211, 309, 361 }, { 361, 309, 211 }, { 195, 345, 332 }, { 332, 345, 195 }, 
	{ -409, -134, 0 }, { -402, -149, -51 }, { -390, -177, -51 }, { -384, -192, 0 }, 
	{ -543, -127, 0 }, { -571, -146, -51 }, { -588, -173, -51 }, { -568, -178, 0 }, 
	{ -637, -109, 0 }, { -675, -127, -51 }, { -707, -147, -51 }, { -696, -141, 0 }, 
	{ -691, -76, 0 }, { -715, -76, -34 }, { -743, -76, -34 }, { -768, -76, 0 }, 
	{ -390, -177, 51 }, { -402, -149, 51 }, { -579, -170, 51 }, { -564, -144, 51 }, 
	{ -698, -142, 51 }, { -668, -124, 51 }, { -743, -76, 34 }, { -715, -76, 34 }, 
	{ -659, 0, 0 }, { -691, 5, -46 }, { -719, 24, -46 }, { -716, 31, 0 }, 
	{ -600, 77, 0 }, { -623, 95, -50 }, { -636, 123, -50 }, { -623, 134, 0 }, 
	{ -505, 173, -51 }, { -493, 210, -51 }, { -486, 230, 0 }, { -712, 23, 46 }, 
	{ -686, 6, 46 }, { -629, 122, 50 }, { -617, 94, 50 }, { -493, 210, 51 }, 
	{ -505, 173, 51 }, { 435, 19, 0 }, { 435, 73, -112 }, { 435, 175, -112 }, 
	{ 435, 230, 0 }, { 552, -44, 0 }, { 598, 6, -94 }, { 631, 71, -94 }, 
	{ 607, 89, 0 }, { 630, -132, 0 }, { 652, -118, -60 }, { 693, -94, -60 }, 
	{ 728, -72, 0 }, { 691, -230, 0 }, { 739, -230, -28 }, { 796, -230, -28 }, 
	{ 844, -230, 0 }, { 435, 175, 112 }, { 435, 73, 112 }, { 618, 65, 94 }, 
	{ 589, 1, 94 }, { 697, -91, 60 }, { 653, -118, 60 }, { 796, -230, 28 }, 
	{ 739, -230, 28 }, { 710, -238, 0 }, { 759, -244, -34 }, { 833, -246, -34 }, 
	{ 863, -242, 0 }, { 720, -238, 0 }, { 763, -244, -29 }, { 830, -247, -29 }, 
	{ 854, -242, 0 }, { 716, -230, 0 }, { 743, -230, -25 }, { 792, -230, -25 }, 
	{ 819, -230, 0 }, { 828, -244, 34 }, { 758, -242, 34 }, { 826, -245, 29 }, 
	{ 761, -243, 29 }, { 792, -230, 25 }, { 743, -230, 25 }, { 0, -422, 0 }, 
	{ 0, -422, 0 }, { 0, -422, 0 }, { 37, -394, 10 }, { 80, -401, -47 }, 
	{ 47, -401, -80 }, { 0, -393, -56 }, { 23, -355, 21 }, { 51, -307, 0 }, 
	{ 40, -307, -23 }, { 23, -307, -40 }, { 0, -307, -51 }, { 0, -422, 0 }, 
	{ -47, -400, -79 }, { -80, -402, -58 }, { -56, -395, -11 }, { -23, -307, -40 }, 
	{ -40, -307, -23 }, { -51, -307, 0 }, { 0, -422, 0 }, { -79, -401, 39 }, 
	{ -58, -403, 74 }, { -11, -395, 51 }, { -40, -307, 23 }, { -23, -307, 40 }, 
	{ 0, -307, 51 }, { 37, -401, 75 }, { 59, -401, 56 }, { 23, -307, 40 }, 
	{ 40, -307, 23 }, { 153, -280, 0 }, { 126, -278, -73 }, { 73, -278, -126 }, 
	{ 0, -280, -153 }, { 253, -256, 0 }, { 234, -258, -137 }, { 137, -258, -234 }, 
	{ 0, -256, -253 }, { 332, -230, 0 }, { 287, -230, -169 }, { 169, -230, -287 }, 
	{ 0, -230, -332 }, { -73, -279, -127 }, { -126, -278, -74 }, { -153, -280, 0 }, 
	{ -137, -258, -229 }, { -234, -258, -137 }, { -253, -256, 0 }, { -169, -230, -287 }, 
	{ -287, -230, -169 }, { -332, -230, 0 }, { -127, -279, 73 }, { -74, -278, 126 }, 
	{ 0, -280, 153 }, { -229, -258, 137 }, { -137, -258, 234 }, { 0, -256, 253 }, 
	{ -287, -230, 169 }, { -169, -230, 287 }, { 0, -230, 332 }, { 74, -279, 127 }, 
	{ 127, -279, 74 }, { 137, -258, 229 }, { 229, -258, 137 }, { 169, -230, 287 }, 
	{ 287, -230, 169 }, { 0, 384, 0 }, { 384, 345, 0 }, { 332, 345, 195 }, 
	{ 195, 345, 332 }, { 0, 345, 384 }, { 334, 362, 0 }, { 316, 364, 185 }, 
	{ 185, 364, 316 }, { 0, 362, 334 }, { 211, 375, 0 }, { 226, 378, 132 }, 
	{ 132, 378, 226 }, { 0, 375, 211 }, { -195, 345, 332 }, { -332, 345, 195 }, 
	{ -384, 345, 0 }, { -185, 363, 307 }, { -316, 364, 184 }, { -334, 362, 0 }, 
	{ -132, 377, 211 }, { -226, 378, 131 }, { -211, 375, 0 }, { -332, 345, -195 }, 
	{ -195, 345, -332 }, { 0, 345, -384 }, { -307, 363, -185 }, { -184, 364, -316 }, 
	{ 0, 362, -334 }, { -211, 377, -132 }, { -131, 378, -226 }, { 0, 375, -211 }, 
	{ 195, 345, -332 }, { 332, 345, -195 }, { 184, 363, -307 }, { 307, 363, -184 }, 
	{ 131, 377, -211 }, { 211, 377, -131 }, 
};

#define NPATCHES 32
#define PATCHDIM 3
#define PATCHSIDE 4
#define PATCHSIDEPLUSONE 5

uint16_t patch[NPATCHES][16] = {
	{   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15 },
	{   3,  16,  17,  18,   7,  19,  20,  21,  11,  22,  23,  24,  15,  25,  26,  27 },
	{  18,  28,  29,  30,  21,  31,  32,  33,  24,  34,  35,  36,  27,  37,  38,  39 },
	{  30,  40,  41,   0,  33,  42,  43,   4,  36,  44,  45,   8,  39,  46,  47,  12 },
	{  12,  13,  14,  15,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59 },
	{  15,  25,  26,  27,  51,  60,  61,  62,  55,  63,  64,  65,  59,  66,  67,  68 },
	{  27,  37,  38,  39,  62,  69,  70,  71,  65,  72,  73,  74,  68,  75,  76,  77 },
	{  39,  46,  47,  12,  71,  78,  79,  48,  74,  80,  81,  52,  77,  82,  83,  56 },
	{  56,  57,  58,  59,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95 },
	{  59,  66,  67,  68,  87,  96,  97,  98,  91,  99, 100, 101,  95, 102, 103, 104 },
	{  68,  75,  76,  77,  98, 105, 106, 107, 101, 108, 109, 110, 104, 111, 112, 113 },
	{  77,  82,  83,  56, 107, 114, 115,  84, 110, 116, 117,  88, 113, 118, 119,  92 },
	{ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135 },
	{ 123, 136, 137, 120, 127, 138, 139, 124, 131, 140, 141, 128, 135, 142, 143, 132 },
	{ 132, 133, 134, 135, 144, 145, 146, 147, 148, 149, 150, 151,  68, 152, 153, 154 },
	{ 135, 142, 143, 132, 147, 155, 156, 144, 151, 157, 158, 148, 154, 159, 160,  68 },
	{ 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176 },
	{ 164, 177, 178, 161, 168, 179, 180, 165, 172, 181, 182, 169, 176, 183, 184, 173 },
	{ 173, 174, 175, 176, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196 },
	{ 176, 183, 184, 173, 188, 197, 198, 185, 192, 199, 200, 189, 196, 201, 202, 193 },
	{ 203, 203, 203, 203, 206, 207, 208, 209, 210, 210, 210, 210, 211, 212, 213, 214 },
	{ 203, 203, 203, 203, 209, 216, 217, 218, 210, 210, 210, 210, 214, 219, 220, 221 },
	{ 203, 203, 203, 203, 218, 223, 224, 225, 210, 210, 210, 210, 221, 226, 227, 228 },
	{ 203, 203, 203, 203, 225, 229, 230, 206, 210, 210, 210, 210, 228, 231, 232, 211 },
	{ 211, 212, 213, 214, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244 },
	{ 214, 219, 220, 221, 236, 245, 246, 247, 240, 248, 249, 250, 244, 251, 252, 253 },
	{ 221, 226, 227, 228, 247, 254, 255, 256, 250, 257, 258, 259, 253, 260, 261, 262 },
	{ 228, 231, 232, 211, 256, 263, 264, 233, 259, 265, 266, 237, 262, 267, 268, 241 },
	{ 269, 269, 269, 269, 278, 279, 280, 281, 274, 275, 276, 277, 270, 271, 272, 273 },
	{ 269, 269, 269, 269, 281, 288, 289, 290, 277, 285, 286, 287, 273, 282, 283, 284 },
	{ 269, 269, 269, 269, 290, 297, 298, 299, 287, 294, 295, 296, 284, 291, 292, 293 },
	{ 269, 269, 269, 269, 299, 304, 305, 278, 296, 302, 303, 274, 293, 300, 301, 270 },
};