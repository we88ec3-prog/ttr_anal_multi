
void FUN_007359e0(int param_1,int *param_2,int *param_3,int *param_4,short *param_5,uint param_6)

{
  short *psVar1;
  short sVar2;
  undefined4 ***pppuVar3;
  int iVar4;
  int *in_ECX;
  undefined4 *in_EDX;
  int iVar5;
  int local_38;
  int local_34;
  undefined4 **local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919548;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_5 != (short *)0x0) {
    psVar1 = param_5 + 1;
    do {
      sVar2 = *param_5;
      param_5 = param_5 + 1;
    } while (sVar2 != 0);
    if ((int)param_5 - (int)psVar1 >> 1 != 0) {
      local_38 = *param_3;
      local_34 = param_3[1];
      FUN_0073ce20(local_14);
      local_8 = 0;
      pppuVar3 = (undefined4 ***)local_30[0];
      if (local_1c < 8) {
        pppuVar3 = local_30;
      }
      iVar4 = FUN_00735620(param_1,*(undefined4 *)(param_1 + 0x20),pppuVar3,param_6);
      if (iVar4 == 0) {
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      else {
        *param_2 = *(int *)(iVar4 + 0x24);
        param_2[1] = *(int *)(iVar4 + 0x28);
        param_2[2] = *(int *)(iVar4 + 0x2c);
        param_2[3] = *(int *)(iVar4 + 0x30);
        if ((param_6 & 1) != 0) {
          local_38 = local_38 +
                     (((param_3[2] - *(int *)(iVar4 + 0x2c)) - *param_3) + *(int *)(iVar4 + 0x24)) /
                     2;
        }
        if ((param_6 & 4) != 0) {
          local_34 = local_34 +
                     (((*(int *)(iVar4 + 0x28) - *(int *)(iVar4 + 0x30)) + param_3[3]) - param_3[1])
                     / 2;
        }
        if (param_4 != (int *)0x0) {
          if (*param_3 < *param_4) {
            iVar5 = *param_4 - *param_3;
            local_38 = local_38 + iVar5;
            *param_2 = *param_2 + iVar5;
          }
          iVar5 = param_4[1];
          if (param_3[1] < iVar5) {
            local_34 = local_34 + (iVar5 - param_3[1]);
            param_2[1] = param_2[1] + (iVar5 - param_3[1]);
          }
          if (param_4[2] < param_3[2]) {
            param_2[2] = param_2[2] + (param_4[2] - param_3[2]);
          }
          if (param_4[3] < param_3[3]) {
            param_2[3] = param_2[3] + (param_4[3] - param_3[3]);
          }
        }
        *in_ECX = local_38;
        in_ECX[1] = local_34;
        in_ECX[2] = (*(int *)(iVar4 + 0x2c) - *(int *)(iVar4 + 0x24)) + local_38;
        in_ECX[3] = (*(int *)(iVar4 + 0x30) - *(int *)(iVar4 + 0x28)) + local_34;
        *in_EDX = *(undefined4 *)(param_1 + 4);
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

