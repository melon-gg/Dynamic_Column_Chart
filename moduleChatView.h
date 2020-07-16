/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QTimer>
#include <QMap>
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
class QBarSet;
QT_CHARTS_END_NAMESPACE

typedef QVector<qreal> DataTable;

QT_CHARTS_USE_NAMESPACE

enum Mode
{
    Normal = 0,
    InDebt,
    Protect,
    TrivePeople
};
class chartViewWidget: public QWidget
{
    Q_OBJECT
public:
    explicit chartViewWidget(QWidget *parent = 0);
    ~chartViewWidget();

private Q_SLOTS:
    void initUI();

private:
    QChart *createBarChart(QString chartName, QBarSet **);

public slots:
    void startSimulation();
    void stopSimulation();
    void resetSimulator();
	void distributeWealth();
    void modeChanged(int i);
    void exchangeAmountChanged(QString num);
    void taxChanged(QString s_tax);
    void protectChanged(QString s_protect);
    void trivePeopleChaned(QString s_trivePeople);
private:
    const static int sampleCounts = 100;
    const static int initialWealth = 100;
	int x_min = 0;
	int x_max = sampleCounts;
	int y_min = -300;
    int y_max = 300;
    QChartView *distributionChartView;
    QChartView *sortChartView;
    QList<QChartView *> m_charts;
    DataTable distributionTable;
	DataTable sortTable;
    QBarSet *distributionSet;
	QBarSet *sortSet;
	QTimer timer;
    Ui_ThemeWidgetForm *m_ui;
    Mode mode = Normal;
    uint8_t exchangeAmount = 1;
    double tax = 0.2;
    int protectAmount = 20;
    int trivePeople = 20;
};

#endif /* THEMEWIDGET_H */
