
uint FUN_00409c60(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int in_EDX;
  undefined4 local_20 [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094219c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  uVar3 = in_EDX - 1;
  if ((uVar3 == 0) && (uVar3 = in_EDX * 0xca8 + 0xa50 + DAT_00f94300, uVar3 != 0)) {
    if (99 < in_ECX - 1U) {
      uVar3 = FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return uVar3 & 0xffffff00;
    }
    puVar1 = (undefined4 *)(in_ECX * 0x20 + uVar3);
    if (((*(int *)(in_ECX * 0x20 + 0xc + uVar3) != 0) && (puVar1[2] != 0)) &&
       (puVar1 != (undefined4 *)0x0)) {
      if ((DAT_00faaffc & 1) == 0) {
        DAT_00faaffc = DAT_00faaffc | 1;
        local_c = 1;
        FUN_008132e0();
        _atexit((_func_4879 *)&LAB_00bccce0);
      }
      local_20[0] = *puVar1;
      piVar2 = (int *)FUN_008438c0(local_20);
      if (*piVar2 == DAT_00fab014) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*piVar2 + 0x10);
      }
      ExceptionList = local_14;
      return CONCAT31((int3)((uint)iVar4 >> 8),iVar4 != 0);
    }
  }
  ExceptionList = local_14;
  return uVar3 & 0xffffff00;
}

