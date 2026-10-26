
undefined4 FUN_007d3870(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937fbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) != 0) {
    puVar4 = (undefined4 *)(param_2 + 8);
    if (0xf < *(uint *)(param_2 + 0x1c)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    iVar2 = FUN_007c65d0(*(int *)(param_1 + 0x10),puVar4,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 != 0) {
      FUN_00860650();
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 0;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      FUN_0079be00(param_3);
      if (param_3 != 0) {
        iVar1 = *(int *)(param_2 + 0x74);
        iVar5 = 0;
        if (0 < *(int *)(iVar1 + 0x178)) {
          do {
            iVar3 = FUN_00843ef0();
            iVar5 = iVar5 + 1;
            *(int *)(iVar3 + 0xb8) = param_3;
          } while (iVar5 < *(int *)(iVar1 + 0x178));
        }
      }
      FUN_008605b0(iVar2);
      FUN_007ee950();
      FUN_007ee9a0(*(undefined4 *)(param_1 + 0x10));
      FUN_007eebf0();
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}

