'use strict';
var Datas = require('dataviz-tangible'),
	datas = new Datas(),
	SerialPort = require('serialport').SerialPort,
	shanghai = new SerialPort('/dev/ttyACM0'),
	rennes = new SerialPort('/dev/ttyACM1'),
	interval = 5000,
	shanghaiOpened = false,
	rennesOpened = false;

var poll = function() {
	shanghaiOpened = false;
	rennesOpened = false;
	setInterval(function() {
		datas.pollution('Shanghai');
		datas.pollution('Rennes');
	}, interval);
};

datas.on('pollution', function(data) {
	switch (data.town) {
		case 'Rennes':
			rennes.write(data.aqi + '#', function() {
				console.log(JSON.stringify(data) + ' sent');
			});
			break;
		case 'Shanghai':
			shanghai.write(data.aqi + '#', function() {
				console.log(JSON.stringify(data) + ' sent');
			});
			break;
	}
});

shanghai.on('open', function () {
	shanghaiOpened = true;
	console.log('Shanghai port opened');
	if (shanghaiOpened && rennesOpened) poll();

});

rennes.on('open', function () {
	rennesOpened = true;
	console.log('Rennes port opened');
	if (shanghaiOpened && rennesOpened) poll();
});
