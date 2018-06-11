#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDBusInterface>

class Controller : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(double opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)

public:
	explicit Controller(QObject *parent = nullptr);

	QString color() const;
	double opacity() const;

signals:
	void colorChanged(QString color);
	void opacityChanged(double opacity);

public slots:
	void setColor(QString color);
	void setOpacity(double opacity);

private:
	QString m_color;
	double m_opacity;
	QDBusInterface *m_interface;
};

#endif // CONTROLLER_H
