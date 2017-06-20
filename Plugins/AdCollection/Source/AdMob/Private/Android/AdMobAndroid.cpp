#include "AdMob.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "StringConv.h"

DEFINE_LOG_CATEGORY_STATIC(AdCollection, Log, All);

//#define CHECK_JNI_METHOD(Id) checkf(Id != nullptr, TEXT("Failed to find " #Id));

void FAdMobModule::ShowBanner(enAdsBannerPos pos)
{
	//UE_LOG(AdCollection, Log, TEXT("Ready ShowBanner In cpp:%s"), TCHAR_TO_UTF8(*adUnit) );
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID ShowBannerMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_ShowBanner", "(Z)V", bIsOptional);
		//CHECK_JNI_METHOD(ShowBannerMethod);
		if (ShowBannerMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_AdMob_ShowBanner not found") );
			return;
		}

		// Convert scope array into java fields
		//jstring AdUnitIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*adUnit) );
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowBannerMethod, pos == enAdsBannerPos::enAdsBannerPos_Bottom);
	}
}

void FAdMobModule::HideBanner()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID HideBannerMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_HideBanner", "()V", bIsOptional);
		//CHECK_JNI_METHOD(HideBannerMethod);

		if (HideBannerMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_AdMob_HideBanner not found"));
			return;
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, HideBannerMethod);
	}
}

//AndroidThunkJava_AdMob_PlayRewardedVideo

void FAdMobModule::ShowInterstitialAd()
{
	//AndroidThunkJava_AdMob_ShowInterstitialAd
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID ShowInterstitialMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_ShowInterstitialAd", "()V", bIsOptional);
		//CHECK_JNI_METHOD(ShowInterstitialMethod);
		if (ShowInterstitialMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_AdMob_ShowInterstitialAd not found"));
			return;
		}

		// Convert scope array into java fields
		//jstring AdUnitIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*adUnit));
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowInterstitialMethod);
	}
}


void FAdMobModule::PlayAd()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID PlayRewardVideoMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_PlayRewardedVideo", "()V", bIsOptional);
		//CHECK_JNI_METHOD(PlayRewardVideoMethod);

		if (PlayRewardVideoMethod == nullptr)
		{
			UE_LOG(AdCollection, Error, TEXT("AndroidThunkJava_AdMob_PlayRewardedVideo not found"));
			return;
		}

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, PlayRewardVideoMethod);
	}
}