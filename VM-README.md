**INSTRUCTIONS FOR PREPARING PRE-INSTALLED THEHASHCOIN WALLET UBUNTU VM:**

Please begin by downloading and installing virtualbox for windows using the following link:

https://www.virtualbox.org/wiki/Downloads

Then download the TheHashCoin-VM virtual disk image file .zip archive from our github using the following link:



After downloading/installing VirtualBox and downloading the virtual disk image .zip archive from github, extract the .zip archive (take note of where, and keep in mind this file is large, it may take a while to extract).

Next, launch VirtualBox.

Within the VirtualBox window click "New".

Name the VM "TheHashCoin-VM" and make sure Linux is selected for type and Ubuntu(64-Bit) is selected for version.

Click Next.

Choose how much RAM to allocate to VM (be sure to use multiples of 1024MB, for example: 2048MB, 4096MB etc.).

Click Next.

Fill in the bubble that says "Use an existing virtual hard disk file" then click the folder icon in the bottom right and navigate to the path where you extracted the THC-VM folder from the thc-vdi.zip file you downloaded and select the TheHashCoin-VM.vdi from within the THC-VM folder.

Click Create.

Now you will see the VM listed on the left hand side. Click it to highlight it and hit the Start button at the top of the Window. This will start the VM and you will automatically be logged in to the Desktop.

If you need to import a wallet.dat it would be best to do this now that the VM is running, but before starting the wallet, so the directions for the quickest way to do this are as follows:

**TO IMPORT WALLET.DAT TO VM**

This is the quickest, simplest method of doing this, not the only one.

Within your windows host, copy your wallet.dat into a new folder named thc-wallet. (Make sure the folder you copy the wallet.dat to is named thc-wallet).

Turn the new folder named thc-wallet containing your wallet.dat into a .zip archive named thc-wallet.zip (Make sure the archive is named thc-wallet.zip)

Attach a copy of your .zip archive containing your wallet.dat to an email. Send the email to yourself, (same send and receive email address)

Next, from within the VM, open firefox by clicking the firefox icon and retrieve the email you sent yourself with the .zip archive attached and download the attached .zip archive. Make sure you select to save the archive to the Downloads folder in the VM.

Next type "Ctrl+Alt+t" to open a terminal.

Type the following then hit enter:

su root

When prompted for the password type the following then hit enter:

thehashcoin1

Next, type or copy and paste the following then hit enter:

cd Downloads && unzip thc-wallet.zip && cd thc-wallet && cp wallet.dat /root/.thehashcoin/wallet.dat

**LAUNCH WALLET**

Last, but not least we will open the wallet by typing the following then pressing enter:

thehashcoin-qt

This will open the wallet which has already been organically synced and tested so you should be all set! 

If anyone uses these instructions and has any issues please contact me here on github OR email me at bhuff25930@gmail.com Thank you!
