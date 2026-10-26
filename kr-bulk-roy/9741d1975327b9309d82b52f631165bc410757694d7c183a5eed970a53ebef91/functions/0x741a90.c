
undefined4 * FUN_00741a90(wchar_t *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_EAX;
  wchar_t *_Str1;
  uint uVar5;
  wchar_t *_Str2;
  undefined4 *puVar6;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*(undefined4 **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)local_8 + 0x39);
  puVar4 = *(undefined4 **)(in_EAX + 4);
  do {
    if (cVar1 != '\0') {
      return puVar4;
    }
    uVar2 = *(uint *)(param_1 + 8);
    _Str1 = (wchar_t *)(local_8 + 3);
    _Str2 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      _Str2 = *(wchar_t **)param_1;
    }
    uVar3 = local_8[7];
    uVar5 = uVar3;
    if (uVar2 <= uVar3) {
      uVar5 = uVar2;
    }
    if (7 < (uint)local_8[8]) {
      _Str1 = *(wchar_t **)_Str1;
    }
    uVar5 = __wcsnicmp(_Str1,_Str2,uVar5);
    if (uVar5 == 0) {
      if (uVar2 <= uVar3) {
        uVar5 = (uint)(uVar3 != uVar2);
        goto LAB_00741aee;
      }
LAB_00741af0:
      puVar6 = (undefined4 *)local_8[2];
      local_8 = puVar4;
    }
    else {
LAB_00741aee:
      if ((int)uVar5 < 0) goto LAB_00741af0;
      puVar6 = (undefined4 *)*local_8;
    }
    cVar1 = *(char *)((int)puVar6 + 0x39);
    puVar4 = local_8;
    local_8 = puVar6;
  } while( true );
}

