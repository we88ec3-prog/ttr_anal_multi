
undefined4 FUN_0077d6f0(int param_1,int param_2)

{
  int iVar1;
  LPCWSTR pWVar2;
  WCHAR WVar3;
  int iVar4;
  undefined4 in_EAX;
  LPCWSTR pWVar5;
  undefined4 uVar6;
  LPCWSTR name;
  int local_8;
  
  iVar4 = param_1;
  iVar1 = param_1 + 0xc;
  param_1 = in_EAX;
  FUN_008438c0(&param_1);
  if (local_8 != *(int *)(iVar4 + 0x10)) {
    return 0;
  }
  name = (LPCWSTR)(param_2 + 0x40);
  pWVar5 = name;
  if (7 < *(uint *)(param_2 + 0x54)) {
    pWVar5 = *(LPCWSTR *)name;
  }
  pWVar2 = pWVar5 + 1;
  do {
    WVar3 = *pWVar5;
    pWVar5 = pWVar5 + 1;
  } while (WVar3 != L'\0');
  if ((int)pWVar5 - (int)pWVar2 >> 1 != 0) {
    if (7 < *(uint *)(param_2 + 0x54)) {
      name = *(LPCWSTR *)name;
    }
    AddFontResourceExW(name,0x10,(PVOID)0x0);
  }
  if (*(int *)(iVar4 + 0x14) != 0) {
    param_1 = *(undefined4 *)(iVar4 + 0x10);
    FUN_0053f8a0();
  }
  uVar6 = FUN_0057ef20();
  FUN_0057e850(iVar1,uVar6);
  return 1;
}

