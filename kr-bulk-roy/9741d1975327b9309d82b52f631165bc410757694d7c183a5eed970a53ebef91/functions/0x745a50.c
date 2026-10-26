
void FUN_00745a50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = _malloc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    *puVar1 = FoxUI::FXUIDockInfo::vftable;
    puVar1[2] = 6;
  }
  *(undefined4 **)(in_ECX + 0x1c) = puVar1;
  *(undefined4 *)(in_ECX + 8) = param_3;
  *(undefined4 *)(in_ECX + 0xc) = param_4;
  *(undefined4 *)(in_ECX + 0x10) = param_5;
  *(undefined4 *)(in_ECX + 0x28) = param_2;
  *(undefined4 *)(in_ECX + 0x14) = param_6;
  *(undefined4 *)(in_ECX + 0x48) = param_1;
  if (param_7 != 0) {
    FUN_00746a40(param_7,param_1,in_ECX);
  }
  FUN_00746f70();
  return;
}

