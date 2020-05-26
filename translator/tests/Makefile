TP_PATTERNS=$(shell find pattern -name "*.cpp")
#TP_PATTERNS=$(shell find pattern/mov -name "*.cpp")
#TP_PATTERNS=pattern/mov/mov000.cpp
TP_CHECK=$(TP_PATTERNS:.cpp=.check)
#TP_RESULTS=$(TP_PATTERNS:.cpp=.result)
USER_NAME=$(shell whoami)

.SUFFIXES: .cpp .check .result

all:all_result

.cpp.check:
	@-./test4.sh -a -A -E $< > /dev/null
	@-./check.sh $@
	@-grep -e OK -e NG $@*

all_result:$(TP_CHECK)
	@./summarize.sh | tee regression.log

clean_check:
	find pattern -name "*.check" -exec rm {} \;
	find pattern -name "*.check.ng" -exec rm {} \;

clean_result:
	find pattern -name "*.result" -exec rm {} \;

clean:
	rm *.log *.bin *.asm