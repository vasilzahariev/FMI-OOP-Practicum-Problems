#include "ConsultantUtils.h"

bool ConsultantUtils::isGoodForGaming(const Computer& computer) {
	std::string_view processor = computer.getProcessor();
	std::string_view GPU = computer.getGPU();
	const double HDD = std::stod((std::string)computer.getHDD());

	return (processor.find("i5") != std::string::npos ||
			processor.find("i7") != std::string::npos) &&
		   (GPU.find("3060") != std::string::npos ||
			GPU.find("3070") != std::string::npos ||
			GPU.find("3080") != std::string::npos ||
			GPU.find("3090") != std::string::npos) &&
			HDD > 512;
}

bool ConsultantUtils::isGoodForTravel(const Computer& computer) {
	return computer.getWeigth() <= 2.5 &&
		   std::stod((std::string) computer.getBatteryLife()) > 6;
}
