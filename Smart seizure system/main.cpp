#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

/* =========================================
   SENSOR CLASS
========================================= */

class Sensor {

private:
    int heartRate;
    float movement;
    int eegSignal;

public:

    void generateData() {

        int seizureChance = rand() % 10;

        if (seizureChance < 3) {

        // Simulated seizure state

        heartRate = 140 + rand() % 40;

        movement = 6.0 + (rand() % 40) / 10.0;

        eegSignal = 80 + rand() % 50;

     } else {

       // Normal state

       heartRate = 60 + rand() % 50;

       movement = (rand() % 50) / 10.0;

       eegSignal = 10 + rand() % 40;
}
    }

    int getHeartRate() {
        return heartRate;
    }

    float getMovement() {
        return movement;
    }

    int getEEGSignal() {
        return eegSignal;
    }
};

/* =========================================
   DETECTION ENGINE CLASS
========================================= */

class DetectionEngine {

private:
    int seizureCounter;
    bool cooldown;

public:

    DetectionEngine() {

        seizureCounter = 0;

        cooldown = false;
    }

    string analyze(
    int heartRate,
    float movement,
    int eegSignal
) {

    if (
        heartRate > 130 &&
        movement > 5.0 &&
        eegSignal > 70
    ) {

        seizureCounter++;

        cout << "Possible seizure pattern detected..."
             << endl;

    } else {

        seizureCounter = 0;

        cooldown = false;
    }

    if (
        seizureCounter >= 2 &&
        !cooldown
    ) {

        cooldown = true;

        return "SEIZURE DETECTED";
    }

    return "NORMAL";
}

    int getConfidence(
    int heartRate,
    float movement,
    int eegSignal
) {

    int confidence = 0;

    // Heart rate scoring
    if (heartRate > 120)
        confidence += 20;
    else if (heartRate > 90)
        confidence += 10;

    // Movement scoring
    if (movement > 6.0)
        confidence += 30;
    else if (movement > 3.0)
        confidence += 15;

    // EEG scoring
    if (eegSignal > 70)
        confidence += 50;
    else if (eegSignal > 40)
        confidence += 25;

    // Limit confidence to 100%
    if (confidence > 100)
        confidence = 100;

    return confidence;
}
};

/* =========================================
   LOGGER CLASS
========================================= */

class Logger {

public:

    void logEvent(
    int heartRate,
    float movement,
    int eegSignal,
    string status,
    int confidence
) {

    ofstream file(
        "seizure_log.txt",
        ios::app
    );

    time_t now = time(0);

    char buffer[80];

    strftime(
        buffer,
        sizeof(buffer),
        "%Y-%m-%d %H:%M:%S",
        localtime(&now)
    );

    file
        << "[" << buffer << "] "
        << "HR: " << heartRate
        << " | Movement: " << movement
        << " | EEG: " << eegSignal
        << " | Status: " << status
        << " | Confidence: "
        << confidence << "%"<< endl;

    file.close();

    cout << "Event successfully logged to seizure_log.txt"<< endl;
    cout << endl;

cout << "===================================="
     << endl;

cout << " LOG ENTRY SAVED "
     << endl;

cout << "===================================="
     << endl;

cout << "Timestamp  : "
     << buffer
     << endl;

cout << "Heart Rate : "
     << heartRate
     << " BPM"
     << endl;

cout << "Movement   : "
     << movement
     << endl;

cout << "EEG Signal : "
     << eegSignal
     << endl;

cout << "Status     : "
     << status
     << endl;

cout << "Confidence : "
     << confidence
     << "%"
     << endl;

cout << "===================================="
     << endl;

cout << endl;
    // Live dashboard data
    ofstream dashboard(
        "live_data.txt"
    );

    dashboard
        << heartRate << endl
        << movement << endl
        << eegSignal << endl
        << status << endl
        << confidence;

    dashboard.close();
}
};

/* =========================================
   MAIN PROGRAM
========================================= */

int main() {

    srand(time(0));

    Sensor sensor;

    DetectionEngine engine;

    Logger logger;

    cout << "======================================" << endl;
    cout << " SMART SEIZURE DETECTION SYSTEM " << endl;
    cout << "======================================" << endl;

    while (true) {

        sensor.generateData();

        int heartRate =
            sensor.getHeartRate();

        float movement =
            sensor.getMovement();

        int eegSignal =
            sensor.getEEGSignal();

        string status =
            engine.analyze(
                heartRate,
                movement,
                eegSignal
            );

        int confidence =
            engine.getConfidence(
                heartRate,
                movement,
                eegSignal
            );
        if (confidence >= 70) {

      cout << "Risk Level  : HIGH" << endl;

      } else if (confidence >= 40) {

      cout << "Risk Level  : MODERATE" << endl;

     } else {

    cout << "Risk Level  : LOW" << endl;
    }

        cout << endl;

        cout << "--------------------------------------" << endl;

        cout << "Heart Rate : "
             << heartRate
             << " BPM"
             << endl;

        cout << "Movement   : "
             << movement
             << endl;

        cout << "EEG Signal : "
             << eegSignal
             << endl;

        cout << "Status     : "
             << status
             << endl;

        cout << "Confidence : "
             << confidence
             << "%"
             << endl;

        if (status == "SEIZURE DETECTED") {

            cout << endl;

            cout << "ALERT: EMERGENCY SIGNAL SENT!"
                 << endl;

            cout << "Caregiver Notified Successfully"
                 << endl;
        }

        logger.logEvent(
            heartRate,
            movement,
            eegSignal,
            status,
            confidence
        );

        this_thread::sleep_for(
            chrono::seconds(3)
        );
    }

    return 0;
}
