
void FUN_00770be0(int param_1)

{
  LPCWSTR pWVar1;
  WCHAR WVar2;
  int in_EAX;
  LPCWSTR pWVar3;
  undefined4 uVar4;
  LPCWSTR name;
  int local_10;
  undefined4 local_c [2];
  
  local_c[0] = 0xd;
  FUN_008438c0(local_c);
  if (local_10 == *(int *)(in_EAX + 0x20)) {
    name = (LPCWSTR)(param_1 + 0x40);
    pWVar3 = name;
    if (7 < *(uint *)(param_1 + 0x54)) {
      pWVar3 = *(LPCWSTR *)name;
    }
    pWVar1 = pWVar3 + 1;
    do {
      WVar2 = *pWVar3;
      pWVar3 = pWVar3 + 1;
    } while (WVar2 != L'\0');
    if ((int)pWVar3 - (int)pWVar1 >> 1 != 0) {
      if (7 < *(uint *)(param_1 + 0x54)) {
        name = *(LPCWSTR *)name;
      }
      AddFontResourceExW(name,0x10,(PVOID)0x0);
    }
    uVar4 = FUN_0057ef20();
    FUN_0057e850(in_EAX + 0x1c,uVar4);
  }
  return;
}

