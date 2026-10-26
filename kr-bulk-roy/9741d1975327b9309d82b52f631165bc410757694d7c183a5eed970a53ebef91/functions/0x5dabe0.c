
void FUN_005dabe0(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *unaff_EDI;
  bool bVar5;
  
  puVar3 = (ushort *)(param_1 + 0x2c8);
  puVar4 = unaff_EDI;
  if (7 < *(uint *)(param_1 + 0x2dc)) {
    puVar3 = *(ushort **)puVar3;
  }
  do {
    uVar1 = *puVar3;
    bVar5 = uVar1 < *puVar4;
    if (uVar1 != *puVar4) {
LAB_005dac26:
      iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_005dac2b;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar3[1];
    bVar5 = uVar1 < puVar4[1];
    if (uVar1 != puVar4[1]) goto LAB_005dac26;
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 2;
  } while (uVar1 != 0);
  iVar2 = 0;
LAB_005dac2b:
  if (iVar2 != 0) {
    FUN_00757710();
    (**(code **)(**(int **)(param_1 + 0x2a4) + 200))();
    puVar3 = unaff_EDI;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    } while (uVar1 != 0);
    FUN_00402160(unaff_EDI,(int)puVar3 - (int)(unaff_EDI + 1) >> 1);
  }
  return;
}

