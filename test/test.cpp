#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DocumentStore
{
public:
    DocumentStore(int capacity)
    {
        this->capacity = capacity;
    }

    int getCapacity() const
    {
        return capacity;
    }

    const std::vector<std::string>& getDocuments() const
    {
        return documents;
    }

    void addDocument(std::string document)
    {
        if (documents.size() >= this->capacity)
            throw std::logic_error("Overfilled");

        documents.push_back(document);
    }

    std::string getDescription()
    {
        if (this->capacity <= documents.size())
            return "Document store is full";
        else
            return "Document store: " + to_string(documents.size())  + "/" + to_string(this->capacity);
    }

private:
    std::vector<std::string> documents;
    int capacity;
};

#ifndef RunTests
int main()
{
    DocumentStore documentStore(2);
    documentStore.addDocument("Item");
    cout << documentStore.getDescription();
}
#endif