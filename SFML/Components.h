#pragma once
#include "Requirement.h"


class InputField {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool selected;
    std::string input;

public:
    InputField(float x, float y, float width, float height, sf::Font& font) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(0.f);
        //shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 5.f, y + 5.f);

        selected = false;
    }

    void setSelected(bool isSelected) {
        selected = isSelected;
        //if (selected)
        //    shape.setOutlineColor(sf::Color::Blue);
        //else
        //    shape.setOutlineColor(sf::Color::Black);
    }

    bool isSelected() const {
        return selected;
    }

    void processInput(sf::Event& event) {
        if (selected) {
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!input.empty())
                        input.pop_back();
                }
                else if (event.text.unicode == '\r') { //Bao's commit No. 01 // Set unselected for ENTER input
                    selected = false;
                }
                else if (event.text.unicode < 128) {
                    input += static_cast<char>(event.text.unicode);
                }
            }
        }
        if (!selected) text.setString(input); //Bao's commit No. 01 // Remove "_" at the end of unselected inputfield
        else text.setString(input + "_"); //Bao's commit No. 01 // Set "_" at the end of selected inputfield
        setSelected(selected);
    }

    std::string getInput() const {
        return input;
    }

    bool contains(const sf::Vector2i& mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    void handleMouseClick(const sf::Vector2i& mousePos) {
        selected = contains(mousePos);
        setSelected(selected);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(fillColor);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(height/2 + 5);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);

        // Calculate position to center the text within the button
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
        text.setPosition(sf::Vector2f(x + width / 2.f, y + height / 2.f));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const sf::Vector2i& mousePos) {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }
};


class TextBox {
private:
    sf::Text text;

public:
    TextBox(float x, float y, int charSize, sf::Color color, sf::Font& font) {
        text.setPosition(x, y);
        text.setCharacterSize(charSize);
        text.setFillColor(color);
        text.setFont(font);
    }

    void setString(std::string content) {
        text.setString(content);
    }

    std::string getString() {
        return text.getString();
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};

//define namespace to work with files
#define fsys std::filesystem

class File {//This class has only worked with CSV files
private: 
    std::fstream file;
    std::vector<std::string> rowContent; //Path of the "mother" folder
    std::string fileName;
    fsys::path folderPath;

public:
    File(fsys::path folderPath, std::string fileName) {
        this->fileName = fileName;
        this->folderPath = folderPath;
        folderPath /= fileName;
        std::fstream file(folderPath);
    }

    void open() {
        this->file.open(this->folderPath / this->fileName);
    }
    
    void close() {
        this->file.close();
    }

    std::vector<std::string> readRow() {//Only store one row per call
        this->rowContent.clear();
        std::string row;
        if (!(this->file >> row)) return this->rowContent;
        std::getline(this->file, row, '\n');
        std::stringstream sRow(row);
        std::string element;
        while (std::getline(sRow, element, ',')) {
            this->rowContent.push_back(element);
        }
        return this->rowContent;
    }

    void write(std::string content) {
        this->file << content << std::endl;
    }

    void update() {

    }
};

class Folder {
private:
    fsys::path folderPath; //Path of the "mother" folder
    std::string folderName;
    int subFolderNum;
    int subFileNum;
    bool CreateDirectoryRecursive(fsys::path const& folderDir, std::error_code& err)
    {
        err.clear();
        if (!std::filesystem::create_directories(folderDir, err))
        {
            if (std::filesystem::exists(folderDir))
            {
                // The folder already exists:
                err.clear();
                return true;
            }
            return false;
        }
        return true;
    }

public:
    Folder(std::string folderName) {
        this->folderPath = "D:/UNI/US/CS162/COURSE MANAGEMENT SYSTEM/SFML/Data";
        this->folderName = folderName;
        std::error_code err;
        if (!CreateDirectoryRecursive(this->folderPath / folderName, err))
        {
            // Report the error:
            std::cout << "CreateDirectoryRecursive FAILED, err: " << err.message() << std::endl;
        }
        this->subFolderNum = 0;
        this->subFileNum = 0;
    }

    Folder(fsys::path folderPath, std::string folderName) {
        this->folderPath = folderPath;
        this->folderName = folderName;
        std::error_code err;
        if (!CreateDirectoryRecursive(this->folderPath / folderName, err))
        {
            // Report the error:
            std::cout << "CreateDirectoryRecursive FAILED, err: " << err.message() << std::endl;
        }
        this->subFolderNum = 0;
        this->subFileNum = 0;
    }

    Folder createSubFolder(std::string folderName) {
        Folder folder(this->folderPath / this -> folderName, folderName);
        this->subFolderNum++;
        return folder;
    }

    File createSubFile(std::string fileName) {
        File file(this->folderPath / this->folderName, fileName); //remember to use file.close() after
        this->subFileNum++;
        return file;

    }
};