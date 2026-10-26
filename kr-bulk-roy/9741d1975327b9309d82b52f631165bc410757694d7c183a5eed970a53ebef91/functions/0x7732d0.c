
undefined4 * FUN_007732d0(int param_1,uint param_2)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      return (undefined4 *)0x0;
    }
    iVar3 = param_1 + 0x6c;
  }
  else {
    iVar3 = param_1 + 0x5c;
  }
  if ((iVar3 != 0) && (FUN_008438c0(&param_2), local_8 == *(int *)(iVar3 + 4))) {
    puVar1 = _malloc(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      DAT_00fba828 = DAT_00fba828 + 1;
      *(byte *)(puVar1 + 5) = (byte)(param_2 >> 1) & 1;
      puVar1[1] = DAT_00fba828;
      *puVar1 = FoxUI::FXUIFontItem::vftable;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = in_EAX;
    }
    puVar1[2] = param_1;
    uVar2 = FUN_0057ef20();
    FUN_0057e850(iVar3,uVar2);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

