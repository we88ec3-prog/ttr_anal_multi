
void FUN_0076cc50(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_8;
  
  *(int *)(in_EAX + 0xac) = -*(int *)(in_EAX + 0xa4);
  *(int *)(in_EAX + 0xb0) = -*(int *)(in_EAX + 0xa8);
  *(int *)(in_EAX + 0xb4) = -*(int *)(in_EAX + 0xa4);
  *(int *)(in_EAX + 0xb8) = -*(int *)(in_EAX + 0xa8);
  piVar1 = *(int **)(in_EAX + 100);
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    iVar8 = *(int *)(in_EAX + 0xac);
    iVar9 = *(int *)(in_EAX + 0xb0);
    iVar7 = *(int *)(in_EAX + 0xb4);
    local_8 = *(int *)(in_EAX + 0xb8);
    do {
      iVar2 = piVar3[2];
      iVar5 = *(int *)(iVar2 + 8);
      if (iVar8 < *(int *)(iVar2 + 8)) {
        iVar5 = iVar8;
      }
      *(int *)(in_EAX + 0xac) = iVar5;
      iVar6 = *(int *)(iVar2 + 0x10);
      if (*(int *)(iVar2 + 0x10) < iVar7) {
        iVar6 = iVar7;
      }
      *(int *)(in_EAX + 0xb4) = iVar6;
      iVar7 = *(int *)(iVar2 + 0xc);
      if (iVar9 < *(int *)(iVar2 + 0xc)) {
        iVar7 = iVar9;
      }
      *(int *)(in_EAX + 0xb0) = iVar7;
      iVar4 = *(int *)(iVar2 + 0x14);
      if (*(int *)(iVar2 + 0x14) < local_8) {
        iVar4 = local_8;
      }
      *(int *)(in_EAX + 0xb8) = iVar4;
      piVar3 = (int *)*piVar3;
      iVar8 = iVar5;
      iVar9 = iVar7;
      iVar7 = iVar6;
      local_8 = iVar4;
    } while (piVar3 != piVar1);
  }
  return;
}

