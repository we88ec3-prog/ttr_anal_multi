
void FUN_007e5c70(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934b26;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(param_1 + 0x19c) != 0) &&
     (FUN_007f8430(DAT_00d61f20 ^ (uint)&stack0xfffffffc), *(int *)(param_1 + 0x19c) != 0)) {
    FUN_007e5ec0();
    *(undefined4 *)(param_1 + 0x19c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x24);
  if ((*piVar1 != 0) && (FUN_007ffcc0(), *piVar1 != 0)) {
    FUN_007f7350();
    *piVar1 = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar1 = DAT_00fb76a8;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    iVar2 = *piVar1;
    uVar3 = FUN_0079be00("SYSTEM_LIGHTMAP");
    (**(code **)(iVar2 + 0x5c))(uVar3);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  }
  uVar4 = 0;
  if (*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x184) >> 2 != 0) {
    do {
      FUN_007f7800();
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x184) >> 2));
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x178) != 0) {
    FUN_00891d3d(*(int *)(param_1 + 0x178));
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  if (*(int *)(param_1 + 0x170) != 0) {
    FUN_00891d3d(*(int *)(param_1 + 0x170));
    *(undefined4 *)(param_1 + 0x170) = 0;
  }
  ExceptionList = local_10;
  return;
}

