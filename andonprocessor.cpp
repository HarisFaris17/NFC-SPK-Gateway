#include "andonprocessor.h"

AndonProcessor::AndonProcessor(QObject *parent) : QObject(parent)
{

}

void AndonProcessor::started()
{
    qDebug() << "Andon Processor started";
}
