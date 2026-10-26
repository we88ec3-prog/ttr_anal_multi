
void FUN_00762030(int param_1)

{
  int iVar1;
  size_t _Size;
  int iVar2;
  HGLOBAL hMem;
  LPVOID _Dst;
  undefined4 *puVar3;
  BOOL BVar4;
  undefined4 local_8;
  
  iVar2 = *(int *)(param_1 + 0x160);
  iVar1 = *(int *)(param_1 + 0x164);
  local_8 = iVar2;
  if ((iVar2 < iVar1) || (local_8 = iVar1, iVar2 <= iVar1)) {
    iVar2 = iVar1;
  }
  if (iVar2 - local_8 < 1) {
    BVar4 = OpenClipboard(*(HWND *)(*(int *)(param_1 + 0x24) + 4));
    if (BVar4 != 0) {
      EmptyClipboard();
      CloseClipboard();
      return;
    }
  }
  else {
    _Size = (iVar2 - local_8) * 2;
    hMem = GlobalAlloc(0x42,_Size + 2);
    _Dst = GlobalLock(hMem);
    puVar3 = (undefined4 *)(param_1 + 0x108);
    if (7 < *(uint *)(param_1 + 0x11c)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FID_conflict__memcpy(_Dst,(void *)((int)puVar3 + local_8 * 2),_Size);
    *(undefined2 *)(_Size + (int)_Dst) = 0;
    GlobalUnlock(hMem);
    BVar4 = OpenClipboard(*(HWND *)(*(int *)(param_1 + 0x24) + 4));
    if (BVar4 != 0) {
      EmptyClipboard();
      SetClipboardData(0xd,hMem);
      CloseClipboard();
    }
  }
  return;
}

