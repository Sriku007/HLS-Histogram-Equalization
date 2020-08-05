#include "image.h"

void hist_equalize_hls(AXI_STREAM24& INPUT_STREAM, AXI_STREAM24& OUTPUT_STREAM)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
	//Create AXI Streaming interfaces for the core
#pragma HLS INTERFACE axis register both port=INPUT_STREAM
#pragma HLS INTERFACE axis register both port=OUTPUT_STREAM

	IMAGE_RGB img_in(MAX_HEIGHT, MAX_WIDTH);
	IMAGE_GRAY img2(MAX_HEIGHT, MAX_WIDTH);
	IMAGE_GRAY img3(MAX_HEIGHT, MAX_WIDTH);
	IMAGE_RGB img_out(MAX_HEIGHT, MAX_WIDTH);

#pragma HLS stream depth=1 variable=img_in.data_stream
#pragma HLS stream depth=1 variable=img_out.data_stream


#pragma HLS dataflow
	hls::AXIvideo2Mat(INPUT_STREAM, img_in);

	hls::CvtColor<HLS_BGR2GRAY>(img_in, img2);
	hls::EqualizeHist(img2, img3);
	hls::CvtColor<HLS_GRAY2BGR>(img3, img_out);

	hls::Mat2AXIvideo(img_out, OUTPUT_STREAM);
}
