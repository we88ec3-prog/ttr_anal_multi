
void FUN_008c12a0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x3d8);
  if (0 < *(short *)(in_EAX + 0x3d6)) {
    uVar2 = *puVar1;
    *(undefined4 *)(in_EAX + 0xc) = uVar2;
    *(undefined4 *)(in_EAX + 8) = uVar2;
    local_c = puVar1[1];
    piVar5 = puVar1 + 2;
    *(int *)(in_EAX + 0x14) = local_c;
    *(int *)(in_EAX + 0x10) = local_c;
    if (piVar5 < puVar1 + *(short *)(in_EAX + 0x3d6) * 2) {
      iVar7 = *(int *)(in_EAX + 8);
      iVar6 = *(int *)(in_EAX + 0xc);
      local_8 = local_c;
      do {
        iVar3 = *piVar5;
        iVar4 = piVar5[1];
        if (iVar3 < iVar7) {
          *(int *)(in_EAX + 8) = iVar3;
          iVar7 = iVar3;
        }
        if (iVar6 < iVar3) {
          *(int *)(in_EAX + 0xc) = iVar3;
          iVar6 = iVar3;
        }
        if (iVar4 < local_8) {
          *(int *)(in_EAX + 0x10) = iVar4;
          local_8 = iVar4;
        }
        if (local_c < iVar4) {
          *(int *)(in_EAX + 0x14) = iVar4;
          local_c = iVar4;
        }
        piVar5 = piVar5 + 2;
      } while (piVar5 < puVar1 + *(short *)(in_EAX + 0x3d6) * 2);
    }
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) >> 6;
    *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) >> 6;
    *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + 0x3f >> 6;
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 0x3f >> 6;
    return;
  }
  *(undefined4 *)(in_EAX + 0xc) = 0;
  *(undefined4 *)(in_EAX + 8) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  *(undefined4 *)(in_EAX + 0x10) = 0;
  return;
}

