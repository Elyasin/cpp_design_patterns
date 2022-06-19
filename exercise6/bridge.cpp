#include <string>

using namespace std;

struct Renderer {
  virtual string render(string) const = 0;
};

struct VectorRenderer : Renderer {
  string render(string name) const override {
    return "Drawing " + name + " as lines";
  }
};

struct RasterRenderer : Renderer {
  string render(string name) const override {
    return "Drawing " + name + " as pixels";
  }
};

struct Shape {
 protected:
  Renderer &renderer;
  string name;
  Shape(Renderer &renderer) : renderer{renderer} {};

 public:
  virtual string str() const = 0;
};

struct Triangle : Shape {
  Triangle(Renderer &renderer) : Shape(renderer) { name = "Circle"; }
  string str() const { return renderer.render(name); }
};

struct Square : Shape {
  Square(Renderer &renderer) : Shape(renderer) { name = "Square"; }
  string str() const { return renderer.render(name); }
};