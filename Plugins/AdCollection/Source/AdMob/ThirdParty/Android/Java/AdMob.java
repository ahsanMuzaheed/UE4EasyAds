/**
 * Created by feixu on 2017/6/18.
 */

package com.epicgames.ue4;

//import android.os.Bundle;
import android.app.Activity;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.PopupWindow;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.logging.Logger;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.InterstitialAd;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.reward.RewardItem;
import com.google.android.gms.ads.reward.RewardedVideoAd;
import com.google.android.gms.ads.reward.RewardedVideoAdListener;

import static com.google.android.gms.internal.zzs.TAG;
//import java.util.Set;

public class AdMob {
    public static final int ANDROID_BUILD_VERSION = android.os.Build.VERSION.SDK_INT;
    private PopupWindow adPopupWindow;
    private AdView adView;
    private boolean adInit = false;
    private LinearLayout adLayout;
    private int adGravity = Gravity.TOP;
    private Activity _activity;

    private LinearLayout activityLayout;

    /** true when the application has requested that an ad be displayed */
    private boolean adWantsToBeShown = false;

    /** true when an ad is available to be displayed */
    private boolean adIsAvailable = false;

    /** true when an ad request is in flight */
    private boolean adIsRequested = false;

    private InterstitialAd mInterstitialAd;
    private  boolean mInterstitialLoaded = false;

    private RewardedVideoAd mRewardAd;
    private boolean mRewardedVideoLoaded = false;

    public AdMob(Activity activity, LinearLayout mainLayout)
    {
        _activity = activity;
        activityLayout = mainLayout;

        Log.d(TAG, "Admob:Init");
    }


    public void InitAdMob(String AppId)
    {
        MobileAds.initialize(_activity, AppId);
    }

    public void playRewardAds(String AdUnit)
    {
        Log.d(TAG, "AdMob:play rewardedvideo:" + AdUnit);
        final String strBackUnit = AdUnit;
        if(mRewardAd == null)
        {
            mRewardAd = MobileAds.getRewardedVideoAdInstance(_activity);
            _activity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Log.d(TAG, "AdMob:play rewardedvideo In UI:" + strBackUnit);
                    mRewardAd.loadAd(strBackUnit, new AdRequest.Builder().build() );
                    mRewardAd.setRewardedVideoAdListener(new RewardedVideoAdListener() {
                        @Override
                        public void onRewardedVideoAdLoaded() {
                            Log.d(TAG, "AdMob:ReeardedVideo Loaded Success");

                            if(!mRewardedVideoLoaded)
                            {
                                mRewardedVideoLoaded = true;
                                mRewardAd.show();
                            }
                        }

                        @Override
                        public void onRewardedVideoAdOpened() {

                        }

                        @Override
                        public void onRewardedVideoStarted() {

                        }

                        @Override
                        public void onRewardedVideoAdClosed() {

                        }

                        @Override
                        public void onRewarded(RewardItem rewardItem) {
                            Log.d(TAG, "AdMob:ReeardedVideo Rewarded");
                        }

                        @Override
                        public void onRewardedVideoAdLeftApplication() {

                        }

                        @Override
                        public void onRewardedVideoAdFailedToLoad(int i) {
                            Log.d(TAG, "AdMob:ReeardedVideo Fail Loads");
                        }
                    });
                }
            });

            return;
        }

        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if(mRewardAd.isLoaded())
                {
                    mRewardAd.show();
                }
                else
                {
                    mRewardAd.loadAd(strBackUnit, new AdRequest.Builder().addTestDevice("D11123E2049EE9FF2D0F5B3B6D8EDEA4").build() );
                }
            }
        });
    }

    public  void OnPause()
    {
        if(mRewardAd != null)
        {
            mRewardAd.pause(_activity);
        }
    }

    public  void OnResume()
    {
        if(mRewardAd != null)
        {
            mRewardAd.resume(_activity);
        }
    }

    public  void OnDestroy()
    {
        if(mRewardAd != null)
        {
            mRewardAd.destroy(_activity);
        }
    }

    private void updateAdVisibility(boolean loadIfNeeded)
    {
        if (!adInit || (adPopupWindow == null))
        {
            return;
        }

        // request an ad if we don't have one available or requested, but would like one
        if (adWantsToBeShown && !adIsAvailable && !adIsRequested && loadIfNeeded)
        {
            AdRequest adRequest = new AdRequest.Builder().addTestDevice("D11123E2049EE9FF2D0F5B3B6D8EDEA4").build();		// add test devices here
            adView.loadAd(adRequest);

            adIsRequested = true;
        }

        if (adIsAvailable && adWantsToBeShown)
        {
            if (adPopupWindow.isShowing())
            {
                return;
            }

            adPopupWindow.showAtLocation(activityLayout, adGravity, 0, 0);
            // don't call update on 7.0 to work around this issue: https://code.google.com/p/android/issues/detail?id=221001
            if (ANDROID_BUILD_VERSION != 24)
            {
                adPopupWindow.update();
            }
        }
        else
        {
            if (!adPopupWindow.isShowing())
            {
                return;
            }

            adPopupWindow.dismiss();
            adPopupWindow.update();
        }
    }

    public void HideAdBanner()
    {
        Log.d(TAG, "In AndroidThunkJava_HideAdBanner");

        if (!adInit)
        {
            return;
        }

        _activity.runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                adWantsToBeShown = false;
                updateAdVisibility(true);
            }
        });
    }

    public  void ShowInterstitialAd(String AdMobAdUnitID)
    {
        Log.d(TAG, "Admob:ShowInterstitialAd AdUnit: " + AdMobAdUnitID);

        if(mInterstitialAd == null)
        {
            mInterstitialAd = new InterstitialAd(_activity);
            mInterstitialAd.setAdUnitId(AdMobAdUnitID);

            _activity.runOnUiThread(new Runnable()
            {
                @Override
                public void run()
                {
                    mInterstitialAd.loadAd(new AdRequest.Builder().addTestDevice("D11123E2049EE9FF2D0F5B3B6D8EDEA4").build());
                }
            });

            mInterstitialAd.setAdListener(new AdListener() {
                @Override
                public void onAdClosed() {
                    // Load the next interstitial.
                    mInterstitialAd.loadAd(new AdRequest.Builder().addTestDevice("D11123E2049EE9FF2D0F5B3B6D8EDEA4").build());
                }

                @Override
                public void onAdLoaded()
                {
                    Log.d(TAG, "AdMob:Interstitial Ads Loaded Success");
                    if(!mInterstitialLoaded)
                    {
                        mInterstitialLoaded = true;
                        mInterstitialAd.show();
                    }
                }
            });

            return;
        }

        _activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if(mInterstitialAd.isLoaded() )
                {
                    mInterstitialAd.show();
                }
            }
        });
    }

    public  void ShowBanner(String AdMobAdUnitID, boolean bShowOnBottonOfScreen)
    {
        Log.d(TAG, "Admob:ShowBanner AdUnit: " + AdMobAdUnitID);

        adGravity = bShowOnBottonOfScreen ? Gravity.BOTTOM : Gravity.TOP;

        if (adInit)
        {
            // already created, make it visible
            _activity.runOnUiThread(new Runnable()
            {
                @Override
                public void run()
                {
                    if ((adPopupWindow == null) || adPopupWindow.isShowing())
                    {
                        return;
                    }

                    adWantsToBeShown = true;
                    updateAdVisibility(true);
                }
            });

            return;
        }

        // init our AdMob window
        adView = new AdView(_activity);
        adView.setAdUnitId(AdMobAdUnitID);
        adView.setAdSize(AdSize.BANNER);

        if (adView != null)
        {
            _activity.runOnUiThread(new Runnable()
            {
                @Override
                public void run()
                {
                    adInit = true;

                    final DisplayMetrics dm = _activity.getResources().getDisplayMetrics();
                    final float scale = dm.density;
                    adPopupWindow = new PopupWindow(_activity);
                    adPopupWindow.setWidth((int)(320*scale));
                    adPopupWindow.setHeight((int)(50*scale));
                    adPopupWindow.setWindowLayoutMode(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
                    adPopupWindow.setClippingEnabled(false);

                    adLayout = new LinearLayout(_activity);

                    final int padding = (int)(-5*scale);
                    adLayout.setPadding(padding,padding,padding,padding);

                    ViewGroup.MarginLayoutParams params = new ViewGroup.MarginLayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);;

                    params.setMargins(0,0,0,0);

                    adLayout.setOrientation(LinearLayout.VERTICAL);
                    adLayout.addView(adView, params);
                    adPopupWindow.setContentView(adLayout);

                    // set up our ad callbacks
                    adView.setAdListener(new AdListener()
                    {
                        @Override
                        public void onAdLoaded()
                        {
                            adIsAvailable = true;
                            adIsRequested = false;
                            Log.d(TAG, "AdMob:" + "AdMob Banner Loaded");
                            updateAdVisibility(true);
                        }

                        @Override
                        public void onAdFailedToLoad(int errorCode)
                        {
                            adIsAvailable = false;
                            adIsRequested = false;

                            Log.d(TAG, "AdMob:" + "AdMob Banner Load Fail:" + errorCode);
                            // don't immediately request a new ad on failure, wait until the next show
                            updateAdVisibility(false);
                        }
                    });

                    adWantsToBeShown = true;
                    updateAdVisibility(true);
                }
            });
        }
    }
}
