
int FUN_008f9df0(int param_1)

{
  void *pvVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_c;
  
  pvVar1 = *(void **)(unaff_ESI + 0x30);
  local_c = *(void **)(unaff_EDI + 0xc);
  pvVar5 = *(void **)(unaff_ESI + 0x34);
  if (pvVar5 < pvVar1) {
    pvVar5 = *(void **)(unaff_ESI + 0x2c);
  }
  uVar2 = *(uint *)(unaff_EDI + 0x10);
  uVar6 = (int)pvVar5 - (int)pvVar1;
  if (uVar2 < (uint)((int)pvVar5 - (int)pvVar1)) {
    uVar6 = uVar2;
  }
  if ((uVar6 != 0) && (param_1 == -5)) {
    param_1 = 0;
  }
  *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + uVar6;
  *(uint *)(unaff_EDI + 0x10) = uVar2 - uVar6;
  if (*(code **)(unaff_ESI + 0x38) != (code *)0x0) {
    uVar3 = (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x3c),pvVar1,uVar6);
    *(undefined4 *)(unaff_ESI + 0x3c) = uVar3;
    *(undefined4 *)(unaff_EDI + 0x30) = uVar3;
  }
  FID_conflict__memcpy(local_c,pvVar1,uVar6);
  local_c = (void *)((int)local_c + uVar6);
  iVar4 = (int)pvVar1 + uVar6;
  if (iVar4 == *(int *)(unaff_ESI + 0x2c)) {
    pvVar1 = *(void **)(unaff_ESI + 0x28);
    if (*(int *)(unaff_ESI + 0x34) == *(int *)(unaff_ESI + 0x2c)) {
      *(void **)(unaff_ESI + 0x34) = pvVar1;
    }
    uVar2 = *(uint *)(unaff_EDI + 0x10);
    uVar6 = *(int *)(unaff_ESI + 0x34) - (int)pvVar1;
    if (uVar2 < uVar6) {
      uVar6 = uVar2;
    }
    if ((uVar6 != 0) && (param_1 == -5)) {
      param_1 = 0;
    }
    *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + uVar6;
    *(uint *)(unaff_EDI + 0x10) = uVar2 - uVar6;
    if (*(code **)(unaff_ESI + 0x38) != (code *)0x0) {
      uVar3 = (**(code **)(unaff_ESI + 0x38))(*(undefined4 *)(unaff_ESI + 0x3c),pvVar1,uVar6);
      *(undefined4 *)(unaff_ESI + 0x3c) = uVar3;
      *(undefined4 *)(unaff_EDI + 0x30) = uVar3;
    }
    FID_conflict__memcpy(local_c,pvVar1,uVar6);
    local_c = (void *)((int)local_c + uVar6);
    iVar4 = (int)pvVar1 + uVar6;
  }
  *(void **)(unaff_EDI + 0xc) = local_c;
  *(int *)(unaff_ESI + 0x30) = iVar4;
  return param_1;
}

