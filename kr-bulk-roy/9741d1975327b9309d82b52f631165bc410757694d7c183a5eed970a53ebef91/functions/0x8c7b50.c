
int FUN_008c7b50(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)param_2[0x85];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),&DAT_00bd7d94);
    if (puVar1 == (undefined4 *)0x0) {
      return 0xb;
    }
    param_2[0x85] = puVar1;
    param_2[0x7f] = *puVar1;
  }
  uVar2 = FUN_008b8ff0(param_2[0x18],"postscript-cmaps");
  param_2[0x86] = uVar2;
  iVar3 = FUN_008c7960();
  if (iVar3 == 0) {
    uVar2 = param_2[0x1a];
    if (param_3 < 0) {
      param_3 = 0;
    }
    if ((int)param_2[0x23] <= param_3) {
      return 6;
    }
    iVar3 = FUN_008b97e0(uVar2,*(undefined4 *)(param_2[0x24] + param_3 * 4));
    if ((iVar3 == 0) && (iVar3 = (*(code *)puVar1[0x16])(param_2,uVar2), iVar3 == 0)) {
      *param_2 = param_2[0x23];
      param_2[1] = param_3;
    }
  }
  return iVar3;
}

