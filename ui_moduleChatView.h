/********************************************************************************
** Form generated from reading UI file 'moduleChatView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULECHATVIEW_H
#define UI_MODULECHATVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeWidgetForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QLineEdit *sampleEdit;
    QLabel *animatedLabel;
    QLineEdit *wealthEdit;
    QLabel *label_4;
    QLineEdit *exchangedEdit;
    QLabel *label;
    QLineEdit *striveEdit;
    QLabel *label_2;
    QLineEdit *taxEdit;
    QLabel *label_3;
    QLineEdit *protectEdit;
    QLabel *legendLabel;
    QComboBox *modeCombox;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *resetBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ThemeWidgetForm)
    {
        if (ThemeWidgetForm->objectName().isEmpty())
            ThemeWidgetForm->setObjectName(QString::fromUtf8("ThemeWidgetForm"));
        ThemeWidgetForm->resize(900, 600);
        verticalLayout = new QVBoxLayout(ThemeWidgetForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        themeLabel = new QLabel(ThemeWidgetForm);
        themeLabel->setObjectName(QString::fromUtf8("themeLabel"));

        horizontalLayout->addWidget(themeLabel);

        sampleEdit = new QLineEdit(ThemeWidgetForm);
        sampleEdit->setObjectName(QString::fromUtf8("sampleEdit"));
        sampleEdit->setEnabled(false);

        horizontalLayout->addWidget(sampleEdit);

        animatedLabel = new QLabel(ThemeWidgetForm);
        animatedLabel->setObjectName(QString::fromUtf8("animatedLabel"));

        horizontalLayout->addWidget(animatedLabel);

        wealthEdit = new QLineEdit(ThemeWidgetForm);
        wealthEdit->setObjectName(QString::fromUtf8("wealthEdit"));
        wealthEdit->setEnabled(false);

        horizontalLayout->addWidget(wealthEdit);

        label_4 = new QLabel(ThemeWidgetForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        exchangedEdit = new QLineEdit(ThemeWidgetForm);
        exchangedEdit->setObjectName(QString::fromUtf8("exchangedEdit"));

        horizontalLayout->addWidget(exchangedEdit);

        label = new QLabel(ThemeWidgetForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        striveEdit = new QLineEdit(ThemeWidgetForm);
        striveEdit->setObjectName(QString::fromUtf8("striveEdit"));

        horizontalLayout->addWidget(striveEdit);

        label_2 = new QLabel(ThemeWidgetForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        taxEdit = new QLineEdit(ThemeWidgetForm);
        taxEdit->setObjectName(QString::fromUtf8("taxEdit"));

        horizontalLayout->addWidget(taxEdit);

        label_3 = new QLabel(ThemeWidgetForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        protectEdit = new QLineEdit(ThemeWidgetForm);
        protectEdit->setObjectName(QString::fromUtf8("protectEdit"));

        horizontalLayout->addWidget(protectEdit);

        legendLabel = new QLabel(ThemeWidgetForm);
        legendLabel->setObjectName(QString::fromUtf8("legendLabel"));

        horizontalLayout->addWidget(legendLabel);

        modeCombox = new QComboBox(ThemeWidgetForm);
        modeCombox->addItem(QString());
        modeCombox->addItem(QString());
        modeCombox->addItem(QString());
        modeCombox->addItem(QString());
        modeCombox->setObjectName(QString::fromUtf8("modeCombox"));

        horizontalLayout->addWidget(modeCombox);

        startBtn = new QPushButton(ThemeWidgetForm);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout->addWidget(startBtn);

        stopBtn = new QPushButton(ThemeWidgetForm);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout->addWidget(stopBtn);

        resetBtn = new QPushButton(ThemeWidgetForm);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));

        horizontalLayout->addWidget(resetBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ThemeWidgetForm);

        QMetaObject::connectSlotsByName(ThemeWidgetForm);
    } // setupUi

    void retranslateUi(QWidget *ThemeWidgetForm)
    {
        themeLabel->setText(QApplication::translate("ThemeWidgetForm", "\346\240\267\346\234\254\344\272\272\346\225\260(M):", nullptr));
        sampleEdit->setText(QApplication::translate("ThemeWidgetForm", "100", nullptr));
        animatedLabel->setText(QApplication::translate("ThemeWidgetForm", "\345\210\235\345\247\213\350\264\242\345\257\214\345\200\274(N):", nullptr));
        wealthEdit->setText(QApplication::translate("ThemeWidgetForm", "100", nullptr));
        label_4->setText(QApplication::translate("ThemeWidgetForm", "\346\257\217\346\254\241\344\272\244\346\215\242\350\264\242\345\257\214\345\200\274:", nullptr));
        exchangedEdit->setText(QApplication::translate("ThemeWidgetForm", "1", nullptr));
        label->setText(QApplication::translate("ThemeWidgetForm", "\345\212\252\345\212\233\347\232\204\344\272\272(x):", nullptr));
        striveEdit->setText(QApplication::translate("ThemeWidgetForm", "20", nullptr));
        label_2->setText(QApplication::translate("ThemeWidgetForm", "\347\250\216\346\224\266:", nullptr));
        taxEdit->setText(QApplication::translate("ThemeWidgetForm", "0.2", nullptr));
        label_3->setText(QApplication::translate("ThemeWidgetForm", "\344\275\216\344\277\235:", nullptr));
        protectEdit->setText(QApplication::translate("ThemeWidgetForm", "20", nullptr));
        legendLabel->setText(QApplication::translate("ThemeWidgetForm", "\346\250\241\345\274\217:", nullptr));
        modeCombox->setItemText(0, QApplication::translate("ThemeWidgetForm", "\344\270\215\350\264\237\345\200\272", nullptr));
        modeCombox->setItemText(1, QApplication::translate("ThemeWidgetForm", "\350\264\237\345\200\272", nullptr));
        modeCombox->setItemText(2, QApplication::translate("ThemeWidgetForm", "\347\250\216\346\224\266\345\222\214\347\244\276\344\277\235", nullptr));
        modeCombox->setItemText(3, QApplication::translate("ThemeWidgetForm", "x\344\270\252\345\212\252\345\212\233\347\232\204\344\272\272", nullptr));

        startBtn->setText(QApplication::translate("ThemeWidgetForm", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        stopBtn->setText(QApplication::translate("ThemeWidgetForm", "\345\201\234\346\255\242\346\250\241\346\213\237", nullptr));
        resetBtn->setText(QApplication::translate("ThemeWidgetForm", "\351\207\215\347\275\256", nullptr));
        Q_UNUSED(ThemeWidgetForm);
    } // retranslateUi

};

namespace Ui {
    class ThemeWidgetForm: public Ui_ThemeWidgetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULECHATVIEW_H
