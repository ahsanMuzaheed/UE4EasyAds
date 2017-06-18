// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollection.h"
#include "AdCollectionBPLibrary.h"

UAdCollectionBPLibrary::UAdCollectionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UAdCollectionBPLibrary::AdCollectionSampleFunction(float Param)
{
	return -1;
}

bool UAdCollectionBPLibrary::PlayAdVideo(EAdType adType)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EAdType"), true);
	if (!EnumPtr) return false;

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
	if (Module != NULL)
	{
		return Module->PlayAd();
	}

	return false;
}
