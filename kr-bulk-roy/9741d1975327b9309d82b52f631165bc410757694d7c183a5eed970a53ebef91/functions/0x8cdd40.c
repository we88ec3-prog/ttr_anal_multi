
int FUN_008cdd40(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  int local_8;
  
  puVar3 = (undefined4 *)FUN_008baee0(param_1,0x9c0,&local_8);
  if (local_8 != 0) {
    *param_3 = (int)puVar3;
    return local_8;
  }
  *puVar3 = param_1;
  puVar5 = puVar3 + 0x35;
  *puVar5 = (uint)*(ushort *)(param_2 + 0x78);
  psVar7 = (short *)(param_2 + 0x80);
  for (uVar8 = (uint)*(byte *)(param_2 + 0x7c); uVar8 != 0; uVar8 = uVar8 - 1) {
    puVar5 = puVar5 + 3;
    *puVar5 = (int)*psVar7;
    psVar7 = psVar7 + 1;
  }
  puVar3[0x34] = *(byte *)(param_2 + 0x7c) + 1;
  puVar5 = puVar3 + 2;
  *puVar5 = (uint)*(ushort *)(param_2 + 0x7a);
  psVar7 = (short *)(param_2 + 0x9a);
  for (uVar8 = (uint)*(byte *)(param_2 + 0x7d); uVar8 != 0; uVar8 = uVar8 - 1) {
    puVar5 = puVar5 + 3;
    *puVar5 = (int)*psVar7;
    psVar7 = psVar7 + 1;
  }
  puVar3[1] = *(byte *)(param_2 + 0x7d) + 1;
  FUN_008cd810(*(undefined1 *)(param_2 + 8),*(undefined1 *)(param_2 + 9),param_2 + 0x28,
               *(undefined4 *)(param_2 + 0x74),0);
  FUN_008cd810(*(undefined1 *)(param_2 + 10),*(undefined1 *)(param_2 + 0xb),param_2 + 0x58,
               *(undefined4 *)(param_2 + 0x74),1);
  FUN_008cdbe0();
  FUN_008cdbe0();
  FUN_008cdbe0();
  sVar2 = FUN_008cdbe0();
  iVar4 = FUN_008b7f40(1000,(int)sVar2);
  iVar6 = *(int *)(param_2 + 0x6c);
  if (iVar4 <= *(int *)(param_2 + 0x6c)) {
    iVar6 = iVar4;
  }
  puVar3[0x26b] = iVar6;
  puVar3[0x26c] = *(undefined4 *)(param_2 + 0x70);
  uVar1 = *(undefined4 *)(param_2 + 0x74);
  puVar3[0x32] = 0;
  puVar3[0x33] = 0;
  puVar3[0x65] = 0;
  puVar3[0x66] = 0;
  puVar3[0x26e] = uVar1;
  *param_3 = (int)puVar3;
  return local_8;
}

