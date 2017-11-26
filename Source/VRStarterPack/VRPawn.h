// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MotionControllerComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "VRPawn.generated.h"

UCLASS()
class VRSTARTERPACK_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
		void CacheMovementInput_LX(float AxisInput);

	UFUNCTION()
		void CacheMovementInput_LY(float AxisInput);

	UFUNCTION()
		void ApplyCachedMovement();


	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UCapsuleComponent * Root;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UMotionControllerComponent * RMotionController;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UMotionControllerComponent * LMotionController;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UStaticMeshComponent * LHandStaticMesh;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UStaticMeshComponent * RHandStaticMesh;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		USkeletalMeshComponent * RHandSkeletalMesh;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		USkeletalMeshComponent * LHandSkeletalMesh;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		USceneComponent * TrackingOrigin;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UCameraComponent * PlayerCamera;

	UPROPERTY(Category = Gameplay, VisibleAnywhere)
		UFloatingPawnMovement * FloatingPawnMovement;

	UPROPERTY(Category = Movement, EditAnywhere)
		float MoveSpeed = 1.0f;

	UPROPERTY(Category = Movement, EditAnywhere)
		float TurnSpeed = 1.0f;

	FVector CurrentMovementInput = FVector(0.0f, 0.0f, 0.0f);
};