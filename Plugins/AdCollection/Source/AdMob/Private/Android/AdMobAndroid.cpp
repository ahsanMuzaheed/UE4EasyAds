#include "AdMob.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "StringConv.h"

DEFINE_LOG_CATEGORY_STATIC(AdCollection, Log, All);

#define CHECK_JNI_METHOD(Id) checkf(Id != nullptr, TEXT("Failed to find " #Id));

void FAdMobModule::ShowBanner(const FString adUnit, enAdsBannerPos pos)
{
	//UE_LOG(AdCollection, Log, TEXT("Ready ShowBanner In cpp:%s"), TCHAR_TO_UTF8(*adUnit) );
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID ShowBannerMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_ShowBanner", "(Ljava/lang/String;Z)V", bIsOptional);
		CHECK_JNI_METHOD(ShowBannerMethod);

		// Convert scope array into java fields
		jstring AdUnitIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*adUnit) );
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, ShowBannerMethod, AdUnitIDArg, pos == enAdsBannerPos::enAdsBannerPos_Bottom);
	}
}

void FAdMobModule::HideBanner()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID HideBannerMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdMob_HideBanner", "()V", bIsOptional);
		CHECK_JNI_METHOD(HideBannerMethod);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, HideBannerMethod);
	}
}