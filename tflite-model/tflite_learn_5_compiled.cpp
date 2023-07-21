/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 18.07.2023 07:35:04

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 2400;
#else
constexpr int kTensorArenaSize = 1376;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_ADD, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[15];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,40 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0013882352504879236, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 160, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int8_t tensor_data2[8] = { 104, 127, -18, 115, 55, -27, 0, 115, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0014522180426865816, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(16) int8_t tensor_data3[16] = { 94, 53, 80, 6, 15, 90, 45, 69, 71, 127, 45, 41, 42, 107, 59, 27, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0023946398869156837, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[3] = { 610, -574, 0, };
const TfArray<1, int> tensor_dimension4 = { 1, { 3 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00013773544924333692, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int8_t tensor_data5[3*160] = { 
  -35, -11, -31, -1, 27, -27, -1, 14, 0, -26, 22, 19, 8, 6, -2, 14, -48, -4, -25, -10, 34, -21, 5, 18, 5, -23, 27, 5, 1, 10, -12, 9, -33, -3, -20, -12, 33, -22, -10, 18, 7, -32, 32, 2, 1, -1, -17, 14, -42, -13, -19, -12, 40, -30, -2, 24, 1, -32, 26, 4, -3, 4, -10, 15, -45, -6, -22, -14, 51, -34, -1, 16, 5, -38, 29, 10, -4, 13, -18, 20, -47, -12, -15, -13, 50, -39, -7, 18, 15, -33, 40, 16, 3, 20, -7, 12, -40, -8, -16, 3, 32, -32, -2, 21, 5, -28, 23, 11, 6, 9, -11, 20, -41, -11, -20, -10, 42, -27, 3, 17, 0, -23, 24, 2, -1, 6, -9, 7, -49, -5, -20, 1, 37, -27, -3, 19, 0, -21, 25, 5, 4, -2, -8, 7, -5, 5, -31, 11, 25, -20, -22, 3, 11, -17, 10, 13, -10, 7, -12, 16, 
  61, 21, 11, 17, -16, 28, 1, -15, -17, 23, -31, 15, 29, -33, 2, 5, 61, 32, 7, 22, -16, 24, -9, -23, -19, 25, -30, 29, 33, -42, -2, 29, 60, 36, 11, 23, -16, 27, -5, -15, -21, 19, -26, 29, 26, -39, 3, 36, 63, 22, 3, 25, -26, 22, -2, -23, -21, 24, -28, 23, 35, -55, 3, 33, 71, 40, 6, 13, -21, 28, -5, -17, -29, 19, -28, 30, 38, -53, -3, 25, 76, 37, 3, 20, -24, 23, -1, -17, -22, 21, -31, 31, 40, -47, 4, 35, 63, 33, 12, 13, -20, 21, -3, -14, -16, 24, -36, 26, 35, -44, 0, 30, 50, 23, 2, 18, -20, 24, -3, -20, -25, 24, -25, 27, 26, -43, 4, 24, 72, 23, 4, 17, -26, 27, -9, -20, -13, 15, -23, 20, 30, -44, -4, 30, 3, 3, 19, 17, -18, 24, 7, -15, -10, 14, -26, 10, 6, -5, -16, 7, 
  -77, -28, 22, -6, -6, 5, 1, 3, 16, 4, -4, -53, -57, 31, 3, -40, -127, -29, 23, -10, -17, 2, 1, 2, 7, 7, -10, -61, -58, 38, 15, -70, -122, -39, 25, -14, -27, 10, 10, -3, 10, 10, -7, -68, -73, 33, 9, -79, -106, -42, 18, -7, -36, 9, 9, -4, 12, 19, -9, -83, -79, 40, 10, -86, -85, -39, 20, 4, -33, 20, 8, -2, 14, 21, -2, -85, -66, 26, 8, -81, -104, -34, 21, -11, -26, 12, 9, 5, 9, 12, -7, -72, -67, 27, 14, -83, -116, -39, 17, -9, -20, 16, 8, -1, 15, 9, -5, -65, -68, 40, 3, -73, -114, -25, 10, -5, -24, 11, 3, 9, 11, 10, -9, -55, -48, 42, 9, -70, -111, -37, 14, -12, -18, 12, 2, 8, 15, 13, 7, -56, -55, 38, 4, -64, -18, -6, 9, -19, -11, -1, 21, 18, 14, 14, 9, -21, 3, -3, 20, -22, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 3,160 } };
const TfArray<1, float> quant5_scale = { 1, { 0.025503523647785187, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int32_t tensor_data6[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension6 = { 1, { 8 } };
const TfArray<8, float> quant6_scale = { 8, { 1.1318406905047596e-05, 1.0109261893376242e-05, 1.0238649338134564e-05, 6.7449645939632319e-06, 7.7693957791780122e-06, 7.7944396252860315e-06, 4.3392910811235197e-06, 1.0871205631701741e-05, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int8_t tensor_data7[8*1*4*1] = { 
  /* [0][0][][] */ -122, 52, -127, -18, 
  /* [1][0][][] */ -88, -111, -105, -127, 
  /* [2][0][][] */ 56, -63, -45, 127, 
  /* [3][0][][] */ -122, 127, 14, 33, 
  /* [4][0][][] */ 127, 61, -106, 62, 
  /* [5][0][][] */ 85, 126, 127, 54, 
  /* [6][0][][] */ -97, -76, -127, -107, 
  /* [7][0][][] */ -58, -127, -98, 1, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,1,4,1 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0081530902534723282, 0.0072820954956114292, 0.0073752985335886478, 0.0048586609773337841, 0.0055965990759432316, 0.0056146387942135334, 0.0031257604714483023, 0.0078309532254934311, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int32_t tensor_data8[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension8 = { 1, { 16 } };
const TfArray<16, float> quant8_scale = { 16, { 6.8423942138906568e-05, 4.306795381125994e-05, 4.7722325689392164e-05, 5.1236325816716999e-05, 3.1629238947061822e-05, 6.1515260313171893e-05, 3.9861366531113163e-05, 4.1912877350114286e-05, 2.6041545424959622e-05, 6.6213840909767896e-05, 4.3028790969401598e-05, 4.4280266592977569e-05, 4.4682394218398258e-05, 2.2204088963917457e-05, 3.3354324841639027e-05, 4.7982826799852774e-05, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int8_t tensor_data9[16*1*2*8] = { 
  /* [0][0][][] */ 27,72,-127,4,-21,-36,12,48, 68,74,-84,-1,-24,-36,6,48, 
  /* [1][0][][] */ 27,127,-43,-14,0,1,15,74, 38,118,-24,7,-13,18,-3,70, 
  /* [2][0][][] */ -120,-80,-54,-6,2,17,-15,-127, -45,-20,-4,27,8,-14,-15,-46, 
  /* [3][0][][] */ -57,47,7,2,2,31,-7,6, -127,-73,3,17,17,32,15,-70, 
  /* [4][0][][] */ 78,-40,121,13,53,-6,-10,82, 127,-40,73,18,16,-20,10,20, 
  /* [5][0][][] */ -115,-88,-38,14,12,25,3,-99, -127,-13,-44,12,11,23,-11,-112, 
  /* [6][0][][] */ -29,-81,14,27,-10,1,-14,35, 33,1,-20,-20,11,22,-5,-127, 
  /* [7][0][][] */ 26,-61,120,4,9,7,18,66, 127,-11,1,26,35,1,15,-48, 
  /* [8][0][][] */ -21,-127,112,-2,-6,-27,2,92, 54,-26,-40,56,33,5,22,-42, 
  /* [9][0][][] */ -127,-80,-30,7,12,19,-15,-100, -90,26,-12,-6,9,11,14,-91, 
  /* [10][0][][] */ 19,-62,114,4,25,-23,-11,48, 127,-7,28,27,38,-2,22,-44, 
  /* [11][0][][] */ 70,117,-10,0,-25,-48,14,92, 67,127,82,7,-9,6,3,100, 
  /* [12][0][][] */ 77,127,-48,-25,-10,-11,9,63, 73,122,67,-6,2,-37,14,85, 
  /* [13][0][][] */ 34,-115,-117,61,-33,-58,-9,-120, -16,-69,127,-15,60,-72,-38,36, 
  /* [14][0][][] */ -105,-102,-1,26,-39,23,-16,-127, -28,46,-38,5,38,-2,-1,-92, 
  /* [15][0][][] */ 97,127,-24,3,-30,-59,-16,65, 49,106,65,-3,20,24,20,85, 
};
const TfArray<4, int> tensor_dimension9 = { 4, { 16,1,2,8 } };
const TfArray<16, float> quant9_scale = { 16, { 0.02367270365357399, 0.014900265261530876, 0.01651054248213768, 0.017726285383105278, 0.010942800901830196, 0.0212824996560812, 0.013790879398584366, 0.014500642195343971, 0.0090096211060881615, 0.022908071056008339, 0.014886715449392796, 0.015319690108299255, 0.015458814799785614, 0.0076819718815386295, 0.011539630591869354, 0.016600668430328369, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int32_t tensor_data10[4] = { 1, 1, 40, 1, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[3] = { 1, 40, 8, };
const TfArray<1, int> tensor_dimension11 = { 1, { 3 } };
const ALIGN(16) int32_t tensor_data12[4] = { 1, 40, 1, 8, };
const TfArray<1, int> tensor_dimension12 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data13[4] = { 1, 1, 20, 8, };
const TfArray<1, int> tensor_dimension13 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data14[3] = { 1, 20, 16, };
const TfArray<1, int> tensor_dimension14 = { 1, { 3 } };
const ALIGN(16) int32_t tensor_data15[4] = { 1, 20, 1, 16, };
const TfArray<1, int> tensor_dimension15 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,40,1 } };
const TfArray<1, float> quant16_scale = { 1, { 0.0013882352504879236, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,40,8 } };
const TfArray<1, float> quant17_scale = { 1, { 0.0073808212764561176, } };
const TfArray<1, int> quant17_zero = { 1, { 22 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<3, int> tensor_dimension18 = { 3, { 1,40,8 } };
const TfArray<1, float> quant18_scale = { 1, { 0.0073808212764561176, } };
const TfArray<1, int> quant18_zero = { 1, { 22 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<3, int> tensor_dimension19 = { 3, { 1,40,8 } };
const TfArray<1, float> quant19_scale = { 1, { 0.0028904152568429708, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<4, int> tensor_dimension20 = { 4, { 1,40,1,8 } };
const TfArray<1, float> quant20_scale = { 1, { 0.0028904152568429708, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<4, int> tensor_dimension21 = { 4, { 1,20,1,8 } };
const TfArray<1, float> quant21_scale = { 1, { 0.0028904152568429708, } };
const TfArray<1, int> quant21_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<4, int> tensor_dimension22 = { 4, { 1,1,20,8 } };
const TfArray<1, float> quant22_scale = { 1, { 0.0028904152568429708, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfArray<4, int> tensor_dimension23 = { 4, { 1,1,20,16 } };
const TfArray<1, float> quant23_scale = { 1, { 0.014852182939648628, } };
const TfArray<1, int> quant23_zero = { 1, { 45 } };
const TfLiteAffineQuantization quant23 = { (TfLiteFloatArray*)&quant23_scale, (TfLiteIntArray*)&quant23_zero, 0 };
const TfArray<3, int> tensor_dimension24 = { 3, { 1,20,16 } };
const TfArray<1, float> quant24_scale = { 1, { 0.014852182939648628, } };
const TfArray<1, int> quant24_zero = { 1, { 45 } };
const TfLiteAffineQuantization quant24 = { (TfLiteFloatArray*)&quant24_scale, (TfLiteIntArray*)&quant24_zero, 0 };
const TfArray<3, int> tensor_dimension25 = { 3, { 1,20,16 } };
const TfArray<1, float> quant25_scale = { 1, { 0.0054006441496312618, } };
const TfArray<1, int> quant25_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant25 = { (TfLiteFloatArray*)&quant25_scale, (TfLiteIntArray*)&quant25_zero, 0 };
const TfArray<4, int> tensor_dimension26 = { 4, { 1,20,1,16 } };
const TfArray<1, float> quant26_scale = { 1, { 0.0054006441496312618, } };
const TfArray<1, int> quant26_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant26 = { (TfLiteFloatArray*)&quant26_scale, (TfLiteIntArray*)&quant26_zero, 0 };
const TfArray<4, int> tensor_dimension27 = { 4, { 1,10,1,16 } };
const TfArray<1, float> quant27_scale = { 1, { 0.0054006441496312618, } };
const TfArray<1, int> quant27_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant27 = { (TfLiteFloatArray*)&quant27_scale, (TfLiteIntArray*)&quant27_zero, 0 };
const TfArray<2, int> tensor_dimension28 = { 2, { 1,160 } };
const TfArray<1, float> quant28_scale = { 1, { 0.0054006441496312618, } };
const TfArray<1, int> quant28_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant28 = { (TfLiteFloatArray*)&quant28_scale, (TfLiteIntArray*)&quant28_zero, 0 };
const TfArray<2, int> tensor_dimension29 = { 2, { 1,3 } };
const TfArray<1, float> quant29_scale = { 1, { 0.26489794254302979, } };
const TfArray<1, int> quant29_zero = { 1, { 58 } };
const TfLiteAffineQuantization quant29 = { (TfLiteFloatArray*)&quant29_scale, (TfLiteIntArray*)&quant29_zero, 0 };
const TfArray<2, int> tensor_dimension30 = { 2, { 1,3 } };
const TfArray<1, float> quant30_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant30_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant30 = { (TfLiteFloatArray*)&quant30_scale, (TfLiteIntArray*)&quant30_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,10 } };
const TfArray<1, int> outputs0 = { 1, { 16 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 16,7,6 } };
const TfArray<1, int> outputs1 = { 1, { 17 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 17,11 } };
const TfArray<1, int> outputs2 = { 1, { 18 } };
const TfLiteAddParams opdata3 = { kTfLiteActRelu };
const TfArray<2, int> inputs3 = { 2, { 18,2 } };
const TfArray<1, int> outputs3 = { 1, { 19 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 19,12 } };
const TfArray<1, int> outputs4 = { 1, { 20 } };
const TfLitePoolParams opdata5 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs5 = { 1, { 20 } };
const TfArray<1, int> outputs5 = { 1, { 21 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 21,13 } };
const TfArray<1, int> outputs6 = { 1, { 22 } };
const TfLiteConvParams opdata7 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs7 = { 3, { 22,9,8 } };
const TfArray<1, int> outputs7 = { 1, { 23 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 23,14 } };
const TfArray<1, int> outputs8 = { 1, { 24 } };
const TfLiteAddParams opdata9 = { kTfLiteActRelu };
const TfArray<2, int> inputs9 = { 2, { 24,3 } };
const TfArray<1, int> outputs9 = { 1, { 25 } };
const TfLiteReshapeParams opdata10 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs10 = { 2, { 25,15 } };
const TfArray<1, int> outputs10 = { 1, { 26 } };
const TfLitePoolParams opdata11 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs11 = { 1, { 26 } };
const TfArray<1, int> outputs11 = { 1, { 27 } };
const TfLiteReshapeParams opdata12 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs12 = { 2, { 27,1 } };
const TfArray<1, int> outputs12 = { 1, { 28 } };
const TfLiteFullyConnectedParams opdata13 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs13 = { 3, { 28,5,4 } };
const TfArray<1, int> outputs13 = { 1, { 29 } };
const TfLiteSoftmaxParams opdata14 = { 1 };
const TfArray<1, int> inputs14 = { 1, { 29 } };
const TfArray<1, int> outputs14 = { 1, { 30 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 48, (TfLiteIntArray*)&tensor_dimension0, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 480, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 256, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data12, (TfLiteIntArray*)&tensor_dimension12, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data13, (TfLiteIntArray*)&tensor_dimension13, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data14, (TfLiteIntArray*)&tensor_dimension14, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data15, (TfLiteIntArray*)&tensor_dimension15, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension17, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension19, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension21, 160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension23, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant23))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension24, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant24))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension25, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant25))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension26, 320, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant26))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 320, (TfLiteIntArray*)&tensor_dimension27, 160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant27))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension28, 160, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant28))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 160, (TfLiteIntArray*)&tensor_dimension29, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant29))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension30, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant30))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_ADD, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_ADD, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs11, (TfLiteIntArray*)&outputs11, const_cast<void*>(static_cast<const void*>(&opdata11)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs12, (TfLiteIntArray*)&outputs12, const_cast<void*>(static_cast<const void*>(&opdata12)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs13, (TfLiteIntArray*)&outputs13, const_cast<void*>(static_cast<const void*>(&opdata13)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs14, (TfLiteIntArray*)&outputs14, const_cast<void*>(static_cast<const void*>(&opdata14)), OP_SOFTMAX, },
};

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {
  if (i < 0) {
    tensor->data.data = nullptr;
    tensor->dims = nullptr;
    return;
  }

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

} // namespace

TfLiteStatus tflite_learn_5_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors_size = 31;
  for (size_t i = 0; i < 31; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_ADD] = Register_ADD();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t i = 0; i < 15; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for (size_t i = 0; i < 15; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      ResetTensors();

      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteStatus tflite_learn_5_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(inTensorIndices[index], tensor);
  return kTfLiteOk;
}

static const int outTensorIndices[] = {
  30, 
};
TfLiteStatus tflite_learn_5_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(outTensorIndices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_5_invoke() {
  for (size_t i = 0; i < 15; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_5_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}