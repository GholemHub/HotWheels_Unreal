// IDataMigrationInterface.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDataMigrationInterface.generated.h"

UINTERFACE(MinimalAPI)
class UDataMigrationInterface : public UInterface
{
    GENERATED_BODY()
};

class VEHOCLEPROJECT_API IDataMigrationInterface
{
    GENERATED_BODY()

public:
    virtual void MigrateRoundCount(class AMenuGameModeBase* MenuGameMode) = 0;
};
