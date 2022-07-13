// Fill out your copyright notice in the Description page of Project Settings.


#include "RingManager.h"
#include "HeatmapManager.h"

// Sets default values for this component's properties
URingManager::URingManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void URingManager::GenerateRings()
{
	FVector2D resolution = AHeatmapManager::GetGameViewportSize();

	// For now divide by 3 to get A and B as X and Y
	resolution /= 5;

	FVector A, B, C, D;
	A = FVector(800, -resolution.X,	-resolution.Y);
	B = FVector(800, resolution.X,	-resolution.Y);
	C = FVector(800, resolution.X,	resolution.Y);	
	D = FVector(800, -resolution.X,	resolution.Y);

	int count = OuterRingLength - 2;
	FString message = "OuterRingCount: ";
	message.AppendInt(count);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, message);
	OuterRing.Add(A);
	OuterRing.Add(B);
	OuterRing.Add(C);
	OuterRing.Add(D);

	float xLength = (resolution.X * 2) / (count + 1);
	float yLength = (resolution.Y * 2) / (count + 1);
	GLog->Log("xLength: " + FString::FromInt(xLength) + " | yLength: " + FString::FromInt(yLength));
	// add to A	
	for (int i = 0; i < count; ++i)
	{
		FVector AHorizontal = A;
		FVector DHorizontal = D;
		FVector AVertical = A;
		FVector BVertical = B;
		AHorizontal.Y += (xLength) * (i + 1);
		DHorizontal.Y += (xLength) * (i + 1);
		AVertical.Z += (yLength) * (i + 1);
		BVertical.Z += (yLength) * (i + 1);
		OuterRing.Add(AHorizontal);
		OuterRing.Add(DHorizontal);
		OuterRing.Add(AVertical);
		OuterRing.Add(BVertical);
	}

	// Now middle ring, Divide it by 4
	resolution = AHeatmapManager::GetGameViewportSize();
	resolution /= 10;
	// Again, same stuff
	A = FVector(800, -resolution.X,	-resolution.Y);
	B = FVector(800, resolution.X,	-resolution.Y);
	C = FVector(800, resolution.X,	resolution.Y);	
	D = FVector(800, -resolution.X,	resolution.Y);

	count = MiddleRingLength - 2;
	message = "MiddleRingCount: ";
	message.AppendInt(count);
	MiddleRing.Add(A);
	MiddleRing.Add(B);
	MiddleRing.Add(C);
	MiddleRing.Add(D);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, message);

	// add to A	
	xLength = (resolution.X * 2) / (count + 1);
	yLength = (resolution.Y * 2) / (count + 1);
	GLog->Log("xLength: " + FString::FromInt(xLength) + " | yLength: " + FString::FromInt(yLength));
	// add to A	
	for (int i = 0; i < count; ++i)
	{
		FVector AHorizontal = A;
		FVector DHorizontal = D;
		FVector AVertical = A;
		FVector BVertical = B;
		AHorizontal.Y += (xLength) * (i + 1);
		DHorizontal.Y += (xLength) * (i + 1);
		AVertical.Z += (yLength) * (i + 1);
		BVertical.Z += (yLength) * (i + 1);
		MiddleRing.Add(AHorizontal);
		MiddleRing.Add(DHorizontal);
		MiddleRing.Add(AVertical);
		MiddleRing.Add(BVertical);
	}

	// Now inner ring ring, Divide it again
	resolution = AHeatmapManager::GetGameViewportSize();
	resolution /= 20;
	// Again, same stuff
	A = FVector(800, -resolution.X, -resolution.Y);
	B = FVector(800, resolution.X, -resolution.Y);
	C = FVector(800, resolution.X, resolution.Y);
	D = FVector(800, -resolution.X, resolution.Y);

	count = InnerRingLength - 2;
	message = "InnerRingLength: ";
	message.AppendInt(count);
	InnerRing.Add(A);
	InnerRing.Add(B);
	InnerRing.Add(C);
	InnerRing.Add(D);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, message);

	// add to A	
	xLength = (resolution.X * 2) / (count + 1);
	yLength = (resolution.Y * 2) / (count + 1);
	GLog->Log("xLength: " + FString::FromInt(xLength) + " | yLength: " + FString::FromInt(yLength));
	// add to A	
	for (int i = 0; i < count; ++i)
	{
		FVector AHorizontal = A;
		FVector DHorizontal = D;
		FVector AVertical = A;
		FVector BVertical = B;
		AHorizontal.Y += (xLength) * (i + 1);
		DHorizontal.Y += (xLength) * (i + 1);
		AVertical.Z += (yLength) * (i + 1);
		BVertical.Z += (yLength) * (i + 1);
		InnerRing.Add(AHorizontal);
		InnerRing.Add(DHorizontal);
		InnerRing.Add(AVertical);
		InnerRing.Add(BVertical);
	}
}

// Called when the game starts
void URingManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URingManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

