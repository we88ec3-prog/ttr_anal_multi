
void FUN_0046d0c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_8;
  
  piVar6 = (int *)(in_EAX + 0xf4);
  piVar7 = (int *)(in_EAX + 0x1d8);
  local_8 = 0x31;
  do {
    iVar1 = *piVar6;
    iVar4 = *piVar7 - *(int *)(iVar1 + 8);
    iVar5 = piVar7[1];
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar4;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar4;
    iVar5 = iVar5 - *(int *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar5;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar5;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar1 + 0x14);
    if (*(int *)(iVar1 + 0x60) != 0) {
      iVar5 = *(int *)(*(int *)(iVar1 + 0x60) + 0x2c);
      *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + iVar5;
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + iVar5;
      iVar5 = *(int *)(*(int *)(iVar1 + 0x60) + 0x30);
      *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + iVar5;
      *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + iVar5;
    }
    puVar2 = *(undefined4 **)(iVar1 + 100);
    for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
      FUN_00746f70();
    }
    (**(code **)(*(int *)*piVar6 + 200))();
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

