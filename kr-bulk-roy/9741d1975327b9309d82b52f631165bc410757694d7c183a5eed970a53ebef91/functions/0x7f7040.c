
void FUN_007f7040(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092642a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)(in_ECX + 4);
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    piVar2 = (int *)*piVar2;
  }
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_8 = 0;
    FUN_00716be0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_00716740(piVar2);
  if (iVar1 != 0) {
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 1;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    FUN_007b8480(&DAT_00fe173c,in_ECX + 0x30);
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 2;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    iVar1 = DAT_00fe173c;
    piVar2 = (int *)**(int **)(DAT_00fe173c + 4);
    if (piVar2 != *(int **)(DAT_00fe173c + 4)) {
      do {
        if (((int *)piVar2[9])[1] == 0) {
          (**(code **)(*(int *)piVar2[9] + 4))();
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(iVar1 + 4));
    }
  }
  ExceptionList = local_10;
  return;
}

