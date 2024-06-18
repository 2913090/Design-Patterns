#include <iostream>
#include <vector>

using namespace std;

class BaseHandler {
protected:
	BaseHandler* next;
public:
	BaseHandler(): next(nullptr){}

	void setNext(BaseHandler* nextHandler) {
		next = nextHandler;
	}
	virtual void handleRequest(string request) {
		if (next) {
			next->handleRequest(request);
		}
		else {
			cout << "Request: " << request << " could not be handled." << endl;
		}
	}
};

class SimpleRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "simple") {
			cout << "Simple request handler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};

class ComplexRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "complex") {
			cout << "Complex request handler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};

class CriticalRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "critical") {
			cout << "Critical request handler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};




int main()
{
	SimpleRequestHandler* srh = new SimpleRequestHandler();
	ComplexRequestHandler* crh = new ComplexRequestHandler();
	CriticalRequestHandler* critrh = new CriticalRequestHandler();

	srh->setNext(crh);
	crh->setNext(critrh);

	srh->handleRequest("");

}