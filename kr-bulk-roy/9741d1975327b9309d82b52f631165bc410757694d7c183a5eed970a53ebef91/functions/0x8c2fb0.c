
int FUN_008c2fb0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar2 = param_2;
  uVar4 = *(undefined4 *)(param_2 + 0x1c);
  *(int *)(param_1 + 0x168) = param_2;
  param_2 = (**(code **)(param_1 + 0x1fc))(param_1,0x6e616d65,param_2,&local_c);
  if (param_2 == 0) {
    iVar3 = FUN_008b9850(iVar2);
    param_2 = FUN_008bacd0(iVar2,&DAT_00bd7e70,param_1 + 0x158);
    if (param_2 == 0) {
      iVar5 = *(int *)(param_1 + 0x15c);
      uVar1 = iVar3 + 6 + iVar5 * 0xc;
      if ((uint)(local_c + iVar3) < uVar1) {
        return 0x91;
      }
      *(undefined4 *)(param_1 + 0x15c) = 0;
      local_8 = iVar5;
      uVar4 = FUN_008bc7d0(uVar4,0x14,0,iVar5,0,&param_2);
      *(undefined4 *)(param_1 + 0x164) = uVar4;
      if ((param_2 == 0) && (param_2 = FUN_008babe0(iVar2,iVar5 * 0xc), param_2 == 0)) {
        iVar5 = *(int *)(param_1 + 0x164);
        if (local_8 != 0) {
          param_2 = 0;
          do {
            param_2 = FUN_008bacd0(iVar2,&DAT_00bd7e84,iVar5);
            if ((param_2 == 0) && (*(ushort *)(iVar5 + 8) != 0)) {
              *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + *(int *)(param_1 + 0x160) + iVar3;
              if ((*(uint *)(iVar5 + 0xc) < uVar1) ||
                 ((uint)(local_c + iVar3) < (uint)*(ushort *)(iVar5 + 8) + *(uint *)(iVar5 + 0xc)))
              {
                *(undefined4 *)(iVar5 + 0xc) = 0;
                *(undefined2 *)(iVar5 + 8) = 0;
              }
              else {
                iVar5 = iVar5 + 0x14;
              }
            }
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
        *(int *)(param_1 + 0x15c) = (iVar5 - *(int *)(param_1 + 0x164)) / 0x14;
        FUN_008baca0(iVar2);
        *(undefined2 *)(param_1 + 0x154) = *(undefined2 *)(param_1 + 0x15c);
      }
    }
  }
  return param_2;
}

