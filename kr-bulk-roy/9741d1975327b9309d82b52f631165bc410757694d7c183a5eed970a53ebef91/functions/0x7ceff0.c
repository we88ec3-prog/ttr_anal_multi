
void FUN_007ceff0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937bec;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  (**(code **)(*piVar2 + 0x104))(piVar2,0,0);
  (**(code **)(*piVar2 + 0x104))(piVar2,1,0);
  (**(code **)(*piVar2 + 0x104))(piVar2,2,0);
  if (param_2 == 0) {
    FUN_007cee10();
  }
  else if (param_2 == 3) {
    FUN_007ce910();
  }
  else if (param_2 == 4) {
    FUN_007ceb80();
  }
  uVar4 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2;
  local_14 = 0;
  if (uVar4 != 0) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x20) + local_14 * 4);
      if (*piVar2 == 2) {
        iVar3 = piVar2[3];
        uVar5 = 0;
        if (piVar2[4] - iVar3 >> 2 != 0) {
          do {
            piVar1 = *(int **)(iVar3 + uVar5 * 4);
            if (piVar1[2] == param_2) {
              (**(code **)(*piVar1 + 0x20))(1,1);
            }
            iVar3 = piVar2[3];
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)(piVar2[4] - iVar3 >> 2));
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < uVar4);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
  ExceptionList = local_10;
  return;
}

