
void FUN_00839e00(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *in_ECX;
  undefined4 *local_1c;
  undefined4 *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0090e627;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbDxRenderer::vftable;
  local_8 = 0xd;
  FUN_0083a130(uVar3);
  piVar2 = (int *)in_ECX[0x3b];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x3b] = 0;
  }
  piVar2 = (int *)in_ECX[0x10b];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x10b] = 0;
  }
  piVar2 = (int *)in_ECX[0x10c];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x10c] = 0;
  }
  piVar2 = (int *)in_ECX[0x113];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x113] = 0;
  }
  piVar2 = (int *)in_ECX[0x112];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x112] = 0;
  }
  piVar2 = (int *)in_ECX[0xfc];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0xfc] = 0;
  }
  piVar2 = (int *)in_ECX[0x115];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x115] = 0;
  }
  FUN_0083ee90(in_ECX + 0x119);
  FUN_0089120c(in_ECX[0x119]);
  piVar2 = (int *)in_ECX[0x10f];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x10f] + 4) = in_ECX[0x10f];
  in_ECX[0x110] = 0;
  if (piVar4 != (int *)in_ECX[0x10f]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x10f]);
  }
  FUN_0089120c(in_ECX[0x10f]);
  if (in_ECX[0x105] != 0) {
    FUN_0089120c(in_ECX[0x105]);
  }
  in_ECX[0x105] = 0;
  in_ECX[0x106] = 0;
  in_ECX[0x107] = 0;
  if (0xf < (uint)in_ECX[0x103]) {
    FUN_0089120c(in_ECX[0xfe]);
  }
  local_18[0] = in_ECX + 0xf8;
  in_ECX[0x103] = 0xf;
  in_ECX[0x102] = 0;
  *(undefined1 *)(in_ECX + 0xfe) = 0;
  local_8._0_1_ = 0xe;
  FUN_0083f530(&local_1c,*(undefined4 *)in_ECX[0xf9],(undefined4 *)in_ECX[0xf9]);
  FUN_0089120c(in_ECX[0xf9]);
  local_1c = in_ECX + 0xf4;
  local_8._0_1_ = 0xf;
  FUN_0083f530(local_18,*(undefined4 *)in_ECX[0xf5],(undefined4 *)in_ECX[0xf5]);
  FUN_0089120c(in_ECX[0xf5]);
  local_1c = in_ECX + 0xf0;
  local_8._0_1_ = 0x10;
  FUN_0083f530(local_18,*(undefined4 *)in_ECX[0xf1],(undefined4 *)in_ECX[0xf1]);
  FUN_0089120c(in_ECX[0xf1]);
  local_8._0_1_ = 5;
  if (in_ECX[0xec] != 0) {
    FUN_00840d00(in_ECX[0xed],local_1c);
    FUN_0089120c(in_ECX[0xec]);
  }
  in_ECX[0xec] = 0;
  in_ECX[0xed] = 0;
  in_ECX[0xee] = 0;
  local_8._0_1_ = 4;
  FUN_00838ce0();
  local_8._0_1_ = 3;
  FUN_00839400();
  puVar1 = in_ECX + 0x5e;
  local_8._0_1_ = 0x12;
  piVar2 = (int *)in_ECX[0x6e];
  local_1c = puVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x6e] = 0;
  }
  local_8._0_1_ = 0x11;
  FUN_00843340(in_ECX + 0x6f);
  local_8._0_1_ = 2;
  FUN_00864660(puVar1);
  puVar1 = in_ECX + 0x4d;
  local_8._0_1_ = 0x13;
  piVar2 = (int *)in_ECX[0x5d];
  local_1c = puVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x5d] = 0;
  }
  local_8._0_1_ = 1;
  FUN_00863ec0(puVar1);
  puVar1 = in_ECX + 0x3c;
  local_8._0_1_ = 0x14;
  piVar2 = (int *)in_ECX[0x4c];
  local_1c = puVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    in_ECX[0x4c] = 0;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00863870(puVar1);
  local_8 = 0xffffffff;
  FUN_008499b0();
  ExceptionList = local_10;
  return;
}

