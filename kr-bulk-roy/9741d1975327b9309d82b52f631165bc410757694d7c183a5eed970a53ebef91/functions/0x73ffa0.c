
int FUN_0073ffa0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int local_10;
  int local_c;
  byte *local_8;
  
  iVar1 = FUN_008b8ce0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x58));
  local_10 = iVar1;
  local_c = iVar1;
  FUN_0082ef00(&local_10);
  if (local_8 == *(byte **)(param_1 + 0x20)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_8 + 0x10);
  }
  *param_2 = iVar2;
  if (iVar2 == 0) {
    if (iVar1 == 0) {
      *param_2 = 0;
      return 0;
    }
    iVar2 = FUN_008bb2e0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x58),iVar1,
                         *(undefined4 *)(param_1 + 0xc));
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x58) + 0x54);
    if ((*(int *)(iVar2 + 0x48) != 0x62697473) &&
       (iVar2 = FUN_008ba9b0(iVar2,*(undefined4 *)(param_1 + 0x10)), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = FUN_00740570(iVar1);
    if ((*(int *)(param_1 + 0x14) != 0) && (*(char *)(iVar2 + 0x1a) == '\x02')) {
      local_8 = *(byte **)(iVar2 + 0x14);
      iVar1 = local_c;
      if (*(int *)(param_1 + 0x14) == 2) {
        param_1 = 0;
        if (0 < *(int *)(iVar2 + 8)) {
          iVar3 = *(int *)(iVar2 + 0xc);
          do {
            iVar4 = 0;
            pbVar5 = local_8;
            if (0 < iVar3) {
              do {
                iVar3 = *(int *)(&DAT_00c460a0 + (uint)*pbVar5 * 4);
                if (0xff < iVar3) {
                  iVar3 = 0xff;
                }
                *pbVar5 = (byte)iVar3;
                iVar3 = *(int *)(iVar2 + 0xc);
                iVar4 = iVar4 + 1;
                pbVar5 = pbVar5 + 1;
              } while (iVar4 < iVar3);
            }
            local_8 = local_8 + *(int *)(iVar2 + 0x10);
            param_1 = param_1 + 1;
          } while (param_1 < *(int *)(iVar2 + 8));
        }
      }
      else {
        local_10 = 0;
        if (0 < *(int *)(iVar2 + 8)) {
          iVar3 = *(int *)(iVar2 + 0xc);
          do {
            iVar1 = 0;
            pbVar5 = local_8;
            if (0 < iVar3) {
              do {
                iVar3 = FUN_0073fcb0();
                if (0xff < iVar3) {
                  iVar3 = 0xff;
                }
                *pbVar5 = (byte)iVar3;
                iVar3 = *(int *)(iVar2 + 0xc);
                iVar1 = iVar1 + 1;
                pbVar5 = pbVar5 + 1;
              } while (iVar1 < iVar3);
            }
            local_8 = local_8 + *(int *)(iVar2 + 0x10);
            local_10 = local_10 + 1;
            iVar1 = local_c;
          } while (local_10 < *(int *)(iVar2 + 8));
        }
      }
    }
    FUN_0073ff40(iVar1,iVar2);
    *param_2 = iVar2;
  }
  return 0;
}

