#ifndef CONSULTANTUTILS_H
#define CONSULTANTUNTILS_H

#include "Computer.h"

class ConsultantUtils {
public:
	static bool isGoodForGaming(const Computer& computer);

	static bool isGoodForTravel(const Computer& computer);
};

#endif // !CONSULTANTUTILS_H
