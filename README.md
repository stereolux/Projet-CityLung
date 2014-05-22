# City Lung

## Installation on a raspberry pi and running it

Open a terminal

```
cd ~
wget http://node-arm.herokuapp.com/node_latest_armhf.deb
sudo dpkg -i node_latest_armhf.deb
git clone https://github.com/stereolux/cityLung.git
cd cityLung
npm install
```

Upload the arduino skecth which is inside the `arduino` folder.

## Running it

```
cd ~/cityLung
node index.js
```

## Run the program when the raspberry pi boots

See http://www.raspberrypi.org/documentation/linux/usage/rc-local.md

## Things to check

- Be sure the Arduino is plugged to the `/dev/ttyACM0` port, otherwise modify the line https://github.com/stereolux/cityLung/blob/master/index.js#L5 with the according port.
- Check network connectivity
