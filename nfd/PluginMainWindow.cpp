// Copyright (c) 2017-2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "PluginMainWindow.h"
#include "ui_PluginMainWindow.h"

PluginMainWindow::PluginMainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::PluginMainWindow)
{
    ui->setupUi(this);

    Plugin::pFormResult=ui->widgetResult;
}

PluginMainWindow::~PluginMainWindow()
{
    delete ui;
}

void PluginMainWindow::on_pushButtonScan_clicked()
{
    QString sFileName=Plugin::sCurrentFileName;

    if(sFileName!="")
    {
        XScanEngine::SCAN_RESULT scanResult;

        XScanEngine::SCAN_OPTIONS scanOptions= {0};
        scanOptions.bIsRecursiveScan=ui->checkBoxRecursiveScan->isChecked();
        scanOptions.bIsDeepScan=ui->checkBoxDeepScan->isChecked();
        scanOptions.bIsHeuristicScan=ui->checkBoxHeuristicScan->isChecked();

        DialogStaticScanProcess ds(this);
        ds.setData(sFileName,&scanOptions,&scanResult);
        ds.exec();

        ui->widgetResult->setData(scanOptions, scanResult, "result.txt");
    }
}
