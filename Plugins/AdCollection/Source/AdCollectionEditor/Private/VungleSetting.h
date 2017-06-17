// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "VungleSetting.generated.h"

/**
 * 
 */
UCLASS(config = Engine, globaluserconfig)
class UVungleSetting : public UObject
{
	GENERATED_BODY()
	
	
		UPROPERTY(GlobalConfig, EditAnywhere, Category = VungleConfig, Meta = (DisplayName = "If Is Vungle Enable"))
		bool bEnabled;

	UPROPERTY(GlobalConfig, EditAnywhere, Category = VungleConfig, Meta = (DisplayName = "Vungle AppID"))
		FString AppId;


#if WITH_EDITOR
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
