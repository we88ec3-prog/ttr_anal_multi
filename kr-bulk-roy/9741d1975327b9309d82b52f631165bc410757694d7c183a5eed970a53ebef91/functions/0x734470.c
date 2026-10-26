
void FUN_00734470(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  uint local_2c;
  int local_28 [6];
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_30 = param_1;
  if (*(int *)(param_1 + 0x44) != 0) {
    local_2c = param_2 & 0xff;
    (**(code **)(**(int **)(param_1 + 0x44) + 0x44))(*(int **)(param_1 + 0x44),0,local_28);
    iVar1 = local_30;
    if (local_28[0] == 0x1a) {
      param_2 = ((param_2 >> 0x10 & 0xf0) + 0xf00) * 0x10 + (local_2c >> 4) + (param_2 >> 8 & 0xf0);
    }
    else if (local_28[0] == 0x19) {
      param_2 = (local_2c >> 3) +
                (((param_2 >> 0x10 & 0xf8) + 0x100) * 0x20 + (param_2 >> 8 & 0xf8)) * 4;
    }
    else if (local_28[0] != 0x15) goto LAB_00734492;
    iVar2 = (**(code **)(**(int **)(local_30 + 0x44) + 0x4c))
                      (*(int **)(local_30 + 0x44),0,local_38,0,0);
    if (-1 < iVar2) {
      uVar4 = 0;
      if (local_c != 0) {
        do {
          uVar3 = 0;
          if (local_10 != 0) {
            do {
              iVar2 = local_10 * uVar4 + uVar3;
              if (local_28[0] == 0x15) {
                *(uint *)(local_34 + iVar2 * 4) = param_2;
              }
              else {
                *(short *)(local_34 + iVar2 * 2) = (short)param_2;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < local_10);
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_c);
      }
      (**(code **)(**(int **)(iVar1 + 0x44) + 0x50))(*(int **)(iVar1 + 0x44),0);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_00734492:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

