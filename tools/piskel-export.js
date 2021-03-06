javascript:(function(){

  function export2uint8() {
    var width = pskl.app.piskelController.getWidth();
    var height = pskl.app.piskelController.getHeight();
    var frameCount = pskl.app.piskelController.getFrameCount();

    var str = ''; str += '#include <stdint.h>\n'; str += '#define SPRITE_SHEET_FRAME_COUNT ' + frameCount + '\n';
    str += '#define SPRITE_SHEET_FRAME_WIDTH ' + width + '\n';
    str += '#define SPRITE_SHEET_FRAME_HEIGHT ' + height + '\n';
    str += 'static const uint32_t sprite_sheet_data[' + frameCount + '][' + width * height + '] = {' + '\n';

    for (i = 0; i < frameCount; i++) {
      var lines = [];
      str += '{\n';

      var frame = pskl.utils.LayerUtils.mergeFrameAt(pskl.app.piskelController.getLayers(), i);

      frame.forEachPixel(function (color, col, row) {
        if (!lines[row]) {
          lines[row] = [];
        }
        var line = lines[row];
        if (col === 0) {
          line.push(' 0b')
        } else if (col % 32 === 0){
          line.push(', 0b')
        }
        var isTransparent = color === pskl.utils.colorToInt(Constants.TRANSPARENT_COLOR);
        line.push(isTransparent ? '0' : '1');
      });

      str += lines.map(function (line) {
        return line.join('');
      }).join(',\n');

      str += '\n},\n';
    }

    str += '};\n';
    return str;
  };

  var code = export2uint8();
  var a = document.createElement('a');
  a.href = "data:text/plain;charset=utf-8," + encodeURIComponent(code);
  a.download = 'sprite_sheet.c';
  document.body.appendChild(a);
  a.click();a.parentNode.removeChild(a);
})();