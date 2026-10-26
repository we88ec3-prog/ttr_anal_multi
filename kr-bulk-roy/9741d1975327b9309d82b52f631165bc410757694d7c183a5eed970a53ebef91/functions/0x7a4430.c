
void FUN_007a4430(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093823e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = *in_ECX;
  uVar3 = 0;
  if (in_ECX[1] - iVar2 >> 2 != 0) {
    do {
      FUN_007d68d0(*(undefined4 *)(iVar2 + uVar3 * 4));
      iVar2 = *in_ECX;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(in_ECX[1] - iVar2 >> 2));
  }
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 0;
    FUN_007b7da0(uVar1);
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = 0xffffffff;
  }
  iVar2 = DAT_00fe173c;
  piVar4 = (int *)**(int **)(DAT_00fe173c + 4);
  if (piVar4 != *(int **)(DAT_00fe173c + 4)) {
    do {
      if (((int *)piVar4[9])[1] == 0) {
        (**(code **)(*(int *)piVar4[9] + 4))();
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(iVar2 + 4));
  }
  ExceptionList = local_10;
  return;
}

