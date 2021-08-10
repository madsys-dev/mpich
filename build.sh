autoconf
./configure --enable-fortran=none --enable-debug  --with-device=ch4:ucx --with-file-system='testfs+ufs+madfs'  --with-madfs=/usr/local
make
sudo make install
