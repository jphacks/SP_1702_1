var serialport = require('serialport');

// -----------------------
// --------- 中略 ---------
// -----------------------

var portName = "/dev/cu.usbmodem1421";
var sp = new serialport.SerialPort(portName, {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline("\n")
});
