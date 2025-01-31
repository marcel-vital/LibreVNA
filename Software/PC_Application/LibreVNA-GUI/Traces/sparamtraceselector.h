#ifndef SPARAMTRACESELECTOR_H
#define SPARAMTRACESELECTOR_H

#include "tracemodel.h"

#include <vector>
#include <map>
#include <QWidget>
#include <QComboBox>

class SparamTraceSelector : public QWidget
{
    Q_OBJECT

public:
    SparamTraceSelector(const TraceModel &model, std::vector<unsigned int> used_ports, bool empty_allowed = false);
    SparamTraceSelector(const TraceModel &model, std::set<unsigned int> used_ports, bool empty_allowed = false);

    bool isValid();

    std::map<QString, Trace*> getTraces();
    unsigned int getPoints() { return points;}

signals:
    void selectionValid(bool valid);

private:
    void setInitialChoices();
    void traceSelectionChanged(QComboBox *cb);
    void createGUI();

    const TraceModel &model;
    std::vector<QComboBox*> boxes;
    bool empty_allowed;

    std::vector<unsigned int> used_ports;
    unsigned int points;
    double minFreq, maxFreq;
    bool valid;
};

#endif // SPARAMTRACESELECTOR_H
