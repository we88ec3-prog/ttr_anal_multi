
void FUN_006bed20(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int *unaff_EDI;
  bool bVar6;
  
  puVar2 = (ushort *)(unaff_EDI[0x5b] + 0xe8);
  iVar5 = 0;
  if (7 < *(uint *)(unaff_EDI[0x5b] + 0xfc)) {
    puVar2 = *(ushort **)puVar2;
  }
  puVar4 = &DAT_00bed1fc;
  do {
    uVar1 = *puVar2;
    bVar6 = uVar1 < *puVar4;
    if (uVar1 != *puVar4) {
LAB_006bed6b:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_006bed70;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar2[1];
    bVar6 = uVar1 < puVar4[1];
    if (uVar1 != puVar4[1]) goto LAB_006bed6b;
    puVar2 = puVar2 + 2;
    puVar4 = puVar4 + 2;
  } while (uVar1 != 0);
  iVar3 = 0;
LAB_006bed70:
  if (iVar3 != 0) {
    iVar5 = 0x14;
  }
  FUN_00749a00(*(undefined4 *)(unaff_EDI[0x5c] + 8),iVar5 + 0x3c);
  FUN_007545b0();
  iVar5 = unaff_EDI[0x57];
  iVar3 = *(int *)(unaff_EDI[0x5c] + 0x14) + 0xf;
  (**(code **)(*(int *)unaff_EDI[0x57] + 0xbc))
            (*(undefined4 *)(iVar5 + 8),*(int *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),
             iVar3 + *(int *)(iVar5 + 0xc));
  (**(code **)(*unaff_EDI + 0xbc))(unaff_EDI[2],unaff_EDI[3],unaff_EDI[4],iVar3 + unaff_EDI[3]);
  return;
}

