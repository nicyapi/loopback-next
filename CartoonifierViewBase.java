/*****************************************************************************
 *  Cartoonifier, for Desktop or Android.
 *  by Shervin Emami, 2012 (shervin.emami@gmail.com)
 *  http://www.shervinemami.info/
 *  Ch1 of the book "Mastering OpenCV with Practical Computer Vision Projects"
 *  Copyright Packt Publishing 2012.
 *****************************************************************************/

package com.Cartoonifier;

import java.io.IOException;
import java.util.List;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ImageFormat;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.hardware.Camera.PreviewCallback;
import android.os.Build;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public abstract class CartoonifierViewBase extends SurfaceView implements SurfaceHolder.Callback, Runnable {
    private static final String TAG = "Cartoonifier::SurfaceView";

    private Camera              mCamera;
    private SurfaceHolder       mHolder;
    private int                 mFrameWidth;
    private int                 mFrameHeight;
    private byte[]              mFrame;
    private boolean             mThreadRun;
    private byte[]              mBuffer;

    // Signal that a camera frame is ready, without blocking the main thread.
    private boolean mCameraIsInitialized = false;

    
    public CartoonifierViewBase(Context context) {
        super(context);
        mHolder = getHolder();
        mHolder.addCallback(this);
        Log.i(TAG, "Instantiated new " + this.getClass());
    }

    public int getFrameWidth() {
        return mFrameWidth;
    }

    public int getFrameHeight() {
        return mFrameHeight;
    }

    public void setPreview() throws IOException {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB)
            mCamera.setPreviewTexture( new SurfaceTexture(10) );
        else
            mCamera.setPreviewDisplay(null);
    }

    public boolean openCamera() {
        Log.i(TAG, "openCamera");
        releaseCamera();
        mCamera = Camera.open();
        if(mCamera == null) {
            Log.e(TAG, "Can't open camera!");
            return false;
        }

        mCamera.setPreviewCallbackWithBuffer(new PreviewCallback() {
            public void onPreviewFrame(byte[] data, Camera camera) {
                // Whenever a camera preview frame is ready, just copy it straight to our mFrame,
                // and don't worry about blocking the main UI thread until it is safe.
                System.arraycopy(data, 0, mFrame, 0, data.length);
                camera.addCallbackBuffer(mBuffer);
                
                // Signal that a camera frame is ready, without blocking the main thread.
                mCameraIsInitialized = true;
            }
        });
        return true;
    }
    
    public void releaseCamera() {
        Log.i(TAG, "releaseCamera");
        mThreadRun = false;
        synchronized (this) {
            if (mCamera != null) {
                mCamera.stopPreview();
                mCamera.setPreviewCallback(null);
                mCamera.release();
                mCamera = null;
                
                // If this app was paused and restarted, it should wait for camera initialization again.
                mCameraIsInitialized = false;
            }
        }
        onPreviewStopped();
    }
    
    public void setupCamera(int width, int height) {
        Log.i(TAG, "setupCamera(" + width + "x" + height + ")");
        synchronized (this) {
            if (mCamera != null) {
                Camera.Parameters params = mCamera.getParameters();
                List<Camera.Size> sizes = params.getSupportedPreviewSizes();
                mFrameWidth = width;
                mFrameHeight = height;

                // selecting optimal camera preview size that is most similar to the screen height.
                {
                    int  minDiff = Integer.MAX_VALUE;
                    