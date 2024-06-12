#include <iostream>

using namespace std;

class Notifier {
public:
    virtual void send(string message) = 0;
};

class EmailNotifier : public Notifier {
public:
    void send(string message) {
        cout << "Sending email: " << message << endl;
    }
};

class NotifierDecorator : public Notifier {
protected:
    Notifier* wrappee;
public:
    NotifierDecorator(Notifier* notifier): wrappee(notifier){}

    void send(string message) {
        wrappee->send(message);
    }
};

class SMSNotifier : public NotifierDecorator {
public:
    SMSNotifier(Notifier* notifier): NotifierDecorator(notifier){}
    void send(string message) {
        NotifierDecorator::send(message);
        sendSMS(message);
    }
private:
    void sendSMS(string message) {
        cout << "Sending SMS: " << message << endl;
    }
};

class FacebookNotifier : public NotifierDecorator {
public:
    FacebookNotifier(Notifier* notifier) : NotifierDecorator(notifier) {}
    void send(string message) {
        NotifierDecorator::send(message);
        sendFacebook(message);
    }
private:
    void sendFacebook(string message) {
        cout << "Sending facebook message: " << message << endl;
    }
};











int main()
{
    Notifier* emailNotifier = new EmailNotifier();
    Notifier* smsNotifier = new SMSNotifier(emailNotifier);
    Notifier* facebookNotifier = new FacebookNotifier(emailNotifier);
    facebookNotifier->send("test");









}
