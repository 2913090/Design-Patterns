#include <iostream>
#include <vector>

using namespace std;

class TreeType {
private:
    string name;
    string color;
    string texture;
public:
    TreeType(string name, string color, string texture) : name(name), color(color), texture(texture){}
    void draw(int x, int y) {
        cout << "Draw " << color << " " << name << " " << texture << " texture at (" << x << ", " << y << ")" << endl;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    string getTexture() {
        return texture;
    }
};

class TreeFactory {
private:
    static vector<TreeType*> treeTypes;
public:
    static TreeType* getTreeType(string name, string color, string texture) {
        for (int i = 0; i < treeTypes.size(); i++) {
            if (treeTypes[i]->getName() == name && treeTypes[i]->getColor() == color && treeTypes[i]->getTexture() == texture) {
                cout << "Object already exist" << endl;
                return treeTypes[i];
            }
        }
        cout << "Create new object" << endl;
        TreeType* type = new TreeType(name, color, texture);
        treeTypes.push_back(type);
        return type;
    }
};

class Tree {
private:
    int x;
    int y;
    TreeType* treeType;
public:
    Tree(int x, int y, TreeType* treeType) : x(x), y(y), treeType(treeType){}
    
    void draw() {
        treeType->draw(x, y);
    }
};

class Forest {
private:
    vector<Tree> trees;
public:
    void plantTree(int x, int y, string name, string color, string texture) {
        TreeType* type = TreeFactory::getTreeType(name, color, texture);
        Tree tree(x, y, type);
        trees.push_back(tree);
    }

    void draw() {
        for (auto tree : trees) {
            tree.draw();
        }
    }
};



vector<TreeType*> TreeFactory::treeTypes;

int main()
{
    Forest f1;
    f1.plantTree(2, 5, "oak", "green", "texture1");
    f1.plantTree(3, 6, "birch", "yellow", "texture2");
    f1.plantTree(9, 3, "oak", "red", "texture2");
    f1.plantTree(7, 1, "oak", "green", "texture3");
    f1.plantTree(4, 7, "oak", "red", "texture2");
    f1.draw();
}