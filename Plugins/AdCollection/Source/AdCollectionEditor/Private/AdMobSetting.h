// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "AdMobSetting.generated.h"

/**
 * 
 */
UCLASS(config = Engine, globaluserconfig)
class UAdMobAndroidSetting : public UObject
{
	GENERATED_BODY()
	
		UPROPERTY(GlobalConfig, EditAnywhere, Category = Android, Meta = (DisplayName = "If Is AdMob Enable"))
		bool bEnabled;

	UPROPERTY(GlobalConfig, EditAnywhere, Category = Android, Meta = (DisplayName = "AdMob AppID"))
		FString AppId;

	UPROPERTY(GlobalConfig, EditAnywhere, Category = Android, Meta = (DisplayName = "AdMob RewardVideo AdUnit"))
	FString RewardedVideoAdUnit;
	
#if WITH_EDITOR
		// UObject interface
		virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
