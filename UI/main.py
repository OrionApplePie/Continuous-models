import sys, os
from PyQt5 import QtWidgets

import design


class ExampleApp(
    QtWidgets.QMainWindow, 
    design.Ui_MainWindow
):
    def __init__(self):

        super().__init__()
        self.setupUi(self)
        self.pushButton.clicked.connect(self.browse_folder)

    def browse_folder(self):
        self.listWidget.clear()  # На случай, если в списке уже есть элементы
        directory = QtWidgets.QFileDialog.getExistingDirectory(self, "Выберите папку")
    # открыть диалог выбора директории и установить значение переменной
    # равной пути к выбранной директории

        if directory:  # не продолжать выполнение, если пользователь не выбрал директорию
            for file_name in os.listdir(directory):  # для каждого файла в директории
                self.listWidget.addItem(file_name)   # добавить файл в listWidget


def main():
    app = QtWidgets.QApplication(sys.argv)  # Новый экземпляр QApplication
    window = ExampleApp()  # Создаём объект класса ExampleApp
    window.show()  # Показываем окно
    app.exec_()  # и запускаем приложение


if __name__ == "__main__":
    main()
