#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "hls_video.h"
#include "hls_stream.h"
#include "ap_int.h"

//Maximum image size
#define MAX_WIDTH 1920
#define MAX_HEIGHT 1080

//typedef video library core structures
typedef hls::stream<ap_axiu<8,1,1,1> > AXI_STREAM8;
typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM24;
typedef hls::stream<ap_axiu<32,1,1,1> > AXI_STREAM32;
typedef hls::stream<ap_axiu<64,1,1,1> > AXI_STREAM64;

typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1> IMAGE_GRAY;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> IMAGE_RGB;


//TOP Level funtion for HW synthesis
void hist_equalize_hls(AXI_STREAM24& INPUT_STREAM, AXI_STREAM24& OUTPUT_STREAM);

#endif
