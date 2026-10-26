
undefined4 FUN_004f10a0(undefined4 *param_1,undefined4 *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  bool bVar5;
  
  puVar4 = (ushort *)*param_2;
  puVar3 = (ushort *)*param_1;
  while( true ) {
    uVar1 = *puVar3;
    bVar5 = uVar1 < *puVar4;
    if (uVar1 != *puVar4) break;
    if (uVar1 == 0) {
      return 0;
    }
    uVar1 = puVar3[1];
    bVar5 = uVar1 < puVar4[1];
    if (uVar1 != puVar4[1]) break;
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 2;
    if (uVar1 == 0) {
      return 0;
    }
  }
  iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 < 0);
}

