
void FUN_007b99c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c4de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3c) == 2) {
    if (*(undefined4 **)(in_ECX + 0x8c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x8c))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      *(undefined4 *)(in_ECX + 0x8c) = 0;
    }
    if ((DAT_00fe3284 & 1) == 0) {
      DAT_00fe3284 = DAT_00fe3284 | 1;
      local_8 = 0;
      FUN_007df1e0();
      _atexit((_func_4879 *)&LAB_00bd0ad0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fe328c != (undefined4 *)0x0) {
      (**(code **)*DAT_00fe328c)(1);
      DAT_00fe328c = (undefined4 *)0x0;
    }
    if (*(int *)(in_ECX + 0x40) != 0) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x40) + 0x24);
      piVar2 = *(int **)(iVar1 + 8);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    piVar2 = *(int **)(in_ECX + 0x68);
    if ((piVar2 != (int *)0x0) && (*piVar2 == 2)) {
      *piVar2 = 1;
    }
    FUN_007e0ba0();
    *(undefined4 *)(in_ECX + 0x3c) = 1;
  }
  ExceptionList = local_10;
  return;
}

