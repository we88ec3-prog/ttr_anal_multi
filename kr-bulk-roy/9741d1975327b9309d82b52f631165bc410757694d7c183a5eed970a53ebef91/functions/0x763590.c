
undefined4 * FUN_00763590(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  if (param_1 == 0xea62) {
    pvVar2 = _malloc(0x38);
    if (pvVar2 != (void *)0x0) {
      puVar1 = (undefined4 *)FUN_0077c340();
      return puVar1;
    }
  }
  else if ((param_1 == 0xea63) && (puVar1 = _malloc(0x48), puVar1 != (undefined4 *)0x0)) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    puVar1[7] = 0;
    puVar1[8] = 7;
    *(undefined2 *)(puVar1 + 3) = 0;
    puVar1[0xd] = 0;
    puVar1[0xc] = 0;
    puVar1[0xb] = 0;
    puVar1[10] = 0;
    puVar1[0x11] = 0x3f800000;
    puVar1[2] = 0;
    *puVar1 = FoxUI::FXUIImageSetItemAnimate::vftable;
    puVar1[0x10] = 1;
    puVar1[0xf] = 1;
    puVar1[0xe] = 1;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

