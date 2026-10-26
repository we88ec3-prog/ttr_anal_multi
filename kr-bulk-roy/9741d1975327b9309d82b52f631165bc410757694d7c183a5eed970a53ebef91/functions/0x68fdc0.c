
int FUN_0068fdc0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009451fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar5 = *(int *)(*(int *)(param_1 + 0x124) + 0xcc);
  iVar3 = 0;
  if (iVar5 != 0) {
    iVar3 = *(int *)(iVar5 + 0xdc);
    if (iVar3 == 0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = *(uint *)(iVar3 + 0x20);
    }
    if (uVar4 != 0xffffffff) {
      if ((DAT_00fb1378 & 1) == 0) {
        DAT_00fb1378 = DAT_00fb1378 | 1;
        local_8 = 0;
        FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bccfb0);
      }
      local_8 = 0xffffffff;
      iVar3 = (DAT_00fb723c - DAT_00fb7238) * 0x4bda12f7;
      if ((uVar4 < (uint)((DAT_00fb723c - DAT_00fb7238) / 0x36)) &&
         (iVar5 = uVar4 * 0x36 + DAT_00fb7238, iVar5 != 0)) {
        puVar2 = (undefined4 *)FUN_00891268(0x18);
        if (puVar2 != (undefined4 *)0x0) {
          uVar1 = *(undefined4 *)(iVar5 + 0x2e);
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf4378;
          *puVar2 = FoxUI::FXUIEventI1::vftable;
          puVar2[5] = uVar1;
        }
        iVar3 = FUN_004072a0();
      }
    }
  }
  ExceptionList = local_10;
  return iVar3;
}

