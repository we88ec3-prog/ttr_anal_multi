
uint FUN_0070db50(int *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar2 = *param_1;
  iVar6 = *(int *)(iVar2 + 0x24);
  uVar3 = 0;
  if (*(char *)(iVar2 + 0x48) != '\0') {
    pbVar5 = (byte *)(param_1 + 0xd);
    do {
      if (((uint)pbVar5[-1] == *param_3) && ((uint)*pbVar5 == param_3[2])) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
      pbVar5 = pbVar5 + 2;
    } while ((int)uVar3 < (int)(uint)*(byte *)(iVar2 + 0x48));
  }
  uVar3 = *(byte *)(iVar2 + 0x48) + 1;
  if (0x3c < uVar3) {
    uVar3 = FUN_0070d7c0();
  }
  if (iVar6 < (int)uVar3) {
    uVar4 = FUN_00700790(param_1[4],*(undefined4 *)(iVar2 + 0x1c),iVar2 + 0x24,4,&DAT_00bf2375);
    *(undefined4 *)(iVar2 + 0x1c) = uVar4;
  }
  if (iVar6 < *(int *)(iVar2 + 0x24)) {
    do {
      *(undefined4 *)(*(int *)(iVar2 + 0x1c) + iVar6 * 4) = 0;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar2 + 0x24));
  }
  *(int *)(*(int *)(iVar2 + 0x1c) + (uint)*(byte *)(iVar2 + 0x48) * 4) = param_2;
  if (((*(byte *)(param_2 + 5) & 3) != 0) && ((*(byte *)(iVar2 + 5) & 4) != 0)) {
    iVar6 = *(int *)(param_1[4] + 0x10);
    if (*(char *)(iVar6 + 0x15) == '\x01') {
      FUN_006f9f70(iVar6,param_2);
    }
    else {
      *(byte *)(iVar2 + 5) = *(byte *)(iVar6 + 0x14) & 3 | *(byte *)(iVar2 + 5) & 0xf8;
    }
  }
  *(char *)((int)param_1 + (uint)*(byte *)(iVar2 + 0x48) * 2 + 0x33) = (char)*param_3;
  *(char *)((int)param_1 + (uint)*(byte *)(iVar2 + 0x48) * 2 + 0x34) = (char)param_3[2];
  bVar1 = *(byte *)(iVar2 + 0x48);
  *(byte *)(iVar2 + 0x48) = bVar1 + 1;
  return (uint)bVar1;
}

