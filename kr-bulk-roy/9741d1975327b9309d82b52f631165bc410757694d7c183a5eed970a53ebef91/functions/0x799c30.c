
void FUN_00799c30(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093273e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x11));
  (**(code **)(*(int *)*in_ECX + 0xd0))(uVar3);
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x11));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  iVar2 = DAT_00fb76a8;
  piVar4 = in_ECX;
  if (*(int *)(DAT_00fb76a8 + 0xec) != 0) {
    (**(code **)(**(int **)(DAT_00fb76a8 + 0xec) + 4))(*(int **)(DAT_00fb76a8 + 0xec));
    piVar4 = *(int **)(iVar2 + 0xec);
  }
  (**(code **)(*piVar4 + 0xec))(piVar4,1,in_ECX + 0x24);
  piVar1 = (int *)in_ECX[0x24];
  (**(code **)(*piVar1 + 0x10))(piVar1);
  (**(code **)(*piVar4 + 0xec))(piVar4,1,in_ECX + 0x25);
  (**(code **)(*piVar4 + 8))(piVar4);
  ExceptionList = local_10;
  return;
}

