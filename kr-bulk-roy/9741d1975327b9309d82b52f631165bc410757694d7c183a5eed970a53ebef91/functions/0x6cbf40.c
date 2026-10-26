
void FUN_006cbf40(int param_1)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  cVar2 = DAT_00f94363;
  local_c = 0xffffffff;
  bVar6 = DAT_00f94363 != '\0';
  iVar5 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if ((iVar5 != 0) && (cVar3 = FUN_00408920(iVar5,bVar6), cVar3 != '\0')) {
    FUN_00749920(*(undefined4 *)(param_1 + 0xec));
  }
  if (bVar6) {
    iVar5 = 0;
    local_1c = 1;
    do {
      iVar4 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
      if ((((iVar4 != 0) && (-1 < iVar5)) &&
          (iVar5 < *(int *)(iVar4 + 0xac) - *(int *)(iVar4 + 0xa8) >> 2)) &&
         (piVar1 = *(int **)(*(int *)(iVar4 + 0xa8) + iVar5 * 4), piVar1 != (int *)0x0)) {
        iVar4 = (**(code **)(*piVar1 + 4))();
        if (iVar4 == 0x12d) {
          (**(code **)(*piVar1 + 0x198))(cVar2);
        }
        else {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        }
      }
      iVar5 = iVar5 + 1;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  ExceptionList = local_14;
  return;
}

