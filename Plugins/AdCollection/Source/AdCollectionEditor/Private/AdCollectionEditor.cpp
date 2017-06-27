// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollectionEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
#include "VungleSetting.h"
#include "AdMobSetting.h"
#include "UnitySetting.h"
#include "ChartBoostSetting.h"
#include "ISettingsModule.h"

#include "LevelEditor.h"

static const FName AdCollectionEditorTabName("AdCollectionEditor");

#define LOCTEXT_NAMESPACE "FAdCollectionEditorModule"

void FAdCollectionEditorModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		
		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("Vungle"),
			LOCTEXT("Vungle", "Vungle"),
			LOCTEXT("Vungle", "Settings for Vungle"),
			GetMutableDefault<UVungleSetting>()
		);
        
        

		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("AdMob"),
			LOCTEXT("AdMob", "AdMob"),
			LOCTEXT("AdMob", "Settings for AdMob"),
			GetMutableDefault<UAdMobAndroidSetting>()
		);

		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("Unity"),
			LOCTEXT("Unity", "Unity"),
			LOCTEXT("Unity", "Settings for Unity"),
			GetMutableDefault<UUnityAndroidSetting>()
		);


		SettingsModule->RegisterSettings(TEXT("Project"), TEXT("AdCollection"), TEXT("ChartBoost"),
			LOCTEXT("ChartBoost", "ChartBoost"),
			LOCTEXT("ChartBoost", "Settings for ChartBoost"),
			GetMutableDefault<UChartBoostAndroidSetting>()
		);
		
	}
}

void FAdCollectionEditorModule::ShutdownModule()
{
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdCollectionEditorModule, AdCollectionEditor)