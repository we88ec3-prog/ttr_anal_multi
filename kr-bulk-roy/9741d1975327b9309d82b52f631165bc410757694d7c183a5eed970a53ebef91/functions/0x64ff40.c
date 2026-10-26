
void FUN_0064ff40(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  double local_a0;
  undefined4 local_98;
  float local_8c;
  float local_88;
  undefined4 uStack_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  puStack_48 = &LAB_0091d3de;
  local_4c = ExceptionList;
  ExceptionList = &local_4c;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_44 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xffffff40);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_44 = 0xffffffff;
  local_a0 = (double)*(float *)(unaff_ESI + 0xac);
  FUN_008ff2e0((double)*(float *)(unaff_ESI + 0xac));
  iVar3 = FUN_008fed10();
  if (2 < iVar3) {
    iVar3 = 2;
  }
  iVar3 = *(int *)(&DAT_00f94524 + iVar3 * 4);
  if (*(int *)(unaff_ESI + 0xfc) != iVar3) {
    if (((iVar3 != 0) && (piVar2 = *(int **)(iVar3 + 8), piVar2 != (int *)0x0)) &&
       (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
      (**(code **)(*piVar2 + 0x24))();
    }
    if ((*(int *)(unaff_ESI + 0xfc) != 0) &&
       (piVar2 = *(int **)(*(int *)(unaff_ESI + 0xfc) + 8), piVar2 != (int *)0x0)) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
    *(int *)(unaff_ESI + 0xfc) = iVar3;
  }
  if (*(int *)(unaff_ESI + 0xfc) != 0) {
    local_a0 = 0.007812501848093234;
    local_98 = 0x3f800000;
    local_8c = (float)param_1;
    local_88 = (float)param_2;
    uStack_84 = 0;
    FUN_00751f90(*(int *)(unaff_ESI + 0xfc),&local_8c,&local_a0);
  }
  ExceptionList = local_4c;
  return;
}

