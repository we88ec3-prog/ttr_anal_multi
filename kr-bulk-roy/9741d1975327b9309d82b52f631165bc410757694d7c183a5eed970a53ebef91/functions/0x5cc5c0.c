
void FUN_005cc5c0(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined2 unaff_SI;
  int unaff_EDI;
  undefined2 uStack_3c;
  undefined4 *local_38;
  int local_30;
  int *local_2c;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_2c = (int *)0xb;
  FUN_0082ef00(&local_2c);
  if (local_30 == *(int *)(in_ECX + 0x50)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_30 + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar2;
  FUN_00643ce0(100);
  FUN_005fed30();
  FUN_00643ce0(300);
  FUN_005d06d0();
  FUN_005d07c0();
  local_18 = in_ECX + 0x334;
  FUN_0046b6f0(600);
  FUN_00643ce0(700);
  FUN_00643ce0(800);
  FUN_00643ce0(900);
  FUN_00643ce0(1000);
  FUN_0043c570(0x1fa4);
  FUN_005d08b0();
  FUN_005d09a0();
  FUN_005d0a90();
  FUN_0046b6f0(0x20d1);
  FUN_0043c570(0x2134);
  FUN_0043c570(0x2198);
  local_c = in_ECX + 0x300;
  FUN_0043c570(49000);
  local_10 = in_ECX + 0x2fc;
  FUN_0043c570(47000);
  local_14 = in_ECX + 0x2f8;
  FUN_0043c570(48000);
  FUN_0043c570(61000);
  FUN_0046b6f0(60000);
  FUN_005d0b80();
  local_38 = (undefined4 *)(in_ECX + 0x10c);
  sVar1 = 0;
  local_30 = 12000;
  iVar5 = 0x30d41;
  do {
    FUN_0043c570(iVar5 + -0x2bf21);
    FUN_0043c570(iVar5 + -0x29811);
    FUN_00615fc0(iVar5 + -0x186a1);
    (**(code **)(*(int *)*local_38 + 0x1a0))(iVar5 + -100000,sVar1);
    FUN_00615fc0(iVar5 + -1);
    (**(code **)(*(int *)local_38[6] + 0x1a0))(iVar5,uStack_3c);
    FUN_00615fc0(iVar5 + 99999);
    (**(code **)(**(int **)(unaff_EDI + 0x30) + 0x1a0))(iVar5 + 100000,unaff_SI);
    FUN_0046b6f0(iVar5 + -0x1869e);
    FUN_0046b6f0(iVar5 + -180000);
    FUN_0046b6f0(iVar5 + -170000);
    FUN_0046b6f0(iVar5 + 2);
    local_2c = local_38 + 0x4f;
    FUN_0046b6f0(iVar5 + 0x186a2);
    piStack_28 = (int *)local_38[0x37];
    piStack_24 = local_38 + 0x37;
    FUN_007444b0(0xbf6b);
    piStack_20 = local_38 + 0x3d;
    *(undefined1 *)((int)piStack_28 + 0xa4) = 1;
    piStack_28 = (int *)*piStack_20;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)((int)piStack_28 + 0xa4) = 1;
    piStack_28 = (int *)local_38[0x43];
    piStack_1c = local_38 + 0x43;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)((int)piStack_28 + 0xa4) = 1;
    iVar4 = local_38[0x49];
    piStack_28 = local_38 + 0x49;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    iVar4 = *local_2c;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    iVar4 = *piStack_24;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    iVar4 = *piStack_20;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    iVar4 = *piStack_1c;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    iVar4 = *piStack_28;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    iVar4 = *local_2c;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    FUN_0046b6f0(local_30 + -1000);
    FUN_0046b6f0(local_30);
    sVar1 = sVar1 + 1;
    local_30 = local_30 + 100;
    local_38 = local_38 + 1;
    iVar5 = iVar5 + 1000;
  } while (iVar5 < 0x324b1);
  FUN_005d0c70();
  FUN_00615fc0(72000);
  FUN_00615fc0(71000);
  FUN_0043c570(73000);
  (**(code **)(**(int **)(in_ECX + 0x30c) + 0x198))(0x11941);
  (**(code **)(**(int **)(in_ECX + 0x310) + 0x198))(0x11559);
  FUN_0046b6f0(0x11942);
  iVar5 = *(int *)(in_ECX + 0x264);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar5 + 0xa4) = 1;
  iVar5 = *(int *)(in_ECX + 0x264);
  if ((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar5 + 0x94) + 0x4c) = 1;
    }
  }
  iVar5 = *piStack_20;
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar5 + 0xa4) = 1;
  FUN_00754510();
  FUN_00754510();
  FUN_00754510();
  return;
}

