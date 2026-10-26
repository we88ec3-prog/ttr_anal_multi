
ulonglong FUN_004f1020(int *param_1,int *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  undefined2 uVar5;
  bool bVar6;
  
  iVar3 = *param_1;
  if (iVar3 != *param_2) {
    return (ulonglong)CONCAT31((int3)((uint)iVar3 >> 8),*param_2 < iVar3);
  }
  puVar2 = (ushort *)param_1[1];
  if (puVar2 == (ushort *)0x0) {
    return CONCAT44(param_1,1);
  }
  puVar4 = (ushort *)param_2[1];
  if (puVar4 == (ushort *)0x0) {
    return (ulonglong)CONCAT43(param_1,(int3)((uint)puVar2 >> 8)) << 8;
  }
  do {
    uVar1 = *puVar2;
    uVar5 = (undefined2)((uint)param_1 >> 0x10);
    param_1 = (int *)CONCAT22(uVar5,uVar1);
    bVar6 = uVar1 < *puVar4;
    if (uVar1 != *puVar4) {
LAB_004f107e:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      return CONCAT44(param_1,CONCAT31((int3)((uint)iVar3 >> 8),iVar3 < 0));
    }
    if (uVar1 == 0) break;
    uVar1 = puVar2[1];
    param_1 = (int *)CONCAT22(uVar5,uVar1);
    bVar6 = uVar1 < puVar4[1];
    if (uVar1 != puVar4[1]) goto LAB_004f107e;
    puVar2 = puVar2 + 2;
    puVar4 = puVar4 + 2;
  } while (uVar1 != 0);
  return ZEXT48(param_1) << 0x20;
}

