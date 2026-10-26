
void FUN_00720b00(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar4 = *(int *)(param_1 + 0x14);
  if ((((iVar4 == 0xb) || (iVar4 == 0xc)) || (iVar4 == 0xe)) || (iVar4 == 0xf)) {
    if (iVar4 != 0x14) goto LAB_00720b6e;
  }
  else if (iVar4 != 0x14) goto LAB_00720b25;
  pbVar3 = *(byte **)(param_1 + 4);
  bVar2 = (&DAT_00c0b650)[*pbVar3];
  while ((bVar2 & 8) != 0) {
    pbVar1 = pbVar3 + 1;
    pbVar3 = pbVar3 + 1;
    bVar2 = (&DAT_00c0b650)[*pbVar1];
  }
  if ((*pbVar3 == 0x28) && (iVar4 = FUN_00720100(), iVar4 == 0)) {
LAB_00720b6e:
    iVar5 = FUN_007203f0(param_1);
    iVar4 = *(int *)(param_1 + 0x14);
    if ((iVar4 == 0x10) || (iVar4 == 0x11)) {
      FUN_0071d0d0();
      if (iVar4 == 0x11) {
        if (*(char *)(iVar5 + 1) != '\x01') {
                    /* WARNING: Subroutine does not return */
          FUN_0071f620();
        }
        puVar6 = (undefined4 *)FUN_0071bdb0();
        if (puVar6 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0071f670();
        }
        *puVar6 = 0x2050138;
        puVar6[1] = iVar5;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
      }
      FUN_00720950(param_1);
    }
    return;
  }
LAB_00720b25:
  FUN_00720a00(param_1);
  return;
}

