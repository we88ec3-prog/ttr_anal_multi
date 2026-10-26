
uint FUN_008edd70(undefined4 *param_1,uint *param_2,undefined4 *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ushort *in_EDX;
  int unaff_EBX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_28 [2];
  ushort local_20;
  
  iVar5 = 9;
  puVar7 = local_28;
  if ((*(byte *)(unaff_EBX + 0x170) & 1) == 0) {
    uVar1 = *(ushort *)(unaff_EBX + 0x120);
    puVar6 = (undefined4 *)(unaff_EBX + 0x48);
  }
  else {
    uVar1 = *(ushort *)(unaff_EBX + 0x11e);
    puVar6 = (undefined4 *)(unaff_EBX + 0x24);
  }
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  if (local_20 <= uVar1) {
    if (*(char *)(unaff_EBX + 0x231) != '\0') {
      *(undefined4 *)(unaff_EBX + 0xc) = 0x86;
    }
    *in_EDX = 0;
    return 1;
  }
  puVar7 = local_28;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_3 = *puVar7;
    puVar7 = puVar7 + 1;
    param_3 = param_3 + 1;
  }
  *in_EDX = uVar1;
  uVar2 = (**(code **)(unaff_EBX + 0x23c))();
  uVar3 = FUN_008b7dc0(uVar2,(int)*(short *)(unaff_EBX + 0x12a),*(undefined4 *)(unaff_EBX + 0x234));
  *param_1 = uVar3;
  uVar4 = FUN_008b7dc0(uVar2,(int)*(short *)(unaff_EBX + 300),*(undefined4 *)(unaff_EBX + 0x234));
  *param_2 = uVar4;
  return uVar4 & 0xffffff00;
}

