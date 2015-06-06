#ifndef WINCAFFEINE_H
#define WINCAFFEINE_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QMenu>
#include <Windows.h>
#include "ui_wincaffeine.h"

class WinCaffeine : public QMainWindow
{
	Q_OBJECT

public:
	WinCaffeine(QWidget *parent = 0);
	~WinCaffeine();

private:
	Ui::WinCaffeineClass ui;

	QTimer timer;

	QSystemTrayIcon trayIcon;
	QIcon ticon;
	QMenu trayIconMenu;

	bool oldSleep;
	bool oldMoni;
	bool forcedNoSleep;

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void programClose();
	void on_SleepBox_clicked();
	void on_MonitorBox_clicked();
	void update();
};

#endif // WINCAFFEINE_H
