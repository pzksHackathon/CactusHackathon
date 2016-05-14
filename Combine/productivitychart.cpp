#include "productivitychart.h"
ProductivityChart::ProductivityChart(double hours[])
{
    for(int i = 0; i < 7; i++)
        this->hours.push_back(hours[i]);
    this->currentChart = nullptr;
}

void ProductivityChart::setHours(double hours[])
{
    for(int i = 0; i < 7; i++)
        this->hours.pop_back();
    for(int i = 0; i < 7; i++)
        this->hours.push_back(hours[i]);

    if(this->currentChart != nullptr)
    {
        QVector<double> x(7), y(7);
        for(int i = 0; i < 7; i++)
        {
            x[i] = i + 1;
            y[i] = hours[i];
        }
        currentChart->addGraph();
        QCPBars * newBars = new QCPBars(currentChart->xAxis, currentChart->yAxis);
        newBars->setWidth(0.2f);
        currentChart->clearPlottables();
        currentChart->addPlottable(newBars);
        newBars->setName("Country population");
        newBars->setData(x, y);
    }
}

void ProductivityChart::Show(QWidget * widget)
{
    if(this->currentChart == nullptr)
    {
        this->currentChart = new QCustomPlot();

        //this->setCentralWidget(customPlot);

        currentChart->setGeometry(50, 50, 100, 100);
        currentChart->xAxis->setRange(0, 7.9);
        currentChart->yAxis->setRange(0, 12);
        this->setHours(&(this->hours.at(0)));

        // create plot (from quadratic plot example):

    }
    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLayout->addWidget((QWidget *)currentChart);
    widget->setLayout(mainLayout);
}
