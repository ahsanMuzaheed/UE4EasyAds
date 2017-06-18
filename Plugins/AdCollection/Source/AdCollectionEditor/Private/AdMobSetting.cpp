// Fill out your copyright notice in the Description page of Project Settings.

#include "AdCollectionEditor.h"
#include "AdMobSetting.h"




#if WITH_EDITOR
void UAdMobAndroidSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig();
}
#endif