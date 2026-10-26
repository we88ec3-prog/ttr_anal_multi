
undefined4 FUN_004b3ee0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00930c2a;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((uint)*(byte *)(param_1 + 2) <
       (uint)(*(int *)(DAT_00fba838 + 0x48) - *(int *)(DAT_00fba838 + 0x44) >> 2)) &&
     (piVar1 = *(int **)(*(int *)(DAT_00fba838 + 0x44) + (uint)*(byte *)(param_1 + 2) * 4),
     piVar1 != (int *)0x0)) {
    iVar2 = piVar1[2];
    iVar3 = *piVar1;
    iVar4 = piVar1[1];
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar7);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    piVar6 = DAT_00fb76e8;
    uVar5 = DAT_00fb79e8 & 1;
    DAT_00fb76e8[3] = iVar3;
    piVar6[4] = iVar4;
    piVar6[5] = iVar2;
    piVar6[0x33] = 0;
    iVar2 = piVar1[5];
    if (uVar5 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar7);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    piVar6 = DAT_00fb76e8;
    uVar5 = DAT_00fb79e8 & 1;
    DAT_00fb76e8[8] = iVar2;
    piVar6[0x33] = 0;
    iVar2 = piVar1[9];
    if (uVar5 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0(uVar7);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    piVar1 = DAT_00fb76e8;
    if (*DAT_00fb76e8 != 0) {
      *(int *)(*DAT_00fb76e8 + 0x7c) = iVar2;
    }
    piVar1[0xc] = iVar2;
  }
  ExceptionList = local_10;
  return 0;
}

