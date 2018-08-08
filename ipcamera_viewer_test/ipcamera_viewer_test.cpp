#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	String rtsp_addr = "rtsp://admin:a1234567@192.168.5.186:554/MPEG-4/ch1/main/av_stream";

	VideoCapture cap(rtsp_addr);
	//    cap.open(rtsp_addr);

	Mat frame;

	for (;;) {
		cap >> frame;
		if (frame.empty())
			break;

		imshow("Video Stream", frame);

		if (waitKey(10) == 'q')
			break;
	}
}