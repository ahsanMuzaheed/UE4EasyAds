// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateBasics.h"
#include "AdCollectionEditorStyle.h"

class FAdCollectionEditorCommands : public TCommands<FAdCollectionEditorCommands>
{
public:

	FAdCollectionEditorCommands()
		: TCommands<FAdCollectionEditorCommands>(TEXT("AdCollectionEditor"), NSLOCTEXT("Contexts", "EditorWindow", "EditorWindow Plugin"), NAME_None, FAdCollectionEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};