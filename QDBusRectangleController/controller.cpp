#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent),
	m_interface(new QDBusInterface("org.jackman98.DBus", "/QDBusRectangle", "org.jackman98.main", QDBusConnection::sessionBus(), this))
{
	setColor("white");
	setOpacity(1.0);
}

QString Controller::color() const
{
	return m_color;
}

double Controller::opacity() const
{
	return m_opacity;
}

void Controller::setColor(QString color)
{
	if (m_color == color)
		return;

	m_interface->call("setColor", color);

	m_color = color;
	emit colorChanged(m_color);
}

void Controller::setOpacity(double opacity)
{
	if (qFuzzyCompare(m_opacity, opacity))
		return;

	m_interface->call("setOpacity", opacity);

	m_opacity = opacity;
	emit opacityChanged(m_opacity);
}

