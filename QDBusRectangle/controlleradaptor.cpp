#include "controlleradaptor.h"
#include <QDBusConnection>

ControllerAdaptor::ControllerAdaptor(QGuiApplication *parent) : QDBusAbstractAdaptor(parent) {
	QDBusConnection::sessionBus().registerService("org.jackman98.DBus");
	QDBusConnection::sessionBus().registerObject("/QDBusRectangle", parent);
	setColor("white");
	setOpacity(1.0);
}

ControllerAdaptor::~ControllerAdaptor() {}

QString ControllerAdaptor::color() const
{
	return m_color;
}

void ControllerAdaptor::setColor(QString color)
{
	if (m_color == color)
		return;
	m_color = color;
	emit colorChanged(m_color);
}

double ControllerAdaptor::opacity() const
{
	return m_opacity;
}

void ControllerAdaptor::setOpacity(double opacity)
{
	if (qFuzzyCompare(m_opacity, opacity))
		return;

	m_opacity = opacity;
	emit opacityChanged(m_opacity);
}
