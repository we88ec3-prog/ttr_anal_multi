
void FUN_00644ec0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x150) + 0x20)) {
      FUN_00644ff0((byte)(*(uint *)(*(int *)(in_ECX + 0x150) + 0x28) >> 9) & 1);
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x154) + 0x20)) {
      if ((*(uint *)(*(int *)(in_ECX + 0x154) + 0x28) >> 9 & 1) == 0) {
        puVar1 = (undefined4 *)FUN_00891268(0x18);
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[1] = 0xffffffff;
          puVar1[2] = 0xffffffff;
          puVar1[3] = 0;
          puVar1[4] = 0xf4328;
          *puVar1 = FoxUI::FXUIEventB1::vftable;
          *(undefined1 *)(puVar1 + 5) = 0;
          FUN_004072a0();
          return;
        }
      }
      else {
        puVar1 = (undefined4 *)FUN_00891268(0x18);
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[1] = 0xffffffff;
          puVar1[2] = 0xffffffff;
          puVar1[3] = 0;
          puVar1[4] = 0xf4328;
          *puVar1 = FoxUI::FXUIEventB1::vftable;
          *(undefined1 *)(puVar1 + 5) = 1;
          FUN_004072a0();
          return;
        }
      }
      FUN_004072a0();
      return;
    }
  }
  else if (((*(int *)(param_1 + 0x10) == 0x76c) && (*(int *)(*(int *)(in_ECX + 0x110) + 0xcc) != 0))
          && (*(int *)(*(int *)(in_ECX + 0x110) + 0xd8) != 0)) {
    iVar2 = FUN_005f55a0();
    if (iVar2 != -1) {
      FUN_00645060(in_ECX);
      FUN_0040f8c0();
      FUN_004d7ab0();
    }
  }
  return;
}

