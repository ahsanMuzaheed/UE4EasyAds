// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollectionEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
//#include "AdCollectionEditorStyle.h"
//#include "AdCollectionEditorCommands.h"
#include "VungleSetting.h"
#include "ISettingsModule.h"
#include "VungleSettingsCustomization.h"

#include "LevelEditor.h"

static const FName AdCollectionEditorTabName("AdCollectionEditor");

#define LOCTEXT_NAMESPACE "FAdCollectionEditorModule"

void FAdCollectionEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.RegisterCustomClassLayout(
		UVungleSetting::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FVungleSettingsCustomization::MakeInstance)
	);

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		
		SettingsModule->RegisterSettings("Project", "AdCollection", "Vungle",
			LOCTEXT("AdCollection", "Vungle"),
			LOCTEXT("AdCollection", "Settings for Vungle"),
			GetMutableDefault<UVungleSetting>()
		);
	}
}

void FAdCollectionEditorModule::ShutdownModule()
{
}



#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdCollectionEditorModule, AdCollectionEditor)