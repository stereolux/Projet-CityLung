'use strict';
var Datas = require('dataviz-tangible'),
	datas = new Datas(),
	SerialPort = require('serialport').SerialPort,
	serialPort = new SerialPort('/dev/ttyACM0'),
	interval = 5000;

datas.on('pollution', function(data) {
	var cmd;
	switch (data.town) {
		case 'Rennes':
			cmd = 'r' + data.aqi + '#';
			break;
		case 'Shanghai':
			cmd = 's' + data.aqi + '#';
			break;
		default:
			cmd = 'r' + data.aqi + '#';
			break;
	}
	serialPort.write(cmd, function() {
		console.log(JSON.stringify(data) + ' sent');
	});

});

serialPort.on('open', function () {
	console.log('Serial port opened');
	setInterval(function(data) {
		datas.pollution('Shanghai');
		datas.pollution('Rennes');
	}, interval);
});
