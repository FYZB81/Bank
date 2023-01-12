QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    Bank.cpp \
    Client.cpp \
    Date.cpp \
    Employee.cpp \
    Facilityemployee.cpp \
    File.cpp \
    Loan.cpp \
    Manager.cpp \
    Person.cpp \
    client_menu.cpp \
    clientmainwindow.cpp \
    employee_menu.cpp \
    employeemainwindow.cpp \
    facility_menu.cpp \
    main.cpp \
    mainwindow.cpp \
    makeclient.cpp \
    manager_menu.cpp \
    show_client_information.cpp \
    show_employee_information.cpp \
    show_loan_information.cpp \
    show_personal_client_information.cpp \
    show_waiting_line.cpp

HEADERS += \
    Account.h \
    Bank.h \
    Client.h \
    Date.h \
    Employee.h \
    Error.h \
    Facilityemployee.h \
    File.h \
    Loan.h \
    Manager.h \
    Person.h \
    client_menu.h \
    clientmainwindow.h \
    employee_menu.h \
    employeemainwindow.h \
    facility_menu.h \
    mainwindow.h \
    makeclient.h \
    manager_menu.h \
    show_client_information.h \
    show_employee_information.h \
    show_loan_information.h \
    show_personal_client_information.h \
    show_waiting_line.h

FORMS += \
    client_menu.ui \
    clientmainwindow.ui \
    employee_menu.ui \
    employeemainwindow.ui \
    facility_menu.ui \
    mainwindow.ui \
    makeclient.ui \
    manager_menu.ui \
    show_client_information.ui \
    show_employee_information.ui \
    show_loan_information.ui \
    show_personal_client_information.ui \
    show_waiting_line.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
