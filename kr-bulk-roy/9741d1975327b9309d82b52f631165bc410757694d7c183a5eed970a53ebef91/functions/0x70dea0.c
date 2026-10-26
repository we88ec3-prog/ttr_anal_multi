
void FUN_0070dea0(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  piVar1 = *(int **)(param_1 + 0x30);
  iVar3 = *piVar1;
  iVar4 = *(int *)(iVar3 + 0x34);
  if (iVar4 < piVar1[0xb] + 1) {
    uVar2 = FUN_00700790(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(iVar3 + 0x10),
                         (int *)(iVar3 + 0x34),4,"constant table overflow");
    *(undefined4 *)(iVar3 + 0x10) = uVar2;
  }
  if (iVar4 < *(int *)(iVar3 + 0x34)) {
    do {
      *(undefined4 *)(*(int *)(iVar3 + 0x10) + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iVar3 + 0x34));
  }
  *(int *)(*(int *)(iVar3 + 0x10) + piVar1[0xb] * 4) = *param_2;
  piVar1[0xb] = piVar1[0xb] + 1;
  if (((*(byte *)(*param_2 + 5) & 3) != 0) && ((*(byte *)(iVar3 + 5) & 4) != 0)) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
    if (*(char *)(iVar4 + 0x15) == '\x01') {
      FUN_006f9f70(iVar4,*param_2);
    }
    else {
      *(byte *)(iVar3 + 5) = *(byte *)(iVar4 + 0x14) & 3 | *(byte *)(iVar3 + 5) & 0xf8;
    }
  }
  uVar2 = FUN_00713370((piVar1[0xb] + -1) * 0x4000 | 0x24,*(undefined4 *)(piVar1[3] + 8));
  param_3[4] = 0xffffffff;
  param_3[5] = 0xffffffff;
  *param_3 = 0xb;
  param_3[2] = uVar2;
  iVar3 = 0;
  if (*(char *)(*param_2 + 0x48) != '\0') {
    pcVar5 = (char *)((int)param_2 + 0x33);
    do {
      FUN_00713370((uint)(byte)pcVar5[1] << 0x17 | (*pcVar5 == '\x06') - 1 & 4,
                   *(undefined4 *)(piVar1[3] + 8));
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 2;
    } while (iVar3 < (int)(uint)*(byte *)(*param_2 + 0x48));
  }
  return;
}

