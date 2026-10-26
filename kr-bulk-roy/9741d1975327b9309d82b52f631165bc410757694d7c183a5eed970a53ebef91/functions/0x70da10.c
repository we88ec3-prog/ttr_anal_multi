
int FUN_0070da10(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = *(int **)(param_1 + 0x30);
  iVar3 = *piVar2;
  iVar6 = *(int *)(iVar3 + 0x38);
  piVar1 = (int *)(iVar3 + 0x38);
  if (iVar6 < (short)piVar2[0xc] + 1) {
    uVar4 = FUN_00700790(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(iVar3 + 0x18),piVar1,0xc,
                         "too many local variables");
    *(undefined4 *)(iVar3 + 0x18) = uVar4;
  }
  if (iVar6 < *piVar1) {
    iVar5 = iVar6 * 0xc;
    do {
      *(undefined4 *)(iVar5 + *(int *)(iVar3 + 0x18)) = 0;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0xc;
    } while (iVar6 < *piVar1);
  }
  *(int *)(*(int *)(iVar3 + 0x18) + (short)piVar2[0xc] * 0xc) = param_2;
  if (((*(byte *)(param_2 + 5) & 3) != 0) && ((*(byte *)(iVar3 + 5) & 4) != 0)) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
    if (*(char *)(iVar6 + 0x15) == '\x01') {
      FUN_006f9f70(iVar6,param_2);
    }
    else {
      *(byte *)(iVar3 + 5) = *(byte *)(iVar6 + 0x14) & 3 | *(byte *)(iVar3 + 5) & 0xf8;
    }
  }
  iVar3 = piVar2[0xc];
  *(short *)(piVar2 + 0xc) = (short)iVar3 + 1;
  return (int)(short)iVar3;
}

