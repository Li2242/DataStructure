CXX = g++
CXXFLAGES = -O2 -Wall

CSRC = ./*.cpp
BUILD_DIR = ./build
$(shell mkdir -p $(BUILD_DIR))

main: $(CSRC)
	$(CXX) $(CXXFLAGES) $(CSRC) -o $(BUILD_DIR)/main

run: main
	$(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)

.PHONY:clean