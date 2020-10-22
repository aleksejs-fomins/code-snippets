# from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout
import matplotlib.pyplot as plt
from PyQt5.QtWidgets import QApplication, QMainWindow, QAction, QFileDialog
from PyQt5.QtGui import QIcon, QImage, QPainter, QPen, QPixmap
from PyQt5.QtCore import Qt, QPoint
from PyQt5 import QtWidgets, QtCore
import sys
import numpy as np


def test():
    print("hi")
    app = QApplication(sys.argv)
    window = QtWidgets.QWidget()
    layout = QtWidgets.QVBoxLayout()
    layout.addWidget(QtWidgets.QPushButton('Top'))
    layout.addWidget(QtWidgets.QPushButton('Bottom'))
    window.setLayout(layout)
    window.show()
    app.exec_()
    app.quit()