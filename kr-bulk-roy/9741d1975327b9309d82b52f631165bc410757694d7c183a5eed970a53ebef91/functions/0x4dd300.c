
void FUN_004dd300(int param_1)

{
  bool bVar1;
  uint uVar2;
  int *_Src;
  int unaff_ESI;
  int *_Dst;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(int **)(unaff_ESI + 0x10);
  bVar1 = false;
  if (_Dst != *(int **)(unaff_ESI + 0x14)) {
    _Src = _Dst + 1;
    do {
      if (*(int *)(*_Dst + 0x1c) < param_1) {
        *(undefined4 *)(*_Dst + 0x24) = 1;
        bVar1 = true;
        FID_conflict__memcpy(_Dst,_Src,(*(int *)(unaff_ESI + 0x14) - (int)_Src >> 2) * 4);
        *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x14) + -4;
      }
      else {
        _Dst = _Dst + 1;
        _Src = _Src + 1;
      }
    } while (_Dst != *(int **)(unaff_ESI + 0x14));
    if (bVar1) {
      param_1 = CONCAT22(0xb5,(undefined2)param_1);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2,uVar2);
      }
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      FUN_0058aad0(0xf4365);
    }
  }
  ExceptionList = local_10;
  return;
}

