TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lssl -lcrypto

SOURCES += \
        Class/n_tls_client.cpp \
        Class/n_tls_server.cpp \
        main.cpp

HEADERS += \
    Class/n_tls_client.h \
    Class/n_tls_server.h
