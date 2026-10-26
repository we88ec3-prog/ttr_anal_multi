
void FUN_00404de0(int param_1)

{
  undefined4 *puVar1;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(unaff_EDI + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(unaff_EDI + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(unaff_EDI + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(unaff_EDI + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(unaff_EDI + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(unaff_EDI + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(unaff_EDI + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(unaff_EDI + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(unaff_EDI + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(unaff_EDI + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(unaff_EDI + 0x48) = *(undefined4 *)(param_1 + 0x48);
  if (unaff_EDI + 0x4c != param_1 + 0x4c) {
    FUN_005540c0(**(undefined4 **)(unaff_EDI + 0x50),*(undefined4 **)(unaff_EDI + 0x50));
    FUN_005c7580(param_1 + 0x4c);
  }
  *(undefined2 *)(unaff_EDI + 0x5c) = *(undefined2 *)(param_1 + 0x5c);
  *(undefined4 *)(unaff_EDI + 0x60) = *(undefined4 *)(param_1 + 0x60);
  if ((undefined4 *)(unaff_EDI + 100) != (undefined4 *)(param_1 + 100)) {
    puVar1 = *(undefined4 **)(param_1 + 100);
    FUN_00404d90(*puVar1,puVar1,param_1);
  }
  *(undefined4 *)(unaff_EDI + 0x70) = *(undefined4 *)(param_1 + 0x70);
  if ((undefined4 *)(unaff_EDI + 0x74) != (undefined4 *)(param_1 + 0x74)) {
    puVar1 = *(undefined4 **)(param_1 + 0x74);
    FUN_00404d90(*puVar1,puVar1,param_1);
  }
  return;
}

