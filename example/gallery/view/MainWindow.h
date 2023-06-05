﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Navigation/NavigationInterface.h"

#include <FramelessHelper/Widgets/framelessmainwindow.h>

#include <QFrame>

class QHBoxLayout;
class PopUpAniStackedWidget;
class GalleryTitleBar;
class FluentIcon;

class HomeInterface;

FRAMELESSHELPER_BEGIN_NAMESPACE
class StandardTitleBar;
FRAMELESSHELPER_END_NAMESPACE

class StackedWidget : public QFrame
{
    Q_OBJECT
public:
    StackedWidget(QWidget *parent = nullptr);

    void addWidget(QWidget *widget);

    void setCurrentWidget(QWidget *widget, bool popOut = false);

    void setCurrentIndex(int index, bool popOut = false);

signals:
    void currentWidgetChanged(QWidget *);

private:
    QHBoxLayout *m_hBoxLayout;
    PopUpAniStackedWidget *m_view;
};

namespace Ui
{
    class MainWindow;
}

class MainWindow : public FRAMELESSHELPER_PREPEND_NAMESPACE(FramelessMainWindow)
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr, const Qt::WindowFlags flags = {});
    ~MainWindow() override;

    void waitReady();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void initialize();

    void initLayout();

    void initNavigation();

    void initWindow();

    void switchTo(QWidget *widget, bool triggerByUser = true);

    void resizeEvent(QResizeEvent *event) override;

    void switchToSample(QString routeKey, int index);

public slots:
    void showMessageBox();
    void homeInterfaceClicked(bool user);

private:
    GalleryTitleBar *m_titleBar  = nullptr;
    Ui::MainWindow *m_mainWindow = nullptr;

    QHBoxLayout *m_hBoxLayout;
    QHBoxLayout *m_widgetLayout;
    StackedWidget *m_stackWidget;
    NavigationInterface *m_navigationInterface;

    HomeInterface *m_homeInterface;
};

#endif  // MAINWINDOW_H