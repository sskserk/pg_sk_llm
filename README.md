pg_sk_llm, a very basic Postgres extension to query LLMs from the PostgreSQL
=========================================

Once pg_config is in your path, do:
    make; sudo make install

Create extension
```sql
    CREATE EXTENSION pg_sk_llm;
```

Then in a psql session issue:
```sql
    SELECT llm_prompt('What is the time?');
```
# Functions
## llm_prompt

## llm_chat

# Parameters
    api_base
    api_token
    model