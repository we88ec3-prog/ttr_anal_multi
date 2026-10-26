
void FUN_008ec000(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_EDX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *param_1 = param_2;
  param_1[1] = in_EDX;
  if (in_EDX != 0) {
    param_1[99] = *(undefined4 *)(in_EDX + 0x74);
    param_1[100] = *(undefined4 *)(in_EDX + 0x78);
    param_1[0x66] = *(undefined4 *)(in_EDX + 0x80);
    param_1[0x67] = *(undefined4 *)(in_EDX + 0x84);
    param_1[0x65] = *(undefined4 *)(in_EDX + 0x7c);
    param_1[0x68] = *(undefined4 *)(in_EDX + 0x88);
    puVar4 = (undefined4 *)(in_EDX + 0x48);
    puVar5 = param_1 + 0x3d;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = (undefined4 *)(in_EDX + 0x2c);
    puVar5 = param_1 + 0x36;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    param_1[0x69] = *(undefined4 *)(in_EDX + 0x8c);
    param_1[0x6a] = *(undefined4 *)(in_EDX + 0x90);
    param_1[0x6f] = *(undefined4 *)(in_EDX + 0x94);
    param_1[0x70] = *(undefined4 *)(in_EDX + 0x98);
    param_1[0x71] = *(undefined4 *)(in_EDX + 0x9c);
    param_1[0x72] = *(undefined4 *)(in_EDX + 0xa0);
    param_1[0x73] = *(undefined4 *)(in_EDX + 0xa4);
    param_1[0x74] = *(undefined4 *)(in_EDX + 0xa8);
    puVar4 = (undefined4 *)(in_EDX + 0xac);
    puVar5 = param_1 + 0x47;
    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    param_1[0x5f] = *(undefined4 *)(in_EDX + 0xf0);
    param_1[0x60] = *(undefined4 *)(in_EDX + 0xf4);
    *(undefined2 *)(param_1 + 0x75) = *(undefined2 *)(in_EDX + 0xf8);
    param_1[0x76] = *(undefined4 *)(in_EDX + 0xfc);
    puVar4 = (undefined4 *)(in_EDX + 0x100);
    puVar5 = param_1 + 0x2d;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    puVar4 = param_1 + 9;
    puVar5 = param_1 + 0x12;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar4 = param_1 + 9;
    puVar5 = param_1 + 0x1b;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  uVar1 = param_1[5];
  iVar3 = FUN_008ebfc0(param_1[2]);
  param_1[5] = uVar1;
  if (iVar3 == 0) {
    uVar2 = param_1[0x61];
    iVar3 = FUN_008ebfc0(param_1[2]);
    param_1[0x61] = uVar2 & 0xffff;
    if (iVar3 == 0) {
      param_1[0x26] = 0;
      puVar4 = param_1 + 0x24;
      puVar5 = param_1 + 0x12;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = param_1 + 0x24;
      puVar5 = param_1 + 0x1b;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = param_1 + 0x24;
      puVar5 = param_1 + 9;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(undefined1 *)(param_1 + 0x7a) = 0;
    }
  }
  return;
}

