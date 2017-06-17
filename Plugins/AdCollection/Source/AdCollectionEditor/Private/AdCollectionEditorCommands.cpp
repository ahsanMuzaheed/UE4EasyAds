#include "AdCollectionEditor.h"
#include "AdCollectionEditorCommands.h"


#define LOCTEXT_NAMESPACE "FAdCollectionEditorModule"

void FAdCollectionEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "AdCollectionEditor", "Bring up EditorWindow window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
