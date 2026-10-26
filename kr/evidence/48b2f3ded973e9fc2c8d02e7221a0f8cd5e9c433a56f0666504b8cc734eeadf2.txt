
undefined4 FUN_00544a00(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  float fVar4;
  float fStack_2c;
  int iStack_28;
  float fStack_24;
  int *piStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009405be;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iStack_1c = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  uVar3 = 0;
  if (iStack_1c != 0) {
    fStack_24 = 999999.0;
    piStack_20 = (int *)0x0;
    if (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2 != 0) {
      fVar4 = 0.0;
      iStack_1c = iStack_1c + 0xa0;
      do {
        iStack_28 = 0;
        fStack_2c = fVar4;
        iVar2 = FUN_00544730(*(undefined4 *)(*(int *)(in_ECX + 4) + uVar3 * 4),&fStack_2c,param_1);
        if (((iStack_28 != 0) && (iVar2 != 0)) && (fStack_2c < fStack_24)) {
          piStack_20 = *(int **)(uVar3 * 4 + *(int *)(in_ECX + 4));
          fStack_24 = fStack_2c;
        }
        piVar1 = piStack_20;
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2));
      if (piStack_20 != (int *)0x0) {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          uStack_c = 0;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          uStack_c = 0xffffffff;
        }
        if (DAT_00f942c0 == '\0') {
          (**(code **)(*piVar1 + 100))();
          ExceptionList = local_14;
          return 1;
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

