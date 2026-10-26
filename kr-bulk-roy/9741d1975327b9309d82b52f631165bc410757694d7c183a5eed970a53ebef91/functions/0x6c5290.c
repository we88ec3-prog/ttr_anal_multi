
void FUN_006c5290(void)

{
  short sVar1;
  short *psVar2;
  HGLOBAL hMem;
  LPVOID _Dst;
  undefined4 *_Src;
  BOOL BVar3;
  int in_ECX;
  short *psVar4;
  undefined4 local_30;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00928b24;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(local_14);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  psVar2 = (short *)FUN_004f6a30(*(undefined4 *)(in_ECX + 0xb4));
  local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  psVar4 = psVar2;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar2,(int)psVar4 - (int)(psVar2 + 1) >> 1);
  local_8 = 1;
  hMem = GlobalAlloc(0x42,local_20 * 2 + 2);
  _Dst = GlobalLock(hMem);
  _Src = local_30;
  if (local_1c < 8) {
    _Src = &local_30;
  }
  FID_conflict__memcpy(_Dst,_Src,local_20 * 2);
  *(undefined2 *)((int)_Dst + local_20 * 2) = 0;
  GlobalUnlock(hMem);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  BVar3 = OpenClipboard(DAT_00f94814);
  if (BVar3 != 0) {
    EmptyClipboard();
    SetClipboardData(0xd,hMem);
    CloseClipboard();
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

