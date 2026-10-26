
undefined4 FUN_007ea3a0(int param_1,int *param_2)

{
  void **ppvVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int *_Str1;
  double dVar7;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909c5b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppvVar1 = &local_10;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  do {
    ExceptionList = ppvVar1;
    iVar3 = (**(code **)(*param_2 + 0x14))(uVar2);
    if (iVar3 != 0) {
      iVar3 = FUN_007300a0("ZScale");
      if (iVar3 == 0) {
LAB_007ea428:
        local_1c = 0.0;
      }
      else {
        pcVar4 = (char *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          pcVar4 = *(char **)pcVar4;
        }
        if (pcVar4 == (char *)0x0) goto LAB_007ea428;
        dVar7 = _atof(pcVar4);
        local_1c = (float)dVar7;
      }
      iVar3 = FUN_007300a0("XScale");
      if (iVar3 == 0) {
LAB_007ea457:
        local_14 = 0.0;
      }
      else {
        pcVar4 = (char *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          pcVar4 = *(char **)pcVar4;
        }
        if (pcVar4 == (char *)0x0) goto LAB_007ea457;
        dVar7 = _atof(pcVar4);
        local_14 = (float)dVar7;
      }
      iVar3 = FUN_007300a0("YScale");
      if (iVar3 == 0) {
LAB_007ea486:
        local_18 = 0.0;
      }
      else {
        pcVar4 = (char *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          pcVar4 = *(char **)pcVar4;
        }
        if (pcVar4 == (char *)0x0) goto LAB_007ea486;
        dVar7 = _atof(pcVar4);
        local_18 = (float)dVar7;
      }
      iVar3 = FUN_00891268(0x1a0);
      local_8 = 0;
      if (iVar3 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_007e4d40(iVar3,local_1c,local_14,local_18);
      }
      local_8 = 0xffffffff;
      iVar3 = *(int *)(param_1 + 4);
      if (*(int **)(iVar3 + 0x40) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + 0x40) + 4))(1);
        *(undefined4 *)(iVar3 + 0x40) = 0;
      }
      *(undefined4 *)(iVar3 + 0x40) = uVar5;
      iVar3 = FUN_0087dc3d(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x38));
      (**(code **)(**(int **)(param_1 + 0x24) + 0x34))
                (*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x28),0);
      if (*(int **)(param_1 + 0x24) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x24) + 0x10))
                  (iVar3,1,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x38));
      }
      iVar6 = FUN_0087dc3d(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x3c));
      FUN_00727190(iVar6);
      FUN_007e5f70(iVar6,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x2c),
                   *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x30));
      if (iVar3 != 0) {
        FUN_00891d3d(iVar3);
      }
      if (iVar6 != 0) {
        FUN_00891d3d(iVar6);
      }
    }
    for (param_2 = (int *)param_2[0x10]; param_2 != (int *)0x0; param_2 = (int *)param_2[0x10]) {
      _Str1 = param_2 + 8;
      if (0xf < (uint)param_2[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar3 = __stricmp((char *)_Str1,"Height");
      if (iVar3 == 0) goto LAB_007ea5c6;
    }
    param_2 = (int *)0x0;
LAB_007ea5c6:
    ppvVar1 = ExceptionList;
    if (param_2 == (int *)0x0) {
      ExceptionList = local_10;
      return 1;
    }
  } while( true );
}

