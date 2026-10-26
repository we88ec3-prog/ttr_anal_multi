
undefined4 FUN_00495b90(int param_1)

{
  code *pcVar1;
  char cVar2;
  HWND hWnd;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int local_8;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 2) == 200) {
    cVar2 = FUN_006ea3d0();
    if (cVar2 == '\0') {
      lParam = 0x20000000;
      wParam = 0xd;
      Msg = 0x104;
      hWnd = (HWND)FUN_006dfd60();
      PostMessageW(hWnd,Msg,wParam,lParam);
    }
    ShellExecuteA((HWND)0x0,"open","iexplore",(LPCSTR)(iVar3 + 6),(LPCSTR)0x0,5);
    return 1;
  }
  if (*(int *)(param_1 + 2) == 0x194) {
    param_1 = 0x106;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (local_8 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    puVar4 = (undefined4 *)(local_8 + 0x10);
    if (7 < *(uint *)(local_8 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_00404b10(0xca,puVar4,&DAT_00bed1fc,0,0);
  }
  return 1;
}

