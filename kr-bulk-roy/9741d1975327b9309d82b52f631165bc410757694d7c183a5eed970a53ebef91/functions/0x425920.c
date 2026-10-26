
void FUN_00425920(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *in_ECX;
  undefined2 auStack_110 [6];
  undefined4 uStack_104;
  undefined4 *puStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined2 auStack_f4 [4];
  undefined4 uStack_ec;
  int iStack_e8;
  undefined4 *puStack_e4;
  int *piStack_e0;
  undefined1 local_c4 [20];
  uint local_b0;
  byte *local_a8;
  undefined1 *local_a4;
  undefined1 *local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
  uint local_80;
  int local_78 [4];
  uint local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b620;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a0 = (undefined1 *)0x0;
  local_a8 = in_ECX;
  (**(code **)(**(int **)(param_1 + 0x254) + 0x94))();
  (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  puStack_e4 = *(undefined4 **)(in_ECX + 0x24);
  if (*(char *)((int)puStack_e4[1] + 0x45) == '\0') {
    puVar1 = (undefined4 *)puStack_e4[1];
    do {
      if (*(byte *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puStack_e4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x45) == '\0');
  }
  if ((puStack_e4 != *(undefined4 **)(in_ECX + 0x24)) && (*(byte *)(puStack_e4 + 3) <= *param_2)) {
    local_9c = *(undefined1 *)(puStack_e4 + 4);
    local_98 = puStack_e4[5];
    piStack_e0 = (int *)0x0;
    puStack_e4 = puStack_e4 + 6;
    local_80 = 7;
    local_84 = 0;
    local_94 = (uint)local_94._2_2_ << 0x10;
    iStack_e8 = 0x4259fc;
    FUN_004026e0();
    piStack_e0 = local_78;
    local_8 = 0;
    puStack_e4 = (undefined4 *)0x425a10;
    FUN_004fcd00();
    local_8 = 1;
    if (*(uint *)(in_ECX + 0x28) < 2) {
      local_30 = local_30 & 0xffff0000;
      piStack_e0 = (int *)&DAT_00bed1fc;
      local_1c = 7;
      local_20 = 0;
      puStack_e4 = (undefined4 *)0x425a70;
      FUN_00402160();
      local_8 = 3;
      local_a0 = (undefined1 *)0x2;
    }
    else {
      FUN_004ed610();
      local_8 = CONCAT31(local_8._1_3_,2);
      local_a0 = (undefined1 *)0x1;
    }
    local_38 = 7;
    local_3c = 0;
    local_4c = (uint)local_4c._2_2_ << 0x10;
    piStack_e0 = (int *)0x425a9d;
    FUN_00402800();
    local_8 = 4;
    if (((uint)local_a0 & 2) != 0) {
      local_a0 = (undefined1 *)((uint)local_a0 & 0xfffffffd);
      if (7 < local_1c) {
        piStack_e0 = (int *)0x425ac3;
        FUN_0089120c();
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
    }
    local_8._0_1_ = 6;
    if (((uint)local_a0 & 1) != 0) {
      if (7 < local_54) {
        piStack_e0 = (int *)0x425af2;
        FUN_0089120c();
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = local_68 & 0xffff0000;
    }
    local_a4 = (undefined1 *)auStack_f4;
    uStack_f8 = 0xffffffff;
    uStack_fc = 0;
    puStack_100 = &local_4c;
    piStack_e0 = (int *)0x7;
    puStack_e4 = (undefined4 *)0x0;
    auStack_f4[0] = 0;
    uStack_104 = 0x425b2b;
    FUN_004026e0();
    local_a0 = (undefined1 *)auStack_110;
    local_8._0_1_ = 7;
    uStack_fc = 7;
    puStack_100 = (undefined4 *)0x0;
    auStack_110[0] = 0;
    FUN_004026e0(in_ECX + 4,0,0xffffffff);
    local_8._0_1_ = 6;
    FUN_004213a0(L"{0}{1}");
    iVar3 = *(int *)(param_1 + 0x250);
    local_8._0_1_ = 8;
    FUN_007578f0();
    piStack_e0 = (int *)0x7b;
    puStack_e4 = (undefined4 *)local_c4;
    uStack_ec = 0x425b92;
    iStack_e8 = iVar3 + 0xe8;
    FUN_00759ed0();
    local_8._0_1_ = 6;
    if (7 < local_b0) {
      piStack_e0 = (int *)0x425bab;
      FUN_0089120c();
    }
    (**(code **)(**(int **)(param_1 + 0x250) + 200))();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8._0_1_ = 9;
      FUN_005c3de0();
      piStack_e0 = (int *)0x425be1;
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8._0_1_ = 6;
    }
    local_a0 = (undefined1 *)(uint)*in_ECX;
    piStack_e0 = (int *)0x425c08;
    FUN_0082ef00();
    local_a4 = *(undefined1 **)(param_1 + 0x248);
    if (((*(char *)((int)local_a4 + 0xa4) != '\0') && (*(int *)((int)local_a4 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)((int)local_a4 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      FUN_0077b200();
      in_ECX = local_a8;
    }
    (**(code **)(**(int **)(param_1 + 0x248) + 200))();
    *(byte *)(param_1 + 600) = *in_ECX;
    *(undefined4 *)(param_1 + 0x25c) = local_98;
    *(byte *)(param_1 + 0x260) = *param_2;
    if (7 < local_38) {
      piStack_e0 = (int *)0x425cac;
      FUN_0089120c();
    }
    local_4c = local_4c & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    if (local_78[0] != 0) {
      piStack_e0 = (int *)0x425cce;
      FUN_0089120c();
    }
    local_78[0] = 0;
    local_78[1] = 0;
    local_78[2] = 0;
    if (7 < local_80) {
      piStack_e0 = (int *)0x425ceb;
      FUN_0089120c();
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  piStack_e0 = (int *)&UNK_00425d16;
  FUN_0087db7d();
}

