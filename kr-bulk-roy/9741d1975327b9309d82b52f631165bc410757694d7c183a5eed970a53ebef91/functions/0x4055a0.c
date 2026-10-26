
void FUN_004055a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  uint local_c;
  
  FUN_00755e50();
  local_c = 0;
  do {
    uVar7 = local_c / 7;
    uVar5 = local_c % 7;
    iVar6 = (uVar7 * 100 + 0x65 + uVar5) * 100;
    FUN_00615fc0(iVar6 + 1000);
    FUN_00615fc0(iVar6 + 1);
    FUN_0043c570(iVar6 + 6);
    iVar1 = *(int *)(in_ECX + ((uVar7 + 0x11) * 7 + uVar5) * 4);
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 3;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 3;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar1 + 0x14);
    if (*(int *)(iVar1 + 0x60) != 0) {
      iVar2 = *(int *)(*(int *)(iVar1 + 0x60) + 0x2c);
      *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + iVar2;
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + iVar2;
      iVar2 = *(int *)(*(int *)(iVar1 + 0x60) + 0x30);
      *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + iVar2;
      *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + iVar2;
    }
    puVar3 = *(undefined4 **)(iVar1 + 100);
    for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
      FUN_00746f70();
    }
    (**(code **)(**(int **)(in_ECX + ((uVar7 + 0xd) * 7 + uVar5) * 4) + 0x198))(iVar6 + 3);
    local_c = local_c + 1;
  } while ((int)local_c < 0x1c);
  FUN_00615fc0(50000);
  FUN_0046b6f0(5);
  FUN_0046b6f0(19000);
  iVar1 = *(int *)(in_ECX + 0x24c);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x24c);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar6 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
  }
  iVar1 = *(int *)(in_ECX + 0x250);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x250);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar6 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
  }
  return;
}

