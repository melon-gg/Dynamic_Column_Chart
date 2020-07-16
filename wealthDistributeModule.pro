QT += charts
requires(qtConfig(combobox))

HEADERS += \
    moduleChatView.h

SOURCES += \
    main.cpp \
    moduleChatView.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/chartthemes
INSTALLS += target

FORMS += \
    moduleChatView.ui
