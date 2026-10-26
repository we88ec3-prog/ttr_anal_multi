
undefined4 FUN_0054b030(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char *_Str1;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 uVar6;
  
  iVar3 = FUN_0072e360();
  do {
    if (iVar3 == 0) {
      return 1;
    }
    for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
      _Str1 = (char *)(iVar1 + 0x14);
      if (0xf < *(uint *)(iVar1 + 0x28)) {
        _Str1 = *(char **)_Str1;
      }
      iVar4 = __stricmp(_Str1,"ID");
      if (iVar4 == 0) {
        if (iVar1 != 0) {
          puVar5 = (undefined4 *)(iVar1 + 0x30);
          if (0xf < *(uint *)(iVar1 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            uVar6 = FUN_008917b4(puVar5);
            goto LAB_0054b08a;
          }
        }
        break;
      }
    }
    uVar6 = 0xffffffff;
LAB_0054b08a:
    puVar5 = *(undefined4 **)(in_ECX + 8);
    param_1 = uVar6;
    if (&param_1 < puVar5) {
      puVar2 = *(undefined4 **)(in_ECX + 4);
      if (&param_1 < puVar2) goto LAB_0054b0eb;
      if (puVar5 == *(undefined4 **)(in_ECX + 0xc)) {
        FUN_006d6240();
      }
      if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 8) =
             *(undefined4 *)(*(int *)(in_ECX + 4) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
      }
    }
    else {
LAB_0054b0eb:
      if (puVar5 == *(undefined4 **)(in_ECX + 0xc)) {
        FUN_006d6240();
      }
      if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
        **(undefined4 **)(in_ECX + 8) = uVar6;
      }
    }
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 4;
    iVar3 = FUN_0072e3c0();
  } while( true );
}

