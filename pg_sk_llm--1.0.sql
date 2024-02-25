-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_sk_llm" to load this file. \quit

CREATE OR REPLACE FUNCTION llm_prompt( TEXT ) RETURNS TEXT
  AS 'pg_sk_llm' LANGUAGE C;

