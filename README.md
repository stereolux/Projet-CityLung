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
