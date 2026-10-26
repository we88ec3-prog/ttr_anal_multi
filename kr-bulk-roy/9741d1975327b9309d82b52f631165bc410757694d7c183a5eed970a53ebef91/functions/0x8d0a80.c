
void FUN_008d0a80(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(char *)(param_1 + 0x44) != '\0') {
    sVar2 = *(short *)(iVar3 + 2);
    iVar4 = *(int *)(iVar3 + 8);
    piVar1 = (int *)(*(int *)(iVar3 + 4) + sVar2 * 8);
    iVar5 = FUN_008b7c80(param_2);
    *piVar1 = iVar5 >> 0x10;
    iVar5 = FUN_008b7c80(param_3);
    piVar1[1] = iVar5 >> 0x10;
    *(char *)(iVar4 + sVar2) = (param_4 == '\0') + '\x01';
  }
  *(short *)(iVar3 + 2) = *(short *)(iVar3 + 2) + 1;
  return;
}

