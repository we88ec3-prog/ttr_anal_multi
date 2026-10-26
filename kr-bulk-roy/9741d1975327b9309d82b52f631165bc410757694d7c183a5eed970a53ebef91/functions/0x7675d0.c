
void FUN_007675d0(void)

{
  size_t _Size;
  HGLOBAL hMem;
  LPVOID _Dst;
  BOOL BVar1;
  int in_ECX;
  undefined1 auStack_5c [4];
  int local_58;
  undefined4 **local_54 [4];
  int local_44;
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091579a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  local_58 = in_ECX;
  FUN_00757200(local_54);
  local_c = 0;
  FUN_00767950(in_ECX,local_54);
  if (local_44 < 1) {
    BVar1 = OpenClipboard(*(HWND *)(*(int *)(in_ECX + 0x24) + 4));
    if (BVar1 == 0) goto LAB_007676b6;
    EmptyClipboard();
  }
  else {
    _Size = local_44 * 2;
    hMem = GlobalAlloc(0x42,_Size + 2);
    _Dst = GlobalLock(hMem);
    if (local_40 < 8) {
      local_54[0] = local_54;
    }
    FID_conflict__memcpy(_Dst,local_54[0],_Size);
    *(undefined2 *)(_Size + (int)_Dst) = 0;
    GlobalUnlock(hMem);
    BVar1 = OpenClipboard(*(HWND *)(*(int *)(local_58 + 0x24) + 4));
    if (BVar1 == 0) goto LAB_007676b6;
    EmptyClipboard();
    SetClipboardData(0xd,hMem);
  }
  CloseClipboard();
LAB_007676b6:
  local_c = 0xffffffff;
  FUN_00757640(local_54);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

