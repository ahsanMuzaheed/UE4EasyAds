// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollectionEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
#include "VungleSetting.h"
#include "ISettingsModule.h"

#include "LevelEditor.h"

static const FName AdCollectionEditorTabName("AdCollectionEditor");

#define LOCTEXT_NAMESPACE "FAdCollectionEditorModule"

void FAdCollectionEditorModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		
		SettingsModule->RegisterSettings("Project", "AdCollection", "Vungle",
			LOCTEXT("AdCollection", "Vungle"),
			LOCTEXT("AdCollection", "Settings for Vungle"),
			GetMutableDefault<UVungleAndroidSetting>()
		);
	}
}

void FAdCollectionEditorModule::ShutdownModule()
{
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdCollectionEditorModule, AdCollectionEditor)