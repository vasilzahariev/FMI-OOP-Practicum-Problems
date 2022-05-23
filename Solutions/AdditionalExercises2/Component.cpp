#include "Component.h"

void Component::output(std::ostream& out) const {
	out << m_label << " " << price() << '\n';
}

Component::Component(std::string_view label)
				: m_label(label) {
}
