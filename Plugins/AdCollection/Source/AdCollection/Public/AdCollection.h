// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class FAdCollectionModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

enum enAdsBannerPos
{
	enAdsBannerPos_Top = 0,
	enAdsBannerPos_Bottom,
};


class IAdModuleInterface :public IModuleInterface
{
public:

	virtual void ShowBanner(enAdsBannerPos pos)
	{
	}

	virtual void HideBanner()
	{
	}

	virtual void PlayRewardedVideo() 
	{
	}

	virtual void ShowInterstitialAd()
	{

	}

	virtual bool IsBannerReady()
	{
		return false;
	}

	virtual bool IsInterstitalReady()
	{
		return false;
	}

	virtual bool IsRewardedVideoReady()
	{
		return false;
	}
};