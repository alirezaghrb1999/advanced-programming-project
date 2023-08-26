#-------------------------------------------------
#
# Project created by QtCreator 2019-07-05T17:57:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MASKAN
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        accept_page.cpp \
        admin.cpp \
        admin_page.cpp \
        aparteman_edit_page.cpp \
        apartemani_page.cpp \
        apartmant.cpp \
        apartmant_home.cpp \
        ejare.cpp \
        ejare_page.cpp \
        foroosh.cpp \
        foroosh_page.cpp \
        insert_maskan.cpp \
        main.cpp \
        mainwindow.cpp \
        maskan.cpp \
        modirregister.cpp \
        my_maskan.cpp \
        north_edit_page.cpp \
        north_vila.cpp \
        observe_edit_maskan.cpp \
        parvande_page.cpp \
        parvandeh.cpp \
        person.cpp \
        request_maskan.cpp \
        search_maskan.cpp \
        signin.cpp \
        singup.cpp \
        south_edit.cpp \
        south_vila.cpp \
        user.cpp \
        user_page.cpp \
        userregister.cpp \
        vahed_page.cpp \
        vila.cpp \
        vila_jonoob_page.cpp \
        vila_shomal_page.cpp

HEADERS += \
        accept_page.h \
        admin.h \
        admin_page.h \
        aparteman_edit_page.h \
        apartemani_page.h \
        apartmant.h \
        apartmant_home.h \
        ejare.h \
        ejare_page.h \
        foroosh.h \
        foroosh_page.h \
        insert_maskan.h \
        mainwindow.h \
        maskan.h \
        modirregister.h \
        my_maskan.h \
        north_edit_page.h \
        north_vila.h \
        observe_edit_maskan.h \
        parvande_page.h \
        parvandeh.h \
        person.h \
        request_maskan.h \
        search_maskan.h \
        signin.h \
        signup.h \
        south_edit.h \
        south_vila.h \
        user.h \
        user_page.h \
        userregister.h \
        vahed_page.h \
        vila.h \
        vila_jonoob_page.h \
        vila_shomal_page.h

FORMS += \
        accept_page.ui \
        admin_page.ui \
        aparteman_edit_page.ui \
        apartemani_page.ui \
        ejare_page.ui \
        foroosh_page.ui \
        insert_maskan.ui \
        mainwindow.ui \
        modirregister.ui \
        my_maskan.ui \
        north_edit_page.ui \
        observe_edit_maskan.ui \
        parvande_page.ui \
        request_maskan.ui \
        search_maskan.ui \
        signin.ui \
        signup.ui \
        south_edit.ui \
        user_page.ui \
        userregister.ui \
        vahed_page.ui \
        vila_jonoob_page.ui \
        vila_shomal_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
