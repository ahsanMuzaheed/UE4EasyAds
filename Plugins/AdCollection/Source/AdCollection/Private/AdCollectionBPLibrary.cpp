// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollection.h"
#include "AdCollectionBPLibrary.h"

UAdCollectionBPLibrary::UAdCollectionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

static IAdModuleInterface* FindAdsModule(EAdType adType)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EAdType"), true);
	if (!EnumPtr) return nullptr;

	FString EnumName = EnumPtr->GetNameByValue((int64)adType).ToString();

	FName adPlatformName;
	int32 ScopeIndex = EnumName.Find(TEXT("::"), ESearchCase::CaseSensitive);
	if (ScopeIndex != INDEX_NONE)
	{
		adPlatformName = FName(*EnumName.Mid(ScopeIndex + 2));
	}
	else
	{
		adPlatformName = FName(*EnumName);
	}

	IAdModuleInterface * Module = FModuleManager::Get().LoadModulePtr<IAdModuleInterface>(adPlatformName);

	return Module;
}


bool UAdCollectionBPLibrary::PlayAdVideo(EAdType adType)
{
	IAdModuleInterface* Module = FindAdsModule(adType);
	if (Module != NULL)
	{
		return Module->PlayAd();
	}

	return false;
}



void UAdCollectionBPLibrary::ShowBanner(EAdType adType, const FString& adUnit, bool isOnBottom)
{
	IAdModuleInterface* Module = FindAdsModule(adType);
	if (Module != NULL)
	{
		enAdsBannerPos pos = enAdsBannerPos::enAdsBannerPos_Bottom;
		if (!isOnBottom) pos = enAdsBannerPos::enAdsBannerPos_Top;
		return Module->ShowBanner(adUnit, pos);
	}
}


void UAdCollectionBPLibrary::HideBanner(EAdType adType)
{
	IAdModuleInterface* Module = FindAdsModule(adType);
	if (Module != NULL)
	{
		Module->HideBanner();
	}
}
