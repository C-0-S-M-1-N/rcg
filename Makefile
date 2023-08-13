CXX 		:= gcc
CXXINCL 	:= -I./include
CXXLIB 		:= -lncurses
SRC_PATH 	:= ./src
OBJ_PATH 	:= ./obj
CXXARGS_DEB := -c -g -O0 -Wall -Werror
CXXARGS_REL := -c -O3
CXXARGS 	:= -c

SRCS 		:= $(shell find ./src -name '*.cpp' -or -name '*.c')
OBJS 		:= $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.c.o,$(filter %.c,$(SRCS)))

no_srcs 	:= $(words $(SRCS))
OBJ_PATHS_  := $(dir $(OBJS))
EXEC 		:= rcg

.PHONY: debug clean release install uninstall

debug: CXXARGS = CXXARGS_DEB
debug: $(EXEC) 

release: CXXARGS = CXXARGS_REL
release: $(EXEC) 

install: $(EXEC)
	@sudo mv $(EXEC) /usr/local/bin/$(EXEC)
	@sudo chmod +x /usr/local/bin/$(EXEC)
uninstall: clean
	@sudo rm -rfv /usr/local/bin/$(EXEC)

$(EXEC): $(OBJS)
	@echo "preparing $@"
	@$(CXX) $^ -o $@ $(CXXLIB)
	@echo "serving $@!"

$(OBJ_PATH)/%.c.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(eval so_far += done)
	@mkdir -p $(@D)
	@echo "cooking $@ ($(words $(so_far)) / $(no_srcs)) ..."
	@$(CXX) $^ -o $@ $(CXXINCL) $(CXXARGS_DEB)

$(OBJ_PATH): 
	@echo "mixing $@"
	@mkdir $@


clean: $(OBJ_PATH)
	@echo "washing the dishes"
	@rm -r $^

# TODO: make no_srcs update to the number of prerequisites of $(EXEC)
