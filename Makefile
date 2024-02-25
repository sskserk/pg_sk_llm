MODULE_big = pg_sk_llm
OBJS = pg_sk_llm.o

EXTENSION = pg_sk_llm
DATA = pg_sk_llm--1.0.sql

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
