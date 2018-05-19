# contrib/dict_hrstemc/Makefile

MODULE_big = dict_hrstemc
OBJS = dict_hrstemc.o hrstemc.o rules.o transformations.o

SHLIB_LINK = -L/usr/local/lib -lpcre
PG_CPPFLAGS = -I/usr/local/include -I /usr/local/include/postgresql/server/ -I /usr/include/postgresql

EXTENSION = dict_hrstemc
DATA = dict_hrstemc--1.0.sql dict_hrstemc--unpackaged--1.0.sql
#DATA_TSEARCH = hrsufx_sample.rules

#REGRESS = dict_hrstemc

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/dict_hrstemc
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
