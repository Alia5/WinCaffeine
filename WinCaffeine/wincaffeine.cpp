#include "wincaffeine.h"

WinCaffeine::WinCaffeine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(size());

	oldMoni = false;
	oldSleep = false;

	//only enable close button on window
	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

	ticon = QIcon(":/WinCaffeine/wincaf.png");
	trayIcon.setIcon(ticon);
	trayIconMenu.addAction("Keep system awake");
	trayIconMenu.addAction("Keep screens on");
	trayIconMenu.addAction("Quit");

	trayIconMenu.actions().at(0)->setCheckable(true);
	trayIconMenu.actions().at(1)->setCheckable(true);

	ui.centralWidget->setWindowIcon(ticon);


	trayIcon.setContextMenu(&trayIconMenu);

	trayIcon.setToolTip("WinCaffeine");
	trayIcon.setVisible(true);

	connect(&trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

	connect(trayIconMenu.actions().at(0), SIGNAL(triggered()), this, SLOT(on_SleepBox_clicked()));
	connect(trayIconMenu.actions().at(1), SIGNAL(triggered()), this, SLOT(on_MonitorBox_clicked()));
	connect(trayIconMenu.actions().at(2), SIGNAL(triggered()), this, SLOT(programClose()));

	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));

	timer.setInterval(30000);
	timer.start();

}

WinCaffeine::~WinCaffeine()
{
	SetThreadExecutionState(ES_CONTINUOUS);
}

void WinCaffeine::closeEvent(QCloseEvent *event)
{
	if (trayIcon.isVisible()) {
		hide();
		trayIcon.showMessage("WinCaffeine", "I'm runing in the background to keep working!\nIf you want to close me rightclick on my trayicon", QSystemTrayIcon::NoIcon, 3000);
		event->ignore();
	}
}

void WinCaffeine::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::DoubleClick:
		//WIndow show
		showNormal();
		break;
	default:
		;
	}
}

void WinCaffeine::on_SleepBox_clicked()
{
	ui.SleepBox->setChecked(!oldSleep);
	oldSleep = ui.SleepBox->isChecked();
	trayIconMenu.actions().at(0)->setChecked(ui.SleepBox->isChecked());
}

void WinCaffeine::on_MonitorBox_clicked()
{
	ui.MonitorBox->setChecked(!oldMoni);
	oldMoni = ui.MonitorBox->isChecked();
	trayIconMenu.actions().at(1)->setChecked(ui.MonitorBox->isChecked());
	if (ui.MonitorBox->isChecked())
	{
		ui.SleepBox->setDisabled(true);
		trayIconMenu.actions().at(0)->setDisabled(true);
		if (!ui.SleepBox->isChecked())
		{
			forcedNoSleep = true;
			ui.SleepBox->setChecked(true);
			trayIconMenu.actions().at(0)->setChecked(true);
		}
	}
	else
	{
		ui.SleepBox->setDisabled(false);
		trayIconMenu.actions().at(0)->setDisabled(false);
		if (forcedNoSleep)
		{
			ui.SleepBox->setChecked(false);
			trayIconMenu.actions().at(0)->setChecked(false);
			forcedNoSleep = false;
		}
	}
}

void WinCaffeine::programClose()
{
	trayIcon.setVisible(false); //enable window closing
	close();
}

void WinCaffeine::update()
{
	if (ui.MonitorBox->isChecked())
	{
		SetThreadExecutionState(ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED | ES_CONTINUOUS);
	}
	else if (ui.SleepBox->isChecked())
	{
		SetThreadExecutionState(ES_SYSTEM_REQUIRED | ES_CONTINUOUS);
	}
}