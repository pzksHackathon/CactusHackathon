#ifndef PRODUCTIVITYCHART_H
#define PRODUCTIVITYCHART_H
#include <algorithm>
#include <vector>
#include <QWidget>
#include <QBoxLayout>
#include "qcustomplot.h"
using namespace std;
class ProductivityChart{
private:
    vector <double> hours;
    QCustomPlot * currentChart;
public:
    ProductivityChart(double hours[7]);
    void setHours(double hours[7]);
    void Show(QWidget *widget);
};

#endif // PRODUCTIVITYCHART_H
