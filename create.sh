if [ $# != 3 ]
then 
    echo "usage: ./$0 dirname file_name test_file_name"
    exit 123
fi
DIR="$( cd "$( dirname "$0"  )" && pwd  )"/$1
TARGET_H=$DIR/$2.h
TARGET_CPP=$DIR/$2.cpp
TARGET_TEST=$DIR/$3.cpp
MACRO=$(echo $2 | tr 'a-z' 'A-Z')_H
if [ ! -d $1 ]
then
    mkdir $1
fi
if [ ! -e $TARGET_H ]
then
    echo "#ifndef $MACRO" >> $TARGET_H 
    echo "#define $MACRO" >> $TARGET_H
    echo "#include <stdlib.h>" >> $TARGET_H
    echo "#include <iostream>" >> $TARGET_H
    echo "
using namespace std;" >> $TARGET_H
    echo "" >> $TARGET_H
    echo "#endif" >> $TARGET_H
fi

if [ ! -e $TARGET_CPP ]
then
    echo "#include \"$2.h\"" >> $TARGET_CPP
fi

if [ ! -e $TARGET_TEST ]
then 
    echo "#include \"$2.h\"" >> $TARGET_TEST
    echo "#include \"../util.h\"" >> $TARGET_TEST
    echo "#include \"../main.h\"" >> $TARGET_TEST
    echo "" >> $TARGET_TEST
    echo "#define null 0" >> $TARGET_TEST
    echo "" >> $TARGET_TEST
    echo "int func(){
    return 0;
}" >> $TARGET_TEST
fi