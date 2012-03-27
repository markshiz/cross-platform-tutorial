package com.mobconverge.CrossPlatformTutorial.utility;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.Context;

public class AssetCopier {
	private static final String dataDirectory = "/data/data/com.mobconverge.CrossPlatformTutorial/";
	
	public static void copyAssetToDataDirectory(String assetPath, String dataPath, Context context) {
	    try {
	        InputStream in = context.getAssets().open(assetPath);
	        FileOutputStream out = new FileOutputStream(dataDirectory + dataPath);
	        int read;
	        byte[] buffer = new byte[4096];
	        while ((read = in.read(buffer)) > 0) {
	            out.write(buffer, 0, read);
	        }
	        out.close();
	        in.close();

	    } catch (IOException e) {
	        throw new RuntimeException(e);
	    }
	}
}
