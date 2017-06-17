package com.epicgames.ue4;

//import android.os.Bundle;
import android.util.Log;

import com.vungle.publisher.VunglePub;
import com.vungle.publisher.EventListener;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
//import java.util.Set;

/**
 * https://developers.facebook.com/docs/facebook-login/android/
 */
public class Vungle 
{
    private GameActivity activity;
	private Logger VungleLog;
	final VunglePub vunglePub = VunglePub.getInstance();

	private final EventListener vungleListener = new EventListener(){

    @Override
    public void onAdStart() {
        // Called before playing an ad
    }

    @Override
    public void onAdEnd(boolean wasSuccessfulView, boolean wasCallToActionClicked) {
        // Called when the user leaves the ad and control is returned to your application        
        // if wasSuccessfulView is true, the user watched the ad and should be rewarded        
        // (if this was a rewarded ad).
        // if wasCallToActionClicked is true, the user clicked the call to action
        // button in the ad.
    }

    @Override
    public void onAdPlayableChanged(boolean isAdPlayable) {
        // Called when the playability state changes. if isAdPlayable is true, you can now        
        // play an ad.
        // If false, you cannot yet play an ad.
		VungleLog.debug("Vungle: onAdPlayableChanged:" + isAdPlayable);
    }

    @Override
    public void onAdUnavailable(String reason) {
        // Called when VunglePub.playAd() was called, but no ad was available to play
		VungleLog.debug("Vungle: onAdUnavailable:" + reason);
    }

  };


   
	/** Constructor */
    public Vungle(GameActivity activity, final Logger InLog) 
	{
        this.activity = activity;
		VungleLog = new Logger("UE4-Vungle");
    } 

	public void OnPause()
	{
		vunglePub.onPause();
	}

	public boolean PlayAd()
	{
		VungleLog.debug("Vungle:play Ads " + vunglePub.isAdPlayable() );
		if(vunglePub.isAdPlayable() )
		{
			vunglePub.playAd();
			return true;
		}

		return false;
	}

	public void InitVungle(final String AppId)
	{
		VungleLog.debug("Vungle:Init:" + AppId);
		vunglePub.init(activity, AppId);
		vunglePub.setEventListeners(vungleListener);
	}

	public void onResume()
	{
		vunglePub.onResume();
	}
}