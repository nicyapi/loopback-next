/*****************************************************************************
 *  Cartoonifier, for Desktop or Android.
 *  by Shervin Emami, 2012 (shervin.emami@gmail.com)
 *  http://www.shervinemami.info/
 *  Ch1 of the book "Mastering OpenCV with Practical Computer Vision Projects"
 *  Copyright Packt Publishing 2012.
 *****************************************************************************/

 package com.Cartoonifier;

import android.content.Context;
import android.graphics.Bitmap;

// For saving Bitmaps to file and the Android picture gallery.
import android.graphics.Bitmap.CompressFormat;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.provider.MediaStore.Images;
import android.text.format.DateFormat;
import android.util.Log;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.util.Date;

// For showing a Notification message when saving a file.
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.ContentValues;
import android.content.Intent;


class CartoonifierView extends CartoonifierViewBase {
    private static final String TAG = "CartoonifierView";
    
    private int mFrameSize;
    private Bitmap mBitmap;
    private int[] mRGBA;

    // Set to true if you want to see line drawings instead of paintings.
    private boolean m_sketchMode = false;
    // Set to true if you want to change the skin color of the character to an alien color.
    private boolean m_alienMode = false;
    // Set to true if you want an evil "bad" character instead of a "good" character.
    private boolean m_evilMode = false;
    // Set to true if you want to see many windows created, showing various debug info. Set to 0 otherwise.
    private boolean m_debugMode = false;
    
    // Whether to cartoonify the next camera frame and save it, instead of just showing the sketch.
    private boolean bSaveThisFrame = false;
    // After processing, don't update the screen for a while, so the user can see the cartoonifier output.
    private boolean bFreezeOutput = false;
    // Set the delay of showing the processed image before displaying the next camera frames.
    private static final int FREEZE_OUTPUT_MSECS = 3000;

    private Context mContext;  // Activity Context, so we can store to the Android Gallery.
    
    private int mNotificationID = 0;    // Notification ID, so we can show a status notification message whenever an image is saved.
    
    
    
    public CartoonifierView(Context context) {
        super(context);
    }

    @Override
    protected void onPreviewStarted(int previewWidth, int previewHeight) {
        mFrameSize = previewWidth * previewHeight;
        mRGBA = new int[mFrameSize];
        mBitmap = Bitmap.createBitmap(previewWidth, previewHeight, Bitmap.Config.ARGB_8888);
    }

    @Override
    protected void onPreviewStopped() {
        if(mBitmap != null) {
            mBitmap.recycle();
            mBitmap = null;
        }
        mRGBA = null;
    }

    // Show a notification message, saying that we've saved another image to the Gallery.
    protected void showNotificationMessage(Context context, String filename)
    {
        // Popup a notification message in the Android status bar. To make sure a notification
        // is shown for each image but only 1 is kept in the statusbar at a time, use a
        // different ID each time but delete previous messages before creating it.
        
        final NotificationManager mgr = (NotificationManager)context.getSystemService(Context.NOTIFICATION_SERVICE);
    
        // Close the previous popup message, so we only have 1 at a time, but it still shows a popup message for each one.
        if (mNotificationID > 0)
            mgr.cancel(mNotificationID);
        mNotificationID++;
    
        Notification notification = new Notification(R.drawable.icon, "Saving to gallery (im