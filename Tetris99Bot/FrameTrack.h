#pragma once
#include <iostream>
extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavutil/imgutils.h>
#include <SDL.h>
#include <SDL_main.h>
};

#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include "piece.h"

#pragma comment(lib ,"SDL2.lib")
#pragma comment(lib ,"SDL2main.lib")

//Refresh Event
#define SFM_REFRESH_EVENT  (SDL_USEREVENT + 1)
#define SFM_BREAK_EVENT  (SDL_USEREVENT + 2)

class FrameTrack {

public:
	static  cv::Rect boardRect;
	static  cv::Rect bigNextPiece;
	static  cv::Rect smallNextPieces[5];
	AVFormatContext *pFormatCtx;
	cv::Mat mat;
	bool nextChanged = false;
	bool filledChanged = false;
	bool grayRowsChanged = false;
	void getFilled(long * rows);
	void getGrayFilled(long * rows);
	void setAllFilled(long * rows, long * grayRows);
	void getNextPieces(Piece ** nextPieces);
	void setNextPieces(Piece ** nextPieces);
	int start();
};