
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494cd0(uint param_1)

{
  short sVar1;
  code *pcVar2;
  char cVar3;
  short *psVar4;
  undefined4 *puVar5;
  FILE *pFVar6;
  FILE *_File;
  int _FileHandle;
  size_t _Count;
  char *pcVar7;
  LPCWSTR lpCaption;
  HWND pHVar8;
  uint uType;
  undefined1 *unaff_EBX;
  uint unaff_ESI;
  LPCWSTR lpText;
  LPCWSTR unaff_EDI;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int iStack_2f4;
  wchar_t *pwStack_2f0;
  short *psStack_2ec;
  int iVar9;
  uint uStack_2e4;
  int local_2d4 [2];
  uint local_2cc;
  uint local_2c4;
  undefined2 local_2c0;
  undefined4 uStack_2bc;
  undefined4 local_2b0;
  undefined4 local_2ac;
  uint uStack_2a8;
  undefined1 auStack_2a0 [612];
  uint uStack_3c;
  void *pvStack_34;
  undefined1 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091b757;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_2d4;
  uStack_2e4 = DAT_00d61f20 ^ (uint)&stack0xfffffd20;
  ExceptionList = &local_14;
  local_2c4 = param_1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 0;
    psStack_2ec = (short *)0x494d40;
    FUN_00584c40();
    psStack_2ec = (short *)0x494d4a;
    _atexit(FUN_00bcf370);
  }
  local_c = 0xffffffff;
  local_2cc = 0x186;
  psStack_2ec = (short *)0x494d73;
  FUN_005740f0();
  if (local_2d4[0] == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psStack_2ec = (short *)(local_2d4[0] + 0x10);
  if (7 < *(uint *)(local_2d4[0] + 0x24)) {
    psStack_2ec = *(short **)psStack_2ec;
  }
  local_2ac = 7;
  local_2b0 = 0;
  local_2c0 = 0;
  psVar4 = psStack_2ec;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  pwStack_2f0 = (wchar_t *)0x494dca;
  FUN_00402160();
  local_c = 1;
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0xfff9:
    break;
  case 0xfffa:
    goto LAB_00494df8;
  case 0xfffb:
    break;
  case 0xfffc:
    goto LAB_00494df8;
  case 0xfffd:
    psStack_2ec = (short *)0x186;
    pwStack_2f0 = L"\xf08bშ༅倀恨쁙贀⒔Ð";
    FUN_005854b0();
    pwStack_2f0 = L"桐奠À钍퀤";
    psStack_2ec = (short *)FUN_00585330();
    pwStack_2f0 = L"%s (0x%08x))";
    iStack_2f4 = 0x494e32;
    FUN_0040aeb0();
    goto LAB_00494e70;
  case 0xfffe:
LAB_00494df8:
    psStack_2ec = (short *)0x494dfd;
    FUN_005854b0();
    psStack_2ec = (short *)0x494e04;
    FUN_00585330();
    goto LAB_00494e70;
  case 0xffff:
    break;
  default:
    goto switchD_00494de5_default;
  }
  psStack_2ec = (short *)0x494e62;
  FUN_005854b0();
  psStack_2ec = (short *)0x494e69;
  FUN_00585330();
LAB_00494e70:
  psStack_2ec = (short *)0x494e75;
  FUN_0041f490();
switchD_00494de5_default:
  iVar9 = 1;
  psStack_2ec = (short *)0x0;
  pwStack_2f0 = 
  L"උꡔûƋ傋樠樁！诒名ﮨ謀謁⁐Ūɪ틿粃㠤謈⑄猤贄⑄値粍䐤翨ﺦ뻿\x10";
  (**(code **)(*DAT_00fba854 + 0x20))();
  pwStack_2f0 = (wchar_t *)0x1;
  iStack_2f4 = 1;
  (**(code **)(*DAT_00fba854 + 0x20))();
  (**(code **)(*DAT_00fba854 + 0x20))(2,1);
  if (local_2c4 < 8) {
    unaff_EBX = &stack0xfffffd28;
  }
  puVar5 = (undefined4 *)FUN_0047f540(unaff_EBX);
  if (0xf < (uint)puVar5[5]) {
    puVar5 = (undefined4 *)*puVar5;
  }
  FUN_006edd00("Disconnected: %s",puVar5);
  if (0xf < uStack_2a8) {
    FUN_0089120c(uStack_2bc);
  }
  if (*(short *)(param_1 + 2) != -3) goto LAB_004950ca;
  _fflush(DAT_00fba804);
  _fclose(DAT_00fba804);
  pFVar6 = _fopen("Tartaros.log","ab");
  _File = _fopen("Log.txt","rb");
  if (pFVar6 == (FILE *)0x0) {
    pFVar6 = _File;
    if (_File != (FILE *)0x0) goto LAB_0049504a;
  }
  else if (_File == (FILE *)0x0) {
LAB_0049504a:
    _fclose(pFVar6);
  }
  else {
    _FileHandle = __fileno(_File);
    _Count = __filelength(_FileHandle);
    psStack_2ec = (short *)FUN_0087dc3d(_Count);
    _fread(psStack_2ec,1,_Count,_File);
    _fclose(_File);
    _fprintf(pFVar6,"\r\n\r\n****** Exception Log Start ******\r\n\r\n");
    _fprintf(pFVar6,"TDMP Error 0x%08x\r\n",*(undefined4 *)(unaff_ESI + 4));
    GetSystemTimeAsFileTime((LPFILETIME)&uStack_2e4);
    FUN_00494c40(auStack_2a0,uStack_2e4,unaff_EDI);
    _fprintf(pFVar6,"Error occurred at %s.\r\n",auStack_2a0);
    _fprintf(pFVar6,"User ID: ");
    pcVar7 = &DAT_00fba700;
    if (DAT_00fba700 == '\0') {
      pcVar7 = "<unknown>";
    }
    _fprintf(pFVar6,"%s\r\n",pcVar7);
    _fprintf(pFVar6,"\r\n\r\n****** Game Log Start ******\r\n\r\n");
    psVar4 = psStack_2ec;
    _fwrite(psStack_2ec,1,_Count,pFVar6);
    _fclose(pFVar6);
    DeleteFileA("Log.txt");
    FUN_00891d3d(psVar4);
    param_1 = unaff_ESI;
  }
  pFVar6 = _fopen("Tartaros.dmp","wb");
  if (pFVar6 != (FILE *)0x0) {
    psStack_2ec = (short *)0x54444d50;
    uStack_2e4 = 6;
    _fwrite(&psStack_2ec,4,1,pFVar6);
    _fwrite(&uStack_2e4,4,1,pFVar6);
    _fwrite((void *)(param_1 + 2),2,1,pFVar6);
    _fwrite((void *)(param_1 + 4),4,1,pFVar6);
    _fclose(pFVar6);
    DAT_00fba79c = 1;
  }
LAB_004950ca:
  if ((*(int *)(iVar9 + 0x3c) == 0) && (cVar3 = FUN_006ea3d0(), cVar3 == '\0')) {
    FUN_006e71f0(1,1);
    FUN_006e2e20();
    FUN_006e71f0(0,0);
    _DAT_00fba7c8 = 1;
  }
  (**(code **)(**(int **)(iVar9 + 0x18) + 0x50))(*(int **)(iVar9 + 0x18),1);
  iVar9 = FUN_00466df0(&stack0xfffffd20,&DAT_00c059b8,2);
  while (iVar9 != -1) {
    FUN_00498090(iVar9,2,&DAT_00c059c0,2);
    iVar9 = FUN_00466df0(&stack0xfffffd20,&DAT_00c059b8,2);
  }
  cVar3 = FUN_006ea3d0();
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    uStack_2c = 2;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    uStack_2c = 1;
  }
  pwStack_2f0 = (wchar_t *)0x199;
  FUN_005740f0(&pwStack_2f0);
  if (iStack_2f4 != DAT_00fe5b10) {
    lpCaption = (LPCWSTR)(iStack_2f4 + 0x10);
    if (7 < *(uint *)(iStack_2f4 + 0x24)) {
      lpCaption = *(LPCWSTR *)lpCaption;
    }
    lpText = unaff_EDI;
    if (local_2cc < 8) {
      lpText = (LPCWSTR)&stack0xfffffd20;
    }
    uType = (cVar3 != '\0') - 1 & 0x40000;
    pHVar8 = (HWND)FUN_006dfd60();
    MessageBoxW(pHVar8,lpText,lpCaption,uType);
    lParam = 1;
    wParam = 0;
    Msg = 0x10;
    pHVar8 = (HWND)FUN_006dfd60();
    PostMessageW(pHVar8,Msg,wParam,lParam);
    if (7 < local_2cc) {
      FUN_0089120c(unaff_EDI);
    }
    ExceptionList = pvStack_34;
    __security_check_cookie(uStack_3c ^ (uint)&iStack_2f4);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

