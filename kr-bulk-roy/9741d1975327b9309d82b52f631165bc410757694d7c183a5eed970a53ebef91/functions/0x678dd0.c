
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00678dd0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
      FUN_0067a010();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      FUN_00679310();
      return;
    }
  }
  else if (iVar1 == 0xf43a9) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_a = *(undefined1 *)(in_ECX + 0x118);
    local_9 = *(undefined1 *)(in_ECX + 0x11c);
    local_c = 0x67;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,4);
      return;
    }
  }
  else {
    if (iVar1 == 0xf43aa) {
      FUN_00679260();
      return;
    }
    if (iVar1 == 0xf4423) {
      iVar1 = FUN_004068c0();
      if (*(int *)(iVar1 + 0x14) == 0x6a7) {
        FUN_00679220();
        return;
      }
      if (*(int *)(iVar1 + 0x14) == 0x6a8) {
        (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(1);
      }
    }
  }
  return;
}

