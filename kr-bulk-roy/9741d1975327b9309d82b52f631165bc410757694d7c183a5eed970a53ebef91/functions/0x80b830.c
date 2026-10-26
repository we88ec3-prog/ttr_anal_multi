
/* WARNING: Removing unreachable block (ram,0x0080ba24) */

void FUN_0080b830(void)

{
  int iVar1;
  int unaff_ESI;
  float10 fVar2;
  undefined1 auStack_3c [4];
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009185ee;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_3c;
  ExceptionList = &local_14;
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x1c))(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
  if ((iVar1 == 1) && (*(int *)(unaff_ESI + 0x1c) == 0)) {
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      uStack_c = 0;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      uStack_c = 0xffffffff;
    }
    if ((DAT_00fab090 == (int *)0x0) && (DAT_00fab028 != (int *)0x0)) {
      DAT_00fab090 = (int *)(**(code **)(*DAT_00fab028 + 0x20))();
      (**(code **)(*DAT_00fab090 + 0x18))(3);
    }
    (**(code **)(*DAT_00fab090 + 0x14))(&fStack_28);
    fStack_34 = *(float *)(unaff_ESI + 0x10) - fStack_28;
    fStack_30 = *(float *)(unaff_ESI + 0x14) - fStack_24;
    fStack_2c = *(float *)(unaff_ESI + 0x18) - fStack_20;
    fStack_38 = fStack_30 * fStack_30 + fStack_34 * fStack_34 + fStack_2c * fStack_2c;
    fVar2 = (float10)FUN_008ff870();
    fStack_38 = (float)fVar2;
    if (*(float *)(*(int *)(*(int *)(unaff_ESI + 4) + 8) + 0x3c) < fStack_38) goto LAB_0080ba37;
    if (1.0 < fStack_38) {
      fStack_38 = 1.0;
    }
    FUN_008fed10();
  }
  (**(code **)(**(int **)(unaff_ESI + 4) + 0x20))();
  FUN_008fed10();
  if (*(int *)(unaff_ESI + 8) == 0) {
    fVar2 = (float10)0;
  }
  else {
    fVar2 = (float10)(**(code **)(**(int **)(unaff_ESI + 8) + 0x30))();
  }
  fStack_38 = (float)fVar2;
  if ((0 < *(int *)(unaff_ESI + 0x24)) ||
     ((*(int *)(unaff_ESI + 8) != 0 &&
      (iVar1 = (**(code **)(**(int **)(unaff_ESI + 8) + 0x10))(), iVar1 != 0)))) {
    fStack_38 = 0.0;
  }
LAB_0080ba37:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_3c);
  return;
}

