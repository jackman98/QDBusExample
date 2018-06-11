#ifndef CONTROLLERADAPTOR_H
#define CONTROLLERADAPTOR_H

#include <QObject>
#include <QGuiApplication>
#include <QDBusAbstractAdaptor>

class ControllerAdaptor : public QDBusAbstractAdaptor
{
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "org.jackman98.main")
	Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(double opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)

public:
	ControllerAdaptor(QGuiApplication *parent);

	QString color() const;
	double opacity() const;

	~ControllerAdaptor();

public slots:
	void setColor(QString color);
	void setOpacity(double opacity);

signals:
	void colorChanged(QString color);
	void opacityChanged(double opacity);

private:
	QString m_color;
	double m_opacity;
};

#endif // CONTROLLERADAPTOR_H
