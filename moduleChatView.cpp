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

#include "moduleChatView.h"
#include "ui_moduleChatView.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QPushButton>
#include <QDebug>

#pragma character_execute_set("utf-8")
chartViewWidget::chartViewWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui_ThemeWidgetForm)
{
    m_ui->setupUi(this);
    for (int i(0); i < x_max; i++)
    {
        distributionTable.append(y_max);
        sortTable.append(y_max);
    }
    distributionChartView = new QChartView(createBarChart("Wealth distribution chart", &distributionSet));
    distributionSet->setLabel("Money : Round(0)");
    sortChartView = new QChartView(createBarChart("Wealth sort chart", &sortSet));
    sortSet->setLabel("Money Sorted : Round(0)");
    m_ui->verticalLayout->addWidget(distributionChartView);
    m_ui->verticalLayout->addWidget(sortChartView);
    m_charts << distributionChartView << sortChartView;
    for (int i = 0; i < distributionTable.size(); i++) {
        distributionSet->replace(i, initialWealth);
        distributionTable.replace(i, initialWealth);
        sortSet->replace(i, initialWealth);
        sortTable.replace(i, initialWealth);
    }
    // Set the colors from the light theme as default ones
    initUI();
    timer.setInterval(20);
    connect(&timer, &QTimer::timeout, this, &chartViewWidget::distributeWealth);
    connect(m_ui->startBtn, &QPushButton::clicked, this, &chartViewWidget::startSimulation);
    connect(m_ui->stopBtn, &QPushButton::clicked, this, &chartViewWidget::stopSimulation);
    connect(m_ui->resetBtn, &QPushButton::clicked, this, &chartViewWidget::resetSimulator);
    connect(m_ui->modeCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(modeChanged(int)));
    connect(m_ui->exchangedEdit, &QLineEdit::textEdited, this, &chartViewWidget::exchangeAmountChanged);
    connect(m_ui->taxEdit, &QLineEdit::textEdited, this, &chartViewWidget::taxChanged);
    connect(m_ui->protectEdit, &QLineEdit::textEdited, this, &chartViewWidget::protectChanged);

}

chartViewWidget::~chartViewWidget()
{
    delete m_ui;
}

QChart *chartViewWidget::createBarChart(QString chartName, QBarSet **bs)
{
    QChart *chart = new QChart();
    chart->setTitle(chartName);
    QStackedBarSeries *series = new QStackedBarSeries(chart);
    series->setBarWidth(1);
    *bs = new QBarSet("样本个体");
    for (auto it : distributionTable)
    {
        **bs << it;
    }
    series->append(*bs);
    chart->addSeries(series);
    chart->createDefaultAxes();
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(x_min, x_max);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("样本个体");
    axisX->setGridLineVisible(true);
    axisX->setMinorTickCount(9);
    axisX->setTickCount(x_max / 10 + 1);
    axisX->setMinorGridLineVisible(false);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(y_min, y_max);
    axisY->setLabelFormat("%g");
    axisY->setTitleText(("财富"));
    axisY->setGridLineVisible(true);
    axisY->setMinorTickCount(4);
    axisY->setTickCount(y_max / 50 + 1);
    axisY->setMinorGridLineVisible(false);
    chart->setAxisX(axisX);
    chart->setAxisY(axisY);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    return chart;
}

void chartViewWidget::startSimulation()
{
    timer.start();
}

void chartViewWidget::stopSimulation()
{
    timer.stop();
}

void chartViewWidget::resetSimulator()
{
    distributionSet->setLabel("Money : Round(0)");
    sortSet->setLabel("Money Sorted : Round(0)");
    for (int i = 0; i < distributionTable.size(); i++) {
        distributionSet->replace(i, initialWealth);
        distributionTable.replace(i, initialWealth);
        sortSet->replace(i, initialWealth);
        sortTable.replace(i, initialWealth);
    }
}

void chartViewWidget::distributeWealth()
{
    static int nums = 0;
    int size = distributionTable.size();
    for (int i = 0; i < size; i++)
    {
        int receiver_i = i;
        while (receiver_i == i)
        {
            receiver_i = QRandomGenerator::global()->bounded(0, size);
        }
        int money = distributionTable.at(i);
        int extra = 0;
        int totalReceive = 0;
        switch (mode) {
        case Normal :
            if(money <= 0)
                continue;
            break;
        case InDebt :
            break;
        case Protect:
            //每次扣税%20
            extra -= exchangeAmount * tax;
            //如果处于低保金额，补贴5元
            if(money < protectAmount)
                distributionTable[i] += 5;
            break;
        case TrivePeople:
            //如果接受财富的人处于trivePeople的行列，增加%1的收益
            if(receiver_i < trivePeople)
                extra += exchangeAmount * 0.01;
            break;
        }
        totalReceive = exchangeAmount + extra;
        distributionTable[receiver_i] += totalReceive;
        distributionTable[i] -= exchangeAmount;
        distributionSet->replace(i, distributionTable[i]);
        distributionSet->replace(receiver_i, distributionTable[receiver_i]);
        distributionSet->setLabel("Money : Round(" + QString::number(nums) + ")");
    }
    sortTable = distributionTable;
    qSort(sortTable.begin(), sortTable.end());
    for (int j = 0; j < sortTable.size(); j++)
    {
        qreal v = sortTable.at(j);
        sortSet->replace(j, v);
    }
    sortSet->setLabel("Money Sorted: Round(" + QString::number(nums++) + ")");
}

void chartViewWidget::modeChanged(int i)
{
    mode = Mode(i);
}

void chartViewWidget::exchangeAmountChanged(QString num)
{
    exchangeAmount = num.toInt();
}

void chartViewWidget::taxChanged(QString s_tax)
{
    tax = s_tax.toDouble();
}

void chartViewWidget::protectChanged(QString s_protect)
{
    protectAmount = s_protect.toInt();
}

void chartViewWidget::trivePeopleChaned(QString s_trivePeople)
{
    trivePeople = s_trivePeople.toInt();
}

void chartViewWidget::initUI()
{
    for (QChartView *chartView : m_charts)
    {
        chartView->setRenderHint(QPainter::Antialiasing, true);
        chartView->chart()->setTheme(QChart::ChartTheme::ChartThemeDark);
        chartView->chart()->legend()->setAlignment(Qt::AlignTop);
        chartView->chart()->legend()->show();
    }
    // Set palette colors based on selected theme
    QPalette pal = window()->palette();
    pal.setColor(QPalette::Window, QRgb(0x9e8965));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));
    window()->setPalette(pal);
}

