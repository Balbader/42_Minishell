
# fcatineau ===> Balbader

# Builtins
## Env
len_tab : ft_get_env_len.c
env_to_tab : ft_convert_env_to_tab.c
ft_env_last : ft_get_last_env.c
ft_push_add_back : ft_add_var_to_env.c
ft_env_create : ft_create_env_list.c
ft_env_delone : ft_del_node.c
ft_env : ft_get_env.c
getall_env : ft_get_all_env.c

ft_compare_before_equals : ft_compare_keys.c
ft_env_value : ft_find_value.c

init_env :  ft_init_env (ft_get_env_utils.c)
add_env :  ft_add_to_env (ft_get_env_utils.c)
delone_env :  ft_del_from_env (ft_get_env_utils.c)
ft_getall_env : ft_get_all_env (ft_get_env_utils.c)

ft_delall_env : ft_del_env.c
modif_shlvl : ft_modif_shlvl.c

builtins_env : ft_exec_env.c
## Export
trim_end_value : ft_get_key_len.c
trim_before_egals : ft_get_key.c
var_exist : ft_does_value_exist.c
move_after_equals : ft_check_cpy.c
builtins_export : ft_exec_export.c

## Unset
verif_unset : ft_check_var_to_unset.c
builtins_unset : ft_exec_unset.c

## Echo
verif_flag_n : ft_check_n_flag.c
builtins_echo : ft_exec_echo.c

## PWD
builtins_pwd : ft_exec_pwd.c
## CD
pwd_old_pwd : ft_replace_working_directory.c
create_pwd : ft_create_working_directory.c
cd_less : ft_change_working_directory.c
find_in_cdpath : ft_get_cd_path.c
len_cd_arg : ft_get_token_len.c

## Exit
revove_quotes : ft_remove_quotes.c
str_is_digit : ft_str_is_digit
len_list : ft_get_token_list
builtins_exit : ft_exec_exit.c

# Utils_2
check_is_not_builtins : ft_check_cmd_for_builtins
check_builtins : ft_run_builtins.c
error_cmd : ft_print_cmd_error.c
error_sig : ft_print_sig_error.c
error_exit : ft_print_exit_error.c
error_export : ft_print_export_error.c
error_unset : ft_print_unset_error.c
error_msg : ft_print_error_msg.c
error_redir : ft_print_redir_error.c
ft_strlen_tab : ft_get_env_len.c
delall : ft_delete_all.c