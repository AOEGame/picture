/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.sifun.picture;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;

public class Picture extends Cocos2dxActivity{
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
	}

    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// Picture should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }
    
    private static int SELECT_PICTURE = 0;
    private static int SELECT_CAMERA = 1;
    
    public static void showImageDialog(){
    	Log.v("cocos2dx", "dddddddddddd");
    	CharSequence[] items = {"相册", "相机"};
    	new AlertDialog.Builder(((Picture)getContext())).setTitle("选择").setItems(items, new OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
//				if(which == 0 ){
//					Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
//					intent.addCategory(Intent.CATEGORY_OPENABLE);
////					intent.setType("image/*");
//					((Picture)getContext()).startActivityForResult(Intent.createChooser(intent, "选择"), SELECT_PICTURE);
//					
//				}else{
//					Log.v("cocos2dx", "相机");
//					Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
//					((Picture)getContext()).startActivityForResult(intent, SELECT_CAMERA);
//				}
			}
		}).create().show();
    	
    }

    static {
        System.loadLibrary("cocos2dcpp");
    }     
}
