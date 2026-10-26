
/* WARNING: Removing unreachable block (ram,0x006cf192) */

undefined4 * FUN_006cf160(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_EAX;
  char *_Str1;
  uint uVar5;
  char *_Str2;
  undefined4 *puVar6;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)(*(undefined4 **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)local_8 + 0x2d);
  puVar4 = *(undefined4 **)(in_EAX + 4);
  do {
    if (cVar1 != '\0') {
      return puVar4;
    }
    uVar2 = *(uint *)(param_1 + 0x10);
    _Str1 = (char *)(local_8 + 3);
    _Str2 = param_1;
    if (0xf < *(uint *)(param_1 + 0x14)) {
      _Str2 = *(char **)param_1;
    }
    uVar3 = local_8[7];
    uVar5 = uVar3;
    if (uVar2 <= uVar3) {
      uVar5 = uVar2;
    }
    if (0xf < (uint)local_8[8]) {
      _Str1 = *(char **)_Str1;
    }
    uVar5 = __strnicmp(_Str1,_Str2,uVar5);
    if (uVar5 == 0) {
      if (uVar2 <= uVar3) {
        uVar5 = (uint)(uVar3 != uVar2);
        goto LAB_006cf1bf;
      }
LAB_006cf1c1:
      puVar6 = (undefined4 *)local_8[2];
      local_8 = puVar4;
    }
    else {
LAB_006cf1bf:
      if ((int)uVar5 < 0) goto LAB_006cf1c1;
      puVar6 = (undefined4 *)*local_8;
    }
    cVar1 = *(char *)((int)puVar6 + 0x2d);
    puVar4 = local_8;
    local_8 = puVar6;
  } while( true );
}

