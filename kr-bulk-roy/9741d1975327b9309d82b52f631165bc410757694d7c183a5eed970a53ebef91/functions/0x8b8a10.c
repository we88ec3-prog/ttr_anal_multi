
undefined4 FUN_008b8a10(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || ((*(byte *)(param_1 + 8) & 2) == 0)) {
    return 0x23;
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x1c))) {
    pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x5c);
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(*(undefined4 *)(param_1 + 0x58));
      return uVar2;
    }
    FUN_008b8760(param_1,param_2);
    return 0;
  }
  return 6;
}

