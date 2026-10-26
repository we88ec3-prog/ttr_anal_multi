
int FUN_008c9220(int param_1,undefined1 *param_2,undefined1 *param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  undefined1 uVar10;
  int iVar11;
  uint uVar12;
  undefined1 *puVar13;
  
  iVar11 = *(int *)(param_1 + 0xc);
  cVar4 = *(char *)(iVar11 + 4);
  cVar5 = *(char *)(iVar11 + 6);
  bVar6 = *(byte *)(iVar11 + 8);
  cVar7 = *(char *)(iVar11 + 10);
  cVar8 = *(char *)(iVar11 + 0xc);
  bVar9 = *(byte *)(iVar11 + 0xe);
  puVar13 = param_2 + 2;
  iVar11 = 0;
  if ((param_3 < puVar13) ||
     (uVar12 = (uint)CONCAT11(*param_2,param_2[1]), param_3 < puVar13 + uVar12 * 4)) {
    return 3;
  }
  param_2 = (undefined1 *)0x0;
  if (uVar12 != 0) {
    do {
      uVar10 = *puVar13;
      puVar1 = puVar13 + 1;
      pbVar2 = puVar13 + 3;
      pbVar3 = puVar13 + 2;
      puVar13 = puVar13 + 4;
      iVar11 = FUN_008c9500(param_1,CONCAT11(uVar10,*puVar1),(uint)*pbVar3 + param_4,
                            (uint)*pbVar2 + param_5);
      if (iVar11 != 0) break;
      param_2 = (undefined1 *)((int)param_2 + 1);
    } while (param_2 < uVar12);
  }
  *(short *)(*(int *)(param_1 + 0xc) + 4) = (short)cVar4;
  *(short *)(*(int *)(param_1 + 0xc) + 6) = (short)cVar5;
  *(ushort *)(*(int *)(param_1 + 0xc) + 8) = (ushort)bVar6;
  *(short *)(*(int *)(param_1 + 0xc) + 10) = (short)cVar7;
  *(short *)(*(int *)(param_1 + 0xc) + 0xc) = (short)cVar8;
  *(ushort *)(*(int *)(param_1 + 0xc) + 0xe) = (ushort)bVar9;
  *(ushort *)(*(int *)(param_1 + 0xc) + 2) = (ushort)*(byte *)(*(int *)(param_1 + 8) + 4);
  **(ushort **)(param_1 + 0xc) = (ushort)**(byte **)(param_1 + 8);
  return iVar11;
}

