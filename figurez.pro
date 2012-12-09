TEMPLATE = app
SOURCES	 += main.cpp \
           rectangle.cpp \
           figure.cpp \
           board.cpp \
           game.cpp \
           hline.cpp \
           vline.cpp \
           diamond.cpp
HEADERS += figure.h \
          rectangle.h \
          const.h \
          board.h \
          game.h \
          hline.h \
          vline.h \
          diamond.h
win32:TARGET	 = ../figurez
