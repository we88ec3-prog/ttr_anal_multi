
void FUN_0073bed0(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)

{
  WCHAR WVar1;
  longlong lVar2;
  int iVar3;
  void *_Dst;
  LPCWSTR ***ppppWVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  LPCWSTR ***lpszString;
  tagSIZE local_4c;
  HDC local_44;
  HGDIOBJ local_40;
  int local_3c;
  int *local_38;
  int local_34;
  LPCWSTR **local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919548;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_5;
  if (param_2 != 0) {
    FUN_0073ce20(local_14);
    local_8 = 0;
    lpszString = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      lpszString = local_30;
    }
    FUN_0073bd60(param_1);
    ppppWVar4 = lpszString;
    do {
      WVar1 = *(WCHAR *)ppppWVar4;
      ppppWVar4 = (LPCWSTR ***)((int)ppppWVar4 + 2);
    } while (WVar1 != L'\0');
    iVar3 = (int)ppppWVar4 - (int)((int)lpszString + 2) >> 1;
    lVar2 = (ulonglong)(iVar3 + 1) * 4;
    _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    _memset(_Dst,0,iVar3 * 4 + 4);
    ppppWVar4 = lpszString;
    do {
      WVar1 = *(WCHAR *)ppppWVar4;
      ppppWVar4 = (LPCWSTR ***)((int)ppppWVar4 + 2);
    } while (WVar1 != L'\0');
    GetTextExtentExPointW
              (local_44,(LPCWSTR)lpszString,(int)ppppWVar4 - (int)((int)lpszString + 2) >> 1,param_3
               ,&local_3c,(LPINT)((int)_Dst + 4),&local_4c);
    iVar3 = 1;
    if (1 < local_3c) {
      do {
        if (param_4 <= *(int *)((int)_Dst + iVar3 * 4)) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_3c);
    }
    uVar5 = *(int *)((int)_Dst + iVar3 * 4) - param_4;
    uVar8 = (int)uVar5 >> 0x1f;
    uVar6 = *(int *)((int)_Dst + (iVar3 + -1) * 4) - param_4;
    uVar9 = (int)uVar6 >> 0x1f;
    iVar7 = iVar3 + -1;
    if ((int)((uVar5 ^ uVar8) - uVar8) <= (int)((uVar6 ^ uVar9) - uVar9)) {
      iVar7 = iVar3;
    }
    *local_38 = iVar7;
    FUN_00891d3d(_Dst);
    SelectObject(*(HDC *)(local_34 + 0xc),local_40);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

