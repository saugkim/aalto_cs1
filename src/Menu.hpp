#include <string>

using namespace std;

class Menu {
  public:
    Menu(char* text) { text_ = text; };
    void Show(string& action, bool menuActive);

  private:
    char* text_;
};
