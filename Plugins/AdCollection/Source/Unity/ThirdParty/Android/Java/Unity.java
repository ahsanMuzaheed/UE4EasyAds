/**
 * Created by feixu on 2017/6/18.
 */
package com.epicgames.ue4;

import android.app.Activity;
import android.app.ActivityOptions;
import android.util.Log;

import com.unity3d.ads.IUnityAdsListener;
import com.unity3d.ads.UnityAds;

public class Unity {

    private static final String TAG = "Unity";
    private boolean mIsUnityAdsAvaliable = false;
    private Activity _activity;

    public  Unity(Activity activity, String appId)
    {
        Log.d(TAG, "UnityAds Init:" + appId);
        _activity = activity;
        UnityAds.initialize(_activity, appId, new IUnityAdsListener() {
            @Override
            public void onUnityAdsReady(String s) {
                Log.d(TAG, "UnityAds Ready");
            }

            @Override
            public void onUnityAdsStart(String s) {
                Log.d(TAG, "UnityAds Start");
            }

            @Override
            public void onUnityAdsFinish(String s, UnityAds.FinishState finishState) {
                Log.d(TAG, "UnityAds Finish");
            }

            @Override
            public void onUnityAdsError(UnityAds.UnityAdsError unityAdsError, String s) {
                Log.d(TAG, "UnityAds Error:" + s);
            }
        });
    }

    public  void PlayRewardVideo()
    {
        if(UnityAds.isReady() )
        {
            _activity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    UnityAds.show(_activity);
                }
            });
        }
    }
}
