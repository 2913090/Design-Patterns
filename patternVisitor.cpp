#include <iostream>
#include <vector>

using namespace std;

class HtmlElement;
class XmlElement;

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(HtmlElement* element) = 0;
    virtual void visit(XmlElement* element) = 0;
};

class Element {
public:
    virtual ~Element() = default;
    virtual void accept(Visitor* visitor) = 0;
};

class HtmlElement : public Element {
public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    string getHtml() {
        return "<html><body>Hello World!</body></html>";
    }
};

class XmlElement : public Element {
public:
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }

    string getXml() {
        return "<xml><message>Hello World!</message></xml>";
    }
};

class PrintVisitor : public Visitor {
public:
    void visit(HtmlElement* element) {
        cout << "HTML Content: " << element->getHtml() << endl;
    }
    
    void visit(XmlElement* element) {
        cout << "XML Content: " << element->getXml() << endl;
    }
};

class Document {
private:
    vector<Element*> elements;
public:
    ~Document() {
        for (auto element : elements) {
            delete element;
        }
    }

    void addElement(Element* element) {
        elements.push_back(element);
    }

    void accept(Visitor* visitor) {
        for (auto element : elements) {
            element->accept(visitor);
        }
    }
};

int main()
{
    Document doc;
    doc.addElement(new XmlElement);
    doc.addElement(new HtmlElement);

    PrintVisitor printVisitor;
    doc.accept(&printVisitor);




}