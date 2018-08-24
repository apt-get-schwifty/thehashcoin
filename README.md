Thank you for checking out TheHashCoin! This is a project that is currently being run solely by my two brothers and I and is still in it's infancy.

At this time we only have 2 dedicated seed nodes (with 3 different public IP addresses), which have been hardcoded into the source code, and do function (usually). If for some reason your wallet doesn't sync with the blockchain please try appending your thehashcoin.conf to include the following lines:

connect=162.208.9.51:421

connect=192.243.103.250:421

connect=162.208.9.65:421

Very few (only the mined transaction icon)/splashes have been altered at this time. We are saving these for finishing touches once the mechanics of the coin and pool(s) are solid. (Which at this time they are!)

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

DEPRECATED VERSION OF BERKLEY DB HEADERS REQUIRED!

To fetch them on ubuntu use:

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8+±dev


To fetch them on other distros append your sources.list with the following:

deb http://ppa.launchpad.net/bitcoin/bitcoin/ubuntu YOUR_UBUNTU_VERSION_HERE main 
deb-src http://ppa.launchpad.net/bitcoin/bitcoin/ubuntu YOUR_UBUNTU_VERSION_HERE main 

Replace YOUR_UBUNTU_VERSION_HERE with either xenial or cosmic and even if you're running a different distro you won't have issues since all we will be fetching from this repo is the Berkely DB Headers.

Add repository PGP key to apt-key using apt-key add:

Follow this link and copy the entire PGP Key, and save it to your system (take note of where you save it)

https://keyserver.ubuntu.com/pks/lookup?op=get&search=0xD46F45428842CE5E

Edit the text file you pasted the key and remove the lines that begin with "Version:" and "Comment:" Save it as bitcoin-repo.pgp (or any name with the .pgp file extension)

After saving the changes:

apt-key add /directory/of/pgp-key-file/bitcoin-repo.pgp

You should now be set to do:

sudo apt-get update 

then: 

sudo apt-get install libdb4.8-dev libdb4.8++-dev

3. Compile and launch:

Navigate to the directory where you cloned or downloaded your copy of thehashcoin's source

In a terminal within the directory type the following:

./autogen.sh

./configure

make OR make install 

If you only run make, the compiled binaries will need to be run from within the directory. The Qt-GUI executable is within thehashcoin/src/qt Use ./thehashcoin-qt to launch it. thehashcoind daemon (non GUI) executable is within thehashcoin/src Use ./thehashcoind to launch it

If you only run make and don't have the Qt dependencies installed, all rpc commands must be issued using thehashcoin-cli "insertrpccall" from within thehashcoin/src with ./thehashcoin-cli  

If you do make install the binaries can be run from within any directory with the terminal command thehashcoin-qt/thehashcoind/thehashcoin-cli etc.

***FOR WINDOWS***:

Please use the following link to download the official TheHashCoin x86/64 bit Windows binaries:

https://ln.sync.com/dl/adc725780/6m2uw34j-acwc7pqe-nd4m97vm-rr96xv77

the binaries are also available locally here on github under TheHashCoin Release v0.2

MINING POOL:

We currently have a NOMP pool that's always running that can be accessed by providing your choice of mining software with the following url:

stratum+tcp://162.208.9.65:3333

The standard stratum port 3333 is @ stratum difficulty 75, for a lower difficulty use port 3032 (stratum difficulty 32) and for a higher difficulty use port 3256 (stratum difficulty 256).

Be sure if you're going to use this pool you append the following line in your thehashcoin.conf

rpcport=422

Username is the address you wish to receive payment for submitted shares in the event of a block being found.

We also have a working pool at https://saltpool.net
 
To access this pool please point your miner to the following URL:

stratum+tcp://saltpool.net:3433 using the address you wish to receive coins with as your user name and using THC as your password

---IMPORTANT---

PLEASE MAKE SURE THE ADDRESS YOU USE FOR PAYOUT IS A LEGACY ADDRESS (STARTS WITH THE LETTER T). SEGWIT IS FULLY DEPLOYED/ACTIVE ON THE NETWORK BUT IS INCOMPATIBLE WITH NOMP'S PAYMENT PROCESSOR. SEGWIT ADDRESSES BEGIN WITH THE LETTER S FOR THIS COIN!

At this time there is no strict password enforcement so you can type anything you want as a password if using our NOMP pool.

Our pool does not take any fees at this time.

Saltpool does take a very small 0.5% fee.

We will be adding more seed nodes and at least one more pool in the immediate future!

If you have any questions, comments, concerns or if you wish to contribute please contact me on github at https://github.com/apt-get-schwifty/thehashcoin OR via email at bhuff25930@gmail.com

Thank you again for checking our coin out!

- Brett Hufnagle and the rest of the TheHashCoin team!
