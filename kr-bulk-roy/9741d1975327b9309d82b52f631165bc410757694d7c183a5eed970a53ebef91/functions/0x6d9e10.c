
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d9e10(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((_DAT_00fc1698 & 1) == 0) {
    _DAT_00fc1698 = _DAT_00fc1698 | 1;
    FUN_0080c8a0();
    _atexit((_func_4879 *)&LAB_00bce320);
  }
  iVar5 = 0;
  while (((int *)(&DAT_00fc16a0)[iVar5] == (int *)0x0 ||
         (iVar2 = (**(code **)(*(int *)(&DAT_00fc16a0)[iVar5] + 0x30))(), iVar2 != 0))) {
    iVar5 = iVar5 + 1;
    if (0xf < iVar5) {
      return;
    }
  }
  piVar1 = (int *)(&DAT_00fc16a0)[iVar5];
  if (piVar1 != (int *)0x0) {
    if ((uint)param_2[6] < 0x10) {
      piVar3 = param_2 + 1;
    }
    else {
      piVar3 = (int *)param_2[1];
    }
    iVar5 = (**(code **)(*piVar1 + 0x14))(piVar3,param_2[8]);
    if (-1 < iVar5) {
      iVar5 = *piVar1;
      uVar4 = FUN_008fed10();
      (**(code **)(iVar5 + 0x48))(uVar4);
      (**(code **)(*piVar1 + 0x4c))(0x3f800000);
      *param_2 = (int)piVar1;
      return;
    }
    FUN_00402a70(&DAT_00bf2375,0);
    *param_2 = 0;
  }
  return;
}

