// Fill out your copyright notice in the Description page of Project Settings.

#include "AdCollectionEditor.h"
#include "VungleSetting.h"




#if WITH_EDITOR
void UVungleAndroidSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig();
}
#endif
