
int FUN_008d18e0(undefined4 *param_1,int param_2,undefined2 *param_3)

{
  char *pcVar1;
  undefined2 extraout_var;
  char *unaff_EBX;
  undefined2 *puVar2;
  undefined2 *local_18;
  int local_14;
  char *local_10;
  undefined2 local_c [3];
  char local_5;
  
  local_10 = (char *)*param_1;
  local_14 = 0;
  if (unaff_EBX <= local_10) goto LAB_008d19b3;
  local_5 = '\0';
  if (*local_10 == '[') {
    local_5 = ']';
LAB_008d1917:
    local_10 = local_10 + 1;
  }
  else if (*local_10 == '{') {
    local_5 = '}';
    goto LAB_008d1917;
  }
  if (local_10 < unaff_EBX) {
    local_18 = param_3;
    while (FUN_008d02f0(), pcVar1 = local_10, local_10 < unaff_EBX) {
      if (*local_10 == local_5) {
        *param_1 = local_10 + 1;
        return local_14;
      }
      if (param_3 == (undefined2 *)0x0) {
        puVar2 = local_c;
      }
      else {
        puVar2 = local_18;
        if (param_2 <= local_14) break;
      }
      FUN_008d1540(&local_10);
      *puVar2 = extraout_var;
      if (pcVar1 == local_10) {
        local_14 = -1;
        break;
      }
      local_14 = local_14 + 1;
      local_18 = local_18 + 1;
      if (local_5 == '\0') break;
      if (unaff_EBX <= local_10) {
        *param_1 = local_10;
        return local_14;
      }
    }
  }
LAB_008d19b3:
  *param_1 = local_10;
  return local_14;
}

