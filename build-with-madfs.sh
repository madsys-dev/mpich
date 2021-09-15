./autogen.sh
./configure --enable-fortran=none --enable-debug  --with-device=ch3 --with-file-system='testfs+ufs+madfs'  --with-madfs=/usr/local
make
sudo make install
