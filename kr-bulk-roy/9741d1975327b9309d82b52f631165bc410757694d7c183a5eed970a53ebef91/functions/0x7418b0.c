
bool FUN_007418b0(void)

{
  uint uVar1;
  uint uVar2;
  wchar_t *in_EAX;
  uint uVar3;
  wchar_t *in_ECX;
  
  uVar1 = *(uint *)(in_EAX + 8);
  if (7 < *(uint *)(in_EAX + 10)) {
    in_EAX = *(wchar_t **)in_EAX;
  }
  uVar2 = *(uint *)(in_ECX + 8);
  uVar3 = uVar2;
  if (uVar1 <= uVar2) {
    uVar3 = uVar1;
  }
  if (7 < *(uint *)(in_ECX + 10)) {
    in_ECX = *(wchar_t **)in_ECX;
  }
  uVar3 = __wcsnicmp(in_ECX,in_EAX,uVar3);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return true;
    }
    uVar3 = (uint)(uVar2 != uVar1);
  }
  return (int)uVar3 < 0;
}

