// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameinstance.h"

#include "Engine/Engine.h"

void UPuzzlePlatformsGameinstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("gameinstance init"))
}

UPuzzlePlatformsGameinstance::UPuzzlePlatformsGameinstance(const FObjectInitializer & FObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Gameinstance Constructor"))
}

void UPuzzlePlatformsGameinstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Hosting"));

	// Server Travelling
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");

}

void UPuzzlePlatformsGameinstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	// Client Travelling
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController!= nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
