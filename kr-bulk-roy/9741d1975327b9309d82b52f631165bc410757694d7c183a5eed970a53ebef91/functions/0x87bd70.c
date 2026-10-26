
void FUN_0087bd70(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((param_5 != 0) && (*(int **)(param_5 + 0x3c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_5 + 0x3c) + 4))();
    if (*(int *)(iVar1 + 4) == -0x5ece0000) {
      iVar1 = *(int *)(param_5 + 0x3c);
      local_1c = *(undefined4 *)(iVar1 + 0x1c0);
      local_24 = *(undefined4 *)(iVar1 + 0x1b8);
      local_20 = *(undefined4 *)(iVar1 + 0x1bc);
      if (param_1 == 6) {
        uVar3 = 3;
        puVar2 = &local_24;
      }
      else {
        if (param_1 != 7) {
          if (param_1 == 0xb) {
            iVar1 = FUN_00843f60(4);
            if (iVar1 != 0) {
              puVar2 = (undefined4 *)FUN_0083b440();
              if (puVar2 != (undefined4 *)0x0) {
                (**(code **)(*param_2 + 0xd0))(param_2,param_3,*puVar2);
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                return;
              }
            }
          }
          goto LAB_0087be83;
        }
        uVar3 = 4;
        puVar2 = &local_18;
        local_c = 0x3f800000;
        local_18 = local_24;
        local_14 = local_20;
        local_10 = local_1c;
      }
      (**(code **)(*param_2 + 0x80))(param_2,param_3,puVar2,uVar3);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_0087be83:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

