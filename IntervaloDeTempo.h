#ifndef PROJETO_INTERVALODETEMPO_H
#define PROJETO_INTERVALODETEMPO_H

#include <iostream>
#include <utility>
#include "DataEHora.h"

using namespace std;

class StartDataEHora: public DataEHora {
public:
    StartDataEHora() = default;
    explicit StartDataEHora(const DataEHora & dataEHora);
};

class EndDataEHora: public DataEHora {
public:
    EndDataEHora() = default;
    explicit EndDataEHora(const DataEHora & dataEHora);
};

class IntervaloDeTempo: public StartDataEHora, public EndDataEHora {
public:
    /**
     * Default constructor.
     */
    IntervaloDeTempo() = default;
    /**
     * Class constructor. Initializes beginning and end of interval.
     * @param st Beginning of the interval.
     * @param ed End of the interval.
     */
    IntervaloDeTempo(const DataEHora& st, const DataEHora& ed);

    /**
     * Sets beginning and end of interval.
     * @param st Beginning of the interval.
     * @param ed End of the interval.
     * @throws InvalidDate if one of the inputs' sate is not valid
     * @throws InvalidTime if one of the inputs' time is not valid
     * @throws InvalidTimeInterval if interval starts after it finishes
     */
    void set(const DataEHora& st, const DataEHora& ed);
    /**
     * @return Returns the beginning of the interval.
     */
    DataEHora getStart() const;
    /**
     * @return Returns the end of the interval.
     */
    DataEHora getEnd() const;
    /**
     * @return Returns self.
     */
    IntervaloDeTempo getTimeInterval() const;
    /**
     * @return Returns reference to self.
     */
    IntervaloDeTempo& getTimeIntervalRef();
    /**
     * Checks if time interval is valid.
     * @return True if it is false otherwhise.
     */
    bool valid() const override;
    /**
     * @return Formatted string with the time interval.
     */
    string str() const override;
    /**
     * Checks if two time intervals don´t overlap.
     * @return True if there is no overlap. False otherwise.
     */
    bool operator^(const IntervaloDeTempo& timeInterval) const;
    /**
     * Checks if two time intervals are equal.
     * @return True if they are equal. False otherwise.
     */
    bool operator==(const IntervaloDeTempo& timeInterval) const;
    /**
     * Output operator.
     */
    friend ostream& operator<<(ostream& output, const IntervaloDeTempo& timeInterval);
    /**
     * Input operator.
     * @throws InvalidDate if one of the inputs' sate is not valid
     * @throws InvalidTime if one of the inputs' time is not valid
     * @throws InvalidTimeInterval if interval starts after it finishes
     */
    friend istream& operator>>(istream& input, IntervaloDeTempo& timeInterval) noexcept(false);
};

class InvalidTimeInterval: public exception {
    const IntervaloDeTempo timeInterval;
    const string msg;
public:
    explicit InvalidTimeInterval(IntervaloDeTempo TI, string M):timeInterval(std::move(TI)), msg(std::move(M)) {}
    const IntervaloDeTempo & getTimeInterval() { return timeInterval; }
    string getMessage() const { return msg; }
};

#endif //PROJETO_INTERVALODETEMPO_H
