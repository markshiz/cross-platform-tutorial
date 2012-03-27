package com.mobconverge.CrossPlatformTutorial;

import com.mobconverge.CrossPlatformTutorial.model.CrossPlatformTutorialModel;
import com.mobconverge.CrossPlatformTutorial.utility.AssetCopier;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class CrossPlatformTutorialActivity extends Activity {
	static {  
   	    System.loadLibrary("gnustl_shared");
	    System.loadLibrary("cross-platform-tutorial-model");  
	} 
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        AssetCopier.copyAssetToDataDirectory("db.sqlite", "db.sqlite", this);
        CrossPlatformTutorialModel model = new CrossPlatformTutorialModel();
        CrossPlatformTutorialModel.Person persons[] = model.getAllPersons();
        
        for ( int i = 0; i < persons.length; ++i ){
        	String name = persons[i].getFirstName() + " " + persons[i].getLastName();
        	Log.e("CrossPlatformTutorialActivity",name);
        }
    }
}