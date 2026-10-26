
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c34b0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093987c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(in_ECX + 0x224) + 0x16c))(0,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar1 = *(int **)(in_ECX + 0x224);
  if ((piVar1[10] & 0x100U) != 0) {
    if ((piVar1[10] & 0x100U) != 0) {
      (**(code **)(*piVar1 + 0xd4))();
    }
    iVar2 = *(int *)(in_ECX + 0x228);
    (**(code **)(**(int **)(iVar2 + 0xa8) + 0x94))(0);
    (**(code **)(**(int **)(iVar2 + 0xa4) + 0x94))(*(char *)(iVar2 + 0xdd) != '\0');
    *(undefined1 *)(iVar2 + 0xde) = 0;
    if ((DAT_00fc0f80 & 1) == 0) {
      DAT_00fc0f80 = DAT_00fc0f80 | 1;
      local_8 = 0;
      FUN_0047aeb0();
      _atexit((_func_4879 *)&LAB_00bcdb70);
    }
    _DAT_00fc0fbc = 0;
    ExceptionList = local_10;
    return;
  }
  FUN_00596e00(in_ECX,piVar1);
  iVar2 = *(int *)(in_ECX + 0x228);
  (**(code **)(**(int **)(iVar2 + 0xa8) + 0x94))(*(char *)(iVar2 + 0xdd) != '\0');
  (**(code **)(**(int **)(iVar2 + 0xa4) + 0x94))(0);
  *(undefined1 *)(iVar2 + 0xde) = 1;
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8 = 1;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
  }
  _DAT_00fc0fbc = 1;
  ExceptionList = local_10;
  return;
}

