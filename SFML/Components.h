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


class Text {
private:
    sf::Text text;
    sf::Font font;

public:
    Text() {}

    Text(float x, float y, const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size) {
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(color);
        text.setString(content);
        text.setPosition(x, y);
    }

    // Set text string
    void setString(const std::string& str) {
        text.setString(str);
    }

    // Set text position
    void setPosition(float x, float y) {
        text.setPosition(x, y);
    }

    // Set text color
    void setColor(const sf::Color& color) {
        text.setFillColor(color);
    }

    // Set text size
    void setSize(unsigned int size) {
        text.setCharacterSize(size);
    }

    // Draw text on SFML window
    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};

//define namespace to work with files
namespace fsys = std::filesystem;

class File {//This class has only worked with CSV files
private: 
    std::fstream file;
    std::vector<std::string> rowContent; //Path of the "mother" folder
    std::string fileName;
    fsys::path folderPath;

public:
    File() {}

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

    ~File() {
        if (file.is_open())
            this->file.close();
    }
};

class Folder {
private:
    fsys::path folderPath; //Path of this folder
    std::string folderName;
    bool CreateDirectoryRecursive(fsys::path const& folderDir, std::error_code& err)
    {
        err.clear();
        if (!fsys::create_directories(folderDir, err))
        {
            if (fsys::exists(folderDir))
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
        this->folderPath = "Data";
        this->folderName = folderName;
        std::error_code err;
        if (!CreateDirectoryRecursive(this->folderPath, err))
        {
            // Report the error:
            std::cout << "CreateDirectoryRecursive FAILED, err: " << err.message() << std::endl;
        }
    }

    Folder(fsys::path folderPath, std::string folderName) {
        this->folderPath = folderPath;
        this->folderName = folderName;
        std::error_code err;
        if (!CreateDirectoryRecursive(this->folderPath, err))
        {
            // Report the error:
            std::cout << "CreateDirectoryRecursive FAILED, err: " << err.message() << std::endl;
        }
    }

    void createSubFolder(std::string folderName) {
        Folder folder(this->folderPath, folderName);
    }

    void createSubFile(std::string fileName) {
        File file(this->folderPath, fileName); //remember to use file.close() after
    }

    void ToSubFolder(std::string folderName) {
        if (!fsys::exists(this->folderPath)) std::cerr << "No such directory " << this->folderPath << std::endl;
        else {
            this->folderPath /= this->folderName;
            this->folderName = folderName;
        }
    }
};