

#include "STD_TYPES.h"
#include "MAP.h"

sint32 Map(sint32 InputMin,sint32 InputMax,sint32 OutputMin,sint32 OutputMax,sint32 InputValue)
{

    return (((OutputMax - OutputMin) * (InputValue - InputMin)) / (InputMax - InputMin)) + OutputMin ;
}