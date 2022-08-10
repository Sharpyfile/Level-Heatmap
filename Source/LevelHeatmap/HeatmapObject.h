// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeatmapObject.generated.h"

UCLASS()
class LEVELHEATMAP_API AHeatmapObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeatmapObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		int64 Counter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		UMaterialInterface* OriginalMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		UMaterialInterface* HeatmapMaterial;

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "GetName"))
		FString GetProperName();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
