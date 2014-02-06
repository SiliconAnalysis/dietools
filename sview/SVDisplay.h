#ifndef SVDISPLAY_H
#define SVDISPLAY_H

#include <QtGui/QWidget>
#include <vector>
#include <string>

using namespace std;
class circuit_map;

class SVDisplay : public QWidget {
  Q_OBJECT

public:
  SVDisplay(QWidget *parent = 0);
  ~SVDisplay();

public slots:
  void hscroll(int);
  void vscroll(int);
  void reload();
  void zoom_in();
  void zoom_out();
  void state_changed();

signals:
  void track(int);

protected:
  void paintEvent(QPaintEvent *e);
  void resizeEvent(QResizeEvent *e);

  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);

private:
  unsigned int *generated_image;
  unsigned int *ids_image;
  QImage *qimg;
  int xc, yc, x0, y0, z;

  void generate_image();
  void generate_ids();
  void rewamp_image();
};

#endif

