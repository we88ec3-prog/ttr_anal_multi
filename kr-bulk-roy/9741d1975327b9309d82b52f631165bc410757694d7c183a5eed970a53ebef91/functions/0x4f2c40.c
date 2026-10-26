
void FUN_004f2c40(int param_1)

{
  void *_Src;
  void *_Dst;
  int iVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  uint uVar4;
  undefined4 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092481c;
  local_10 = ExceptionList;
  iVar1 = *(int *)(unaff_ESI + 0x5ecc);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 8) != param_1)) {
    uVar2 = *(int *)(unaff_ESI + 0x5ed4) - *(int *)(unaff_ESI + 0x5ed0) >> 2;
    if (uVar2 == 0) {
      return;
    }
    piVar3 = *(int **)(unaff_ESI + 0x5ed0);
    uVar4 = 0;
    while (*(int *)(*piVar3 + 8) != param_1) {
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
      if (uVar2 <= uVar4) {
        return;
      }
    }
    ExceptionList = &local_10;
    if (*(int *)(*(int *)(unaff_ESI + 0x5ed0) + uVar4 * 4) != 0) {
      FUN_0089120c(*(undefined4 *)(*(int *)(unaff_ESI + 0x5ed0) + uVar4 * 4),
                   DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      *(undefined4 *)(*(int *)(unaff_ESI + 0x5ed0) + uVar4 * 4) = 0;
    }
    _Dst = (void *)(*(int *)(unaff_ESI + 0x5ed0) + uVar4 * 4);
    _Src = (void *)((int)_Dst + 4);
    FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x5ed4) - (int)_Src >> 2) * 4);
    *(int *)(unaff_ESI + 0x5ed4) = *(int *)(unaff_ESI + 0x5ed4) + -4;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    uVar5 = 0xf4255;
  }
  else {
    ExceptionList = &local_10;
    FUN_0089120c(iVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)(unaff_ESI + 0x5ecc) = 0;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    uVar5 = 0xf4254;
  }
  FUN_0058ab80(uVar5,param_1);
  ExceptionList = local_10;
  return;
}

