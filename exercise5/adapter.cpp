struct Square {
  int side{0};

  explicit Square(const int side) : side(side) {}
};

struct Rectangle {
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const { return width() * height(); }
};

struct SquareToRectangleAdapter : Rectangle {
  int side;
  SquareToRectangleAdapter(const Square& square) { this->side = square.side; }

 public:
  int width() const { return side; }
  int height() const { return side; }
};