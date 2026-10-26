
undefined4 * FUN_0040ca50(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
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
  if ((in_EDX == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (in_ECX - 1U < 100) {
      puVar1 = (undefined4 *)(in_ECX * 0x20 + iVar2);
      if (((*(int *)(in_ECX * 0x20 + 0xc + iVar2) != 0) && (puVar1[2] != 0)) &&
         (puVar1 != (undefined4 *)0x0)) {
        if ((DAT_00faaffc & 1) == 0) {
          DAT_00faaffc = DAT_00faaffc | 1;
          local_c = 1;
          FUN_008132e0();
          _atexit((_func_4879 *)&LAB_00bccce0);
        }
        local_20[0] = *puVar1;
        piVar3 = (int *)FUN_008438c0(local_20);
        if ((*piVar3 != DAT_00fab014) && (*(int *)(*piVar3 + 0x10) != 0)) {
          ExceptionList = local_14;
          return puVar1;
        }
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
  }
  ExceptionList = local_14;
  return (undefined4 *)0x0;
}

