
int FUN_007f21a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  int local_44;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00909bd3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = FUN_00891268(0xb4,DAT_00d61f20 ^ (uint)&stack0xffffffb0);
  uVar3 = 0;
  local_c = 0;
  if (iVar1 == 0) {
    local_44 = 0;
  }
  else {
    local_44 = FUN_007f15b0(1);
  }
  local_c = 0xffffffff;
  *(undefined4 *)(local_44 + 0x70) = *(undefined4 *)(in_ECX + 0x70);
  *(undefined4 *)(local_44 + 0xb0) = *(undefined4 *)(in_ECX + 0xb0);
  *(undefined4 *)(local_44 + 0xac) = *(undefined4 *)(in_ECX + 0xac);
  if (*(int *)(in_ECX + 0x88) != 0) {
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x88) + 0xc))();
    *(undefined4 *)(local_44 + 0x88) = uVar2;
    iStack_28 = 0;
    iStack_24 = 0;
    uStack_20 = 0;
    local_c = 1;
    FUN_007c7dd0(uVar2,&iStack_28);
    if (iStack_24 - iStack_28 >> 2 != 0) {
      do {
        FUN_008551d0();
        FUN_00855110();
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(iStack_24 - iStack_28 >> 2));
    }
    FUN_007f1eb0(local_44);
    FUN_007cbb00(*(undefined4 *)(local_44 + 0x88),local_44 + 0x9c);
    if (iStack_28 != 0) {
      FUN_0089120c(iStack_28);
    }
  }
  ExceptionList = local_14;
  return local_44;
}

