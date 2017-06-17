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

bool UAdCollectionBPLibrary::PlayAdVideo(const FName& AdPlatform)
{
	IAdModuleInterface * Module = FModuleManager::Get().LoadModulePtr<IAdModuleInterface>(AdPlatform);
	if (Module != NULL)
	{
		return Module->PlayAd();
	}

	return false;
}
