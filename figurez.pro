TEMPLATE = app
QT+= widgets
SOURCES	 += main.cpp \
           rectangle.cpp \
           figure.cpp \
           board.cpp \
           game.cpp \
           hline.cpp \
           vline.cpp \
           diamond.cpp \
           output_widget.cpp \
           window_interface.cpp \
           const.cpp
HEADERS += figure.h \
          rectangle.h \
          const.h \
          board.h \
          game.h \
          hline.h \
          vline.h \
          diamond.h \
          output_widget.h \
          window_interface.h
win32:TARGET	 = ../figurez

RESOURCES += \
    figurez.qrc