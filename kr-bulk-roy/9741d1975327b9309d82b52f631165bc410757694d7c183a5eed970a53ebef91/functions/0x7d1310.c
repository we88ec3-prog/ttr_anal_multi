
void FUN_007d1310(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  void *pvVar10;
  undefined4 uVar11;
  int iVar12;
  int *local_2c [2];
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00934c3c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  piVar4 = DAT_00fb76a8;
  local_c = 0xffffffff;
  local_2c[0] = DAT_00fb76a8;
  piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  local_24 = piVar1;
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x98,0);
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0x4004)) {
    do {
      (**(code **)(**(int **)(param_1 + 0x2004 + iVar12 * 4) + 0xc))(piVar4,1);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x4004));
  }
  *(undefined4 *)(param_1 + 0x4004) = 0;
  FUN_0079b520(&DAT_00fb76a8,3);
  local_2c[0] = (int *)0x1;
  uVar11 = 0x1c;
  (**(code **)(*piVar1 + 0xe8))(piVar1,0x1c,local_2c);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1c,0);
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0x6008)) {
    do {
      (**(code **)(**(int **)(param_1 + 0x4008 + iVar12 * 4) + 0xc))(piVar4,2);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x6008));
  }
  *(undefined4 *)(param_1 + 0x6008) = 0;
  (**(code **)(*piVar4 + 0xc))(1,1,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1c,uVar11);
  FUN_007d1c90(piVar4);
  piVar1 = (int *)0x1;
  (**(code **)(*piVar4 + 0xc))(1,1,1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  FUN_0079b520(&DAT_00fb76a8,5);
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0xa010)) {
    do {
      (**(code **)(**(int **)(param_1 + 0x8010 + iVar12 * 4) + 0xc))(piVar4,4);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0xa010));
  }
  iVar12 = 0;
  *(undefined4 *)(param_1 + 0xa010) = 0;
  if (0 < *(int *)(param_1 + 0x2003c)) {
    do {
      (**(code **)(**(int **)(param_1 + 0x1e03c + iVar12 * 4) + 0xc))(piVar4,0xf);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x2003c));
  }
  *(undefined4 *)(param_1 + 0x2003c) = 0;
  (**(code **)(*piVar4 + 0xc))(1,1,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  FUN_007d18a0(piVar4);
  (**(code **)(*piVar4 + 0xc))(1,1,1);
  pvVar10 = (void *)0x34;
  piVar8 = piVar1;
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x34,0);
  (**(code **)(*piVar1 + 0x104))(piVar1,1,0);
  piVar7 = (int *)0x2;
  (**(code **)(*piVar1 + 0x104))(piVar1,2,0);
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  iVar12 = 0;
  do {
    (**(code **)(*piVar2 + 0xd4))(piVar2,iVar12,0);
    iVar12 = iVar12 + 1;
  } while (iVar12 < 8);
  if (DAT_00fb7990 == 0) {
    FUN_007d1960(0);
  }
  else if (DAT_00fb7990 == 1) {
    FUN_007d17b0(1);
    FUN_007d1960(1);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x98,0);
    iVar12 = 0;
    piVar4 = piVar7;
    if (0 < *(int *)(param_1 + 0x1a030)) {
      do {
        (**(code **)(**(int **)(param_1 + 0x18030 + iVar12 * 4) + 0xc))(piVar7,0xc);
        iVar12 = iVar12 + 1;
        piVar4 = piVar7;
      } while (iVar12 < *(int *)(param_1 + 0x1a030));
    }
    *(undefined4 *)(param_1 + 0x1a030) = 0;
    (**(code **)(*piVar4 + 0xc))(1,1,1);
    FUN_007d17b0(0);
    FUN_007d1960(0);
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x98,0);
  }
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0x26048)) {
    do {
      (**(code **)(**(int **)(param_1 + 0x24048 + iVar12 * 4) + 0xc))(piVar4,0x12);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(param_1 + 0x26048));
  }
  *(undefined4 *)(param_1 + 0x26048) = 0;
  piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  iVar12 = 0;
  do {
    (**(code **)(*piVar1 + 0xd4))(piVar1,iVar12,0);
    iVar12 = iVar12 + 1;
  } while (iVar12 < 8);
  iVar12 = param_1 + 0x2604c;
  uVar9 = 0x13;
  bVar6 = true;
  do {
    if (bVar6) {
      iVar5 = 0;
      if (0 < *(int *)(iVar12 + 0x2000)) {
        do {
          (**(code **)(**(int **)(iVar12 + iVar5 * 4) + 0xc))(piVar4,uVar9);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(iVar12 + 0x2000));
      }
      *(undefined4 *)(iVar12 + 0x2000) = 0;
    }
    uVar9 = uVar9 + 1;
    iVar12 = iVar12 + 0x2004;
    bVar6 = uVar9 < 0x16;
  } while ((int)uVar9 < 0x16);
  (**(code **)(*piVar4 + 0xc))(1,1,1);
  puVar3 = (undefined4 *)(param_1 + 0x2000);
  iVar12 = 0x16;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 0x801;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  ExceptionList = pvVar10;
  return;
}

