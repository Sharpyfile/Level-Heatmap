// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RingManager.generated.h"


UCLASS(Blueprintable)
class LEVELHEATMAP_API URingManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URingManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		TArray<FVector> OuterRing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		TArray<FVector> MiddleRing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		FVector Inner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		int OuterRingLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		int MiddleRingLength;

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "GenerateRings"))
		void GenerateRings();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
