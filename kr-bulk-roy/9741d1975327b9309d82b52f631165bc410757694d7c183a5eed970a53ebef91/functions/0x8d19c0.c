
int FUN_008d19c0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  char *unaff_EBX;
  undefined4 *puVar3;
  undefined4 local_18;
  undefined4 *local_14;
  int local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)*param_1;
  local_10 = 0;
  if (unaff_EBX <= local_c) goto LAB_008d1a91;
  local_5 = '\0';
  if (*local_c == '[') {
    local_5 = ']';
LAB_008d19f7:
    local_c = local_c + 1;
  }
  else if (*local_c == '{') {
    local_5 = '}';
    goto LAB_008d19f7;
  }
  if (local_c < unaff_EBX) {
    local_14 = param_3;
    while (FUN_008d02f0(), pcVar1 = local_c, local_c < unaff_EBX) {
      if (*local_c == local_5) {
        *param_1 = local_c + 1;
        return local_10;
      }
      if (param_3 == (undefined4 *)0x0) {
        puVar3 = &local_18;
      }
      else {
        puVar3 = local_14;
        if (param_2 <= local_10) break;
      }
      uVar2 = FUN_008d1540(&local_c);
      *puVar3 = uVar2;
      if (pcVar1 == local_c) {
        local_10 = -1;
        break;
      }
      local_10 = local_10 + 1;
      local_14 = local_14 + 1;
      if (local_5 == '\0') break;
      if (unaff_EBX <= local_c) {
        *param_1 = local_c;
        return local_10;
      }
    }
  }
LAB_008d1a91:
  *param_1 = local_c;
  return local_10;
}

