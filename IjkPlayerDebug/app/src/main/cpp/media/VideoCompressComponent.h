//
// Created by developer on 2018/12/9.
//

#ifndef IJKPLAYERDEBUG_VIDEOCOMPRESSCOMPONENT_H
#define IJKPLAYERDEBUG_VIDEOCOMPRESSCOMPONENT_H


#include "decode/FFmpegDecode.h"
#include "demux/FFmpegDemux.h"
#include "encode/AudioEncoder.h"
#include "encode/VideoEncoder.h"



#include <mutex>

using namespace std;

typedef void(*pF)(void *);
class VideoCompressComponent : public EventHandler<MediaEvent> {
private:
    FFmpegDemux *mDemux = nullptr;
    FFmpegDecode *mVideoFfmpegDecode = nullptr;
    FFmpegDecode *mAudioFfmpegDecode = nullptr;
    AudioEncoder *audioEncoder = nullptr;
    VideoEncoder *videoEncoder = nullptr;
    RtmpStreamer *rtmpStreamer = nullptr;


    mutable mutex mut;

public:


    const char *destPath = nullptr;

    bool isRunning = false;

    VideoCompressComponent();

    virtual ~VideoCompressComponent();

    RtmpStreamer *getRtmpStreamer() const;

    bool initialize();

    FFmpegDemux *getDemux();

    FFmpegDecode *getVideoDecode();

    FFmpegDecode *getAudioDecode();

    AudioEncoder *getAudioEncode();

    VideoEncoder *getVideoEncode();

    bool openSource(const char *url);

    long mScaleWidth;

    long mScaleHeight;


    void setMScaleWidth(long mScaleWidth);


    void setMScaleHeight(long mScaleHeight);

    long getMScaleWidth();

    long getMScaleHeight();

    virtual bool open(const char *url);

    pF mPf = nullptr;

    pF mpF1 = nullptr;

    functionP functionP1 = nullptr;

    void setCallback(void(*pF)(void *));

    void setDestPath(const char *string);

    void release();

    void stop();

    void setStopCallBack(void(*pF)(void *));

    void setProgressCallBack(void (*fun)(long, long));

    AVFormatContext *avFormatContext = NULL;

    virtual void onEvent(MediaEvent &e);


    HandlerRegistration *pRegistration = NULL;
};


#endif //IJKPLAYERDEBUG_VIDEOCOMPRESSCOMPONENT_H
