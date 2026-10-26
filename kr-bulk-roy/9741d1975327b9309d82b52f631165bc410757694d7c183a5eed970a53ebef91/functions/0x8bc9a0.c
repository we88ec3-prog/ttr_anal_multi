
int FUN_008bc9a0(undefined4 *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  puVar2 = param_1;
  uVar5 = param_1[1];
  uVar6 = *param_1;
  uVar7 = (int)*(short *)((int)param_1 + 0x16) + *(short *)((int)param_1 + 0x3a) + param_2;
  bVar1 = false;
  param_1 = (undefined4 *)0x0;
  if (uVar5 < uVar7) {
    uVar7 = uVar7 + 7 & 0xfffffff8;
    if (0x7fff < uVar7) {
      return 10;
    }
    uVar3 = FUN_008bc7d0(uVar6,8,uVar5,uVar7,puVar2[6],&param_1);
    puVar2[6] = uVar3;
    if (param_1 != (undefined4 *)0x0) goto LAB_008bcafc;
    uVar3 = FUN_008bc7d0(uVar6,1,uVar5,uVar7,puVar2[7],&param_1);
    puVar2[7] = uVar3;
    if (param_1 != (undefined4 *)0x0) goto LAB_008bcafc;
    if (*(char *)(puVar2 + 4) != '\0') {
      iVar4 = FUN_008bc7d0(uVar6,8,uVar5 * 2,uVar7 * 2,puVar2[10],&param_1);
      puVar2[10] = iVar4;
      if (param_1 != (undefined4 *)0x0) goto LAB_008bcafc;
      FID_conflict__memcpy((void *)(iVar4 + uVar7 * 8),(void *)(uVar5 * 8 + iVar4),uVar5 * 8);
      puVar2[0xb] = puVar2[10] + uVar7 * 8;
    }
    bVar1 = true;
    puVar2[1] = uVar7;
  }
  uVar5 = (int)*(short *)(puVar2 + 5) + *(short *)(puVar2 + 0xe) + param_3;
  if (uVar5 <= (uint)puVar2[2]) {
    if (!bVar1) {
      return (int)param_1;
    }
    FUN_008b82f0();
    return (int)param_1;
  }
  uVar5 = uVar5 + 3 & 0xfffffffc;
  if (0x7fff < uVar5) {
    return 10;
  }
  uVar6 = FUN_008bc7d0(uVar6,2,puVar2[2],uVar5,puVar2[8],&param_1);
  puVar2[8] = uVar6;
  if (param_1 == (undefined4 *)0x0) {
    puVar2[2] = uVar5;
    FUN_008b82f0();
    return (int)param_1;
  }
LAB_008bcafc:
  FUN_008ba230(puVar2);
  return (int)param_1;
}

