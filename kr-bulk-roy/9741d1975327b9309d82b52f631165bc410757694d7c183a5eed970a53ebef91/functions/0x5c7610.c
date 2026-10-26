
undefined4 * FUN_005c7610(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  wchar_t *_Str1;
  int iVar3;
  wchar_t *_Str2;
  undefined4 *puVar4;
  undefined4 *puVar5;
  wchar_t *unaff_EDI;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x2d);
  puVar2 = *(undefined4 **)(in_EAX + 4);
  while (cVar1 == '\0') {
    _Str1 = (wchar_t *)(puVar4 + 3);
    _Str2 = unaff_EDI;
    if (7 < *(uint *)(unaff_EDI + 10)) {
      _Str2 = *(wchar_t **)unaff_EDI;
    }
    if (7 < (uint)puVar4[8]) {
      _Str1 = *(wchar_t **)_Str1;
    }
    iVar3 = __wcsicmp(_Str1,_Str2);
    if (iVar3 < 1) {
      puVar5 = (undefined4 *)*puVar4;
    }
    else {
      puVar5 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x2d);
  }
  return puVar2;
}

