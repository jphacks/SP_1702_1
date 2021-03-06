var express = require('express');
var routes = require('routes');
var path = require('path');
var serialport = require('serialport');


// Serial Port
var portName = '/dev/cu.usbmodem1421';
var sp = new serialport.SerialPort(portName, {
  baudRate: 9600,
  dataBits: 8,
  parity: 'none',
  stopBits: 1,
  flowControl: false,
  parser: serialport.parsers.readline("\n")
});


// data from Serial port
sp.on('data', function(input) {

    var buffer = new Buffer(input, 'utf8');
    var jsonData;
    try {
        jsonData = JSON.parse(buffer);
        console.log('tem: ' + jsonData.tem);
    } catch(e) {
        return;
    }
    io.sockets.json.emit('message', { value: jsonData });
});
