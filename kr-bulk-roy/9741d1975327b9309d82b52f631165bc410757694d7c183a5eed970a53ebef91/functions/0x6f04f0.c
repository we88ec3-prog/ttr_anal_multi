
int * FUN_006f04f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  char *_Dst;
  int iVar3;
  uint uVar4;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905b93;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0;
  param_1[1] = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  *param_1 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*param_1 + 4) = *param_1;
  local_8 = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 3),4000);
  local_8 = CONCAT31(local_8._1_3_,1);
  while( true ) {
    _Dst = (char *)FUN_00891268(0x800,uVar1);
    if (_Dst == (char *)0x0) {
      _Dst = (char *)0x0;
    }
    else {
      _memset(_Dst,0,0x800);
    }
    iVar2 = *param_1;
    local_14 = _Dst;
    iVar3 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_14);
    if (param_1[1] == 0x3ffffffe) break;
    param_1[1] = param_1[1] + 1;
    *(int *)(iVar2 + 4) = iVar3;
    uVar4 = uVar4 + 1;
    **(int **)(iVar3 + 4) = iVar3;
    if (999 < uVar4) {
      ExceptionList = local_10;
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

