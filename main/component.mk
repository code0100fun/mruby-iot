#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)
COMPONENT_DEPENDS = mruby

COMPONENT_EXTRA_CLEAN := app_mrb.h

esp32-mruby-test.o: app_mrb.h

app_mrb.h: $(COMPONENT_PATH)/main.rb
	$(COMPONENT_PATH)/../components/mruby/mruby/bin/mrbc -B app_mrb -o $@ $^

.PHONY: app_mrb.h
