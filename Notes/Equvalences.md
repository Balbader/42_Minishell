
# fcatineau ===> Balbader

## Env
len_tab : ft_get_env_len.c
env_to_tab : ft_convert_env_to_tab.c
ft_env_last : ft_get_last_env.c
ft_push_add_back : ft_add_var_to_env.c
ft_env_create : ft_create_env_list.c
ft_env_delone : ft_del_node.c
ft_env : ft_get_env.c

ft_compare_before_equals : ft_compare_keys.c
ft_env_value : ft_find_value.c

init_env :  ft_init_env (ft_get_env_utils.c)
add_env :  ft_add_to_env (ft_get_env_utils.c)
delone_env :  ft_del_from_env (ft_get_env_utils.c)
ft_getall_env : ft_get_all_env (ft_get_env_utils.c)

ft_delall_env : ft_del_env.c

modif_shlvl : ft_modif_shlvl.c

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

## CD
pwd_old_pwd : ft_replace_working_directory.c
create_pwd : ft_create_working_directory.c
cd_less : ft_change_working_directory.c
find_in_cdpath : ft_get_cd_path.c
len_cd_arg : ft_get_token_len.c