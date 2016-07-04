#include <gtest/gtest.h>
#include <workaround.hpp>
#include "opencv2/core/core.hpp"

#include <iostream>

using namespace cv;

TEST(dummy, dummy_Test1)
{
	MatrixProcessor ap;
	unsigned char *testing = new uchar[4];
	for (int i = 0; i < 4; i++)
	{
		testing[i] = i;
	}
	unsigned char *original = new uchar[4];
	for (int i = 0; i < 3; i++)
	{
		original[i] = 0;
	}
	original[3] = 3;
	ap.Threshold(testing, 2, 2, 3);
	bool flag = true;
	for (int i = 0; i < 4; i++)
	{
		if (original[i] != testing[i])
			flag = false;
	}
	EXPECT_TRUE(flag);

}

TEST(dummy, dummy_test)
{
    Mat mat(3, 7, CV_8UC1, Scalar::all(0));
    Mat submat = mat(Rect(0, 0, 2, 3));



    EXPECT_FALSE(submat.isContinuous());
}
