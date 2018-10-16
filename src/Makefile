APP ?= RMII
PLUGDIR = ../plugin

C = $(APP)AnalyzerSettings.cpp $(APP)SimulationDataGenerator.cpp

H = $(APP)AnalyzerSettings.h $(APP)SimulationDataGenerator.h

L += -lAnalyzer

CXXFLAGS += -L../AnalyzerSDK/lib
CXXFLAGS += -I../AnalyzerSDK/include

CXXFLAGS += -shared -rdynamic -fpic

$(PLUGDIR)/lib$(APP)Analyzer.so: $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C) $(L) && readelf -a $@ > $(APP).map

