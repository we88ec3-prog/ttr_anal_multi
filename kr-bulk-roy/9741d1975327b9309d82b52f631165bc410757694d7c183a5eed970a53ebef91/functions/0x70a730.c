
undefined4 FUN_0070a730(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  pcVar3 = (char *)FUN_006f6210(param_1);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  *(undefined4 *)(param_1 + 0x60) = 5;
  local_18[0] = FUN_006fec70(param_1,"preload",7);
  local_10 = 4;
  FUN_006fb850(param_1,(undefined4 *)(param_1 + 0x58),local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if ((*(undefined **)(param_1 + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(param_1 + 8) + -8) != 5)) {
    FUN_006f5f30(param_1,"\'package.preload\' must be a table");
  }
  iVar2 = *(int *)(param_1 + 8);
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_18[0] = FUN_006fec70(param_1,pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
  local_10 = 4;
  FUN_006fb850(param_1,iVar2 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if ((*(undefined **)(param_1 + 8) != &DAT_00c0bfd8) &&
     (*(int *)(*(undefined **)(param_1 + 8) + -8) == 0)) {
    FUN_006f5580(param_1,"\n\tno field package.preload[\'%s\']",pcVar3);
  }
  return 1;
}

