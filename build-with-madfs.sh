./autogen.sh
./configure --enable-fortran=none --enable-debug  --with-device=ch3 --with-file-system='testfs+ufs+madfs'  --with-madfs=/home/mhy/local --prefix=/home/mhy/local
make
make install
