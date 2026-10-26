
undefined4 FUN_004ae380(int param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bc9c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 6) != -1) {
    if (*(char *)(param_1 + 7) == '\0') {
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8 = 0;
        FUN_004d4d10(uVar2);
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_8 = 0xffffffff;
      FUN_004d6ce0(&DAT_00fb11e8);
    }
    psVar6 = (short *)(param_1 + 8);
    psVar3 = psVar6;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if ((int)psVar3 - (param_1 + 10) >> 1 != 0) {
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8 = 1;
        FUN_004d4d10(uVar2);
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = 0xffffffff;
      }
      FUN_004d69a0(&DAT_00fb11e8);
      if ((*(char *)(param_1 + 6) != '\x02') && (*(char *)(param_1 + 6) != '\x03')) {
        FUN_0048a3d0();
        iVar4 = FUN_004f2940();
        if (iVar4 == 0) {
          FUN_0040f060();
          iVar4 = FUN_004dfad0();
          if (iVar4 != 0) {
            uVar5 = *(undefined4 *)(iVar4 + 4);
            FUN_0040f060(uVar5);
            iVar4 = FUN_004dfaa0(uVar5);
            if (iVar4 != 0) {
              iVar4 = (int)*(char *)(param_1 + 6);
              uVar5 = FUN_0048a1d0(psVar6,iVar4);
              FUN_0055ae70(uVar5,psVar6,iVar4);
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

