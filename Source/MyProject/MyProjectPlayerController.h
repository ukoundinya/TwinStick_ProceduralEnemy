// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BetweenWavesWidget.h"
#include "MyCustomGameInstance.h"
#include "GameFramework/PlayerController.h"
#include "MyProjectPlayerController.generated.h"

UCLASS()
class AMyProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyProjectPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor... */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	//called on Tick Function

public:
	UBetweenWavesWidget* p_BetweenWavesUI;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBetweenWavesWidget> BetweenWavesUI_BP;

public:
	virtual void Possess(APawn* i_Pawn) override;
	void UpdateCollectedItems(FText i_text);

	UFUNCTION(BlueprintCallable, Category = UI)
	void UpdateInstanceParameters();

	UMyCustomGameInstance *p_Instance;

};


