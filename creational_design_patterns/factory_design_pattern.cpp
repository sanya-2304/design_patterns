    #include<bits/stdc++.h>
    using namespace std;

    class Document {
    public:
        virtual void open()=0;
        virtual ~Document(){
            cout<<"Deleting document"<<endl;
        };
    };
    class WordDocument: public Document{
        public:
        void open() override{
            cout<<"Opening worDocument"<<endl;
        }
    };
    class PdfDocument: public Document{
        public:
        void open() override{
            cout<<"Opening PdfDocument"<<endl;
        }
    };
    class SpreadsheetDocument : public Document{
        public:
        void open() override{
            cout<<"Opening SpreadsheetDocument "<<endl;
        }
    };

    class DocumentCreator {
    public:

    virtual Document* createDocument()=0;
    };

 class WordCreator: public DocumentCreator {
public:
    Document* createDocument() override {
        cout << "Creating Word Document" << endl;
        return new WordDocument();
    }
};

class PdfCreator: public DocumentCreator {
public:
    Document* createDocument() override {
        cout << "Creating PDF Document" << endl;
        return new PdfDocument();
    }
};

class SpreadsheetCreator: public DocumentCreator {
public:
    Document* createDocument() override {
        cout << "Creating Spreadsheet Document" << endl;
        return new SpreadsheetDocument();
    }
};


    int main(){
        // The pattern’s intent is to encapsulate object creation — not necessarily to eliminate new altogether.It’s a common, straightforward implementation that demonstrates Factory Method.
        //But it does not fully hide dynamic allocation from client code 
        DocumentCreator* docCreate=new PdfCreator();
        Document* doc=docCreate->createDocument();
        if(doc){
        doc->open();
        delete doc;
        }
        return 0;
    }