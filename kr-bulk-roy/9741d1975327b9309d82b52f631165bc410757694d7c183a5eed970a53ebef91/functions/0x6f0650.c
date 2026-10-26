
void FUN_006f0650(char *param_1)

{
  int *piVar1;
  char *_Dst;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *unaff_ESI;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905b58;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 3));
  local_8 = 0;
  piVar1 = *(int **)*unaff_ESI;
  _Dst = (char *)piVar1[2];
  local_14 = _Dst;
  if (piVar1 != (int *)*unaff_ESI) {
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    FUN_0089120c(piVar1,uVar3);
    unaff_ESI[1] = unaff_ESI[1] + -1;
  }
  if (param_1 != (char *)0x0) {
    _strncpy_s(_Dst,0x800,param_1,0x7ff);
  }
  iVar2 = *unaff_ESI;
  iVar4 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_14);
  if (unaff_ESI[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  unaff_ESI[1] = unaff_ESI[1] + 1;
  *(int *)(iVar2 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 3));
  ExceptionList = local_10;
  return;
}

