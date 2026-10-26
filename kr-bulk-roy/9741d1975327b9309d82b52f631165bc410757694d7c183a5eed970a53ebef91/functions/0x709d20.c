
undefined4 FUN_00709d20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar1[2])) {
    pcVar3 = (char *)FUN_006f6210(param_1);
  }
  else {
    pcVar3 = (char *)0x0;
  }
  iVar2 = FUN_006f5fa0(param_1,2);
  pcVar3 = _setlocale(*(int *)(&DAT_00c0b9d0 + iVar2 * 4),pcVar3);
  FUN_006f5510(pcVar3);
  return 1;
}

