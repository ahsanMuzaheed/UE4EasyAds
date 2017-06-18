#include "Vungle.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "StringConv.h"

DEFINE_LOG_CATEGORY_STATIC(AdCollection, Log, All);

#define CHECK_JNI_METHOD(Id) checkf(Id != nullptr, TEXT("Failed to find " #Id));

void FVungleModule::PlayAd()
{
	UE_LOG(AdCollection, Log, TEXT("Ready PLayAd In cpp") );
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		const bool bIsOptional = false;
		static jmethodID PlayAdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Vungle_PlayAd", "()Z", bIsOptional);
		CHECK_JNI_METHOD(PlayAdMethod);

		// Convert scope array into java fields
		FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, PlayAdMethod);
	}
}
