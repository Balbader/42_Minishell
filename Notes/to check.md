Export many args
check cases:
1. When the key is the same but the value differs, export will simply replace the actual key value by the new key value
## Needed

+ Function to compare the key of token && token->next
	+ if the are the same -> replace old token value by new
	+ if different -> add back

+ 1. fct that checks if the incoming key does exist in the env