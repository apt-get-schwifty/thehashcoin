Thank you for checking out TheHashCoin! This is a project currently being run solely my two brothers and I. 
At this time the project is still in it's infancy.

At this time we only have 1 dedicated seed node, which has been hardcoded into the source code, and does function (usually). If for some reason your wallet doesn't sync with the blockchain please append your thehashcoin.conf to include the following line:

connect=162.208.9.51:421

None of the icons or splashes/thematics of the qt-GUI have been changed yet.

BUILD INSTRUCTIONS (linux only):

1. MAKE SURE YOUR DISTRO IS UP TO DATE:

sudo apt-get update && sudo apt-get upgrade

2. DOWNLOAD/INSTALL ALL REQUIRED DEPENDENCIES:

sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev

sudo apt-get install sudo apt-get install bsdmainutils libboost-system-dev libboost-filesystem-dev libboost-chrono-dev

sudo apt-get install libboost-program-options-dev libboost-test-dev libboost-thread-dev

sudo apt-get install libqrencode-dev protobuf-compiler miniupnpc

(optional, GUI only):  sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev

---IMPORTANT---	

DEPRECATED VERSION OF BERKLEY DB HEADERS IS REQUIRED!

To fetch them on ubuntu use:

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8+±dev


To fetch them on other distros append your sources.list with the following:

deb http://ppa.launchpad.net/bitcoin/bitcoin/ubuntu YOUR_UBUNTU_VERSION_HERE main 
deb-src http://ppa.launchpad.net/bitcoin/bitcoin/ubuntu YOUR_UBUNTU_VERSION_HERE main 

Replace YOUR_UBUNTU_VERSION_HERE with either xenial or cosmic and even if you're running a different distro you won't have issues since all we will be fetching from this repo is the Berkely DB Headers.

Add repository PGP key to apt-key using add-apt-key:

Follow this link and copy the entire PGP Key, and save it to your system (take note of where you save it)

https://keyserver.ubuntu.com/pks/lookup?op=get&search=0xD46F45428842CE5E

Edit the text file you pasted the key and remove the lines that begin with "Version:" and "Comment:" Save it as bitcoin-repo.pgp (or any name with the .pgp file extension)

After saving the changes:

add-apt-key /directory/of/pgp-key-file/bitcoin-repo.pgp

You should now be set to do sudo apt-get update then sudo apt-get install libdb4.8-dev libdb4.8++-dev

3. Compile and launch:

Navigate to the directory where you cloned or downloaded your copy of thehashcoin's source

In a terminal within the directory type the following:

./autogen.sh

./configure

make OR make install 

If you only run make, the compiled binaries will need to be run from within the directory. The Qt-GUI executable is within thehashcoin/src/qt Use ./thehashcoin-qt to launch it. thehashcoind daemon (non GUI) executable is within thehashcoin/src Use ./thehashcoind to launch it

If you only run make and don't have the Qt dependencies installed, all rpc commands must be issued using thehashcoin-cli "insertrpccall" from within thehashcoin/src with ./thehashcoin-cli  

If you do make install the binaries can be run from within any directory with the terminal command thehashcoin-qt/thehashcoind/thehashcoin-cli etc.

MINING POOL:

We currently have a NOMP pool that's always running that can be accessed by providing your choice of mining software with the following url:

stratum+tcp://162.208.9.65:3333

Be sure if you're going to use this pool you append the following line in your thehashcoin.conf

rpcport=422

Username is the address you wish to receive payment for submitted shares in the event of a block being found.

At this time there is no strict password enforcement so you can type anything you want as a password.

Our pool does not take any fees at this time.

If you have any questions, comments, concerns or if you wish to contribute please contact me on github at https://github.com/apt-get-schwifty/thehashcoin OR via email at bhuff25930@gmail.com

Thank you again for checking our coin out!

- Brett Hufnagle and the rest of the TheHashCoin team!