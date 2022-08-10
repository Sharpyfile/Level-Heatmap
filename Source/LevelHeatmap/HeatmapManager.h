// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "HeatmapManager.generated.h"

class AHeatmapObject;

UCLASS()
class LEVELHEATMAP_API AHeatmapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeatmapManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
		TArray<AHeatmapObject*> HeatmapObjects;

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "LoadTxt"))
		bool LoadTxt(FString FileNameA, FString& SaveTextA);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxt"))
		bool SaveTxt(FString SaveTextB, FString FileNameB);	

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "LoadDataNew"))
		void LoadDataNew();

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "ViewportSize"))
		static FVector2D GetGameViewportSize();

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "FindHeatmapObjectByName"))
		AHeatmapObject* FindHeatmapObjectByName(FString objectName);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
