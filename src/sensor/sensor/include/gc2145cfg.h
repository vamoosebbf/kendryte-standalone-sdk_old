#ifndef __GC2145_H__
#define __GC2145_H__

const uint8_t gc2145_sensor_default_regs[][2] = {
    {0xfe, 0xf0},
    {0xfe, 0xf0},
    {0xfe, 0xf0},
    {0xfc, 0x06},
    {0xf6, 0x00},
    {0xf7, 0x1d},
    {0xf8, 0x84},
    {0xfa, 0x00},
    {0xf9, 0xfe},
    {0xf2, 0x00},
    //////////////////////////////////////////////////////
    ////////////////////  Analog & Cisctl ////////////////
    //////////////////////////////////////////////////////
    {0xfe, 0x00},
    {0x03, 0x04},
    {0x04, 0x00},
    {0x09, 0x00},
    {0x0a, 0x00},
    {0x0b, 0x00},
    {0x0c, 0x00},
    {0x0d, 0x04},
    {0x0e, 0xc0},
    {0x0f, 0x06},
    {0x10, 0x52},
    {0x12, 0x2e},
    {0x17, 0x14}, // 14
    {0x18, 0x22},
    {0x19, 0x0f},
    {0x1a, 0x01},
    {0x1b, 0x4b},
    {0x1c, 0x07},
    {0x1d, 0x10},
    {0x1e, 0x88},
    {0x1f, 0x78},
    {0x20, 0x03},
    {0x21, 0x40},
    {0x22, 0xf0},
    {0x24, 0x16},
    {0x25, 0x01},
    {0x26, 0x10},
    {0x2d, 0x60},
    {0x30, 0x01},
    {0x31, 0x90},
    {0x33, 0x06},
    {0x34, 0x01},
    ///////////////////////////////////////////////////
    ////////////////////  ISP reg  //////////////////////
    //////////////////////////////////////////////////////
    {0x80, 0xff},
    {0x81, 0x24},
    {0x82, 0xfa},
    {0x83, 0x00},

    // {0x84, 0x01},//
    {0x84, 0x02},//
    // {0x84, 0x03},//
    // {0x84, 0x06},//
    // {0x84, 0x18},//

    {0x86, 0x06},
    {0x88, 0x03},
    {0x89, 0x03},
    {0x85, 0x30},
    {0x8a, 0x00},
    {0x8b, 0x00},
    {0xb0, 0x55},
    {0xc3, 0x00},
    {0xc4, 0x80},
    {0xc5, 0x90},
    {0xc6, 0x38},
    {0xc7, 0x40},
    {0xec, 0x06},
    {0xed, 0x04},
    {0xee, 0x60},
    {0xef, 0x90},
    {0xb6, 0x01},
    {0x90, 0x01},
    {0x91, 0x00},
    {0x92, 0x00},
    {0x93, 0x00},
    {0x94, 0x00},

    /**
     * 设置输出窗口 Height*width
     * 0x95 out window height[10:8]
     * 0x96 out window height[7:0]
     * 0x97 out window width[10:8]
     * 0x98 out window width[7:0]
     * H*W: 240*320 [0x00, 0xF0, 0x01, 0x01, 0x40]
     */
    {0x95, 0x00},
    {0x96, 0xf0},
    {0x97, 0x01},
    {0x98, 0x40},

    // {0x95, 0x04},
    // {0x96, 0xb0},
    // {0x97, 0x06},
    // {0x98, 0x40},
    ///////////////////////////////////////////////
    ///////////  BLK ////////////////////////
    ///////////////////////////////////////////////
    {0x18, 0x02},
    {0x40, 0x42},
    {0x41, 0x00},
    {0x43, 0x54},
    {0x5e, 0x00},
    {0x5f, 0x00},
    {0x60, 0x00},
    {0x61, 0x00},
    {0x62, 0x00},
    {0x63, 0x00},
    {0x64, 0x00},
    {0x65, 0x00},
    {0x66, 0x20},
    {0x67, 0x20},
    {0x68, 0x20},
    {0x69, 0x20},
    {0x76, 0x00},
    {0x6a, 0x02},
    {0x6b, 0x02},
    {0x6c, 0x02},
    {0x6d, 0x02},
    {0x6e, 0x02},
    {0x6f, 0x02},
    {0x70, 0x02},
    {0x71, 0x02},
    {0x76, 0x00},
    {0x72, 0xf0},
    {0x7e, 0x3c},
    {0x7f, 0x00},
    {0xfe, 0x02},
    {0x48, 0x15},
    {0x49, 0x00},
    {0x4b, 0x0b},
    {0xfe, 0x00},
    ///////////////////////////////////////////////
    /////////// AEC ////////////////////////
    ///////////////////////////////////////////////
    //// AEC:AUTO-EXPOSURE-CONTROL
    {0xfe, 0x01},//0xFE[2:0]页选择 Page 1
    // {0x74, 0x00},
    
    {0x01, 0x04},//AEC_x1 Default: 0x04
    {0x02, 0x60},//AEC_x2 Default: 0x60
    {0x03, 0x02},//AEC_y1 Default: 0x02
    {0x04, 0x48},//AEC_y2 Default: 0x48
    
    {0x05, 0x20},
    {0x06, 0x40},
    {0x07, 0x18},
    {0x08, 0x40},

    {0x09, 0x00},
    
    {0x0a, 0x80},

    {0x0b, 0x11},
    {0x0c, 0x10},
    {0x13, 0x40},
    {0x17, 0x00},
    {0x1c, 0x11},
    {0x1e, 0x61},
    {0x1f, 0x30},
    {0x20, 0x40},
    {0x22, 0x80},
    {0x23, 0x20},
    {0xfe, 0x02},
    {0x0f, 0x04},
    {0xfe, 0x01},
    {0x12, 0x00},
    {0x15, 0x50},
    {0x10, 0x31},
    {0x3e, 0x28},
    {0x3f, 0xe0},
    {0x40, 0xe0},
    {0x41, 0x0f},
    /////////////////////////////
    //////// INTPEE /////////////
    /////////////////////////////
    {0xfe, 0x02},
    {0x90, 0x6c},
    {0x91, 0x03},
    {0x92, 0xc8},
    {0x94, 0x66},
    {0x95, 0xb5},
    {0x97, 0x64},
    {0xa2, 0x11},
    {0xfe, 0x00},
    /////////////////////////////
    //////// DNDD///////////////
    /////////////////////////////
    {0xfe, 0x02},
    {0x80, 0xc1},
    {0x81, 0x08},
    {0x82, 0x08},
    {0x83, 0x05},
    {0x84, 0x0a},
    {0x86, 0x50},
    {0x87, 0x30},
    {0x88, 0x15},
    {0x89, 0x80},
    {0x8a, 0x60},
    {0x8b, 0x30},
    /////////////////////////////////////////////////
    ///////////// ASDE ////////////////////////
    /////////////////////////////////////////////////
    {0xfe, 0x01},
    {0x21, 0x14},
    {0xfe, 0x02},
    {0xa3, 0x40},
    {0xa4, 0x20},
    {0xa5, 0x40},
    {0xa6, 0x80},
    {0xab, 0x40},
    {0xae, 0x0c},
    {0xb3, 0x34},
    {0xb4, 0x44},
    {0xb6, 0x38},
    {0xb7, 0x02},
    {0xb9, 0x30},
    {0x3c, 0x08},
    {0x3d, 0x30},
    {0x4b, 0x0d},
    {0x4c, 0x20},
    {0xfe, 0x00},
    /////////////gamma1//////////////////
    /////////////////////Gamma///////////////////////
    ///////////////////////////////////////
    {0xfe, 0x02},
    {0x10, 0x10},
    {0x11, 0x15},
    {0x12, 0x1a},
    {0x13, 0x1f},
    {0x14, 0x2c},
    {0x15, 0x39},
    {0x16, 0x45},
    {0x17, 0x54},
    {0x18, 0x69},
    {0x19, 0x7d},
    {0x1a, 0x8f},
    {0x1b, 0x9d},
    {0x1c, 0xa9},
    {0x1d, 0xbd},
    {0x1e, 0xcd},
    {0x1f, 0xd9},
    {0x20, 0xe3},
    {0x21, 0xea},
    {0x22, 0xef},
    {0x23, 0xf5},
    {0x24, 0xf9},
    {0x25, 0xff},
    /////auto gamma/////
    {0xfe, 0x02},
    {0x26, 0x0f},
    {0x27, 0x14},
    {0x28, 0x19},
    {0x29, 0x1e},
    {0x2a, 0x27},
    {0x2b, 0x33},
    {0x2c, 0x3b},
    {0x2d, 0x45},
    {0x2e, 0x59},
    {0x2f, 0x69},
    {0x30, 0x7c},
    {0x31, 0x89},
    {0x32, 0x98},
    {0x33, 0xae},
    {0x34, 0xc0},
    {0x35, 0xcf},
    {0x36, 0xda},
    {0x37, 0xe2},
    {0x38, 0xe9},
    {0x39, 0xf3},
    {0x3a, 0xf9},
    {0x3b, 0xff},
    ///////////////////gamma2////////////////////
    ////Gamma outdoor
    /*
{0xfe, 0x02},
{0x26, 0x17},
{0x27, 0x18},
{0x28, 0x1c},
{0x29, 0x20},
{0x2a, 0x28},
{0x2b, 0x34},
{0x2c, 0x40},
{0x2d, 0x49},
{0x2e, 0x5b},
{0x2f, 0x6d},
{0x30, 0x7d},
{0x31, 0x89},
{0x32, 0x97},
{0x33, 0xac},
{0x34, 0xc0},
{0x35, 0xcf},
{0x36, 0xda},
{0x37, 0xe5},
{0x38, 0xec},
{0x39, 0xf8},
{0x3a, 0xfd},
{0x3b, 0xff},
*/
    ///////////////////////////////////////////////
    ///////////   YCP       ///////////////////////
    ///////////////////////////////////////////////
    {0xfe, 0x02},
    {0xd1, 0x30},
    {0xd2, 0x30},
    {0xd3, 0x45},
    {0xdd, 0x14},
    {0xde, 0x86},
    {0xed, 0x01},
    {0xee, 0x28},
    {0xef, 0x30},
    {0xd8, 0xd8},
    ////////////////////////////
    //////// LSC  0.8///////////////
    ////////////////////////////
    {0xfe, 0x01},
    {0xc2, 0x1a},
    {0xc3, 0x0b},
    {0xc4, 0x0e},
    {0xc8, 0x20},
    {0xc9, 0x0c},
    {0xca, 0x12},
    {0xbc, 0x41},
    {0xbd, 0x1f},
    {0xbe, 0x29},
    {0xb6, 0x48},
    {0xb7, 0x22},
    {0xb8, 0x28},
    {0xc5, 0x04},
    {0xc6, 0x00},
    {0xc7, 0x00},
    {0xcb, 0x12},
    {0xcc, 0x00},
    {0xcd, 0x08},
    {0xbf, 0x14},
    {0xc0, 0x00},
    {0xc1, 0x10},
    {0xb9, 0x0f},
    {0xba, 0x00},
    {0xbb, 0x00},
    {0xaa, 0x0a},
    {0xab, 0x00},
    {0xac, 0x00},
    {0xad, 0x09},
    {0xae, 0x00},
    {0xaf, 0x02},
    {0xb0, 0x04},
    {0xb1, 0x00},
    {0xb2, 0x00},
    {0xb3, 0x03},
    {0xb4, 0x00},
    {0xb5, 0x02},
    {0xd0, 0x42},
    {0xd1, 0x00},
    {0xd2, 0x00},
    {0xd6, 0x47},
    {0xd7, 0x07},
    {0xd8, 0x00},
    {0xd9, 0x34},
    {0xda, 0x13},
    {0xdb, 0x00},
    {0xd3, 0x2b},
    {0xd4, 0x18},
    {0xd5, 0x10},
    {0xa4, 0x00},
    {0xa5, 0x00},
    {0xa6, 0x77},
    {0xa7, 0x77},
    {0xa8, 0x77},
    {0xa9, 0x77},
    {0xa1, 0x80},
    {0xa2, 0x80},

    {0xfe, 0x01},
    {0xdf, 0x00},
    {0xdc, 0x80},
    {0xdd, 0x30},
    {0xe0, 0x6b},
    {0xe1, 0x70},
    {0xe2, 0x6b},
    {0xe3, 0x70},
    {0xe6, 0xa0},
    {0xe7, 0x60},
    {0xe8, 0xa0},
    {0xe9, 0x60},
    {0xfe, 0x00},

    /////////////////////////////////////////////////
    /////////////    AWB     ////////////////////////
    /////////////////////////////////////////////////

    {0xfe, 0x01},
    {0x4f, 0x00},
    {0x4f, 0x00},
    {0x4b, 0x01},
    {0x4f, 0x00},
    {0x4c, 0x01}, // D75
    {0x4d, 0x71},
    {0x4e, 0x01},
    {0x4c, 0x01},
    {0x4d, 0x91},
    {0x4e, 0x01},
    {0x4c, 0x01},
    {0x4d, 0x70},
    {0x4e, 0x01},
    {0x4c, 0x01}, // D65
    {0x4d, 0x90},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xb0},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0x8f},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0x6f},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xaf},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xd0},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xf0},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xcf},
    {0x4e, 0x02},
    {0x4c, 0x01},
    {0x4d, 0xef},
    {0x4e, 0x02},
    {0x4c, 0x01}, //D50
    {0x4d, 0x6e},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x8e},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xae},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xce},
    {0x4e, 0x03},

    {0x4c, 0x01},
    {0x4d, 0xee},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x6d},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x8d},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xad},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xcd},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xed},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x6c},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x8c},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xac},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xcc},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0xec},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x6b},
    {0x4e, 0x03},
    {0x4c, 0x01},
    {0x4d, 0x8b},
    {0x4e, 0x03}, //skin

    {0x4c, 0x01},
    {0x4d, 0x8a},
    {0x4e, 0x03},

    {0x4c, 0x01}, // CWF
    {0x4d, 0xaa},
    {0x4e, 0x04},
    {0x4c, 0x01}, // CWF
    {0x4d, 0xab},
    {0x4e, 0x04},
    {0x4c, 0x01}, // CWF
    {0x4d, 0xcb},
    {0x4e, 0x04},
    {0x4c, 0x01}, // CWF
    {0x4d, 0xa9},
    {0x4e, 0x04},
    {0x4c, 0x01},
    {0x4d, 0xca},
    {0x4e, 0x04},
    {0x4c, 0x01},
    {0x4d, 0xc9},
    {0x4e, 0x04},
    {0x4c, 0x01},
    {0x4d, 0x8a},
    {0x4e, 0x04},
    {0x4c, 0x01},
    {0x4d, 0x89},
    {0x4e, 0x04},
    {0x4c, 0x01}, // TL84
    {0x4d, 0xeb},
    {0x4e, 0x05},
    {0x4c, 0x02},
    {0x4d, 0x0b},
    {0x4e, 0x05},
    {0x4c, 0x02},
    {0x4d, 0x0c},
    {0x4e, 0x05},
    {0x4c, 0x02},
    {0x4d, 0x2c},
    {0x4e, 0x05},
    {0x4c, 0x02},
    {0x4d, 0x2b},
    {0x4e, 0x05},
    {0x4c, 0x01},
    {0x4d, 0xea},
    {0x4e, 0x05},
    {0x4c, 0x02},
    {0x4d, 0x0a},
    {0x4e, 0x05},

    {0x4c, 0x02},
    {0x4d, 0x8b},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x2a},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x4a},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x6a},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x8a},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0xaa},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x09},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x29},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x49},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0x69},
    {0x4e, 0x06},
    {0x4c, 0x02},
    {0x4d, 0xcc},
    {0x4e, 0x07},
    {0x4c, 0x02},
    {0x4d, 0xca},
    {0x4e, 0x07},
    {0x4c, 0x02},
    {0x4d, 0xa9},
    {0x4e, 0x07},
    {0x4c, 0x02},
    {0x4d, 0xc9},
    {0x4e, 0x07},
    {0x4c, 0x02},
    {0x4d, 0xe9},
    {0x4e, 0x07},

    {0x4f, 0x01},
    {0x50, 0x80},
    {0x51, 0xa8},
    {0x52, 0x47},
    {0x53, 0x38},
    {0x54, 0xc7},
    {0x56, 0x0e},
    {0x58, 0x08},
    {0x5b, 0x00},
    {0x5c, 0x74},
    {0x5d, 0x8b},
    {0x61, 0xdb},
    {0x62, 0xb8},
    {0x63, 0x86},
    {0x64, 0xc0},
    {0x65, 0x04},

    {0x67, 0xa8},
    {0x68, 0xb0},
    {0x69, 0x00},
    {0x6a, 0xa8},
    {0x6b, 0xb0},
    {0x6c, 0xaf},
    {0x6d, 0x8b},
    {0x6e, 0x50},
    {0x6f, 0x18},
    {0x73, 0xe0},
    {0x70, 0x0d},
    {0x71, 0x68},
    {0x72, 0x81},
    {0x74, 0x01},
    {0x75, 0x01},
    {0x7f, 0x0c},
    {0x76, 0x70},
    {0x77, 0x58},
    {0x78, 0xa0},
    {0x79, 0x5e},
    {0x7a, 0x54},
    {0x7b, 0x55},
    {0xfe, 0x00},

    //////////////////////////////////////////
    ///////////  CC   ////////////////////////
    //////////////////////////////////////////
    {0xfe, 0x02},
    {0xc0, 0x01},
    {0xC1, 0x44},
    {0xc2, 0xF4},
    {0xc3, 0x02},
    {0xc4, 0xf2},
    {0xc5, 0x44},
    {0xc6, 0xf8},
    {0xC7, 0x50},
    {0xc8, 0xf2},
    {0xc9, 0x00},
    {0xcA, 0xE0},
    {0xcB, 0x45},
    {0xcC, 0xec},
    {0xCd, 0x45},
    {0xce, 0xf0},
    {0xcf, 0x00},
    {0xe3, 0xf0},
    {0xe4, 0x45},
    {0xe5, 0xe8},

    ///////output//////////////////////////
    {0xfe, 0x00},
    {0xf2, 0x0f},

    ////////////////dark  sun//////////////
    {0x18, 0x22},
    {0xfe, 0x02},
    {0x40, 0xbf},
    {0x46, 0xcf},
    {0xfe, 0x00},

    //////////////frame rate   50Hz
    {0xfe, 0x00},
    {0x05, 0x01},
    {0x06, 0x56},
    {0x07, 0x00},
    {0x08, 0x32},
    {0xfe, 0x01},
    {0x25, 0x00},
    {0x26, 0xfa},
    {0x27, 0x04},
    {0x28, 0xe2},
    {0x29, 0x05},
    {0x2a, 0xdc},
    {0x2b, 0x06},
    {0x2c, 0xd6},
    {0x2d, 0x0b},
    {0x2e, 0xb8},
    {0xfe, 0x00},

    /**************************************************************************/
    //use this for 320x240 (QVGA) capture
    {0xfe, 0x00}, //0xFE[2:0]页选择
    {0xfd, 0x01}, //Salar mode
    {0xfa, 0x00}, // CLK DIV_MODE
    // crop window

    {0xfe, 0x00},
    {0x99, 0x55}, //subsample
    {0x9a, 0x06}, //subsampel mode

    {0x9b, 0x02}, //Sub_row_N1
    {0x9c, 0x00}, //Sub_row_N2
    {0x9d, 0x00}, //Sub_row_N3
    {0x9e, 0x00}, //Sub_row_N4

    {0x9f, 0x02}, //Sub_col_N1
    {0xa0, 0x00}, //Sub_col_N2
    {0xa1, 0x00}, //Sub_col_N3
    {0xa2, 0x00}, //Sub_col_N4

    {0x90, 0x01}, //Crop enable: Crop out window mode
    {0x91, 0x00}, //out window y1[10:8]
    {0x92, 0x00}, //out window y1[7:0]
    {0x93, 0x00}, //out window x1[10:8]
    {0x94, 0x00}, //out window x1[7:0]

    // /**
    //  * 设置输出窗口 Height*width
    //  * 0x95 out window height[10:8]
    //  * 0x96 out window height[7:0]
    //  * 0x97 out window width[10:8]
    //  * 0x98 out window width[7:0]
    //  * H*W: 240*320 [0x00, 0xF0, 0x01, 0x01, 0x40]
    //  */
    // {0x95, 0x00},
    // {0x96, 0xf0},
    // {0x97, 0x01},
    // {0x98, 0x40},

    /**************************************************************************/
    // {0xfe, 0x00},//0xFE[2:0]页选择 Page 0
    // // Measure Window 测量窗口
    // {0xec, 0x02},//C_by_win_x0 Default: 0x04
    // {0xed, 0x02},//C_by_win_y0 Default: 0x02
    // {0xee, 0x30},//C_by_win_x1 Default: 0x30
    // {0xef, 0x48},//C_by_win_y1 Default: 0x48
    
    // {0xfe, 0x02}, //0xFE[2:0]页选择 Page 2
    // {0x9d, 0x08},//Edge_effect_scaler

    
    //// AEC:AUTO-EXPOSURE-CONTROL
    // {0xfe, 0x01},//0xFE[2:0]页选择 Page 1
    // // {0x74, 0x00},
    
    // {0x01, 0x04},//AEC_x1 Default: 0x04
    // {0x02, 0x60},//AEC_x2 Default: 0x60
    // {0x03, 0x02},//AEC_y1 Default: 0x02
    // {0x04, 0x48},//AEC_y2 Default: 0x48
    
    // {0x05, 0x20},
    // {0x06, 0x40},
    // {0x07, 0x18},
    // {0x08, 0x40},
    // {0x05, 0x18},//AEC_center_x1 Default: 0x20
    // {0x06, 0x50},//AEC_center_x2 Default: 0x40
    // {0x07, 0x10},//AEC_center_y1 Default: 0x18
    // {0x08, 0x38},//AEC_center_y2 Default: 0x40
    
    // {0x0a, 0x00},//AEC_mode1
    // {0x0a, 0x80},//AEC_mode1
    // {0x0a, 0x80},//AEC_mode2
    // {0x0a, 0x80},//AEC_mode3
    // {0x0a, 0x80},//AEC_mode4
    // {0x21, 0x04},
    // {0x21, 0x14},

    // {0xfe, 0x00},//0xFE[2:0]页选择 Page 0
    // {0x20, 0x03},//Analog mode3

    //// mipi
    // {0xfe, 0x03},//0xFE[2:0]页选择 Page 3
    // {0x12, 0x80},
    // {0x13, 0x02},
    // {0x04, 0x40},
    // {0x05, 0x01},
    // {0xfe, 0x00},
    
};



#endif