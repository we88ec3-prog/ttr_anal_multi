
undefined4 FUN_004ff6a0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 *unaff_ESI;
  uint local_30;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092413e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_004ff610(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  if (param_2 < 0x7f) {
    FUN_006edb60(&DAT_00bf6cbc);
  }
  if (param_2 < 0x87) {
    FUN_006edb60(&DAT_00bf6cbc);
  }
  if (param_2 < 0x88) {
    FUN_006edb60(&DAT_00bf6cbc);
  }
  local_30 = 0x8c;
  if (param_2 < 0x8c) {
    FUN_006edb60(&DAT_00bf6cbc);
  }
  *unaff_ESI = *(undefined4 *)(param_1 + 2);
  *(undefined2 *)(unaff_ESI + 1) = *(undefined2 *)(param_1 + 6);
  *(undefined2 *)(unaff_ESI + 3) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(unaff_ESI + 4) = *(undefined2 *)(param_1 + 0x12);
  *(undefined2 *)((int)unaff_ESI + 0xe) = *(undefined2 *)(param_1 + 0xe);
  *(undefined1 *)((int)unaff_ESI + 0x1e) = *(undefined1 *)(param_1 + 0x34);
  *(undefined1 *)((int)unaff_ESI + 0x1f) = *(undefined1 *)(param_1 + 0x36);
  *(undefined1 *)(unaff_ESI + 9) = *(undefined1 *)(param_1 + 0x3f);
  unaff_ESI[0xd] = *(undefined4 *)(param_1 + 0x4d);
  unaff_ESI[0xe] = *(undefined4 *)(param_1 + 0x55);
  *(undefined2 *)(unaff_ESI + 0xf) = *(undefined2 *)(param_1 + 0x5d);
  unaff_ESI[0x10] = *(undefined4 *)(param_1 + 0x61);
  *(undefined2 *)(unaff_ESI + 0x11) = *(undefined2 *)(param_1 + 0x69);
  *(undefined2 *)((int)unaff_ESI + 0x12) = *(undefined2 *)(param_1 + 0x1c);
  *(undefined2 *)(unaff_ESI + 6) = *(undefined2 *)(param_1 + 0x22);
  *(undefined2 *)(unaff_ESI + 5) = *(undefined2 *)(param_1 + 0x1e);
  *(undefined2 *)((int)unaff_ESI + 0x1a) = *(undefined2 *)(param_1 + 0x24);
  *(undefined2 *)((int)unaff_ESI + 0x16) = *(undefined2 *)(param_1 + 0x20);
  *(undefined2 *)(unaff_ESI + 7) = *(undefined2 *)(param_1 + 0x26);
  *(undefined1 *)(unaff_ESI + 8) = *(undefined1 *)(param_1 + 0x37);
  *(undefined1 *)((int)unaff_ESI + 0x21) = *(undefined1 *)(param_1 + 0x38);
  *(undefined1 *)((int)unaff_ESI + 0x22) = *(undefined1 *)(param_1 + 0x39);
  *(undefined1 *)((int)unaff_ESI + 0x23) = *(undefined1 *)(param_1 + 0x3a);
  *(undefined2 *)((int)unaff_ESI + 0x26) = *(undefined2 *)(param_1 + 0x41);
  *(undefined2 *)(unaff_ESI + 10) = *(undefined2 *)(param_1 + 0x43);
  *(undefined2 *)((int)unaff_ESI + 0x2a) = *(undefined2 *)(param_1 + 0x45);
  *(undefined1 *)((int)unaff_ESI + 6) = *(undefined1 *)(param_1 + 0x87);
  unaff_ESI[2] = *(undefined4 *)(param_1 + 0x88);
  *(undefined1 *)(unaff_ESI + 0xb) = *(undefined1 *)(param_1 + 0x80);
  *(undefined1 *)((int)unaff_ESI + 0x2d) = *(undefined1 *)(param_1 + 0x81);
  *(undefined1 *)((int)unaff_ESI + 0x2e) = *(undefined1 *)(param_1 + 0x82);
  *(undefined1 *)((int)unaff_ESI + 0x2f) = *(undefined1 *)(param_1 + 0x83);
  *(undefined1 *)(unaff_ESI + 0xc) = *(undefined1 *)(param_1 + 0x84);
  *(undefined1 *)((int)unaff_ESI + 0x31) = *(undefined1 *)(param_1 + 0x85);
  *(undefined1 *)((int)unaff_ESI + 0x32) = *(undefined1 *)(param_1 + 0x86);
  pbVar4 = (byte *)(param_1 + 0x8c);
  while (local_30 < param_2) {
    local_30 = local_30 + 0xf;
    if (param_2 < local_30) {
      FUN_006edb60(&DAT_00bf6cbc);
    }
    uVar2 = *(undefined4 *)(pbVar4 + 0xb);
    uVar3 = *(undefined4 *)(pbVar4 + 5);
    local_20 = CONCAT22(local_20._2_2_,*(undefined2 *)(pbVar4 + 9));
    puVar1 = unaff_ESI + (uint)*pbVar4 * 4 + 0x12;
    *puVar1 = *(undefined4 *)(pbVar4 + 1);
    puVar1[1] = uVar3;
    puVar1[2] = local_20;
    puVar1[3] = uVar2;
    pbVar4 = pbVar4 + 0xf;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf431e);
  ExceptionList = local_14;
  return 0;
}

