// QR-Code-Detector.cpp
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;


int main()
{
	// Image Read
	string imgPath = DATA_PATH + "/images/IDCard-Satya.png";
	Mat img = imread(imgPath, 1);

	cout << img.size().height << " " << img.size().width;

	// Create a QRCodeDetector Object
	Mat bbox, rectifiedImage;
	QRCodeDetector qrDecoder = QRCodeDetector();
	
	// Detect QR Code in the Image
	string opencvData = qrDecoder.detectAndDecode(img, bbox, rectifiedImage);

	// Check if a QR Code has been detected
	if (opencvData.length() > 0)
		cout << "QR Code Detected" << endl;
	else
		cout << "QR Code NOT Detected" << endl;

	// Draw the bounding box
	int n{ bbox.rows };
	for (size_t i{}; i < n; i++)
	{
		line(img, Point2i(bbox.at<float>(i, 0), bbox.at<float>(i, 1)),
			Point2i(bbox.at<float>((i + 1) % n, 0), bbox.at<float>((i + 1) % n, 1)),
			Scalar(255, 0, 0), 3);
	}

	// Display the data of QR code
	cout << "QR Code Detected!" << endl;
	cout << "Decoded data: " << opencvData << endl;

	// Save the results
	string resultImagePath = "./QRCode-Output.png";
	imwrite(resultImagePath, img);
	imshow("Result", img);
	//waitKey(0);
}
