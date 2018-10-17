
# add files you create here
OBJ = example.o IntegerSetArray.o linkedlist.o PList.o IntArray.o randomHash.o

all: libece309.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libece309.a $(OBJ)

libece309.a: $(OBJ)
	$(AR) -r $@ $(OBJ)

%.o:%.cpp
	$(CXX) -c -std=c++11 -o $@ -I . -I ../include $< -Wall -Werror
