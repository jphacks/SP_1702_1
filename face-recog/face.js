var cv = require('opencv');

var RED = [0, 0, 255];
var THICKNESS = 2;

try {
  var camera = new cv.VideoCapture(0);
  var window = new cv.NamedWindow('Video', 0);

  camera.setWidth(480);
  camera.setHeight(320);

  setInterval(function() {
    camera.read(function(err, im) {
      if (err) throw err;

      if (im.size()[0] > 0 && im.size()[1] > 0){
        im.detectObject("./haarcascade_frontalface_alt.xml", {}, function(err, faces){
          for (var i=0;i<faces.length; i++){
            var face = faces[i]
            im.rectangle([face.x, face.y], [face.width, face.height], RED, THICKNESS);
          }
          window.show(im);
        });
        window.blockingWaitKey(0, 50);
      }
    });
  }, 500);

} catch (e){
  console.log("Couldn't start camera:", e)
}
