
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f2980(int param_1)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  int *piVar2;
  int unaff_ESI;
  uint uVar3;
  undefined2 local_18;
  int local_16;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092484e;
  local_10 = ExceptionList;
  uVar3 = 0;
  uVar1 = *(int *)(unaff_ESI + 0x5eb0) - *(int *)(unaff_ESI + 0x5eac) >> 2;
  if (uVar1 != 0) {
    piVar2 = *(int **)(unaff_ESI + 0x5eac);
    while (*(int *)(*piVar2 + 8) != param_1) {
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 1;
      if (uVar1 <= uVar3) {
        return;
      }
    }
    ExceptionList = &local_10;
    if (*(int *)(*(int *)(unaff_ESI + 0x5eac) + uVar3 * 4) != 0) {
      FUN_0089120c(*(undefined4 *)(*(int *)(unaff_ESI + 0x5eac) + uVar3 * 4),
                   DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      *(undefined4 *)(*(int *)(unaff_ESI + 0x5eac) + uVar3 * 4) = 0;
    }
    _Dst = (void *)(*(int *)(unaff_ESI + 0x5eac) + uVar3 * 4);
    _Src = (void *)((int)_Dst + 4);
    FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x5eb0) - (int)_Src >> 2) * 4);
    *(int *)(unaff_ESI + 0x5eb0) = *(int *)(unaff_ESI + 0x5eb0) + -4;
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_18 = 0xbcb;
    local_16 = param_1;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,&local_18,6);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058ab80(0xf424d,param_1);
  }
  ExceptionList = local_10;
  return;
}

