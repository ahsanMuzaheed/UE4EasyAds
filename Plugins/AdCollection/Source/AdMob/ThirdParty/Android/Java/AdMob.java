package com.epicgames.ue4;

//import android.os.Bundle;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import com.google.android.gms.ads.MobileAds;
//import java.util.Set;

/**
 * https://developers.facebook.com/docs/facebook-login/android/
 */
public class AdMob 
{
    private GameActivity activity;
	private Logger AdMobLog;
	private AdView adView;
	
	public AdMob(GameActivity _activity)
	{
		activity = _activity;
		AdMobLog = new Logger("UE4-AdMob");
		adView = new AdView(activity);
		adView.setAdSize(AdSize.BANNER);

	}

	public void InitAdMob(String AppId)
	{
		AdMobLog.debug("AdMob:Init:" + AppId);
		MobileAds.initialize(activity, AppId);
	}

	public void ShowBanner(String AdUnit, )
	{
		
	}
}