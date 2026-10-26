
undefined4 FUN_004fdf30(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  float local_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094024e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  piVar2 = *(int **)(param_1 + 4);
  if ((char)(short)piVar2[1] == '\0') {
    iVar3 = piVar2[0x27];
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (iVar3 != DAT_00f93930) {
      fVar4 = (float10)FUN_008ff870();
      if ((piVar2[0x57] == 0) || (piVar2[0xdc] == 0)) {
        local_30 = 0.0;
      }
      else {
        fVar5 = (float10)FUN_007a7100();
        local_30 = (float)fVar5;
      }
      if ((float)fVar4 < local_30) {
        fVar1 = *(float *)(in_ECX + 0x1c);
        iVar3 = (**(code **)(*piVar2 + 0x4c))();
        fVar4 = (float10)FUN_004ff540(fVar1 - *(float *)(iVar3 + 8));
        if ((piVar2[0x57] == 0) || (piVar2[0xdc] == 0)) {
          local_30 = 0.0;
        }
        else {
          fVar5 = (float10)FUN_007a7100();
          local_30 = (float)fVar5;
        }
        if ((float)fVar4 < local_30) {
          FUN_00443d10();
          if (4 < (uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2)) {
            ExceptionList = local_14;
            return 0;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 1;
}

