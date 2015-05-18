// ver2
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

#define HAARCASCADE_FACE_DB "c:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml"


int main(void)
{
	// Load the cascades
	CascadeClassifier face_cascade;
	if (!face_cascade.load(HAARCASCADE_FACE_DB))
	{
		printf("Error loading\n");
	}

	// Read the image
	Mat frame;
	frame = imread("./abc.jpg", CV_LOAD_IMAGE_COLOR);

	// detect and display
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// face detection
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	// for all faces in a picture
	for (int i = 0; i < faces.size(); i++)
	{
		// rectangles' left-top and right-bottom position
		Point leftTop(faces[i].x, faces[i].y);
		Point rightBottom(faces[i].x + faces[i].width, faces[i].y + faces[i].height);

		// draw rectangle
		rectangle(frame, leftTop, rightBottom, Scalar(255, 255, 255), 4, 8, 0);
	}

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", frame);

	waitKey(0);

	return 0;
}
